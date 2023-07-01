
#ifndef VIDEOTHREAD_H
#define VIDEOTHREAD_H

#include <QThread>
#include<QDebug>
#include<QImage>
#include <QObject>
#include <QReadWriteLock>

class VideoThread : public QThread
{
    Q_OBJECT
public:
    explicit VideoThread(QObject *parent = nullptr);
    virtual ~VideoThread();
    void StopRun();
protected:
    void run() override;

public slots:
    void SlotSpacePressed();

signals:
    void SignalSaveImage();
    void SignalUpdateImage(QString);

    void SignalUpdateVideoFrame(QImage);

    void SignalVideoLoaded();

private:
    bool m_bRunning;
    bool m_bSpaceFlag = false;
    QReadWriteLock m_spaceFlagLock;
    QImage qimg;

};

#endif // VIDEOTHREAD_H
