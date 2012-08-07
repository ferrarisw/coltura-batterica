#include <QtGui/QApplication>
#include "mainwindow.h"
#include "pilamatrici.h"
#include "test.h"

//TODO widget di apertura
//TODO pulizia main
//TODO commenti
//TODO makefile
//TODO revisione classe coltura
//TODO modalita` dio        Funzione implementata ma da completare
//TODO indietro nel tempo   Funzione implementata, meglio controllarla

//Idee sulla gestione degli errori con popup, soprattutto nella modalità Dio

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    testGrafica();

    testPila();

    return a.exec();
}
