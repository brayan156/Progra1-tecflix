#include "modebutton.h"

ModeButton::ModeButton()
{

}

void ModeButton::mousePressEvent(QMouseEvent *event)
{
    if (this->text().compare("scroll")==0){
      this->main->pagina_actual=1;
      this->main->modo="scroll";
      this->main->crear_scroll();
    }
    else if (this->text().compare("pagina")==0) {
        this->main->pagina_actual=0;
        this->main->modo="pagina";
        this->main->mostrar_paginacion();
    }
    else if (this->text().compare("todo")==0){

        this->main->modo="todo";
        this->main->mostrar_todo();
    }
}
