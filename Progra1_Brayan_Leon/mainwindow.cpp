#include "customitem.h"
#include "buttonfactory.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <fstream>
#include <sstream>
#include "custompagebutton.h"
#include "customscroll.h"



using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    scene=new QGraphicsScene ();
    ui->setupUi(this);
    this->leer_csv();
    this->ui->graphicsView->setScene(scene);
    this->calcular_tarjetas();
    CustomScroll *scroll=new CustomScroll;
    scroll->main=this;
    this->ui->graphicsView->setVerticalScrollBar(scroll);

//    this->mostrar_todo();
    ui->groupBox->setAccessibleDescription("no tengo layout");
    this->poner_botones();
//    QImage image("indice.jpeg");
//    image = image.scaled(200, 200);
//    item=new QGraphicsPixmapItem(QPixmap::fromImage(image));
//    item->update(item->x(),item->y(),100,100);
    ui->graphicsView->main=this;

     mManager = new QNetworkAccessManager(this);
     connect(mManager, &QNetworkAccessManager::finished, this,[&] (QNetworkReply *reply)
     {
            data=reply->readAll();
            reply->deleteLater();
            QString str =QString::fromLatin1(data);

             });


}






MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::leer_csv()
{
    string string="";
    ifstream lectura;
    lectura.open("movie_metadata.csv",ios::in);
    cantidad_datos=0;

    for (std::string linea; std::getline(lectura, linea); )
    {
        if (cantidad_datos==0){this->titles=linea.c_str();}
        stringstream registro(linea);
        cantidad_datos++;        
        string.append(linea);
        string.append(";");

    }
    cantidad_datos--;
    std::cout<<cantidad_datos;
    this->dataset=string.c_str();




}

void MainWindow::calcular_tarjetas()
{
    int tarjetasy=((this->height()-128)/(220*this->ui->graphicsView->escala));
    int tarjetasx=((this->width()-18)/(220*this->ui->graphicsView->escala));
    cantidad_tarjetas=tarjetasx*tarjetasy;

//    if (cant-cantidad_tarjetas!=0 && cantidad_tarjetas!=0){cantidad_tarjetas+=1;}
    if(cantidad_tarjetas==0){
        cantidad_paginas=0;

    }
    else{
        cantidad_paginas=cantidad_datos/cantidad_tarjetas;

        this->botones_totales=this->width()/40;
        if (this->primer_boton>this->cantidad_paginas){
            primer_boton=this->cantidad_paginas-this->botones_totales;
        }
        qDebug()<<cantidad_paginas<<","<<cantidad_tarjetas<<","<<cantidad_datos;
    }


}

void MainWindow::mostrar_todo()
{
   if (this->modo.compare("todo")==0){
   scene=new QGraphicsScene ();

   QStringList list=this->dataset.split(";");
   int x=0;
   int y=0;
   qDebug()<<ui->graphicsView->escala<<"de escala";
   for(int i=1;i<this->cantidad_datos;i++){
       QString string=list.at(i);
       if (string.split(",").length()<18){
//            qDebug()<<"tamano de lista "<<list.at(i+1);
           Button *button=ButtonFactory::crear_boton(boton::tarjeta);
           button->main=this;
           button->cvdata=string;
           button->link="";
           if ((x+1)*220*ui->graphicsView->escala<(this->width()-18)){
               button->move(220*x,220*y);
               x++;
           }
           else{
               y++;
               x=0;
               button->move(220*x,220*y);
               x++;
           }


           QString name="no name";
   //        qDebug()<<i<<"en "<<pagina<<"de "<<cantidad_tarjetas;
           if (name.length()>24){
               button->setText(name.remove(25,string.length()));
           }
           else{button->setText(name);}
           button->resize(200,200);
           scene->addWidget(button);
       }else{

   Button *button=ButtonFactory::crear_boton(boton::tarjeta);

   if ((x+1)*220*ui->graphicsView->escala<(this->width()-18)){
       button->move(220*x,220*y);
       x++;
   }
   else{
       y++;
       x=0;
       button->move(220*x,220*y);
       x++;
   }
   button->main=this;
   button->cvdata=string;
   button->link=string.split(",").at(17);
   QString name=list.at(i).split(",").at(11);
   if (name.length()>24){
       button->setText(name.remove(25,name.length()));
   }
   else{button->setText(name);}
   button->resize(200,200);
   scene->addWidget(button);
//   qDebug()<<list.at(i);
   }
   }
   delete ui->graphicsView->scene();
   ui->graphicsView->setScene(scene);
   this->mpaginas=1;
   }
}


void MainWindow::mostrar_paginacion()
{
    if (this->modo.compare("pagina")==0){
   delete ui->graphicsView->scene();
    listapaginas->clear();
    this->mpaginas=0;
    if (pagina_actual>0){
        listapaginas->append(crear_pagina(pagina_actual-1));
        this->mpaginas++;
    }

    QGraphicsScene *scenex=crear_pagina(pagina_actual);
    listapaginas->append(scenex);
    scene=scenex;
    this->mpaginas++;
    if (pagina_actual<this->cantidad_paginas){
        QGraphicsScene *sceney=crear_pagina(pagina_actual+1);
        listapaginas->append(sceney);
        this->mpaginas++;
    }
//   qDebug()<<this->cantidad_tarjetas;

   ui->graphicsView->setScene(scene);
//   qDebug()<<this->cantidad_tarjetas;
    }else{}
}
void MainWindow::pasar_pagina()
{
    try {

    if (this->modo.compare("pagina")==0){
    qDebug()<<pagina_actual<<"estoy en esta pagina";
    qDebug()<<sig_pagina<<"voy para esta pagina";
    qDebug()<<listapaginas->length()<<"paginas guardadas";
    if (this->cantidad_paginas==0){}
    else if (sig_pagina==pagina_actual){}
    else if(sig_pagina==pagina_actual+1){
        this->mpaginas=0;
        pagina_actual=sig_pagina;
//        ui->graphicsView->invalidateScene();
        scene=listapaginas->last();
        this->mpaginas++;
        this->mpaginas++;
        ui->graphicsView->setScene(scene);
        if (listapaginas->length()==3){
            qDebug()<<listapaginas->length()<<"paginas guardadas2";
            listapaginas->removeFirst();
            this->mpaginas--;
        }
        qDebug()<<listapaginas->length()<<"paginas guardadas3";
        if (pagina_actual<this->cantidad_paginas-1){
            this->mpaginas=0;
        listapaginas->append(crear_pagina(pagina_actual+1));
        this->mpaginas++;
        }
        qDebug()<<listapaginas->length()<<"paginas guardadas4";

    }
    else if(sig_pagina==pagina_actual-1){
        this->mpaginas=0;
        pagina_actual=sig_pagina;
        scene=listapaginas->first();
        this->mpaginas++;
        this->mpaginas++;
        ui->graphicsView->setScene(scene);
        if (listapaginas->length()==3){
            listapaginas->removeLast();
            this->mpaginas--;
        }
        if (pagina_actual>0){
        listapaginas->insert(0,crear_pagina(pagina_actual-1));
        this->mpaginas++;
        }
//        ui->graphicsView->invalidateScene();

    }
    else{
        listapaginas->clear();
        pagina_actual=sig_pagina;
        qDeleteAll(this->ui->graphicsView->items());
        if (pagina_actual>0){
            listapaginas->append(crear_pagina(pagina_actual-1));
            this->mpaginas++;
        }

        QGraphicsScene *scenex=crear_pagina(pagina_actual);
        listapaginas->append(scenex);
        this->mpaginas++;
        scene=scenex;
        if (pagina_actual<this->cantidad_paginas-1){
            QGraphicsScene *sceney=crear_pagina(pagina_actual+1);
            listapaginas->append(sceney);
            this->mpaginas++;
        }
//       qDebug()<<this->cantidad_tarjetas;
       ui->graphicsView->setScene(scene);
//       qDebug()<<this->cantidad_tarjetas;
    }
    }else{}
    } catch (exception e) {
      qDebug()<<"error inesperado ocurrido";
    }
}

void MainWindow::actualizar_scroll(int pagina_actual, int slide_pos)
{
    if (this->modo.compare("scroll")==0){
        if (pagina_actual==2){

        }else if(pagina_actual==1){
            this->crear_pagina_scroll();
            this->ui->graphicsView->verticalScrollBar()->setSliderPosition((this->ui->graphicsView->verticalScrollBar()->maximum()+this->ui->graphicsView->verticalScrollBar()->size().rheight())/3+slide_pos);

        }else{
            this->crear_pagina_scroll();
            this->ui->graphicsView->verticalScrollBar()->setSliderPosition(slide_pos-(this->ui->graphicsView->verticalScrollBar()->maximum()+this->ui->graphicsView->verticalScrollBar()->size().rheight())/3);

            }
        }



}

void MainWindow::crear_scroll()
{
    scene=new QGraphicsScene ();

    QStringList list=this->dataset.split(";");
    int x=0;
    int y=0;
    qDebug()<<ui->graphicsView->escala<<"de escala";
    for(int i=(this->pagina_actual-1)*this->cantidad_tarjetas+1;(i-((this->pagina_actual-1)*this->cantidad_tarjetas))<=this->cantidad_tarjetas*3;i++){


    Button *button=ButtonFactory::crear_boton(boton::tarjeta);
    if ((x+1)*220*ui->graphicsView->escala<(this->width()-18)){
        button->move(220*x,220*y);
        x++;
    }
    else{
        y++;
        x=0;
        button->move(220*x,220*y);
        x++;
    }
    QString string=list.at(i);
    button->main=this;
    button->cvdata=string;
    button->link=string.split(",").at(17);
    QString name=list.at(i).split(",").at(11);
    if (name.length()>24){
        button->setText(name.remove(25,name.length()));
    }
    else{button->setText(name);}
    button->resize(200,200);
    scene->addWidget(button);
 //   qDebug()<<list.at(i);
    }
    delete ui->graphicsView->scene();
    ui->graphicsView->setScene(scene);
    this->ui->graphicsView->verticalScrollBar()->setSliderPosition(0);
    this->mpaginas=3;
}

void MainWindow::crear_pagina_scroll()
{
    scene=new QGraphicsScene ();

    QStringList list=this->dataset.split(";");
    int x=0;
    int y=0;
    qDebug()<<ui->graphicsView->escala<<"de escala";
    for(int i=(this->pagina_actual-1)*this->cantidad_tarjetas+1;(i-((this->pagina_actual-1)*this->cantidad_tarjetas))<=this->cantidad_tarjetas*3;i++){


    Button *button=ButtonFactory::crear_boton(boton::tarjeta);
    if ((x+1)*220*ui->graphicsView->escala<this->width()){
        button->move(220*x,220*y);
        x++;
    }
    else{
        y++;
        x=0;
        button->move(220*x,220*y);
        x++;
    }
    QString string=list.at(i);
    button->main=this;
    button->cvdata=string;
    button->link=string.split(",").at(17);
    QString name=list.at(i).split(",").at(11);
    if (name.length()>24){
        button->setText(name.remove(25,name.length()));
    }
    else{button->setText(name);}
    button->resize(200,200);
    scene->addWidget(button);
 //   qDebug()<<list.at(i);
    }
    delete ui->graphicsView->scene();
    ui->graphicsView->setScene(scene);
}

void MainWindow::calcular_memoria()
{
    Button *button=new Button;
    if (this->modo.compare("todo")==0){this->mpagina=sizeof (*button)*this->cantidad_datos;}
    else {this->mpagina=sizeof (*button)*this->cantidad_tarjetas;}
}


void MainWindow::poner_botones()
{
    QLayout *layoutv=new QVBoxLayout();
    QLayout *layouth=new QHBoxLayout();
    QLayout *layouth2=new QHBoxLayout();
    QLayout *layouth3=new QHBoxLayout();
    qDebug()<<ui->groupBox->accessibleDescription().compare("tengo layout");
    if (ui->groupBox->accessibleDescription().compare("tengo layout")==0){
        qDeleteAll(ui->groupBox->children());

    }
        layoutv->addItem(layouth);
        layoutv->addItem(layouth2);
        layoutv->addItem(layouth3);
        Button *button=ButtonFactory::crear_boton(boton::pasar);
        button->main=this;
        button->setText("<");
        button->setMinimumSize(10,10);
        button->resize(40,10);
        layouth->addWidget(button);
    Button *boton1=ButtonFactory::crear_boton(boton::cambiarmodo);
    Button *boton2=ButtonFactory::crear_boton(boton::cambiarmodo);
    Button *boton3=ButtonFactory::crear_boton(boton::cambiarmodo);
    Button *boton4=ButtonFactory::crear_boton(boton::cambiarmodo);
    boton1->setText("pagina");
    boton2->setText("scroll");
    boton3->setText("todo");
    boton4->setText("mantenimiento");
    boton1->main=this;
    boton2->main=this;
    boton3->main=this;
    boton4->main=this;
    layouth2->addWidget(boton1);
    layouth2->addWidget(boton2);
    layouth2->addWidget(boton3);
    layouth2->addWidget(boton4);

    layouth->setSpacing(0);
    int i;
    for (i=1; i<this->cantidad_paginas;i++){
        if ((i+1)*40>this->width() || i+primer_boton>this->cantidad_paginas){
            Button *button=ButtonFactory::crear_boton(boton::pasar);
            button->setText(">");
            button->setMinimumSize(10,10);
            button->resize(40,10);
            button->main=this;
            layouth->addWidget(button);
            break;}
        Button *button=ButtonFactory::crear_boton(boton::pagina);
        button->setText(QString::number(i+this->primer_boton));
        button->num=i+this->primer_boton;
        button->setMinimumSize(10,10);
        button->resize(40,10);
        button->main=this;
        layouth->addWidget(button);

         }
    ui->groupBox->setAccessibleDescription("tengo layout");
    this->mbotones=sizeof(*button)*(i+4);
    layouth3->addWidget(new QLabel("pagina: "+QString::number(this->mpagina)));
    layouth3->addWidget(new QLabel("paginas: "+QString::number(this->mpagina*this->mpaginas)));
    layouth3->addWidget(new QLabel("todo: "+QString::number(this->mpagina*this->mpaginas+sizeof(*this)+this->mbotones)));
    ui->groupBox->setLayout(layoutv);

}



void MainWindow::resizeEvent(QResizeEvent *event)
{
    int dato_actual=this->pagina_actual*this->cantidad_tarjetas;
    this->calcular_tarjetas();
    int tarjetasy=((this->height()-128)/(220*this->ui->graphicsView->escala));
    int tarjetasx=((this->width()-18)/(220*this->ui->graphicsView->escala));
    int cantidad_tarjetas=tarjetasx*tarjetasy;
    if(cantidad_tarjetas==0){
        cantidad_paginas=0;

    }
    else{
        this->pagina_actual=dato_actual/cantidad_tarjetas;
    }
    if (this->modo.compare("pagina")==0){this->mostrar_paginacion();}
    else if (this->modo.compare("scroll")==0){if(pagina_actual==0){pagina_actual++;}crear_scroll();}
    else if (this->modo.compare("todo")==0){mostrar_todo();}
    this->calcular_memoria();
    this->poner_botones();


}

QGraphicsScene* MainWindow::crear_pagina(int pagina)
{


    QGraphicsScene *scenex=new QGraphicsScene();
    QStringList list=this->dataset.split(";");
qDebug()<<"tamano de i "<<pagina*this->cantidad_tarjetas+1;
    int x=0;
    int y=0;

//    qDebug()<<ui->graphicsView->escala;
    for(int i=pagina*this->cantidad_tarjetas+1;(i-(pagina*this->cantidad_tarjetas))<=this->cantidad_tarjetas;i++){        
        if (i>=this->cantidad_datos){}else{
        QString string=list.at(i);
        if (string.split(",").length()<18){
//            qDebug()<<"tamano de lista "<<list.at(i+1);
            Button *button=ButtonFactory::crear_boton(boton::tarjeta);
            button->main=this;
            button->cvdata=string;
            button->link="";
            if ((x+1)*220*ui->graphicsView->escala<(this->width()-18)){
                button->move(220*x,220*y);
                x++;
            }
            else{
                y++;
                x=0;
                button->move(220*x,220*y);
                x++;
            }


            QString name="no name";
    //        qDebug()<<i<<"en "<<pagina<<"de "<<cantidad_tarjetas;
            if (name.length()>24){
                button->setText(name.remove(25,string.length()));
            }
            else{button->setText(name);}
            button->resize(200,200);
            scenex->addWidget(button);
        }else{
        Button *button=ButtonFactory::crear_boton(boton::tarjeta);
        button->main=this;
        button->cvdata=string;
        button->link=string.split(",").at(17);
        if ((x+1)*220*ui->graphicsView->escala<(this->width()-18)){
            button->move(220*x,220*y);
            x++;
        }
        else{
            y++;
            x=0;
            button->move(220*x,220*y);
            x++;
        }


        QString name=string.split(",").at(11);
//        qDebug()<<i<<"en "<<pagina<<"de "<<cantidad_tarjetas;
        if (name.length()>24){
            button->setText(name.remove(25,string.length()));
        }
        else{button->setText(name);}
        button->resize(200,200);
        scenex->addWidget(button);
        }
    }
    }
    qDebug()<<"salgo de crear pagina";
    return scenex;

}



