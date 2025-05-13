/****************************************************************************
** Meta object code from reading C++ file 'deskwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../deskwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deskwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSdeskwindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSdeskwindowENDCLASS = QtMocHelpers::stringData(
    "deskwindow",
    "on_pushButton_clicked",
    "",
    "on_addbutton_clicked",
    "getItemLevel",
    "QTreeWidgetItem*",
    "item",
    "on_addParallelbutton_clicked",
    "updateItemNumbers",
    "parent",
    "on_deletebutton_clicked",
    "on_saveButton_clicked",
    "freshlist",
    "expandAllItems",
    "QTreeWidget*",
    "treeWidget",
    "expandAllChildItems",
    "on_seeDetailsButton_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSdeskwindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    1,   82,    2, 0x08,    3 /* Private */,
       7,    0,   85,    2, 0x08,    5 /* Private */,
       8,    1,   86,    2, 0x08,    6 /* Private */,
      10,    0,   89,    2, 0x08,    8 /* Private */,
      11,    0,   90,    2, 0x08,    9 /* Private */,
      12,    0,   91,    2, 0x08,   10 /* Private */,
      13,    1,   92,    2, 0x08,   11 /* Private */,
      16,    1,   95,    2, 0x08,   13 /* Private */,
      17,    0,   98,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject deskwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSdeskwindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSdeskwindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSdeskwindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<deskwindow, std::true_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addbutton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getItemLevel'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>,
        // method 'on_addParallelbutton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateItemNumbers'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>,
        // method 'on_deletebutton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_saveButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'freshlist'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'expandAllItems'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTreeWidget *, std::false_type>,
        // method 'expandAllChildItems'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>,
        // method 'on_seeDetailsButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void deskwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<deskwindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_addbutton_clicked(); break;
        case 2: { int _r = _t->getItemLevel((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->on_addParallelbutton_clicked(); break;
        case 4: _t->updateItemNumbers((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1]))); break;
        case 5: _t->on_deletebutton_clicked(); break;
        case 6: _t->on_saveButton_clicked(); break;
        case 7: _t->freshlist(); break;
        case 8: _t->expandAllItems((*reinterpret_cast< std::add_pointer_t<QTreeWidget*>>(_a[1]))); break;
        case 9: _t->expandAllChildItems((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1]))); break;
        case 10: _t->on_seeDetailsButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTreeWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *deskwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *deskwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSdeskwindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int deskwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
