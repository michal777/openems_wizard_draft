/****************************************************************************
** Meta object code from reading C++ file 'PageMaterials.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../openEMSwizard/PageMaterials.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PageMaterials.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PageMaterials_t {
    QByteArrayData data[8];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PageMaterials_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PageMaterials_t qt_meta_stringdata_PageMaterials = {
    {
QT_MOC_LITERAL(0, 0, 13), // "PageMaterials"
QT_MOC_LITERAL(1, 14, 21), // "OnAddOrChangeMaterial"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 16), // "OnRemoveMaterial"
QT_MOC_LITERAL(4, 54, 21), // "OnGetSelectedMaterial"
QT_MOC_LITERAL(5, 76, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 93, 4), // "item"
QT_MOC_LITERAL(7, 98, 17) // "OnSetMaterialType"

    },
    "PageMaterials\0OnAddOrChangeMaterial\0"
    "\0OnRemoveMaterial\0OnGetSelectedMaterial\0"
    "QListWidgetItem*\0item\0OnSetMaterialType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PageMaterials[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    1,   36,    2, 0x0a /* Public */,
       7,    0,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

       0        // eod
};

void PageMaterials::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PageMaterials *_t = static_cast<PageMaterials *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnAddOrChangeMaterial(); break;
        case 1: _t->OnRemoveMaterial(); break;
        case 2: _t->OnGetSelectedMaterial((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->OnSetMaterialType(); break;
        default: ;
        }
    }
}

const QMetaObject PageMaterials::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_PageMaterials.data,
      qt_meta_data_PageMaterials,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PageMaterials::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PageMaterials::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PageMaterials.stringdata0))
        return static_cast<void*>(this);
    return QWizardPage::qt_metacast(_clname);
}

int PageMaterials::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
