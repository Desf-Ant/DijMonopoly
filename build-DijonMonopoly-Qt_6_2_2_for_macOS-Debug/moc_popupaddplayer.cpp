/****************************************************************************
** Meta object code from reading C++ file 'popupaddplayer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../DijonMonopoly/popupaddplayer.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'popupaddplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PopUpAddPlayer_t {
    const uint offsetsAndSize[10];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PopUpAddPlayer_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PopUpAddPlayer_t qt_meta_stringdata_PopUpAddPlayer = {
    {
QT_MOC_LITERAL(0, 14), // "PopUpAddPlayer"
QT_MOC_LITERAL(15, 15), // "newPlayerSignal"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 24), // "std::vector<std::string>"
QT_MOC_LITERAL(57, 13) // "preparePlayer"

    },
    "PopUpAddPlayer\0newPlayerSignal\0\0"
    "std::vector<std::string>\0preparePlayer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PopUpAddPlayer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   31,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void PopUpAddPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PopUpAddPlayer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newPlayerSignal((*reinterpret_cast< std::vector<std::string>(*)>(_a[1])),(*reinterpret_cast< std::vector<std::string>(*)>(_a[2]))); break;
        case 1: _t->preparePlayer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PopUpAddPlayer::*)(std::vector<std::string> , std::vector<std::string> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PopUpAddPlayer::newPlayerSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject PopUpAddPlayer::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_PopUpAddPlayer.offsetsAndSize,
    qt_meta_data_PopUpAddPlayer,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PopUpAddPlayer_t
, QtPrivate::TypeAndForceComplete<PopUpAddPlayer, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::string>, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::string>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *PopUpAddPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PopUpAddPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PopUpAddPlayer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PopUpAddPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void PopUpAddPlayer::newPlayerSignal(std::vector<std::string> _t1, std::vector<std::string> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
