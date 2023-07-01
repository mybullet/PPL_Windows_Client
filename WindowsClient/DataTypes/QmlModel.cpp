#include "QmlModel.h"

QmlModel* QmlModel::instance = nullptr;

QmlModel::QmlModel(QObject *parent) : QObject(parent)
{

    qDebug() << "QmlModel is constructed!!!";

    m_bShowQmlWin = false;
    m_qmlImage = "110";

    if(instance == nullptr)
    {
        qDebug() << "instance == nullptr!!!";
    }

    instance = this;

    if(instance != nullptr)
    {
        qDebug() << "instance != nullptr!!!";
    }

    //connect(this,&QmlModel::bSaveImageFromQmlChanged,this,&QmlModel::SlotSaveImage);
}

QmlModel *QmlModel::GetSingleton()
{
    qDebug() << "GetSingleton!!!";
    static QmlModel * obj = new QmlModel();
    return obj;
}



bool QmlModel::bShowQmlWin() const
{
    qDebug() << "call bShowQmlWin;";
    return m_bShowQmlWin;
}

void QmlModel::setBShowQmlWin(bool newBShowQmlWin)
{
    qDebug() << "call setBShowQmlWin;";
    if (m_bShowQmlWin == newBShowQmlWin)
        return;
    m_bShowQmlWin = newBShowQmlWin;

    qDebug() << "before emit setBShowQmlWin();";
    emit bShowQmlWinChanged();
    qDebug() << "after emit setBShowQmlWin();";
}

void QmlModel::SlotUpdateImage(QString imagePath)
{
    if(bShowQmlWin())
    {
        setBShowQmlWin(false);
        m_qmlImage = "qrc:/Image/full_black.jpg";
        setBShowQmlWin(true);

        setBShowQmlWin(false);
        setQmlImage(imagePath);
        //m_qmlImage = "qrc:/Image/full_black.jpg";
        setBShowQmlWin(true);
    }
    else
    {
        setQmlImage(imagePath);
        setBShowQmlWin(true);
    }


    qDebug() << "!!!!!!!!imgName!!!!!!!!!!!!!!!!!!!" + qmlImage();
}

void QmlModel::slotSaveImage()
{
    qDebug() << "!!!!!!!slotSaveImage!!!!!!!!!slotSaveImage!!!!!slotSaveImage!!";
    QString sourcePath = "./release/SourceImage/pic_buffer.jpg";
    QString destinationPath = "./release/SourceImage/pic_";

    // Check if the source image file exists
    if (QFile::exists(sourcePath)) {
        // Get the current date and time
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString dateTimeString = currentDateTime.toString("yyyyMMddhhmmss");

        // Append the date and time to the destination path
        destinationPath.append(dateTimeString).append(".jpg");

        // Copy the source image file to the destination path
        QFile::copy(sourcePath, destinationPath);
        qDebug() << destinationPath << "   exist";
    }
    else
    {
        qDebug() << destinationPath << "1111335456";
    }
}

bool QmlModel::bSaveImageFromQml() const
{
    return m_bSaveImageFromQml;
}

void QmlModel::setBSaveImageFromQml(bool newBSaveImageFromQml)
{
    if (m_bSaveImageFromQml == newBSaveImageFromQml)
        return;
    m_bSaveImageFromQml = newBSaveImageFromQml;
    emit bSaveImageFromQmlChanged();
}



QString QmlModel::qmlImage() const
{
    return m_qmlImage;
}

// Replace the leading "." with "/build"
QString QmlModel::ModifyFilePath(QString filePath)
{
    if (filePath.startsWith("."))
    {
        filePath.replace(0, 1, "/build");
    }
    return filePath;
}

QString QmlModel::GetAbsFilePath(QString filePath)
{
    QFileInfo fileInfo(filePath);
    if (fileInfo.isAbsolute())
    {
        return filePath;
    } else
    {
        QDir dir(".");
        QString absPath = dir.absoluteFilePath(filePath);

        qDebug() << "GetAbsFilePath : "  << absPath;

        return absPath;
    }


}

QString QmlModel::GetQmlFilePath(QString adsPath)
{
    return "file:///" + adsPath;
}

void QmlModel::setQmlImage(QString newQmlImage)
{
    if (m_qmlImage == newQmlImage)
        return;

    //m_qmlImage = ModifyFilePath(newQmlImage);
    m_qmlImage = GetQmlFilePath(GetAbsFilePath(newQmlImage));

    qDebug() << "before emit setQmlImage();";
    emit qmlImageChanged();
    qDebug() << "after emit setQmlImage();";
}



