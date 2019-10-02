#include "pasarbutton.h"

PasarButton::PasarButton()
{

}

void PasarButton::mousePressEvent(QMouseEvent *event)
{
    if (this->text().compare("<")==0){
        if(this->main->primer_boton==0){}
        else{
            this->main->primer_boton-=this->main->botones_totales-2;
            if (this->main->primer_boton<0){this->main->primer_boton=0;}
            this->main->poner_botones();
        }
    }else{
        if(this->main->primer_boton+this->main->botones_totales-2>this->main->cantidad_paginas){}
        else{
            this->main->primer_boton+=this->main->botones_totales-2;
            this->main->poner_botones();
        }

    }
}
