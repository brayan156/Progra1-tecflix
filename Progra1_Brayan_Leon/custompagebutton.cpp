#include "custompagebutton.h"

Custompagebutton::Custompagebutton()
{

}

void Custompagebutton::mousePressEvent(QMouseEvent *event)
{
    this->main->sig_pagina=this->num-1;
    this->main->pasar_pagina();
    this->main->poner_botones();

}
