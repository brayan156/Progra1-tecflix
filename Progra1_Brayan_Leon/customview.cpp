#include "customview.h"
#include <iostream>
using namespace std;
Customview::Customview(QWidget *parent):QGraphicsView (parent)
{

}

void Customview::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor=1.50;
    if (event->delta()>0){
        scale(scaleFactor,scaleFactor);
        escala*=scaleFactor;
    }else{
      scale(1/scaleFactor,1/scaleFactor);
      escala*=(1/scaleFactor);
    }
    main->calcular_tarjetas();
    if (this->main->modo.compare("pagina")==0){this->main->mostrar_paginacion();}
    else if (this->main->modo.compare("scroll")==0){this->main->crear_scroll();}
    else if (this->main->modo.compare("todo")==0){this->main->mostrar_todo();}
    main->poner_botones();



}
