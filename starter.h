#ifndef STARTER_H
#define STARTER_H

#include <QWidget>
#include <QtGui>
#include "mainwindow.h"

class Starter : public QWidget
{
    Q_OBJECT
public:
    explicit Starter(QPaintEvent * event, QWidget *parent = 0);
    explicit Starter(QWidget *parent = 0);
private:
    MainWindow * mainwindow;
    int dim;


signals:
    
public slots:
    void avvio();
    void changeDimension(int);
};

#endif // STARTER_H