#ifndef SINGLETON_H
#define SINGLETON_H


#include <QGraphicsView>
#include <QLineEdit>
#include <QTextBrowser>
#include <iostream>

class ManteView: public QGraphicsView
{

    public:
        ManteView();
        /* Static access method. */
        void cargar_dataset();
        void generar_lines();
        void crear_view(QString string);
        QTextBrowser *Textb;
        QList<QLineEdit*> *linelist=new QList<QLineEdit*>();
        QString string;
};

/* Null, because instance will be initialized on demand. */


#endif // SINGLETON_H
