/****************************************************************************
** Meta object code from reading C++ file 'segyfileform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SEGYReader/segyfileform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'segyfileform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SegyFileForm_t {
    QByteArrayData data[19];
    char stringdata0[343];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SegyFileForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SegyFileForm_t qt_meta_stringdata_SegyFileForm = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SegyFileForm"
QT_MOC_LITERAL(1, 13, 12), // "traceChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 1), // "i"
QT_MOC_LITERAL(4, 29, 15), // "someItemChanged"
QT_MOC_LITERAL(5, 45, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(6, 63, 3), // "twi"
QT_MOC_LITERAL(7, 67, 17), // "textHeaderChanged"
QT_MOC_LITERAL(8, 85, 3), // "row"
QT_MOC_LITERAL(9, 89, 6), // "column"
QT_MOC_LITERAL(10, 96, 19), // "binaryHeaderChanged"
QT_MOC_LITERAL(11, 116, 18), // "traceHeaderChanged"
QT_MOC_LITERAL(12, 135, 36), // "on_textHeaderTable_cellDouble..."
QT_MOC_LITERAL(13, 172, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(14, 194, 30), // "on_textHeaderTable_cellClicked"
QT_MOC_LITERAL(15, 225, 32), // "on_binaryHeaderTable_cellClicked"
QT_MOC_LITERAL(16, 258, 38), // "on_binaryHeaderTable_cellDoub..."
QT_MOC_LITERAL(17, 297, 37), // "on_traceBinaryHeaderTable_cel..."
QT_MOC_LITERAL(18, 335, 7) // "convert"

    },
    "SegyFileForm\0traceChanged\0\0i\0"
    "someItemChanged\0QTableWidgetItem*\0twi\0"
    "textHeaderChanged\0row\0column\0"
    "binaryHeaderChanged\0traceHeaderChanged\0"
    "on_textHeaderTable_cellDoubleClicked\0"
    "on_pushButton_clicked\0"
    "on_textHeaderTable_cellClicked\0"
    "on_binaryHeaderTable_cellClicked\0"
    "on_binaryHeaderTable_cellDoubleClicked\0"
    "on_traceBinaryHeaderTable_cellClicked\0"
    "convert"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SegyFileForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       4,    1,   77,    2, 0x08 /* Private */,
       7,    2,   80,    2, 0x08 /* Private */,
      10,    2,   85,    2, 0x08 /* Private */,
      11,    2,   90,    2, 0x08 /* Private */,
      12,    2,   95,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    2,  101,    2, 0x08 /* Private */,
      15,    2,  106,    2, 0x08 /* Private */,
      16,    2,  111,    2, 0x08 /* Private */,
      17,    2,  116,    2, 0x08 /* Private */,
      18,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void,

       0        // eod
};

void SegyFileForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SegyFileForm *_t = static_cast<SegyFileForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->traceChanged((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->someItemChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->textHeaderChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->binaryHeaderChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->traceHeaderChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        //case 5: _t->on_textHeaderTable_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_textHeaderTable_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->on_binaryHeaderTable_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        //case 9: _t->on_binaryHeaderTable_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->on_traceBinaryHeaderTable_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->convert(); break;
        default: ;
        }
    }
}

const QMetaObject SegyFileForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SegyFileForm.data,
      qt_meta_data_SegyFileForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SegyFileForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SegyFileForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SegyFileForm.stringdata0))
        return static_cast<void*>(const_cast< SegyFileForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int SegyFileForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
