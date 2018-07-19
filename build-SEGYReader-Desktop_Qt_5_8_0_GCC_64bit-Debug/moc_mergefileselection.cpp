/****************************************************************************
** Meta object code from reading C++ file 'mergefileselection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SEGYReader/mergefileselection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mergefileselection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MergeFileSelection_t {
    QByteArrayData data[10];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MergeFileSelection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MergeFileSelection_t qt_meta_stringdata_MergeFileSelection = {
    {
QT_MOC_LITERAL(0, 0, 18), // "MergeFileSelection"
QT_MOC_LITERAL(1, 19, 24), // "on_addFileManual_clicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 15), // "on_cell_clicked"
QT_MOC_LITERAL(4, 61, 3), // "row"
QT_MOC_LITERAL(5, 65, 3), // "col"
QT_MOC_LITERAL(6, 69, 28), // "on_showLocationCheck_toggled"
QT_MOC_LITERAL(7, 98, 7), // "checked"
QT_MOC_LITERAL(8, 106, 25), // "on_saveFileButton_clicked"
QT_MOC_LITERAL(9, 132, 27) // "on_addFilesTextFile_clicked"

    },
    "MergeFileSelection\0on_addFileManual_clicked\0"
    "\0on_cell_clicked\0row\0col\0"
    "on_showLocationCheck_toggled\0checked\0"
    "on_saveFileButton_clicked\0"
    "on_addFilesTextFile_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MergeFileSelection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    2,   40,    2, 0x08 /* Private */,
       6,    1,   45,    2, 0x08 /* Private */,
       8,    0,   48,    2, 0x08 /* Private */,
       9,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MergeFileSelection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MergeFileSelection *_t = static_cast<MergeFileSelection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_addFileManual_clicked(); break;
        case 1: _t->on_cell_clicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->on_showLocationCheck_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_saveFileButton_clicked(); break;
        case 4: _t->on_addFilesTextFile_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MergeFileSelection::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_MergeFileSelection.data,
      qt_meta_data_MergeFileSelection,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MergeFileSelection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MergeFileSelection::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MergeFileSelection.stringdata0))
        return static_cast<void*>(const_cast< MergeFileSelection*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int MergeFileSelection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
