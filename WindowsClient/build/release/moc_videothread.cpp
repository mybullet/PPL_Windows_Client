/****************************************************************************
** Meta object code from reading C++ file 'videothread.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Services/videothread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videothread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoThread_t {
    const uint offsetsAndSize[14];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_VideoThread_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_VideoThread_t qt_meta_stringdata_VideoThread = {
    {
QT_MOC_LITERAL(0, 11), // "VideoThread"
QT_MOC_LITERAL(12, 15), // "SignalSaveImage"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 17), // "SignalUpdateImage"
QT_MOC_LITERAL(47, 22), // "SignalUpdateVideoFrame"
QT_MOC_LITERAL(70, 17), // "SignalVideoLoaded"
QT_MOC_LITERAL(88, 16) // "SlotSpacePressed"

    },
    "VideoThread\0SignalSaveImage\0\0"
    "SignalUpdateImage\0SignalUpdateVideoFrame\0"
    "SignalVideoLoaded\0SlotSpacePressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoThread[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    1,   45,    2, 0x06,    2 /* Public */,
       4,    1,   48,    2, 0x06,    4 /* Public */,
       5,    0,   51,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   52,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void VideoThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoThread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SignalSaveImage(); break;
        case 1: _t->SignalUpdateImage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->SignalUpdateVideoFrame((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 3: _t->SignalVideoLoaded(); break;
        case 4: _t->SlotSpacePressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VideoThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoThread::SignalSaveImage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VideoThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoThread::SignalUpdateImage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VideoThread::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoThread::SignalUpdateVideoFrame)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (VideoThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoThread::SignalVideoLoaded)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject VideoThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_VideoThread.offsetsAndSize,
    qt_meta_data_VideoThread,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_VideoThread_t
, QtPrivate::TypeAndForceComplete<VideoThread, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QImage, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *VideoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int VideoThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void VideoThread::SignalSaveImage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VideoThread::SignalUpdateImage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VideoThread::SignalUpdateVideoFrame(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void VideoThread::SignalVideoLoaded()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
