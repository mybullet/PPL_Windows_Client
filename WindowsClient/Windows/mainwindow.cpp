#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QtConcurrent/QtConcurrent>
#include <QtConcurrentRun>
#include <QMessageBox>
#include <opencv2/opencv.hpp>

#include <QNetworkInterface>
#include <QUdpSocket>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建 QMessageBox 对象
    m_messageBox = new QMessageBox(this);
    m_messageBox->setWindowModality(Qt::NonModal);

    m_hisWin = new HistoryWindow(this);

    client = new TcpClient();
    connect(client, &TcpClient::SignalUpdateMainWindow,this,&MainWindow::SlotUpdateMainWindowState);
    connect(this, &MainWindow::SignalUpdateSelectedFilePath,client,&TcpClient::SlotUpdateSelectedFilePath);
    connect(m_hisWin, &HistoryWindow::SignalPullInfo,client,&TcpClient::SlotPullInfo);

    m_UiStateStr =
    {
        {UiState::Connected,"系统正常"},
        {UiState::Disconnected,"服务器未连接"},
        {UiState::Requesting,"正在请求服务"},
        {UiState::Confirming,"等待服务完成"},
        {UiState::Failed,"请重新操作"},
        {UiState::Success,"执行成功"}
    };

    //初始化UI
    MainWindowState uiState;
    uiState.m_commState = UiState::Disconnected;
    SlotUpdateMainWindowState(uiState);

    m_videoCap = new VideoThread(this);
    m_videoCap->start();
    connect(m_videoCap, SIGNAL(&QThread::finished), this, SLOT(&QObject::deleteLater));



    connect(m_videoCap, &VideoThread::SignalUpdateImage,this,&MainWindow::SignalUpdateImage);


    m_videoWin = new VideoWindow(this);
    QObject::connect(m_videoWin, &VideoWindow::SignalExitWin, this, &MainWindow::show);


    QObject::connect(m_videoCap, &VideoThread::SignalUpdateVideoFrame, m_videoWin, &VideoWindow::SlotUpdateVideoFrame);
    QObject::connect(m_videoWin, &VideoWindow::SignalSpacePressed, m_videoCap, &VideoThread::SlotSpacePressed);

    QObject::connect(m_videoCap, &VideoThread::SignalVideoLoaded, this, &MainWindow::SlotVideoLoaded);



}

MainWindow::~MainWindow()
{
    m_videoCap->StopRun();
    m_videoCap->quit();
    m_videoCap->wait();

    delete ui;
    // 释放 QMessageBox 对象
    delete m_messageBox;
}






void MainWindow::on_historyInfo_pushButton_clicked()
{

    this->setWindowModality(Qt::ApplicationModal);
    m_hisWin->show();
}

void MainWindow::SlotUpdateMainWindowState(MainWindowState uiState)
{
    ui->selectImage_pushButton->setEnabled(uiState.m_enableButton);
    ui->historyInfo_pushButton->setEnabled(uiState.m_enableButton);
    ui->startRecognize_pushButton->setEnabled(uiState.m_enableButton);
    ui->commState_label->setText(m_UiStateStr.value(uiState.m_commState));

    if(uiState.m_clearDisplayUrl)
    {
        ui->displayUrl_lineEdit->clear();
        ui->displayUrl_lineEdit->setText(uiState.m_displayUrl);
    }
    else
    {
        ;
    }

    if(uiState.m_clearDisplayMessage)
    {
        ui->displayMessage_textEdit->clear();
        ui->displayMessage_textEdit->append(uiState.m_displayMessage);
    }
    else
    {
        ui->displayMessage_textEdit->append(uiState.m_displayMessage);
    }
}

void MainWindow::on_startRecognize_pushButton_clicked()
{
    client->SendRecogRequest();
}

void MainWindow::on_selectImage_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
            this,
            tr("select a image."),
            QCoreApplication::applicationDirPath() + "/SourceImage/",
            tr("images(*.png *jpeg *bmp *jpg);;All files(*.*)"));
        if (!fileName.isEmpty())
        {
            ui->displayUrl_lineEdit->clear();
            ui->displayUrl_lineEdit->setText(fileName);
            emit SignalUpdateSelectedFilePath(fileName);
        }

}



void MainWindow::SlotVideoLoaded()
{
        ui->VideoView->setEnabled(true);
}





void MainWindow::on_VideoView_triggered()
{
        this->hide();
        m_videoWin->show();

}


extern QReadWriteLock custom_ip_lock;
extern QString custom_ip;
void MainWindow::on_setAddress_pushButton_clicked()
{
    QString serverAddress = ui->serverAddress_lineEdit->text();

    // 使用正则表达式判断是否为正确的 IPv4 地址格式
    static QRegularExpression ipRegex(
        R"(^(?:\d{1,3}\.){3}\d{1,3}$)"
    );
    QRegularExpressionMatch match = ipRegex.match(serverAddress);
    if (match.hasMatch())
    {
        // 加写锁，防止多个线程同时修改 g_ip_list
        QWriteLocker locker(&custom_ip_lock);
        custom_ip = serverAddress;

        // 设置 QMessageBox 的文本内容
        m_messageBox->setText("写入成功");
        m_messageBox->setWindowTitle("提示");
        m_messageBox->show();
    }
    else
    {
        // 加写锁，防止多个线程同时修改 g_ip_list
        QWriteLocker locker(&custom_ip_lock);
        ui->serverAddress_lineEdit->clear();
        custom_ip.clear();

        // 设置 QMessageBox 的文本内容
        m_messageBox->setText("格式错误，请重新写入");
        m_messageBox->setWindowTitle("错误");
        m_messageBox->show();
    }
}

