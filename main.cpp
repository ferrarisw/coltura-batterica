#include <QtGui>
#include "mainwindow.h"
#include "pilamatrici.h"
#include <iostream>
#include "coltura.h"
#include "mainwindow.h"
#include "starter.h"
#include "main.h"
#include "popup.h"

using namespace std;



//TODO widget di apertura
//TODO pulizia main
//TODO commenti
//TODO makefile
//TODO revisione classe coltura
//TODO modalita` dio        Funzione implementata ma da completare
//TODO indietro nel tempo   Funzione implementata, meglio controllarla
//TODO restart, new
//TODO barra del tempo

//Idee sulla gestione degli errori con popup, soprattutto nella modalità Dio

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GD1(cout<<"[main] sto per inizializzare lo starter"<<endl;)
    Starter * starter = new Starter();
    starter->show();

    /*
    Popup * popup = new Popup();
    popup->show();
    */

    return a.exec();
}
