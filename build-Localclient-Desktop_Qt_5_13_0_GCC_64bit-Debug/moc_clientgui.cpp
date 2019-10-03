/****************************************************************************
** Meta object code from reading C++ file 'clientgui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Localclient/clientgui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Clientgui_t {
    QByteArrayData data[8];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Clientgui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Clientgui_t qt_meta_stringdata_Clientgui = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Clientgui"
QT_MOC_LITERAL(1, 10, 19), // "on_conectar_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 17), // "on_quitar_clicked"
QT_MOC_LITERAL(4, 49, 17), // "on_editar_clicked"
QT_MOC_LITERAL(5, 67, 17), // "on_buscar_clicked"
QT_MOC_LITERAL(6, 85, 24), // "on_insertararbol_clicked"
QT_MOC_LITERAL(7, 110, 24) // "on_eliminararbol_clicked"

    },
    "Clientgui\0on_conectar_clicked\0\0"
    "on_quitar_clicked\0on_editar_clicked\0"
    "on_buscar_clicked\0on_insertararbol_clicked\0"
    "on_eliminararbol_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Clientgui[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Clientgui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Clientgui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_conectar_clicked(); break;
        case 1: _t->on_quitar_clicked(); break;
        case 2: _t->on_editar_clicked(); break;
        case 3: _t->on_buscar_clicked(); break;
        case 4: _t->on_insertararbol_clicked(); break;
        case 5: _t->on_eliminararbol_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Clientgui::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Clientgui.data,
    qt_meta_data_Clientgui,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Clientgui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Clientgui::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Clientgui.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Clientgui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
