/****************************************************************************
** Meta object code from reading C++ file 'PageGeometry.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../openEMSwizard/PageGeometry.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PageGeometry.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PageGeometry_t {
    QByteArrayData data[8];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PageGeometry_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PageGeometry_t qt_meta_stringdata_PageGeometry = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PageGeometry"
QT_MOC_LITERAL(1, 13, 20), // "OnSetShapeTypeLayout"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 18), // "OnAddOrChangeShape"
QT_MOC_LITERAL(4, 54, 13), // "OnRemoveShape"
QT_MOC_LITERAL(5, 68, 18), // "OnGetSelectedShape"
QT_MOC_LITERAL(6, 87, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(7, 104, 4) // "item"

    },
    "PageGeometry\0OnSetShapeTypeLayout\0\0"
    "OnAddOrChangeShape\0OnRemoveShape\0"
    "OnGetSelectedShape\0QListWidgetItem*\0"
    "item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PageGeometry[] = {

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
       4,    0,   36,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void PageGeometry::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PageGeometry *_t = static_cast<PageGeometry *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnSetShapeTypeLayout(); break;
        case 1: _t->OnAddOrChangeShape(); break;
        case 2: _t->OnRemoveShape(); break;
        case 3: _t->OnGetSelectedShape((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject PageGeometry::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_PageGeometry.data,
      qt_meta_data_PageGeometry,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PageGeometry::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PageGeometry::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PageGeometry.stringdata0))
        return static_cast<void*>(this);
    return QWizardPage::qt_metacast(_clname);
}

int PageGeometry::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
