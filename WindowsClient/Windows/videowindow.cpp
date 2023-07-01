#include "videowindow.h"
#include "ui_videowindow.h"

VideoWindow::VideoWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window); //脱离父窗口,成为独立的窗口
    //setWindowModality(Qt::ApplicationModal); //子窗口显示时，父窗口不可操作
    setWindowTitle("摄像头");

}

VideoWindow::~VideoWindow()
{
    delete ui;
}

void VideoWindow::closeEvent(QCloseEvent *)
{
    emit SignalExitWin();
}

void VideoWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        emit SignalSpacePressed();
    }
    else
    {
        VideoWindow::keyPressEvent(event);
    }
}

void VideoWindow::SlotUpdateVideoFrame(QImage qimg)
{
    QPixmap pixmap = QPixmap::fromImage(qimg);
    ui->video_label->setPixmap(pixmap);
}
