
#ifndef IMAGESAVER_H
#define IMAGESAVER_H


#include <QObject>
#include <QImage>


class ImageSaver : public QObject
{
    Q_OBJECT

public:
    ImageSaver(QImage image, QString fileName = "pic_buffer.jpg") :  m_image(image) {m_filePath = m_folderPath + fileName;}

public slots:
    void SlotSaveImage();

signals:
    void finished();
    void SignalUpdateImage(QString);
private:
    const QString m_folderPath = "./release/SourceImage/";

    QString m_filePath;
    QImage m_image;
};
#endif // IMAGESAVER_H
