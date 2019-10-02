#ifndef CUSTOMPAGEBUTTON_H
#define CUSTOMPAGEBUTTON_H

#include "button.h"




class Custompagebutton: public Button
{
public:
    Custompagebutton();
    void mousePressEvent(QMouseEvent *event);
};

#endif // CUSTOMPAGEBUTTON_H
