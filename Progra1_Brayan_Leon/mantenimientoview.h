#ifndef MANTENIMIENTOVIEW_H
#define MANTENIMIENTOVIEW_H

#include "mainwindow.h"

#include <QGraphicsView>
#include <QLabel>
#include <QLineEdit>
#include <QTextBrowser>



class mantenimientoview: public QGraphicsView
{

public:
    mantenimientoview(QString string);
    void cargar_dataset();
    void generar_lines();

    QTextBrowser *Textb;
    QList<QLineEdit*> *linelist=new QList<QLineEdit*>();
    QList<QLabel*> *labellist=new QList<QLabel*>();
    QString string;

};

#endif // MANTENIMIENTOVIEW_H
