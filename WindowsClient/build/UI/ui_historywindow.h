/********************************************************************************
** Form generated from reading UI file 'historywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYWINDOW_H
#define UI_HISTORYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QCalendarWidget *calendarWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *hour_comboBox;
    QComboBox *minute_comboBox;
    QComboBox *second_comboBox;
    QPushButton *pullInfo_pushButton;

    void setupUi(QWidget *HistoryWindow)
    {
        if (HistoryWindow->objectName().isEmpty())
            HistoryWindow->setObjectName(QString::fromUtf8("HistoryWindow"));
        HistoryWindow->resize(400, 300);
        gridLayout = new QGridLayout(HistoryWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        calendarWidget = new QCalendarWidget(HistoryWindow);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        verticalLayout_2->addWidget(calendarWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(HistoryWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Agency FB")});
        font.setPointSize(12);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(HistoryWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(HistoryWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        hour_comboBox = new QComboBox(HistoryWindow);
        hour_comboBox->setObjectName(QString::fromUtf8("hour_comboBox"));
        hour_comboBox->setMinimumSize(QSize(0, 36));

        horizontalLayout_2->addWidget(hour_comboBox);

        minute_comboBox = new QComboBox(HistoryWindow);
        minute_comboBox->setObjectName(QString::fromUtf8("minute_comboBox"));
        minute_comboBox->setMinimumSize(QSize(0, 36));

        horizontalLayout_2->addWidget(minute_comboBox);

        second_comboBox = new QComboBox(HistoryWindow);
        second_comboBox->setObjectName(QString::fromUtf8("second_comboBox"));
        second_comboBox->setMinimumSize(QSize(0, 36));

        horizontalLayout_2->addWidget(second_comboBox);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        pullInfo_pushButton = new QPushButton(HistoryWindow);
        pullInfo_pushButton->setObjectName(QString::fromUtf8("pullInfo_pushButton"));
        pullInfo_pushButton->setMinimumSize(QSize(0, 36));
        pullInfo_pushButton->setFont(font);

        verticalLayout_2->addWidget(pullInfo_pushButton);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(HistoryWindow);

        QMetaObject::connectSlotsByName(HistoryWindow);
    } // setupUi

    void retranslateUi(QWidget *HistoryWindow)
    {
        HistoryWindow->setWindowTitle(QCoreApplication::translate("HistoryWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("HistoryWindow", "Hour", nullptr));
        label_2->setText(QCoreApplication::translate("HistoryWindow", "Minute", nullptr));
        label_3->setText(QCoreApplication::translate("HistoryWindow", "Second", nullptr));
        pullInfo_pushButton->setText(QCoreApplication::translate("HistoryWindow", "\346\213\211\345\217\226\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoryWindow: public Ui_HistoryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYWINDOW_H
