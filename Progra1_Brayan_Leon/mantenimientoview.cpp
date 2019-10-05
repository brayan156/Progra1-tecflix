
#include "mantebutton.h"
#include "mantenimientoview.h"

#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>



mantenimientoview::mantenimientoview(QString string)
{
    this->string=string;
    QGraphicsScene *scene=new QGraphicsScene;
    this->setScene(scene);
    this->Textb=new QTextBrowser;
    this->cargar_dataset();
    Textb->move(0,0);
    Textb->setMinimumSize(600,200);
    scene->addWidget(Textb);
    this->generar_lines();

}

void mantenimientoview::cargar_dataset()
{
    this->Textb->clear();
    QStringList list=string.split(";");
    for (int i=1;i<list.length();i++){
    this->Textb->append(QString::number(i)+" = "+list.at(i));
    }
}

void mantenimientoview::generar_lines()
{
    QString titles=this->string.split(";").at(0);
    QGroupBox *box=new QGroupBox;
    box->move(0,220);
    QLayout *layoutv=new QVBoxLayout();
    QLayout *layouth2=new QHBoxLayout();
    layoutv->addItem(layouth2);
    ManteButton *boton1=new ManteButton;
    ManteButton *boton2=new ManteButton;
    ManteButton *boton3=new ManteButton;
    ManteButton *boton4=new ManteButton;
    ManteButton *boton5=new ManteButton;
    boton1->setText("buscar");
    boton2->setText("agregar");
    boton3->setText("editar");
    boton4->setText("eliminar");
    boton5->setText("actualizar");
    boton1->mant=this;
    boton2->mant=this;
    boton3->mant=this;
    boton4->mant=this;
    boton5->mant=this;
    QLineEdit *line= new QLineEdit;
    this->linelist->append(line);
    layouth2->addWidget(new QLabel("busqueda(numero):"));
    layouth2->addWidget(line);
    layouth2->addWidget(boton1);
    layouth2->addWidget(boton2);
    layouth2->addWidget(boton3);
    layouth2->addWidget(boton4);
    layouth2->addWidget(boton5);
    for (int i=0; i<titles.split(",").length();i++){
        QLayout *layouth=new QHBoxLayout();
        layoutv->addItem(layouth);
        layouth->addWidget(new QLabel(titles.split(",").at(i)));
        QLineEdit *line= new QLineEdit;
        this->linelist->append(line);
        layouth->addWidget(line);
        QLabel *label= new QLabel;
        this->labellist->append(label);
        layouth->addWidget(label);
    }
    box->setLayout(layoutv);
    this->scene()->addWidget(box);
}
