/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *VideoView;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *displayUrl_lineEdit;
    QPushButton *selectImage_pushButton;
    QTextEdit *displayMessage_textEdit;
    QHBoxLayout *horizontalLayout;
    QLineEdit *serverAddress_lineEdit;
    QPushButton *setAddress_pushButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *commState_label;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *historyInfo_pushButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *startRecognize_pushButton;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(960, 720);
        MainWindow->setMinimumSize(QSize(960, 720));
        MainWindow->setMaximumSize(QSize(960, 720));
        QFont font;
        font.setFamilies({QString::fromUtf8("Agency FB")});
        font.setPointSize(20);
        font.setBold(true);
        MainWindow->setFont(font);
        VideoView = new QAction(MainWindow);
        VideoView->setObjectName(QString::fromUtf8("VideoView"));
        VideoView->setEnabled(false);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Agency FB")});
        font1.setPointSize(11);
        font1.setBold(true);
        VideoView->setFont(font1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        displayUrl_lineEdit = new QLineEdit(centralwidget);
        displayUrl_lineEdit->setObjectName(QString::fromUtf8("displayUrl_lineEdit"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Agency FB")});
        font2.setPointSize(16);
        font2.setBold(true);
        displayUrl_lineEdit->setFont(font2);
        displayUrl_lineEdit->setCursor(QCursor(Qt::IBeamCursor));

        gridLayout->addWidget(displayUrl_lineEdit, 0, 0, 1, 1);

        selectImage_pushButton = new QPushButton(centralwidget);
        selectImage_pushButton->setObjectName(QString::fromUtf8("selectImage_pushButton"));
        selectImage_pushButton->setMinimumSize(QSize(0, 30));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font3.setPointSize(16);
        font3.setBold(true);
        selectImage_pushButton->setFont(font3);
        selectImage_pushButton->setCursor(QCursor(Qt::OpenHandCursor));

        gridLayout->addWidget(selectImage_pushButton, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        displayMessage_textEdit = new QTextEdit(centralwidget);
        displayMessage_textEdit->setObjectName(QString::fromUtf8("displayMessage_textEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(displayMessage_textEdit->sizePolicy().hasHeightForWidth());
        displayMessage_textEdit->setSizePolicy(sizePolicy);
        displayMessage_textEdit->setFont(font2);
        displayMessage_textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));

        verticalLayout->addWidget(displayMessage_textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        serverAddress_lineEdit = new QLineEdit(centralwidget);
        serverAddress_lineEdit->setObjectName(QString::fromUtf8("serverAddress_lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(serverAddress_lineEdit->sizePolicy().hasHeightForWidth());
        serverAddress_lineEdit->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Agency FB")});
        font4.setPointSize(20);
        font4.setBold(false);
        font4.setKerning(true);
        serverAddress_lineEdit->setFont(font4);
        serverAddress_lineEdit->setMaxLength(15);
        serverAddress_lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(serverAddress_lineEdit);

        setAddress_pushButton = new QPushButton(centralwidget);
        setAddress_pushButton->setObjectName(QString::fromUtf8("setAddress_pushButton"));
        setAddress_pushButton->setFont(font3);
        setAddress_pushButton->setCursor(QCursor(Qt::OpenHandCursor));

        horizontalLayout->addWidget(setAddress_pushButton);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        commState_label = new QLabel(centralwidget);
        commState_label->setObjectName(QString::fromUtf8("commState_label"));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font5.setPointSize(16);
        font5.setBold(false);
        font5.setUnderline(true);
        commState_label->setFont(font5);

        horizontalLayout->addWidget(commState_label);

        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        historyInfo_pushButton = new QPushButton(centralwidget);
        historyInfo_pushButton->setObjectName(QString::fromUtf8("historyInfo_pushButton"));
        historyInfo_pushButton->setFont(font3);
        historyInfo_pushButton->setCursor(QCursor(Qt::OpenHandCursor));

        horizontalLayout->addWidget(historyInfo_pushButton);

        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        startRecognize_pushButton = new QPushButton(centralwidget);
        startRecognize_pushButton->setObjectName(QString::fromUtf8("startRecognize_pushButton"));
        startRecognize_pushButton->setMinimumSize(QSize(0, 30));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font6.setPointSize(16);
        font6.setBold(true);
        font6.setStrikeOut(false);
        startRecognize_pushButton->setFont(font6);
        startRecognize_pushButton->setCursor(QCursor(Qt::OpenHandCursor));

        horizontalLayout->addWidget(startRecognize_pushButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(VideoView);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\274\240\345\233\276\350\257\206\345\255\227", nullptr));
        VideoView->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", nullptr));
#if QT_CONFIG(tooltip)
        VideoView->setToolTip(QCoreApplication::translate("MainWindow", "switch to vide view", nullptr));
#endif // QT_CONFIG(tooltip)
        selectImage_pushButton->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\345\233\276\347\211\207", nullptr));
        displayMessage_textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Agency FB'; font-size:16pt; font-weight:700; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p></body></html>", nullptr));
        setAddress_pushButton->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        commState_label->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201", nullptr));
        historyInfo_pushButton->setText(QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262\344\277\241\346\201\257", nullptr));
        startRecognize_pushButton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\257\206\345\210\253", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
