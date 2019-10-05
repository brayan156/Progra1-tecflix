#include "buttonfactory.h"
#include "custombutton.h"
#include "custompagebutton.h"
#include "linkbutton.h"
#include "modebutton.h"
#include "pasarbutton.h"



Button* ButtonFactory::crear_boton(boton button)
{
    Button* butn=NULL;
    if (button==boton::pasar){
        butn=new  PasarButton;
    }
    else if (button==boton::pagina) {
        butn=new Custompagebutton;
    }
    else if (button==boton::tarjeta) {
        butn=new CustomButton;
    }
    else if (button==boton::cambiarmodo) {
        butn=new ModeButton;
    }
    else if (button==boton::link) {
        butn=new LinkButton;
    }
    return butn;
}
