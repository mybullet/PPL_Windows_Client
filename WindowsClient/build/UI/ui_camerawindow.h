/********************************************************************************
** Form generated from reading UI file 'camerawindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAWINDOW_H
#define UI_CAMERAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *videoLabel;
    QLabel *imageLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *openButton;
    QPushButton *takeButton;
    QPushButton *closeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CameraWindow)
    {
        if (CameraWindow->objectName().isEmpty())
            CameraWindow->setObjectName(QString::fromUtf8("CameraWindow"));
        CameraWindow->resize(800, 600);
        CameraWindow->setMinimumSize(QSize(800, 600));
        centralwidget = new QWidget(CameraWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        videoLabel = new QLabel(centralwidget);
        videoLabel->setObjectName(QString::fromUtf8("videoLabel"));
        videoLabel->setMinimumSize(QSize(0, 530));

        horizontalLayout_2->addWidget(videoLabel);

        imageLabel = new QLabel(centralwidget);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setMinimumSize(QSize(0, 530));

        horizontalLayout_2->addWidget(imageLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setMinimumSize(QSize(0, 50));

        horizontalLayout->addWidget(openButton);

        takeButton = new QPushButton(centralwidget);
        takeButton->setObjectName(QString::fromUtf8("takeButton"));
        takeButton->setMinimumSize(QSize(0, 50));

        horizontalLayout->addWidget(takeButton);

        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMinimumSize(QSize(0, 50));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        CameraWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CameraWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        CameraWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CameraWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CameraWindow->setStatusBar(statusbar);

        retranslateUi(CameraWindow);

        QMetaObject::connectSlotsByName(CameraWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CameraWindow)
    {
        CameraWindow->setWindowTitle(QCoreApplication::translate("CameraWindow", "MainWindow", nullptr));
        videoLabel->setText(QCoreApplication::translate("CameraWindow", "TextLabel", nullptr));
        imageLabel->setText(QCoreApplication::translate("CameraWindow", "TextLabel", nullptr));
        openButton->setText(QCoreApplication::translate("CameraWindow", "open", nullptr));
        takeButton->setText(QCoreApplication::translate("CameraWindow", "take", nullptr));
        closeButton->setText(QCoreApplication::translate("CameraWindow", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CameraWindow: public Ui_CameraWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAWINDOW_H
