#include <QtGui/QApplication>
#include "mainwindow.h"
#include "pilamatrici.h"
#include "test.h"

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

    testGrafica();

    testPila();

    return a.exec();
}
