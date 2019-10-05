#include "customview.h"
#include <iostream>
using namespace std;
Customview::Customview(QWidget *parent):QGraphicsView (parent)
{

}

void Customview::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor=1.25;
    if (event->delta()>0){
        scale(scaleFactor,scaleFactor);
        escala*=scaleFactor;
    }else{
      scale(1/scaleFactor,1/scaleFactor);
      escala*=(1/scaleFactor);
    }
    qDebug()<<sizeof (*this)<<" de memoria";
    int dato_actual=this->main->pagina_actual*this->main->cantidad_tarjetas;
    this->main->calcular_tarjetas();

    int tarjetasy=((this->main->height()-128)/(220*this->escala));
    int tarjetasx=((this->main->width()-18)/(220*this->escala));
    int cantidad_tarjetas=tarjetasx*tarjetasy;
    if(cantidad_tarjetas==0){
        this->main->cantidad_paginas=0;

    }
    else{
        this->main->pagina_actual=dato_actual/cantidad_tarjetas;
    }
    if (this->main->modo.compare("pagina")==0){this->main->mostrar_paginacion();}
    else if (this->main->modo.compare("scroll")==0){if (this->main->pagina_actual==0){this->main->pagina_actual=1;}this->main->crear_scroll();}
    else if (this->main->modo.compare("todo")==0){this->main->mostrar_todo();}
    this->main->calcular_memoria();
    this->main->poner_botones();



}
