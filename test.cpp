#include "test.h"
#include "pilamatrici.h"
#include "coltura.h"
#include "iostream"
#include "mainwindow.h"
#include <QtGui>
using namespace std;

bool testGrafica()
{
    MainWindow * finestra = new MainWindow();
    finestra->show();
    return true;
}

bool testPila()
{
    PilaMatrici* pila = new PilaMatrici (40, 40);
    pila->stampa();

    pila->next();
    pila->stampa();
    pila->next();
    pila->stampa();

    return true;
}
