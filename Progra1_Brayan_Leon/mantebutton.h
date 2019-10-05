#ifndef MANTEBUTTON_H
#define MANTEBUTTON_H

#include "mantenimientoview.h"

#include <QPushButton>



class ManteButton: public QPushButton
{
public:
    ManteButton();
    void mousePressEvent(QMouseEvent *event);
    mantenimientoview *mant;
};

#endif // MANTEBUTTON_H
