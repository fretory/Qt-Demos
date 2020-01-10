/****************************************************************************
** Meta object code from reading C++ file 'trafficadvisorysystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../trafficadvisorysystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trafficadvisorysystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Trafficadvisorysystem_t {
    QByteArrayData data[23];
    char stringdata0[251];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Trafficadvisorysystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Trafficadvisorysystem_t qt_meta_stringdata_Trafficadvisorysystem = {
    {
QT_MOC_LITERAL(0, 0, 21), // "Trafficadvisorysystem"
QT_MOC_LITERAL(1, 22, 13), // "onCloseButton"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 13), // "onMinszButton"
QT_MOC_LITERAL(4, 51, 16), // "selectPosition_l"
QT_MOC_LITERAL(5, 68, 16), // "selectPosition_r"
QT_MOC_LITERAL(6, 85, 17), // "changetPosition_l"
QT_MOC_LITERAL(7, 103, 3), // "loc"
QT_MOC_LITERAL(8, 107, 17), // "changetPosition_r"
QT_MOC_LITERAL(9, 125, 13), // "eButtonaction"
QT_MOC_LITERAL(10, 139, 13), // "qButtonaction"
QT_MOC_LITERAL(11, 153, 6), // "update"
QT_MOC_LITERAL(12, 160, 10), // "deleteItem"
QT_MOC_LITERAL(13, 171, 9), // "addItemOn"
QT_MOC_LITERAL(14, 181, 7), // "addEdge"
QT_MOC_LITERAL(15, 189, 1), // "s"
QT_MOC_LITERAL(16, 191, 8), // "EdgeNode"
QT_MOC_LITERAL(17, 200, 1), // "e"
QT_MOC_LITERAL(18, 202, 7), // "addNode"
QT_MOC_LITERAL(19, 210, 9), // "editvalue"
QT_MOC_LITERAL(20, 220, 12), // "foucusChange"
QT_MOC_LITERAL(21, 233, 5), // "index"
QT_MOC_LITERAL(22, 239, 11) // "queryButton"

    },
    "Trafficadvisorysystem\0onCloseButton\0"
    "\0onMinszButton\0selectPosition_l\0"
    "selectPosition_r\0changetPosition_l\0"
    "loc\0changetPosition_r\0eButtonaction\0"
    "qButtonaction\0update\0deleteItem\0"
    "addItemOn\0addEdge\0s\0EdgeNode\0e\0addNode\0"
    "editvalue\0foucusChange\0index\0queryButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Trafficadvisorysystem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    0,   95,    2, 0x0a /* Public */,
       4,    0,   96,    2, 0x0a /* Public */,
       5,    0,   97,    2, 0x0a /* Public */,
       6,    1,   98,    2, 0x0a /* Public */,
       8,    1,  101,    2, 0x0a /* Public */,
       9,    0,  104,    2, 0x0a /* Public */,
      10,    0,  105,    2, 0x0a /* Public */,
      11,    0,  106,    2, 0x0a /* Public */,
      12,    0,  107,    2, 0x0a /* Public */,
      13,    0,  108,    2, 0x0a /* Public */,
      14,    2,  109,    2, 0x0a /* Public */,
      18,    1,  114,    2, 0x0a /* Public */,
      19,    0,  117,    2, 0x0a /* Public */,
      20,    1,  118,    2, 0x0a /* Public */,
      22,    0,  121,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 16,   15,   17,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   21,
    QMetaType::Void,

       0        // eod
};

void Trafficadvisorysystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Trafficadvisorysystem *_t = static_cast<Trafficadvisorysystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onCloseButton(); break;
        case 1: _t->onMinszButton(); break;
        case 2: _t->selectPosition_l(); break;
        case 3: _t->selectPosition_r(); break;
        case 4: _t->changetPosition_l((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->changetPosition_r((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->eButtonaction(); break;
        case 7: _t->qButtonaction(); break;
        case 8: _t->update(); break;
        case 9: _t->deleteItem(); break;
        case 10: _t->addItemOn(); break;
        case 11: _t->addEdge((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< EdgeNode(*)>(_a[2]))); break;
        case 12: _t->addNode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->editvalue(); break;
        case 14: _t->foucusChange((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 15: _t->queryButton(); break;
        default: ;
        }
    }
}

const QMetaObject Trafficadvisorysystem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Trafficadvisorysystem.data,
      qt_meta_data_Trafficadvisorysystem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Trafficadvisorysystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Trafficadvisorysystem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Trafficadvisorysystem.stringdata0))
        return static_cast<void*>(const_cast< Trafficadvisorysystem*>(this));
    return QWidget::qt_metacast(_clname);
}

int Trafficadvisorysystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
