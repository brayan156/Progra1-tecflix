#include "customscroll.h"

CustomScroll::CustomScroll()
{

}

void CustomScroll::mouseReleaseEvent(QMouseEvent *event)
{
    if (this->main->modo.compare("scroll")==0){
    int tamano_pagina=this->maximum()/3;
    int slide=this->sliderPosition();
    int pagina_actual;
    qDebug()<<this->size().rwidth();
    if (this->main->pagina_actual==1){
        if (slide<tamano_pagina){
            pagina_actual=2;
        }
        else if (slide>tamano_pagina*2){
            this->main->pagina_actual+=1;
            pagina_actual=3;
        }
    }
    else if (this->main->pagina_actual==this->main->cantidad_paginas-1){
        if (slide<tamano_pagina){
            this->main->pagina_actual-=1;
            pagina_actual=1;
        }
        else if (slide>tamano_pagina){
            pagina_actual=2;
        }
    }
    else {
        if (slide<tamano_pagina){
            this->main->pagina_actual-=1;
            pagina_actual=1;
        }
        else if (slide>tamano_pagina*2){
            this->main->pagina_actual+=1;
            pagina_actual=3;

        }
        else{
            pagina_actual=2;
        }
    }
    this->main->actualizar_scroll(pagina_actual,slide);
    }

    //    QScrollBar::mouseReleaseEvent(event);
}


