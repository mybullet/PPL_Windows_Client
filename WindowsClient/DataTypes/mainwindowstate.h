#ifndef MAINWINDOWSTATE_H
#define MAINWINDOWSTATE_H

#include <QObject>
#include <QMetaType>
#include "Common/Common.h"

class MainWindowState : public QObject
{
    Q_OBJECT
public:
    explicit MainWindowState(QObject *parent = nullptr);
    MainWindowState(const MainWindowState& obj);
signals:

public:
    bool m_enableButton;

    UiState m_commState;

    bool m_clearDisplayUrl;
    QString m_displayUrl;

    bool m_clearDisplayMessage;
    QString m_displayMessage;

};
Q_DECLARE_METATYPE(MainWindowState);
#endif // MAINWINDOWSTATE_H
