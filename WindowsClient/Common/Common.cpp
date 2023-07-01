#include "Common.h"
#include "DataTypes/mainwindowstate.h"

#include <QHostAddress>
#include <QReadWriteLock>
#include <QRegularExpression>

void RegisterDataType()
{
    qRegisterMetaType<MainWindowState>("MainWindowState");
    qRegisterMetaType<MainWindowState>("MainWindowState&");

}

extern QReadWriteLock g_ip_lock;
extern QStringList g_ip_list;

void ProcessDatagram(const QByteArray &datagram)
{
    QString message = QString::fromUtf8(datagram);
    QStringList parts = message.split("-");

    // 构造 IPv4 正则表达式模式
    static QRegularExpression ipv4Pattern(
        R"(^(?:\d{1,3}\.){3}\d{1,3}$)"
        );

    // 遍历 QStringList，剔除非 IPv4 格式的字符串
    QStringList filteredList;
    for (const QString& str : parts) {
        if (ipv4Pattern.match(str).hasMatch()) {
            filteredList.append(str);
        }
    }

    if (!g_ip_lock.tryLockForWrite()) 
    {
        qDebug() << "Could not obtain write lock, skipping code block";
    } 
    else 
    {
        if(g_ip_list.empty())
        {
            foreach (const QString &ip, filteredList)
            {
                QHostAddress address(ip);
                if (address.protocol() == QAbstractSocket::IPv4Protocol && address.toString() == ip)
                {
                    g_ip_list.append(ip);
                }
            }
            qDebug() << "IP List is updated!";
        }
        g_ip_lock.unlock();
    }

    qDebug() << filteredList;
}

