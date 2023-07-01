#ifndef QMLMODEL_H
#define QMLMODEL_H

#include <QObject>
#include <QtQml>
#include <QString>
#include <QImage>

class QmlModel : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit QmlModel(QObject *parent = nullptr);

    static QmlModel* GetSingleton();

    bool bShowQmlWin() const;
    void setBShowQmlWin(bool newBShowQmlWin);

    QString qmlImage() const;
    void setQmlImage(QString newQmlImage);

    friend QmlModel* GetQmlModel();

    Q_INVOKABLE void slotSaveImage();

    QString ModifyFilePath(QString filePath);
    QString GetAbsFilePath(QString filePath);
    QString GetQmlFilePath(QString adsPath);


    bool bSaveImageFromQml() const;
    void setBSaveImageFromQml(bool newBSaveImageFromQml);

signals:
    void bShowQmlWinChanged();
    void qmlImageChanged();

    void bShowQmlWinShadowChanged();

    void bSaveImageFromQmlChanged();

public slots:
    void SlotUpdateImage(QString);

private:

    bool m_bShowQmlWin;
    bool m_bSaveImageFromQml;
    QString m_qmlImage;

    Q_PROPERTY(bool bShowQmlWin READ bShowQmlWin WRITE setBShowQmlWin NOTIFY bShowQmlWinChanged)
    Q_PROPERTY(QString qmlImage READ qmlImage WRITE setQmlImage NOTIFY qmlImageChanged)

    static QmlModel* instance;

    Q_PROPERTY(bool bSaveImageFromQml READ bSaveImageFromQml WRITE setBSaveImageFromQml NOTIFY bSaveImageFromQmlChanged)
};

#endif // QMLMODEL_H
