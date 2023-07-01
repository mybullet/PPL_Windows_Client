/****************************************************************************
** Meta object code from reading C++ file 'TcpClient.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Services/TcpClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TcpClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpClient_t {
    const uint offsetsAndSize[28];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TcpClient_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TcpClient_t qt_meta_stringdata_TcpClient = {
    {
QT_MOC_LITERAL(0, 9), // "TcpClient"
QT_MOC_LITERAL(10, 22), // "SignalUpdateMainWindow"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 15), // "MainWindowState"
QT_MOC_LITERAL(50, 19), // "SlotReconnectToHost"
QT_MOC_LITERAL(70, 16), // "SlotDisconnected"
QT_MOC_LITERAL(87, 13), // "SlotConnected"
QT_MOC_LITERAL(101, 13), // "SlotReadyRead"
QT_MOC_LITERAL(115, 14), // "SlotAliveTimer"
QT_MOC_LITERAL(130, 26), // "SlotUpdateSelectedFilePath"
QT_MOC_LITERAL(157, 8), // "filePath"
QT_MOC_LITERAL(166, 12), // "TransferData"
QT_MOC_LITERAL(179, 12), // "SlotPullInfo"
QT_MOC_LITERAL(192, 2) // "dt"

    },
    "TcpClient\0SignalUpdateMainWindow\0\0"
    "MainWindowState\0SlotReconnectToHost\0"
    "SlotDisconnected\0SlotConnected\0"
    "SlotReadyRead\0SlotAliveTimer\0"
    "SlotUpdateSelectedFilePath\0filePath\0"
    "TransferData\0SlotPullInfo\0dt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpClient[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   71,    2, 0x0a,    3 /* Public */,
       5,    0,   72,    2, 0x0a,    4 /* Public */,
       6,    0,   73,    2, 0x0a,    5 /* Public */,
       7,    0,   74,    2, 0x0a,    6 /* Public */,
       8,    0,   75,    2, 0x0a,    7 /* Public */,
       9,    1,   76,    2, 0x0a,    8 /* Public */,
      11,    1,   79,    2, 0x0a,   10 /* Public */,
      12,    1,   82,    2, 0x0a,   12 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

void TcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SignalUpdateMainWindow((*reinterpret_cast< std::add_pointer_t<MainWindowState>>(_a[1]))); break;
        case 1: _t->SlotReconnectToHost(); break;
        case 2: _t->SlotDisconnected(); break;
        case 3: _t->SlotConnected(); break;
        case 4: _t->SlotReadyRead(); break;
        case 5: _t->SlotAliveTimer(); break;
        case 6: _t->SlotUpdateSelectedFilePath((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->TransferData((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 8: _t->SlotPullInfo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< MainWindowState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpClient::*)(MainWindowState );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::SignalUpdateMainWindow)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TcpClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TcpClient.offsetsAndSize,
    qt_meta_data_TcpClient,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TcpClient_t
, QtPrivate::TypeAndForceComplete<TcpClient, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<MainWindowState, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qint64, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *TcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void TcpClient::SignalUpdateMainWindow(MainWindowState _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
