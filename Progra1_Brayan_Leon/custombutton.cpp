#include "custombutton.h"
#include "customview.h"

CustomButton::CustomButton()
{

}
void CustomButton::mousePressEvent(QMouseEvent *event){
    QGraphicsView *view=new QGraphicsView();
    view->move(0,0);
    view->setMinimumSize(700,700);
    QGraphicsScene *scene=new QGraphicsScene;
    int distance=0;
    int i=0;
    for( i=0;i<this->main->titles.split(",").length();i++){
        QLabel *label=new QLabel;
        label->setText(this->main->titles.split(",").at(i)+": "
        +this->cvdata.split(",").at(i));
        if (label->text().length()>distance){
            distance=label->text().length();
        }
        label->move(0,i*22);
        scene->addWidget(label);
    }
    qDebug()<<distance<<"de distancia";
    if (this->link.compare("")==0){}else{
        qDebug()<<link.split("/").at(4);
    QUrl url("http://www.omdbapi.com/?apikey=cf31fe72&i="+link.split("/").at(4)+"&plot=full");
        QNetworkRequest request(url);
        this->main->mManager->get(request);
            QTime dieTime= QTime::currentTime().addMSecs(1000);
            while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);
        QJsonDocument document = QJsonDocument::fromJson(this->main->data);
        QTextBrowser *label=new QTextBrowser;
        label->setText(document["Plot"].toString());
        label->move(0,i*22);
        label->setMinimumSize(distance*9,200);
        scene->addWidget(label);
//        qDebug()<<document["Plot"].toString();
        url.setUrl(document["Poster"].toString());
        request.setUrl(url);
        this->main->mManager->get(request);
        QImage imagen;
        QGraphicsPixmapItem *iten=new QGraphicsPixmapItem;
        dieTime= QTime::currentTime().addMSecs(1000);
       while (QTime::currentTime() < dieTime)
           QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);
        imagen.loadFromData(this->main->data);
//             dieTime= QTime::currentTime().addMSecs(500);
//            while (QTime::currentTime() < dieTime)
//                QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);
                iten->setPixmap(QPixmap::fromImage(imagen));
                iten->setX(distance*8);
                iten->setY(0);
                scene->addItem(iten);
    }
    view->setScene(scene);
    view->show();
    QPushButton::mousePressEvent(event);
}
