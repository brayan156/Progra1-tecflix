#ifndef PASARBUTTON_H
#define PASARBUTTON_H

#include "button.h"




class PasarButton: public Button
{
public:
    PasarButton();
    void mousePressEvent(QMouseEvent *event);
};

#endif // PASARBUTTON_H
