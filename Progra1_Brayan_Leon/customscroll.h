#ifndef CUSTOMSCROLL_H
#define CUSTOMSCROLL_H

#include <QScrollBar>
#include "mainwindow.h"



class CustomScroll: public QScrollBar
{
public:
    CustomScroll();
    void mouseReleaseEvent(QMouseEvent *event);
    MainWindow *main;
};

#endif // CUSTOMSCROLL_H
