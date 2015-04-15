/****************************************************************************
** Meta object code from reading C++ file 'control.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/control.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'control.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Control_t {
    QByteArrayData data[8];
    char stringdata[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Control_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Control_t qt_meta_stringdata_Control = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Control"
QT_MOC_LITERAL(1, 8, 10), // "showChoose"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 8), // "showFind"
QT_MOC_LITERAL(4, 29, 10), // "showMemory"
QT_MOC_LITERAL(5, 40, 11), // "showArticle"
QT_MOC_LITERAL(6, 52, 12), // "showSettings"
QT_MOC_LITERAL(7, 65, 5) // "query"

    },
    "Control\0showChoose\0\0showFind\0showMemory\0"
    "showArticle\0showSettings\0query"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Control[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    1,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void Control::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Control *_t = static_cast<Control *>(_o);
        switch (_id) {
        case 0: _t->showChoose(); break;
        case 1: _t->showFind(); break;
        case 2: _t->showMemory(); break;
        case 3: _t->showArticle(); break;
        case 4: _t->showSettings(); break;
        case 5: _t->query((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Control::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Control.data,
      qt_meta_data_Control,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Control::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Control::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Control.stringdata))
        return static_cast<void*>(const_cast< Control*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Control::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
