/********************************************************************************
** Form generated from reading UI file 'QmlWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMLWINDOW_H
#define UI_QMLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QmlWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;

    void setupUi(QMainWindow *QmlWindow)
    {
        if (QmlWindow->objectName().isEmpty())
            QmlWindow->setObjectName(QString::fromUtf8("QmlWindow"));
        QmlWindow->resize(800, 600);
        QmlWindow->setMinimumSize(QSize(800, 600));
        centralwidget = new QWidget(QmlWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        QmlWindow->setCentralWidget(centralwidget);

        retranslateUi(QmlWindow);

        QMetaObject::connectSlotsByName(QmlWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QmlWindow)
    {
        QmlWindow->setWindowTitle(QCoreApplication::translate("QmlWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QmlWindow: public Ui_QmlWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMLWINDOW_H
