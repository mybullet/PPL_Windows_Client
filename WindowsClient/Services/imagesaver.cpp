
#include "imagesaver.h"
#include <QThread>
#include <QDir>

void ImageSaver::SlotSaveImage()
{

    QDir folder(m_folderPath);
    if (!folder.exists())
    {
        folder.mkpath(".");
    }

    // Check if file already exists and remove it
    if (QFile::exists(m_filePath))
    {
        QFile::remove(m_filePath);
    }


    if (m_image.scaledToWidth(640).scaledToHeight(480).save(m_filePath, "JPG", 100))
    {
        qDebug() << "Image saved successfully!";
        emit SignalUpdateImage(m_filePath);
    } else
    {
        qDebug() << "Failed to save image!";

    }

    emit finished();
}
