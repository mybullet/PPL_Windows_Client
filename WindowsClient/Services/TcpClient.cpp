#include "TcpClient.h"
#include <iostream>
#include <QDebug>
#include <QDataStream>
#include <QMessageBox>
#include <QTextCodec>
#include <thread>
//#pragma execution_character_set("utf-8")

TcpClient::TcpClient():m_connectTimer(new QTimer(this)),
    m_aliveTimer(new QTimer(this)),
    m_clientSocket(new QTcpSocket(this)),
    m_serviceState(FSM::InitialState),
    m_count(0),
    m_fileName("")
{
    m_payloadSize=64*1024;
    m_totalBytes=0;
    m_bytesWritten=0;
    m_bytesToWrite=0;
        
    m_enableTransfer = true;

    m_aliveTimer->setInterval(1000);
    m_connectTimer->setInterval(3000);
    connect(this->m_connectTimer,&QTimer::timeout,this,&TcpClient::SlotReconnectToHost);
    connect(this->m_clientSocket,&QTcpSocket::connected,this,&TcpClient::SlotConnected);
    connect(this->m_clientSocket,&QTcpSocket::disconnected,this,&TcpClient::SlotDisconnected);
    connect(this->m_clientSocket,&QTcpSocket::readyRead,this,&TcpClient::SlotReadyRead);
    connect(this->m_aliveTimer,&QTimer::timeout,this,&TcpClient::SlotAliveTimer);
    connect(this->m_clientSocket,SIGNAL(bytesWritten(qint64)),this,SLOT(TransferData(qint64)));

    //m_clientSocket->connectToHost("192.168.3.5", 65432);
    m_connectTimer->start();
}

TcpClient::~TcpClient()
{
    delete this->m_aliveTimer;
    delete this->m_connectTimer;
    delete this->m_clientSocket;
}

void TcpClient::SlotPullInfo(QString dt)
{
    m_selectDataTime = dt;
    qDebug() << "SlotPullInfo  : " <<dt;

    if(m_selectDataTime.isEmpty())
    {
        QMessageBox bb(QMessageBox::Warning, "提示", "请选择检索时间",QMessageBox::Yes);
        bb.exec();
        return;
    }

    if(m_serviceState == FSM::InitialState)
    {
        m_count = 0;
        m_serviceState = FSM::RequestSelectState;
        if(m_clientSocket->state() == QAbstractSocket::ConnectedState)
        {
            if(!m_aliveTimer->isActive())
            {
                m_aliveTimer->start();
                //发射信号{UiState::Requesting,"正在请求服务"},
                MainWindowState uiState;
                uiState.m_commState = UiState::Requesting;
                uiState.m_enableButton = false;
                emit SignalUpdateMainWindow(uiState);
            }
        }
    }
}

void TcpClient::SendRecogRequest()
{
    if(m_fileName.isEmpty())
    {
        QMessageBox bb(QMessageBox::Warning, "提示", "请选择一张图片",QMessageBox::Yes);
        bb.exec();
        return;
    }
    if(m_serviceState == FSM::InitialState)
    {
        m_count = 0;
        m_serviceState = FSM::RequestRecogState;
        if(m_clientSocket->state() == QAbstractSocket::ConnectedState)
        {
            if(!m_aliveTimer->isActive())
            {
                m_aliveTimer->start();
                //发射信号{UiState::Requesting,"正在请求服务"},
                MainWindowState uiState;
                uiState.m_commState = UiState::Requesting;
                uiState.m_enableButton = false;
                emit SignalUpdateMainWindow(uiState);
            }
        }
    }

}

void TcpClient::StartTransfer()
{
    if(m_enableTransfer)
    {
        m_enableTransfer = false;

        m_localFile=new QFile(m_fileName);
        if(!m_localFile->open(QFile::ReadOnly))
        {
            qDebug()<<"client：open file error!";
            return;
        }
        m_totalBytes=m_localFile->size();

        QString currentFileName=m_fileName.right(m_fileName.size()-m_fileName.lastIndexOf('/')-1);

        QString firstSendData = "RequestRecog" + QString::number(m_totalBytes, 10) + "_" + currentFileName;

        qDebug()<<"firstSendData ： "<<firstSendData;

        QByteArray bArray;
        bArray.append(firstSendData.toStdString().c_str());
        //m_bytesToWrite=m_totalBytes-m_clientSocket->write(bArray);
        m_bytesToWrite = m_totalBytes;
        m_clientSocket->write(bArray);
        m_bytesWritten-=bArray.size();
        //m_clientSocket->flush();
    }

}

//只要send，就会进这个函数
void TcpClient::TransferData(qint64 numBytes)
{
    if(m_serviceState == FSM::RequestRecogState)
    {
        qDebug() << "TransferData : " << numBytes;
        if(m_totalBytes > 0)
        {
            m_bytesWritten+=(int)numBytes;
        }

        if(m_bytesToWrite>0)
        {

            m_outBlock=m_localFile->read(qMin(m_bytesToWrite,m_payloadSize));
            m_bytesToWrite-=(int)m_clientSocket->write(m_outBlock);

            m_outBlock.resize(0);
        }
        else
        {
            m_localFile->close();
        }


        if(m_bytesWritten==m_totalBytes)
        {

            m_localFile->close();
            m_enableTransfer = true;
            m_totalBytes = 0;
            m_bytesToWrite = 0;
            m_bytesWritten = 0;
            m_outBlock.resize(0);
        }

        qDebug() << "m_enableTransfer: "<<m_enableTransfer;
        qDebug() << "m_totalBytes: "<<m_totalBytes;
        qDebug() << "m_bytesToWrite: "<<m_bytesToWrite;
        qDebug() << "m_bytesWritten: "<<m_bytesWritten;
    }

}



void TcpClient::InitialTcpClient()
{
    m_count = 0;
    m_serviceState = FSM::InitialState;
    //m_connectTimer->stop();
    //m_aliveTimer->stop();
}

extern QReadWriteLock g_ip_lock;
extern QStringList g_ip_list;

extern QReadWriteLock custom_ip_lock;
extern QString custom_ip;

void TcpClient::SlotReconnectToHost()
{
    if (m_clientSocket->state() == QAbstractSocket::ConnectedState)
    {
        m_connectTimer->stop();
    }
    else
    {
        qDebug() << "trying";

        {
            QWriteLocker locker(&g_ip_lock);
            // 遍历 ip_list 中的 IP 地址尝试建立连接
            if (!g_ip_list.empty())
            {
                QString ip = g_ip_list.takeFirst();
                qDebug() << "trying to connect " << ip;

                m_clientSocket->connectToHost(ip, 65432, QAbstractSocket::ReadWrite, QAbstractSocket::IPv4Protocol);

                // 检查连接是否成功
                if (m_clientSocket->waitForConnected(400))
                {
                    qDebug() << "连接成功";
                    g_ip_list.clear();
                }
                else
                {
                    qDebug() << "连接失败: " << m_clientSocket->errorString();
                }

            }
        }

        {
            QReadLocker locker(&custom_ip_lock);
            if (!custom_ip.isNull())
            {
                qDebug() << "trying to connect " << custom_ip;

                m_clientSocket->connectToHost(custom_ip, 65432, QAbstractSocket::ReadWrite, QAbstractSocket::IPv4Protocol);

                // 检查连接是否成功
                if (m_clientSocket->waitForConnected(500))
                {
                    qDebug() << "连接成功";
                }
                else
                {
                    qDebug() << "连接失败: " << m_clientSocket->errorString();
                }

            }
        }


    }
}


void TcpClient::SlotDisconnected()
{
    m_connectTimer->start();
    m_aliveTimer->stop();
    InitialTcpClient();
    MainWindowState uiState;
    uiState.m_commState = UiState::Disconnected;
    uiState.m_enableButton = false;
    emit SignalUpdateMainWindow(uiState);

    qDebug() << "void TcpClient::SlotDisconnected()";
}

void TcpClient::SlotConnected()
{
    m_connectTimer->stop();
    m_aliveTimer->stop();
    InitialTcpClient();
    MainWindowState uiState;
    uiState.m_commState = UiState::Connected;
    uiState.m_enableButton = true;
    emit SignalUpdateMainWindow(uiState);
}


//
void TcpClient::SlotReadyRead()
{
    QString receiveServerData = QString::fromStdString(m_clientSocket->readAll().toStdString());
    qDebug() << receiveServerData;

    if(m_serviceState == FSM::RequestRecogState)
    {
        if(receiveServerData.contains("ConfirmRecog"))
        {
            m_count = 0;
            m_serviceState = FSM::ConfirmRecogState;
            //发射信号{UiState::Confirming,"等待服务完成"},
            MainWindowState uiState;
            uiState.m_commState = UiState::Confirming;
            uiState.m_enableButton = false;
            emit SignalUpdateMainWindow(uiState);
        }
    }
    else if(m_serviceState == FSM::ConfirmRecogState)
    {
        if(receiveServerData.contains("WaitRecog"))
        {
            m_count = 0;
            MainWindowState uiState;
            uiState.m_commState = UiState::Confirming;
            uiState.m_enableButton = false;
            uiState.m_clearDisplayMessage = true;
            uiState.m_displayMessage = "please wait a moment...";
            emit SignalUpdateMainWindow(uiState);
        }
        else //if(receiveServerData.contains("ReturnRecog"))
        {
            m_serviceState = FSM::InitialState;
            m_aliveTimer->stop();
            MainWindowState uiState;
            uiState.m_commState = UiState::Success;
            uiState.m_enableButton = true;
            uiState.m_clearDisplayMessage = true;
            uiState.m_displayMessage = receiveServerData;
            emit SignalUpdateMainWindow(uiState);
        }
    }
    else if(m_serviceState == FSM::RequestSelectState)
    {
        if(receiveServerData.contains("ConfirmSelect"))
        {
            m_count = 0;
            m_serviceState = FSM::ConfirmSelectState;
            //发射信号{UiState::Confirming,"等待服务完成"},
            MainWindowState uiState;
            uiState.m_commState = UiState::Confirming;
            uiState.m_enableButton = false;
            uiState.m_clearDisplayMessage = true;
            uiState.m_displayMessage = "please wait a moment...";
            emit SignalUpdateMainWindow(uiState);
        }
    }
    else if(m_serviceState == FSM::ConfirmSelectState)
    {
        if(receiveServerData.contains("ConfirmSelect"))
        {
            m_count = 0;
            MainWindowState uiState;
            uiState.m_commState = UiState::Confirming;
            uiState.m_enableButton = false;
            uiState.m_clearDisplayMessage = true;
            uiState.m_displayMessage = "please wait a moment...";
            emit SignalUpdateMainWindow(uiState);
        }
        else //if(receiveServerData.contains("ReturnSelect"))
        {
            m_serviceState = FSM::InitialState;
            m_aliveTimer->stop();
            MainWindowState uiState;
            uiState.m_commState = UiState::Success;
            uiState.m_enableButton = true;
            uiState.m_clearDisplayMessage = true;
            uiState.m_displayMessage = receiveServerData;
            emit SignalUpdateMainWindow(uiState);
        }
    }

}

void TcpClient::SlotAliveTimer()
{
    if(m_serviceState == FSM::RequestRecogState || m_serviceState == FSM::RequestSelectState)
    {
        if(m_count > MAX_REQUEST_COUNT)
        {
            m_serviceState = FSM::InitialState;

        }
    }
    else if(m_serviceState == FSM::ConfirmRecogState || m_serviceState == FSM::ConfirmSelectState)
    {
        if(m_count > MAX_CONFIRM_COUNT)
        {
            m_serviceState = FSM::InitialState;

        }
    }


    switch (m_serviceState)
    {


        case FSM::RequestRecogState:
        {
//            m_clientSocket->write(tr("RequestRecog").toUtf8());
//            m_clientSocket->flush();
        qDebug() << "111111111 : " << m_enableTransfer;
            StartTransfer();
            m_count++;
            break;
        }


        case FSM::ConfirmRecogState:
        {
            m_clientSocket->write(tr("GetRecog").toUtf8());
            m_clientSocket->flush();
            m_count++;
            break;
        }


        case FSM::RequestSelectState:
        {
            QString selectCmd = "RequestSelect_" + m_selectDataTime;
            qDebug() << "555555555555555555 : " << selectCmd;

            m_clientSocket->write(selectCmd.toUtf8());
            m_clientSocket->flush();

            m_count++;
            break;
        }


        case FSM::ConfirmSelectState:
        {
            m_clientSocket->write(tr("GetSelect").toUtf8());
            m_clientSocket->flush();
            m_count++;
            break;
        }


        case FSM::InitialState:
        {
            //发射信号，请重新操作
            qDebug() << "请重新操作!!!";
            m_enableTransfer = true; //超时复位
            MainWindowState uiState;
            uiState.m_commState = UiState::Failed;
            uiState.m_enableButton = true;
            emit SignalUpdateMainWindow(uiState);
            m_aliveTimer->stop();
            break;
        }



        default:
        {
            m_serviceState = FSM::InitialState;
            qDebug() << "go into default!!!";
            m_aliveTimer->stop();
            break;
        }

    }
}

void TcpClient::SlotUpdateSelectedFilePath(QString filePath)
{
    m_fileName = filePath;
    qDebug() << "SlotUpdateSelectedFilePath : " << m_fileName;

}














