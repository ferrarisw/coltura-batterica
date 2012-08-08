#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "coltura.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(int, int, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void play(bool toggled);

private:
    QSlider * slider;
    Coltura * coltura;
    int x,y;
    bool playing;
};

#endif // MAINWINDOW_H
