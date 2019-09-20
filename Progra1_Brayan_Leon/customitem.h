#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <qgraphicsitem.h>



class Customitem : public QGraphicsPixmapItem
{
public:
    Customitem();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CUSTOMITEM_H
