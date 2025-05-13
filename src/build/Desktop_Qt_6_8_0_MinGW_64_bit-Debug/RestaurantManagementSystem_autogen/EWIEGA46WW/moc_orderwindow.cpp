/****************************************************************************
** Meta object code from reading C++ file 'orderwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../orderwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'orderwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSorderwindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSorderwindowENDCLASS = QtMocHelpers::stringData(
    "orderwindow",
    "on_saveAndClose_clicked",
    "",
    "on_statusButton_clicked",
    "on_payButton_clicked",
    "on_displayAll_clicked",
    "on_displayWaiting_clicked",
    "on_displayEating_clicked",
    "on_floorBox_currentIndexChanged",
    "index",
    "on_areaBox_currentIndexChanged",
    "on_deskBox_currentIndexChanged",
    "isCorrectWithDeskCombobox",
    "orderNode*",
    "node",
    "on_vipPayButton_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSorderwindowENDCLASS[] = {

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
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    0,   84,    2, 0x08,    5 /* Private */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    1,   86,    2, 0x08,    7 /* Private */,
      10,    1,   89,    2, 0x08,    9 /* Private */,
      11,    1,   92,    2, 0x08,   11 /* Private */,
      12,    1,   95,    2, 0x08,   13 /* Private */,
      15,    0,   98,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Bool, 0x80000000 | 13,   14,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject orderwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSorderwindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSorderwindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSorderwindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<orderwindow, std::true_type>,
        // method 'on_saveAndClose_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_statusButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_payButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_displayAll_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_displayWaiting_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_displayEating_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_floorBox_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_areaBox_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_deskBox_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'isCorrectWithDeskCombobox'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<orderNode *, std::false_type>,
        // method 'on_vipPayButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void orderwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<orderwindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_saveAndClose_clicked(); break;
        case 1: _t->on_statusButton_clicked(); break;
        case 2: _t->on_payButton_clicked(); break;
        case 3: _t->on_displayAll_clicked(); break;
        case 4: _t->on_displayWaiting_clicked(); break;
        case 5: _t->on_displayEating_clicked(); break;
        case 6: _t->on_floorBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->on_areaBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_deskBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: { bool _r = _t->isCorrectWithDeskCombobox((*reinterpret_cast< std::add_pointer_t<orderNode*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->on_vipPayButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *orderwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *orderwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSorderwindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int orderwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
