#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Services/TcpClient.h"
#include "historywindow.h"
#include "DataTypes/mainwindowstate.h"
#include "Services/videothread.h"
#include <QMessageBox>
#include <QThread>
#include "videowindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    VideoThread* m_videoCap;
    TcpClient* client;

    void ProcessDatagram(const QByteArray &datagram);

private slots:
    void on_historyInfo_pushButton_clicked();
    void SlotUpdateMainWindowState(MainWindowState);

    void on_startRecognize_pushButton_clicked();

    void on_selectImage_pushButton_clicked();



    void SlotVideoLoaded();

    void on_VideoView_triggered();

    void on_setAddress_pushButton_clicked();

signals:
    void SignalUpdateSelectedFilePath(QString filePath);

    void SignalUpdateImage(QString);

private:
    Ui::MainWindow *ui;
    HistoryWindow* m_hisWin;
    VideoWindow* m_videoWin;
    QMap<UiState,QString> m_UiStateStr;

    QMessageBox* m_messageBox;



    //VideoWindow* m_videoWin;
};
#endif // MAINWINDOW_H
