#ifndef BUTTONFACTORY_H
#define BUTTONFACTORY_H

#include "button.h"

#include <QPushButton>


enum boton{
  pasar,
  pagina,
  cambiarmodo,
  tarjeta,
};
class ButtonFactory
{
public:
   static Button* crear_boton(boton button);

};

#endif // BUTTONFACTORY_H
