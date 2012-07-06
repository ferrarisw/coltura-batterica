#include <QtGui/QApplication>
#include "mainwindow.h"
#include "pilamatrici.h"
#include "test.h"




/** Funzione setDebug().
  * Questa funzione setta a vero o falso il debug.
  *
  * @param [in]   debug   Se vero il debug è attivo
  */
void setDebug(bool);
bool DEBUG = false;


int main(int argc, char *argv[])
{
//    setDebug(false);

    QApplication a(argc, argv);


    testGrafica();

    PilaMatrici* pila = new PilaMatrici (10, 10);
    pila->stampa();
    pila->next();
    pila->stampa();
    pila->next();
    pila->stampa();


    return a.exec();
}

void setDebug(bool debug)
{
    DEBUG = debug;
}
