/****************************************************************************
** Meta object code from reading C++ file 'VectorSorter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VectorSorter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VectorSorter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VectorSorter_t {
    QByteArrayData data[5];
    char stringdata[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_VectorSorter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_VectorSorter_t qt_meta_stringdata_VectorSorter = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 13),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 12),
QT_MOC_LITERAL(4, 41, 11)
    },
    "VectorSorter\0vectorChanged\0\0sortFinished\0"
    "setInterval\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VectorSorter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06,
       3,    0,   32,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    1,   33,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void VectorSorter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VectorSorter *_t = static_cast<VectorSorter *>(_o);
        switch (_id) {
        case 0: _t->vectorChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sortFinished(); break;
        case 2: _t->setInterval((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VectorSorter::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VectorSorter::vectorChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (VectorSorter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VectorSorter::sortFinished)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject VectorSorter::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_VectorSorter.data,
      qt_meta_data_VectorSorter,  qt_static_metacall, 0, 0}
};


const QMetaObject *VectorSorter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VectorSorter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VectorSorter.stringdata))
        return static_cast<void*>(const_cast< VectorSorter*>(this));
    return QThread::qt_metacast(_clname);
}

int VectorSorter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void VectorSorter::vectorChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VectorSorter::sortFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
