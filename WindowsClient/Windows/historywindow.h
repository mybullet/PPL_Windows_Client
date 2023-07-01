#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QWidget>

namespace Ui {
class HistoryWindow;
}

class HistoryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryWindow(QWidget *parent = nullptr);
    ~HistoryWindow();

private slots:
    void on_pullInfo_pushButton_clicked();
    void SlotChangeData();

signals:
    void SignalPullInfo(QString dataTime);
private:
    Ui::HistoryWindow *ui;

    QString m_selectedData;
};

#endif // HISTORYWINDOW_H
