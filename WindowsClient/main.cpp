#include <QApplication>

#include <QLocale>
#include <QTranslator>

#include "./Windows/mainwindow.h"
#include "Common/Common.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "./encryption/encryption.h"
#include <DataTypes/QmlModel.h>

QmlModel* GetQmlModel()
{
    qDebug() << "GetQmlModel!!!!!!!";
    return QmlModel::instance;
}

QReadWriteLock g_ip_lock;
QStringList g_ip_list;

QReadWriteLock custom_ip_lock;
QString custom_ip;

int main(int argc, char *argv[])
{
    RegisterDataType();
    //qmlRegisterType<QmlModel>("MyQmlModel",1,0,"QmlModel");
    qmlRegisterSingletonInstance("MyQmlModel",1,0,"QmlModel",QmlModel::GetSingleton());

    QApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "WindowsClient_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    // 从文件中读取公钥和私钥的字符串表示
    QString publicKeyPath = QCoreApplication::applicationDirPath() + "/key/public_key.pem";
    QString privateKeyPath = QCoreApplication::applicationDirPath() + "/key/private_key.pem";

    MainWindow w;
    w.show();

    QQmlApplicationEngine engine;


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    qDebug() << "before load";
    engine.load(url);
    qDebug() << "after load";


    //QObject::connect(&w,&MainWindow::SignalTakePicture,GetQmlModel(),&QmlModel::SlotTakePicture);
    QObject::connect(&w,&MainWindow::SignalUpdateImage,QmlModel::GetSingleton(),&QmlModel::SlotUpdateImage);

//    auto objList = engine.rootObjects();
//    auto qmlMainWindow = objList.first();
//    QObject::connect(QmlModel::GetSingleton(),SIGNAL(bShowQmlWinChanged()),qmlMainWindow,SLOT(slotUpdateQmlWindow()));


    QUdpSocket socket;
    //将其绑定到本地主机的所有 IPv4 地址和 1234 端口。这样，我们就可以接收到局域网内的所有 UDP 消息。
    if (!socket.bind(QHostAddress::AnyIPv4, 1234)) {
        qDebug() << "Failed to bind UDP socket to port 1234.";
        return -1;
    }

    QObject::connect(&socket, &QUdpSocket::readyRead, [&]() {
        while (socket.hasPendingDatagrams()) {
            QByteArray datagram;
            datagram.resize(socket.pendingDatagramSize());
            QHostAddress senderAddress;
            quint16 senderPort;
            socket.readDatagram(datagram.data(), datagram.size(), &senderAddress, &senderPort);

            qDebug() << "decryptData:" << QString::fromUtf8(datagram);

            // 解密数据
            decryptData(datagram, privateKeyPath, "qwer1234");

            ProcessDatagram(datagram);

            QString receivedMessage = QString::fromUtf8(datagram);
            qDebug() << "Received message:" << receivedMessage;
            qDebug() << "From:" << senderAddress.toString() << "Port:" << senderPort;
        }
    });


    return app.exec();



}


