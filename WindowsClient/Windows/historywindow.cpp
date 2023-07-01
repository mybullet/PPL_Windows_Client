#include "historywindow.h"
#include "ui_historywindow.h"
#include <QDebug>
#include <QMessageBox>

HistoryWindow::HistoryWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistoryWindow),
    m_selectedData("")
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window); //脱离父窗口,成为独立的窗口
    setWindowModality(Qt::ApplicationModal); //子窗口显示时，父窗口不可操作

    QStringList timeList;
    for(int i = 0; i < 24;i++)
    {
        timeList.append(QString::number(i,10));

    }
    ui->hour_comboBox->addItems(timeList);

    timeList.clear();
    for(int i = 0; i < 60;i++)
    {
        timeList.append(QString::number(i,10));

    }
    ui->minute_comboBox->addItems(timeList);

    timeList.clear();
    for(int i = 0; i < 60;i++)
    {
        timeList.append(QString::number(i,10));

    }
    ui->second_comboBox->addItems(timeList);

    connect(ui->calendarWidget,SIGNAL(selectionChanged()),this,SLOT(SlotChangeData()));

}

HistoryWindow::~HistoryWindow()
{
    delete ui;
}

void HistoryWindow::on_pullInfo_pushButton_clicked()
{
    if(m_selectedData.isEmpty())
    {
        QMessageBox bb(QMessageBox::Warning, "提示", "请选择一个日期",QMessageBox::Yes);
        bb.exec();
        return;
    }

    QString strTime = QString("%1:%2:%3")
        .arg(ui->hour_comboBox->currentText().toUInt(), 2, 10, QLatin1Char('0'))
        .arg(ui->minute_comboBox->currentText().toUInt(), 2, 10, QLatin1Char('0'))
        .arg(ui->second_comboBox->currentText().toUInt(), 2, 10, QLatin1Char('0'));

    QString dtStr = m_selectedData + " " + strTime;



    qDebug() << dtStr;
    emit SignalPullInfo(dtStr);
    this->hide();
}

void HistoryWindow::SlotChangeData()
{
    m_selectedData = ui->calendarWidget->selectedDate().toString("yyyy/M/d");
    qDebug() << m_selectedData;
}
