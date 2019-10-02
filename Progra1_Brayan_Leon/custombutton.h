#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include "button.h"





class CustomButton:public Button
{
public:
    CustomButton();
    void mousePressEvent(QMouseEvent *event);



};

#endif // CUSTOMBUTTON_H
