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
    this->mostrar_paginacion();
    ui->groupBox->setAccessibleDescription("no tengo layout");
    this->poner_botones();
//    QImage image("indice.jpeg");
//    image = image.scaled(200, 200);
//    item=new QGraphicsPixmapItem(QPixmap::fromImage(image));
//    item->update(item->x(),item->y(),100,100);
    ui->graphicsView->main=this;
     Customitem *iten=new Customitem;




//     Customitem *ite;

//    Customview *view=new Customview;
//    view->setScene(scene);
//    view->resize(100,100);
//    view->move(100,100);
//    view->show();
//     item->setX(0);
//     item->setY(0);
//    scene->addItem(item);
    QImage imagen;
    QPixmap pixmap;




     mManager = new QNetworkAccessManager(this);
     connect(mManager, &QNetworkAccessManager::finished, this,[&] (QNetworkReply *reply)
     {
            data=reply->readAll();
            reply->deleteLater();
            QString str =QString::fromLatin1(data);
//            std::cout<<str.toStdString()<<std::endl;
//            QJsonDocument document = QJsonDocument::fromJson(data);

//                if(document.isObject()){
//                    QJsonObject valuesO = document.object();

//                    for(auto key: valuesO.keys()){
//                        qDebug()<<key<<" : "<<valuesO[key].toString();
//                    }



//                }

//            imagen.loadFromData(data);
//            QFile file("/home/brayan/myImage.jpeg");
//            file.open(QIODevice::WriteOnly);
//            file.write((data));
//            file.close();






             });

//    QUrl url("https://thumbs.dreamstime.com/b/manos-que-sostienen-la-tierra-azul-en-la-nube-y-el-cielo-elementos-de-este-imag-61052787.jpg");



//    QUrl url("http://www.omdbapi.com/?apikey=cf31fe72&i=tt0378407&plot=full");
//    QNetworkRequest request(url);
//    mManager->get(request);


//    QTime dieTime= QTime::currentTime().addMSecs(500);
//    while (QTime::currentTime() < dieTime)
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);
//        iten->setPixmap(QPixmap::fromImage(imagen));
//        iten->setX(800);
//        iten->setY(800);

//        scene->addItem(iten);

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

//        for (std::string dato; std::getline(registro, dato, ','); )
//        {
//            std::cout << dato << '\n';

//        }

//        std::cout << '\n';
    }
    cantidad_datos--;
    std::cout<<cantidad_datos;
    this->dataset=string.c_str();




}

void MainWindow::calcular_tarjetas()
{
    cantidad_tarjetas=(this->width()/(220*this->ui->graphicsView->escala))*(this->height()/(220*this->ui->graphicsView->escala));
    if(cantidad_tarjetas==0){
        cantidad_paginas=0;

    }
    else{
        cantidad_paginas=cantidad_datos/cantidad_tarjetas;
        this->botones_totales=this->width()/40;
        if (this->primer_boton>this->cantidad_paginas){
            primer_boton=this->cantidad_paginas-this->botones_totales;
        }
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
   for(int i=1;i<=this->cantidad_datos/100;i++){


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

   QString string=list.at(i).split(",").at(11);
   if (string.length()>24){
       button->setText(string.remove(25,string.length()));
   }
   else{button->setText(string);}
   button->resize(200,200);
   scene->addWidget(button);
//   qDebug()<<list.at(i);
   }
   delete ui->graphicsView->scene();
   ui->graphicsView->setScene(scene);

//   Customitem *iten;
//   iten->
//   iten->setX(800);
//   iten->setY(800);

//   scene->addItem(iten);

   }
}


void MainWindow::mostrar_paginacion()
{
    if (this->modo.compare("pagina")==0){
   delete ui->graphicsView->scene();
    listapaginas->clear();
    if (pagina_actual>0){
        listapaginas->append(crear_pagina(pagina_actual-1));
    }

    QGraphicsScene *scenex=crear_pagina(pagina_actual);
    listapaginas->append(scenex);
    scene=scenex;
    if (pagina_actual<this->cantidad_paginas){
        QGraphicsScene *sceney=crear_pagina(pagina_actual+1);
        listapaginas->append(sceney);
    }
   qDebug()<<this->cantidad_tarjetas;

   ui->graphicsView->setScene(scene);
   qDebug()<<this->cantidad_tarjetas;
    }else{}
}
void MainWindow::pasar_pagina()
{
    if (this->modo.compare("pagina")==0){
    qDebug()<<pagina_actual<<"estoy en esta pagina";
    qDebug()<<sig_pagina<<"voy para esta pagina";
    qDebug()<<listapaginas->length()<<"paginas guardadas";
    if (this->cantidad_paginas==0){}
    else if (sig_pagina==pagina_actual){}
    else if(sig_pagina==pagina_actual+1){
        pagina_actual=sig_pagina;
//        ui->graphicsView->invalidateScene();
        scene=listapaginas->last();
        ui->graphicsView->setScene(scene);
        if (listapaginas->length()==3){
            qDebug()<<listapaginas->length()<<"paginas guardadas2";
            listapaginas->removeFirst();
        }
        qDebug()<<listapaginas->length()<<"paginas guardadas3";
        listapaginas->append(crear_pagina(pagina_actual+1));
        qDebug()<<listapaginas->length()<<"paginas guardadas4";

    }
    else if(sig_pagina==pagina_actual-1){

        pagina_actual=sig_pagina;
        scene=listapaginas->first();
        ui->graphicsView->setScene(scene);
        if (listapaginas->length()==3){
            listapaginas->removeLast();
        }
        if (pagina_actual>0){
        listapaginas->insert(0,crear_pagina(pagina_actual-1));
        }
//        ui->graphicsView->invalidateScene();

    }
    else{
        listapaginas->clear();
        pagina_actual=sig_pagina;
        qDeleteAll(this->ui->graphicsView->items());
        if (pagina_actual>0){
            listapaginas->append(crear_pagina(pagina_actual-1));
        }

        QGraphicsScene *scenex=crear_pagina(pagina_actual);
        listapaginas->append(scenex);
        scene=scenex;
        if (pagina_actual<this->cantidad_paginas){
            QGraphicsScene *sceney=crear_pagina(pagina_actual+1);
            listapaginas->append(sceney);
        }
       qDebug()<<this->cantidad_tarjetas;
       ui->graphicsView->setScene(scene);
       qDebug()<<this->cantidad_tarjetas;
    }
    }else{}
}

void MainWindow::poner_botones()
{
    QLayout *layoutv=new QVBoxLayout();
    QLayout *layouth=new QHBoxLayout();
    QLayout *layouth2=new QHBoxLayout();
    qDebug()<<ui->groupBox->accessibleDescription().compare("tengo layout");
    if (ui->groupBox->accessibleDescription().compare("tengo layout")==0){
        qDeleteAll(ui->groupBox->children());

    }
        layoutv->addItem(layouth);
        layoutv->addItem(layouth2);
        Button *button=ButtonFactory::crear_boton(boton::pasar);
        button->main=this;
        button->setText("<");
        button->setMinimumSize(10,10);
        button->resize(40,10);
        layouth->addWidget(button);
    Button *boton1=ButtonFactory::crear_boton(boton::cambiarmodo);
    Button *boton2=ButtonFactory::crear_boton(boton::cambiarmodo);
    Button *boton3=ButtonFactory::crear_boton(boton::cambiarmodo);
    boton1->setText("pagina");
    boton2->setText("scroll");
    boton3->setText("todo");
    boton1->main=this;
    boton2->main=this;
    boton3->main=this;
    layouth2->addWidget(boton1);
    layouth2->addWidget(boton2);
    layouth2->addWidget(boton3);

    layouth->setSpacing(0);
    for (int i=1; i<this->cantidad_paginas;i++){
        if ((i+1)*40>this->width() || i+primer_boton==this->cantidad_paginas){
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
    ui->groupBox->setLayout(layoutv);

}



void MainWindow::resizeEvent(QResizeEvent *event)
{
    if (this->modo.compare("pagina")==0){mostrar_paginacion();}
    else if (this->modo.compare("scroll")==0){}
    else if (this->modo.compare("todo")==0){mostrar_todo();}
   this->calcular_tarjetas();
   this->poner_botones();
}

QGraphicsScene* MainWindow::crear_pagina(int pagina)
{
    QGraphicsScene *scenex=new QGraphicsScene();
    QStringList list=this->dataset.split(";");
    int x=0;
    int y=0;
//    qDebug()<<ui->graphicsView->escala;
    for(int i=pagina*this->cantidad_tarjetas+1;(i-(pagina*this->cantidad_tarjetas))<=this->cantidad_tarjetas;i++){
        QString string=list.at(i);
        Button *button=ButtonFactory::crear_boton(boton::tarjeta);
        button->main=this;
        button->cvdata=string;
        button->link=string.split(",").at(17);
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


        QString name=string.split(",").at(11);
        qDebug()<<i<<"en "<<pagina<<"de "<<cantidad_tarjetas;
        if (name.length()>24){
            button->setText(name.remove(25,string.length()));
        }
        else{button->setText(name);}
        button->resize(200,200);
        scenex->addWidget(button);
    }
    qDebug()<<"salgo";
    return scenex;
}



