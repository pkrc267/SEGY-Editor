/****************************************************************************
** Meta object code from reading C++ file 'mergetextualheader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SEGYReader/mergetextualheader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mergetextualheader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MergeTextualHeader_t {
    QByteArrayData data[7];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MergeTextualHeader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MergeTextualHeader_t qt_meta_stringdata_MergeTextualHeader = {
    {
QT_MOC_LITERAL(0, 0, 18), // "MergeTextualHeader"
QT_MOC_LITERAL(1, 19, 25), // "on_fileListWidget_clicked"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 5), // "index"
QT_MOC_LITERAL(4, 52, 26), // "on_tableWidget_cellChanged"
QT_MOC_LITERAL(5, 79, 3), // "row"
QT_MOC_LITERAL(6, 83, 6) // "column"

    },
    "MergeTextualHeader\0on_fileListWidget_clicked\0"
    "\0index\0on_tableWidget_cellChanged\0row\0"
    "column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MergeTextualHeader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    2,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,

       0        // eod
};

void MergeTextualHeader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MergeTextualHeader *_t = static_cast<MergeTextualHeader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_fileListWidget_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_tableWidget_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject MergeTextualHeader::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_MergeTextualHeader.data,
      qt_meta_data_MergeTextualHeader,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MergeTextualHeader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MergeTextualHeader::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MergeTextualHeader.stringdata0))
        return static_cast<void*>(const_cast< MergeTextualHeader*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int MergeTextualHeader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
