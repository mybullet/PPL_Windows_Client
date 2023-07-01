#include "mainwindowstate.h"

MainWindowState::MainWindowState(QObject *parent) : QObject(parent)
{
    m_enableButton = false;

    m_commState = UiState::Disconnected;

    m_clearDisplayUrl = false;
    m_displayUrl = "";

    m_clearDisplayMessage = false;
    m_displayMessage = "";
}

MainWindowState::MainWindowState(const MainWindowState &obj)
{
    m_enableButton = obj.m_enableButton;

    m_commState = obj.m_commState;

    m_clearDisplayUrl = obj.m_clearDisplayUrl;
    m_displayUrl = obj.m_displayUrl;

    m_clearDisplayMessage = obj.m_clearDisplayMessage;
    m_displayMessage = obj.m_displayMessage;
}


