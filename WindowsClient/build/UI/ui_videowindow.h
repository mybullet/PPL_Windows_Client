/********************************************************************************
** Form generated from reading UI file 'videowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWINDOW_H
#define UI_VIDEOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *video_label;

    void setupUi(QWidget *VideoWindow)
    {
        if (VideoWindow->objectName().isEmpty())
            VideoWindow->setObjectName(QString::fromUtf8("VideoWindow"));
        VideoWindow->resize(640, 480);
        VideoWindow->setMinimumSize(QSize(640, 480));
        VideoWindow->setMaximumSize(QSize(640, 480));
        gridLayout = new QGridLayout(VideoWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        video_label = new QLabel(VideoWindow);
        video_label->setObjectName(QString::fromUtf8("video_label"));

        gridLayout->addWidget(video_label, 0, 0, 1, 1);


        retranslateUi(VideoWindow);

        QMetaObject::connectSlotsByName(VideoWindow);
    } // setupUi

    void retranslateUi(QWidget *VideoWindow)
    {
        VideoWindow->setWindowTitle(QCoreApplication::translate("VideoWindow", "Form", nullptr));
        video_label->setText(QCoreApplication::translate("VideoWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoWindow: public Ui_VideoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWINDOW_H
