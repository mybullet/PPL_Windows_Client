#ifndef COMMON_H
#define COMMON_H
#include <QMap>
#include <QReadWriteLock>




enum class FSM
{
    InitialState,
    RequestRecogState,
    ConfirmRecogState,
    RequestSelectState,
    ConfirmSelectState
};

enum class UiState
{
    Connected,
    Disconnected,
    Requesting,
    Confirming,
    Failed,
    Success
};




void RegisterDataType();
void ProcessDatagram(const QByteArray &datagram);

#endif // COMMON_H
