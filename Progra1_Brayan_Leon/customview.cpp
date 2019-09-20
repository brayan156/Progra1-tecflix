#include "customview.h"

Customview::Customview(QWidget *parent):QGraphicsView (parent)
{

}

void Customview::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor=1.15;
    if (event->delta()>0){
        scale(scaleFactor,scaleFactor);
    }else{
      scale(1/scaleFactor,1/scaleFactor);
    }
}

void Customview::mousePressEvent(QMouseEvent *event)
{

           QGraphicsView::mousePressEvent(event);
}
