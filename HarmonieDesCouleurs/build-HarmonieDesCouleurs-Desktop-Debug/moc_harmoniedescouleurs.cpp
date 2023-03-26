/****************************************************************************
** Meta object code from reading C++ file 'harmoniedescouleurs.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../HarmonieDesCouleurs/harmoniedescouleurs.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'harmoniedescouleurs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HarmonieDesCouleurs_t {
    const uint offsetsAndSize[40];
    char stringdata0[378];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_HarmonieDesCouleurs_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_HarmonieDesCouleurs_t qt_meta_stringdata_HarmonieDesCouleurs = {
    {
QT_MOC_LITERAL(0, 19), // "HarmonieDesCouleurs"
QT_MOC_LITERAL(20, 10), // "imageIsSet"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 11), // "imageValide"
QT_MOC_LITERAL(44, 20), // "on_Parcourir_clicked"
QT_MOC_LITERAL(65, 26), // "on_actionQuitter_triggered"
QT_MOC_LITERAL(92, 11), // "colorChosen"
QT_MOC_LITERAL(104, 15), // "colorChosenBool"
QT_MOC_LITERAL(120, 24), // "on_colorSelector_clicked"
QT_MOC_LITERAL(145, 15), // "imageIsModified"
QT_MOC_LITERAL(161, 13), // "imageModifiee"
QT_MOC_LITERAL(175, 26), // "on_actionCredits_triggered"
QT_MOC_LITERAL(202, 21), // "on_dom_colors_clicked"
QT_MOC_LITERAL(224, 20), // "on_Supprimer_clicked"
QT_MOC_LITERAL(245, 20), // "on_d_color_1_clicked"
QT_MOC_LITERAL(266, 20), // "on_d_color_2_clicked"
QT_MOC_LITERAL(287, 20), // "on_d_color_3_clicked"
QT_MOC_LITERAL(308, 20), // "on_d_color_4_clicked"
QT_MOC_LITERAL(329, 26), // "on_GenererImgFinal_clicked"
QT_MOC_LITERAL(356, 21) // "on_Save_image_clicked"

    },
    "HarmonieDesCouleurs\0imageIsSet\0\0"
    "imageValide\0on_Parcourir_clicked\0"
    "on_actionQuitter_triggered\0colorChosen\0"
    "colorChosenBool\0on_colorSelector_clicked\0"
    "imageIsModified\0imageModifiee\0"
    "on_actionCredits_triggered\0"
    "on_dom_colors_clicked\0on_Supprimer_clicked\0"
    "on_d_color_1_clicked\0on_d_color_2_clicked\0"
    "on_d_color_3_clicked\0on_d_color_4_clicked\0"
    "on_GenererImgFinal_clicked\0"
    "on_Save_image_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HarmonieDesCouleurs[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x08,    1 /* Private */,
       4,    0,  107,    2, 0x08,    3 /* Private */,
       5,    0,  108,    2, 0x08,    4 /* Private */,
       6,    1,  109,    2, 0x08,    5 /* Private */,
       8,    0,  112,    2, 0x08,    7 /* Private */,
       9,    1,  113,    2, 0x08,    8 /* Private */,
      11,    0,  116,    2, 0x08,   10 /* Private */,
      12,    0,  117,    2, 0x08,   11 /* Private */,
      13,    0,  118,    2, 0x08,   12 /* Private */,
      14,    0,  119,    2, 0x08,   13 /* Private */,
      15,    0,  120,    2, 0x08,   14 /* Private */,
      16,    0,  121,    2, 0x08,   15 /* Private */,
      17,    0,  122,    2, 0x08,   16 /* Private */,
      18,    0,  123,    2, 0x08,   17 /* Private */,
      19,    0,  124,    2, 0x08,   18 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
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

void HarmonieDesCouleurs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HarmonieDesCouleurs *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->imageIsSet((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->on_Parcourir_clicked(); break;
        case 2: _t->on_actionQuitter_triggered(); break;
        case 3: _t->colorChosen((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->on_colorSelector_clicked(); break;
        case 5: _t->imageIsModified((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->on_actionCredits_triggered(); break;
        case 7: _t->on_dom_colors_clicked(); break;
        case 8: _t->on_Supprimer_clicked(); break;
        case 9: _t->on_d_color_1_clicked(); break;
        case 10: _t->on_d_color_2_clicked(); break;
        case 11: _t->on_d_color_3_clicked(); break;
        case 12: _t->on_d_color_4_clicked(); break;
        case 13: _t->on_GenererImgFinal_clicked(); break;
        case 14: _t->on_Save_image_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject HarmonieDesCouleurs::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_HarmonieDesCouleurs.offsetsAndSize,
    qt_meta_data_HarmonieDesCouleurs,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_HarmonieDesCouleurs_t
, QtPrivate::TypeAndForceComplete<HarmonieDesCouleurs, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *HarmonieDesCouleurs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HarmonieDesCouleurs::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HarmonieDesCouleurs.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int HarmonieDesCouleurs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
