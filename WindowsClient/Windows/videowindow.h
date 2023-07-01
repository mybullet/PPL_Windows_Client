#ifndef VIDEOWINDOW_H
#define VIDEOWINDOW_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class VideoWindow;
}

class VideoWindow : public QWidget
{
    Q_OBJECT

public:
    explicit VideoWindow(QWidget *parent = nullptr);
    ~VideoWindow();

    //重写关闭事件
    void closeEvent(QCloseEvent *);

    // Override the keyPressEvent to emit spacePressed signal when space key is pressed
    void keyPressEvent(QKeyEvent *event);

public slots:
    void SlotUpdateVideoFrame(QImage);


signals:
    void SignalExitWin();
    void SignalSpacePressed();

private:
    Ui::VideoWindow *ui;
};

#endif // VIDEOWINDOW_H
