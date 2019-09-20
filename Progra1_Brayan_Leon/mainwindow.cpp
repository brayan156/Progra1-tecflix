#include "customitem.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage image("indice.jpeg");
    item=new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene=new QGraphicsScene (this);
    ui->graphicsView->setScene(scene);
     Customitem *iten=new Customitem;
     iten->setPixmap(QPixmap::fromImage(image));
     iten->setX(800);
     iten->setY(800);
     scene->addItem(iten);

//     Customitem *ite;

//    Customview *view=new Customview;
//    view->setScene(scene);
//    view->resize(100,100);
//    view->move(100,100);
//    view->show();
     item->setX(0);
     item->setY(0);
    scene->addItem(item);



}

void Customitem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug()<<"item clicked";
    QGraphicsPixmapItem::mousePressEvent(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}


