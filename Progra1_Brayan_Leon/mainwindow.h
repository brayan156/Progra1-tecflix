#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include<QGraphicsItem>
#include <QGraphicsScene>
#include<QtGui>
#include <QtNetwork/QNetworkAccessManager>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void clicked(QMouseEvent *event);
    void leer_csv();
    void reajustar_paginas();
    void calcular_tarjetas();
    void mostrar_todo();
    void mostrar_paginacion();
    void poner_botones();
    void pasar_pagina();
    void actualizar_scroll(int pagina_actual,int slidepos);
    void crear_scroll();
    void crear_pagina_scroll();
    void resizeEvent(QResizeEvent *event);
    QGraphicsScene* crear_pagina(int pagina);
    int primer_boton=0;
    int pagina_actual=1;
    QString modo="scroll";
    QString dataset;
    int botones_totales;
    int cantidad_paginas;
    int sig_pagina=0;
    QByteArray data;
    QString titles;
    QNetworkAccessManager *mManager;
private:
    Ui::MainWindow *ui;
    QGraphicsItem *item;
    QGraphicsScene *scene=new QGraphicsScene;

    int cantidad_datos;
    int cantidad_tarjetas;





    QList <QGraphicsScene*> *listapaginas=new QList<QGraphicsScene*>();
};

#endif // MAINWINDOW_H
