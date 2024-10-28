/****************************************************************************
** Meta object code from reading C++ file 'GiaoDienKhachHang.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../View/GiaoDienKhachHang.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GiaoDienKhachHang.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
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
struct qt_meta_stringdata_CLASSCustomerInterfaceENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSCustomerInterfaceENDCLASS = QtMocHelpers::stringData(
    "CustomerInterface",
    "productAdded",
    "",
    "productName",
    "productDeleted",
    "showOverview",
    "showProducts",
    "filterProducts",
    "showCart",
    "showOrders",
    "showAccount",
    "showInvoice",
    "payment",
    "checkout"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCustomerInterfaceENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,
       4,    1,   83,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   86,    2, 0x08,    5 /* Private */,
       6,    0,   87,    2, 0x08,    6 /* Private */,
       7,    0,   88,    2, 0x08,    7 /* Private */,
       8,    0,   89,    2, 0x08,    8 /* Private */,
       9,    0,   90,    2, 0x08,    9 /* Private */,
      10,    0,   91,    2, 0x08,   10 /* Private */,
      11,    0,   92,    2, 0x08,   11 /* Private */,
      12,    0,   93,    2, 0x08,   12 /* Private */,
      13,    0,   94,    2, 0x08,   13 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CustomerInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSCustomerInterfaceENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCustomerInterfaceENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCustomerInterfaceENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CustomerInterface, std::true_type>,
        // method 'productAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'productDeleted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'showOverview'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showProducts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'filterProducts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showCart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showOrders'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showAccount'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showInvoice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'payment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CustomerInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CustomerInterface *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->productAdded((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->productDeleted((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->showOverview(); break;
        case 3: _t->showProducts(); break;
        case 4: _t->filterProducts(); break;
        case 5: _t->showCart(); break;
        case 6: _t->showOrders(); break;
        case 7: _t->showAccount(); break;
        case 8: _t->showInvoice(); break;
        case 9: _t->payment(); break;
        case 10: _t->checkout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CustomerInterface::*)(const QString & );
            if (_t _q_method = &CustomerInterface::productAdded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CustomerInterface::*)(const QString & );
            if (_t _q_method = &CustomerInterface::productDeleted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *CustomerInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomerInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCustomerInterfaceENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CustomerInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void CustomerInterface::productAdded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CustomerInterface::productDeleted(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
