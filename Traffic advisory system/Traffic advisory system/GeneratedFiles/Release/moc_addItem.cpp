/****************************************************************************
** Meta object code from reading C++ file 'addItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../addItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_addItem_t {
    QByteArrayData data[15];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_addItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_addItem_t qt_meta_stringdata_addItem = {
    {
QT_MOC_LITERAL(0, 0, 7), // "addItem"
QT_MOC_LITERAL(1, 8, 7), // "retEdge"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 1), // "s"
QT_MOC_LITERAL(4, 19, 8), // "EdgeNode"
QT_MOC_LITERAL(5, 28, 1), // "e"
QT_MOC_LITERAL(6, 30, 7), // "retNode"
QT_MOC_LITERAL(7, 38, 6), // "cancel"
QT_MOC_LITERAL(8, 45, 7), // "addEdge"
QT_MOC_LITERAL(9, 53, 16), // "selectPosition_s"
QT_MOC_LITERAL(10, 70, 16), // "selectPosition_t"
QT_MOC_LITERAL(11, 87, 17), // "changetPosition_s"
QT_MOC_LITERAL(12, 105, 3), // "loc"
QT_MOC_LITERAL(13, 109, 17), // "changetPosition_t"
QT_MOC_LITERAL(14, 127, 7) // "addNode"

    },
    "addItem\0retEdge\0\0s\0EdgeNode\0e\0retNode\0"
    "cancel\0addEdge\0selectPosition_s\0"
    "selectPosition_t\0changetPosition_s\0"
    "loc\0changetPosition_t\0addNode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_addItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       6,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   67,    2, 0x0a /* Public */,
       8,    0,   68,    2, 0x0a /* Public */,
       9,    0,   69,    2, 0x0a /* Public */,
      10,    0,   70,    2, 0x0a /* Public */,
      11,    1,   71,    2, 0x0a /* Public */,
      13,    1,   74,    2, 0x0a /* Public */,
      14,    0,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,

       0        // eod
};

void addItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        addItem *_t = static_cast<addItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->retEdge((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< EdgeNode(*)>(_a[2]))); break;
        case 1: _t->retNode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->cancel(); break;
        case 3: _t->addEdge(); break;
        case 4: _t->selectPosition_s(); break;
        case 5: _t->selectPosition_t(); break;
        case 6: _t->changetPosition_s((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->changetPosition_t((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->addNode(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (addItem::*_t)(int , EdgeNode );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&addItem::retEdge)) {
                *result = 0;
            }
        }
        {
            typedef void (addItem::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&addItem::retNode)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject addItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_addItem.data,
      qt_meta_data_addItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *addItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_addItem.stringdata0))
        return static_cast<void*>(const_cast< addItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int addItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void addItem::retEdge(int _t1, EdgeNode _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void addItem::retNode(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
