/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../finalStudentApp/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "connectToServer"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "onConnectServer"
QT_MOC_LITERAL(4, 44, 11), // "sendRequest"
QT_MOC_LITERAL(5, 56, 11), // "readMessage"
QT_MOC_LITERAL(6, 68, 24), // "connectionClosedByServer"
QT_MOC_LITERAL(7, 93, 5), // "error"
QT_MOC_LITERAL(8, 99, 6), // "reboot"
QT_MOC_LITERAL(9, 106, 11), // "processKill"
QT_MOC_LITERAL(10, 118, 6), // "number"
QT_MOC_LITERAL(11, 125, 8), // "pListSet"
QT_MOC_LITERAL(12, 134, 12), // "processParse"
QT_MOC_LITERAL(13, 147, 15), // "vector<QString>"
QT_MOC_LITERAL(14, 163, 5), // "char*"
QT_MOC_LITERAL(15, 169, 5), // "pfile"
QT_MOC_LITERAL(16, 175, 10), // "dirIsDigit"
QT_MOC_LITERAL(17, 186, 11), // "processData"
QT_MOC_LITERAL(18, 198, 10), // "processPid"
QT_MOC_LITERAL(19, 209, 21) // "on_pushButton_clicked"

    },
    "MainWindow\0connectToServer\0\0onConnectServer\0"
    "sendRequest\0readMessage\0"
    "connectionClosedByServer\0error\0reboot\0"
    "processKill\0number\0pListSet\0processParse\0"
    "vector<QString>\0char*\0pfile\0dirIsDigit\0"
    "processData\0processPid\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    1,   91,    2, 0x0a /* Public */,
      11,    0,   94,    2, 0x0a /* Public */,
      12,    1,   95,    2, 0x0a /* Public */,
      16,    1,   98,    2, 0x0a /* Public */,
      17,    0,  101,    2, 0x0a /* Public */,
      18,    1,  102,    2, 0x0a /* Public */,
      19,    0,  105,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    0x80000000 | 13, 0x80000000 | 14,   15,
    QMetaType::Int, 0x80000000 | 14,    2,
    QMetaType::QByteArray,
    QMetaType::QString, QMetaType::Int,   10,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectToServer(); break;
        case 1: _t->onConnectServer(); break;
        case 2: _t->sendRequest(); break;
        case 3: _t->readMessage(); break;
        case 4: _t->connectionClosedByServer(); break;
        case 5: _t->error(); break;
        case 6: _t->reboot(); break;
        case 7: _t->processKill((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->pListSet(); break;
        case 9: { vector<QString> _r = _t->processParse((*reinterpret_cast< char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<QString>*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->dirIsDigit((*reinterpret_cast< char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: { QByteArray _r = _t->processData();
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 12: { QString _r = _t->processPid((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 13: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
