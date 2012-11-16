#include "main.h"
#include "QtGui"
using namespace std;

int screenX; /**< distanza dei widget dal punto 0,0*/
int screenY; /**< altezza dei widget dal punto 0,0*/


/**
 * main.
 *
 * @param argc
 * @param argv
 * @return esecuzione del programma
 *
 * Con QApplication inizializziamo le variabili d'ambiente del sistema, poi
 * creiamo un nuovo oggetto ::Starter (QMainWindow) e facciamo partire il main
 * loop del programma con exec
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDesktopWidget *d = new QDesktopWidget();
    /**** modifica di variabili globali ****/
    screenX = d->window()->width();
    screenY = d->window()->height();
    TRACE("dimensioni dello schermo"<<screenX<<"*"<<screenY);

    GD1(cout<<"[main] sto per inizializzare lo starter"<<endl);
    Starter * starter = new Starter();
    starter->show();

    return a.exec();

}

