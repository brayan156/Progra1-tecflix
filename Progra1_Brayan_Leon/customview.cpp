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
    main->mostrar_paginacion();
    main->poner_botones();



}

void Customview::mousePressEvent(QMouseEvent *event)
{

           QGraphicsView::mousePressEvent(event);
}
