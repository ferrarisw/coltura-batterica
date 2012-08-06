#include <QtGui/QApplication>
#include "mainwindow.h"
#include "pilamatrici.h"
#include <iostream>
#include "coltura.h"
#include "mainwindow.h"
#include "starter.h"
using namespace std;



//TODO widget di apertura
//TODO pulizia main
//TODO commenti
//TODO makefile
//TODO revisione classe coltura
//TODO modalita` dio
//TODO indietro nel tempo

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Starter * starter = new Starter();
    starter->show();

    MainWindow * finestra = new MainWindow();
    finestra->show();

    return a.exec();
}
