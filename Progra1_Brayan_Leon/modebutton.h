#ifndef MODEBUTTON_H
#define MODEBUTTON_H

#include "button.h"



class ModeButton:public Button
{
public:
    ModeButton();
    void mousePressEvent(QMouseEvent *event);
    void crearmante();

};

#endif // MODEBUTTON_H
