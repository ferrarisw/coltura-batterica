#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "coltura.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void changeDimension(int);
private slots:
    void play(bool toggled);

private:
    QSlider * slider;
    Coltura * coltura;
    int dim;
    bool playing;
};

#endif // MAINWINDOW_H
