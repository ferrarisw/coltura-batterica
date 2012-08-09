#ifndef STARTER_H
#define STARTER_H

#include <QWidget>
#include <QtGui>
#include "mainwindow.h"

class Starter : public QWidget
{
    Q_OBJECT
public:
    explicit Starter(QWidget *parent = 0);
private:
    MainWindow * mainwindow;
    int x;
    int y;


signals:
    
public slots:
    void avvio();
    void changeXDimension(int);
    void changeYDimension(int);
};

#endif // STARTER_H
