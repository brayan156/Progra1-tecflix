/********************************************************************************
** Form generated from reading UI file 'clientgui.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTGUI_H
#define UI_CLIENTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Clientgui
{
public:
    QWidget *centralWidget;
    QPushButton *conectar;
    QPushButton *quitar;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QPushButton *editar;
    QPushButton *insertararbol;
    QPushButton *eliminararbol;
    QPushButton *buscar;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Clientgui)
    {
        if (Clientgui->objectName().isEmpty())
            Clientgui->setObjectName(QString::fromUtf8("Clientgui"));
        Clientgui->resize(536, 388);
        centralWidget = new QWidget(Clientgui);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        conectar = new QPushButton(centralWidget);
        conectar->setObjectName(QString::fromUtf8("conectar"));
        conectar->setGeometry(QRect(330, 110, 89, 25));
        quitar = new QPushButton(centralWidget);
        quitar->setObjectName(QString::fromUtf8("quitar"));
        quitar->setGeometry(QRect(430, 110, 89, 25));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(300, 40, 113, 25));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(60, 110, 256, 192));
        editar = new QPushButton(centralWidget);
        editar->setObjectName(QString::fromUtf8("editar"));
        editar->setGeometry(QRect(330, 150, 89, 25));
        insertararbol = new QPushButton(centralWidget);
        insertararbol->setObjectName(QString::fromUtf8("insertararbol"));
        insertararbol->setGeometry(QRect(318, 220, 101, 25));
        eliminararbol = new QPushButton(centralWidget);
        eliminararbol->setObjectName(QString::fromUtf8("eliminararbol"));
        eliminararbol->setGeometry(QRect(428, 220, 101, 25));
        buscar = new QPushButton(centralWidget);
        buscar->setObjectName(QString::fromUtf8("buscar"));
        buscar->setGeometry(QRect(430, 150, 89, 25));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(90, 40, 113, 25));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 40, 41, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 40, 61, 17));
        Clientgui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Clientgui);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 536, 22));
        Clientgui->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Clientgui);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Clientgui->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Clientgui);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Clientgui->setStatusBar(statusBar);

        retranslateUi(Clientgui);

        QMetaObject::connectSlotsByName(Clientgui);
    } // setupUi

    void retranslateUi(QMainWindow *Clientgui)
    {
        Clientgui->setWindowTitle(QCoreApplication::translate("Clientgui", "Clientgui", nullptr));
        conectar->setText(QCoreApplication::translate("Clientgui", "insertar lista", nullptr));
        quitar->setText(QCoreApplication::translate("Clientgui", "eliminar lista", nullptr));
        editar->setText(QCoreApplication::translate("Clientgui", "editar", nullptr));
        insertararbol->setText(QCoreApplication::translate("Clientgui", "insertar arbol", nullptr));
        eliminararbol->setText(QCoreApplication::translate("Clientgui", "eliminar arbol", nullptr));
        buscar->setText(QCoreApplication::translate("Clientgui", "buscar", nullptr));
        label->setText(QCoreApplication::translate("Clientgui", "valor", nullptr));
        label_2->setText(QCoreApplication::translate("Clientgui", "posicion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Clientgui: public Ui_Clientgui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTGUI_H
