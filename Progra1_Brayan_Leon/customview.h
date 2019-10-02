#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H
#include "mainwindow.h"

#include <QGraphicsView>
#include <QtWidgets>
#include <QWidget>

class Customview : public QGraphicsView
{
public:
    Customview(QWidget* parent=0);
    double escala=1;
    MainWindow *main;
protected:
    virtual void wheelEvent (QWheelEvent *event);
    void mousePressEvent(QMouseEvent *event);
};


#endif // CUSTOMVIEW_H
