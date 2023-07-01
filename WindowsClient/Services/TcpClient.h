#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include <QObject>
#include <QTimer>
#include <QTcpSocket>
#include <qfile.h>
#include <QReadWriteLock>
#include "./Common/Common.h"
#include "DataTypes/mainwindowstate.h"

#define  MAX_REQUEST_COUNT 3
#define  MAX_CONFIRM_COUNT 2



class TcpClient : public QObject
{
    Q_OBJECT
public:
    TcpClient();
    ~TcpClient();
    void SendRecogRequest();
    void StartTransfer();


private:
    void InitialTcpClient();

public slots:
    //void GetCurrentServerState();
    void SlotReconnectToHost();
    void SlotDisconnected();
    void SlotConnected();
    void SlotReadyRead();
    void SlotAliveTimer();
    void SlotUpdateSelectedFilePath(QString filePath);
    void TransferData(qint64);
    void SlotPullInfo(QString dt);
signals:
    void SignalUpdateMainWindow(MainWindowState);

private:
    QTimer* m_connectTimer;
    QTimer* m_aliveTimer;
    QTcpSocket* m_clientSocket;
    FSM m_serviceState;
    int m_count;

    QFile *m_localFile;
    qint64 m_totalBytes;
    qint64 m_bytesWritten;
    qint64 m_bytesToWrite;
    qint64 m_payloadSize;
    QString m_fileName;
    QByteArray m_outBlock;
    
    bool m_enableTransfer;

    QString m_selectDataTime;
};

#endif // TCPCLIENT_H
