#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsItem>
#include <QGraphicsScene>
#include<QtGui>
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
private:
    Ui::MainWindow *ui;
    QGraphicsItem *item;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
