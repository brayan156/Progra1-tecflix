#ifndef LINKBUTTON_H
#define LINKBUTTON_H

#include "button.h"



class LinkButton:public Button
{
public:
    LinkButton();
    void mousePressEvent(QMouseEvent *event);
};

#endif // LINKBUTTON_H
