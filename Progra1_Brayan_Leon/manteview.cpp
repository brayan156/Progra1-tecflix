#include "button.h"
#include "buttonfactory.h"
#include "manteview.h"

#include <QVBoxLayout>



void ManteView::cargar_dataset()
{
        this->Textb->clear();
        QStringList list=string.split(";");
        for (int i=1;i<list.length();i++){
            this->Textb->append(QString::number(i)+" = "+list.at(i));
        }
}

void ManteView::generar_lines()
{
        QLayout *layoutv=new QVBoxLayout();
        QLayout *layouth=new QHBoxLayout();
        QLayout *layouth2=new QHBoxLayout();
        QLayout *layouth3=new QHBoxLayout();
        layoutv->addItem(layouth);
        layoutv->addItem(layouth2);
        layoutv->addItem(layouth3);
        Button *boton1=ButtonFactory::crear_boton(boton::mantenimiento);
        Button *boton2=ButtonFactory::crear_boton(boton::mantenimiento);
        Button *boton3=ButtonFactory::crear_boton(boton::mantenimiento);
        Button *boton4=ButtonFactory::crear_boton(boton::mantenimiento);
        Button *boton5=ButtonFactory::crear_boton(boton::mantenimiento);
        boton1->setText("buscar");
        boton2->setText("agregar");
        boton3->setText("editar");
        boton4->setText("eliminar");
        boton4->setText("Actualizar");
        layouth2->addWidget(boton1);
        layouth2->addWidget(boton2);
        layouth2->addWidget(boton3);
        layouth2->addWidget(boton4);
}

void ManteView::crear_view(QString string)
{
        this->string=string;
        QGraphicsScene *scene=new QGraphicsScene;
        this->Textb=new QTextBrowser;
        this->cargar_dataset();
        Textb->move(0,0);
        Textb->setMinimumSize(600,200);
        scene->addWidget(Textb);
    //    this->generar_lines();
        this->setScene(scene);
}
