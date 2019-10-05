#include "linkbutton.h"

LinkButton::LinkButton()
{

}

void LinkButton::mousePressEvent(QMouseEvent *event)
{
    QDesktopServices::openUrl(QUrl(this->link));
}
