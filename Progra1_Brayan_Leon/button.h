#ifndef BUTTON_H
#define BUTTON_H

#include "mainwindow.h"

#include <QPushButton>



class Button: public QPushButton
{
public:
    Button();
    virtual void mousePressEvent(QMouseEvent *event);
    QString cvdata;
    QString link;
    int num;
    MainWindow *main;
};

#endif // BUTTON_H
