/****************************************************************************
** Meta object code from reading C++ file 'QmlModel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DataTypes/QmlModel.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QmlModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QmlModel_t {
    const uint offsetsAndSize[26];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_QmlModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_QmlModel_t qt_meta_stringdata_QmlModel = {
    {
QT_MOC_LITERAL(0, 8), // "QmlModel"
QT_MOC_LITERAL(9, 11), // "QML.Element"
QT_MOC_LITERAL(21, 4), // "auto"
QT_MOC_LITERAL(26, 18), // "bShowQmlWinChanged"
QT_MOC_LITERAL(45, 0), // ""
QT_MOC_LITERAL(46, 15), // "qmlImageChanged"
QT_MOC_LITERAL(62, 24), // "bShowQmlWinShadowChanged"
QT_MOC_LITERAL(87, 24), // "bSaveImageFromQmlChanged"
QT_MOC_LITERAL(112, 15), // "SlotUpdateImage"
QT_MOC_LITERAL(128, 13), // "slotSaveImage"
QT_MOC_LITERAL(142, 11), // "bShowQmlWin"
QT_MOC_LITERAL(154, 8), // "qmlImage"
QT_MOC_LITERAL(163, 17) // "bSaveImageFromQml"

    },
    "QmlModel\0QML.Element\0auto\0bShowQmlWinChanged\0"
    "\0qmlImageChanged\0bShowQmlWinShadowChanged\0"
    "bSaveImageFromQmlChanged\0SlotUpdateImage\0"
    "slotSaveImage\0bShowQmlWin\0qmlImage\0"
    "bSaveImageFromQml"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QmlModel[] = {

 // content:
      10,       // revision
       0,       // classname
       1,   14, // classinfo
       6,   16, // methods
       3,   60, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   52,    4, 0x06,    4 /* Public */,
       5,    0,   53,    4, 0x06,    5 /* Public */,
       6,    0,   54,    4, 0x06,    6 /* Public */,
       7,    0,   55,    4, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   56,    4, 0x0a,    8 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   59,    4, 0x02,   10 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,

 // methods: parameters
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::Bool, 0x00015103, uint(0), 0,
      11, QMetaType::QString, 0x00015103, uint(1), 0,
      12, QMetaType::Bool, 0x00015103, uint(3), 0,

       0        // eod
};

void QmlModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QmlModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->bShowQmlWinChanged(); break;
        case 1: _t->qmlImageChanged(); break;
        case 2: _t->bShowQmlWinShadowChanged(); break;
        case 3: _t->bSaveImageFromQmlChanged(); break;
        case 4: _t->SlotUpdateImage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->slotSaveImage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QmlModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QmlModel::bShowQmlWinChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QmlModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QmlModel::qmlImageChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QmlModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QmlModel::bShowQmlWinShadowChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QmlModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QmlModel::bSaveImageFromQmlChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QmlModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->bShowQmlWin(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->qmlImage(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->bSaveImageFromQml(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QmlModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBShowQmlWin(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setQmlImage(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setBSaveImageFromQml(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QmlModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QmlModel.offsetsAndSize,
    qt_meta_data_QmlModel,
    qt_static_metacall,
    nullptr,
qt_metaTypeArray<
bool, QString, bool, QmlModel, void, void, void, void
, void, QString
, void

>,
    nullptr
} };


const QMetaObject *QmlModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QmlModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QmlModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QmlModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QmlModel::bShowQmlWinChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QmlModel::qmlImageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QmlModel::bShowQmlWinShadowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QmlModel::bSaveImageFromQmlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
