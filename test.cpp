#include <QtGui>
#include <iostream>
#include "test.h"
#include "pilamatrici.h"
#include "coltura.h"
#include "mainwindow.h"
using namespace std;

bool testGrafica()
{
    MainWindow * finestra = new MainWindow();
    finestra->show();
    return true;
}

bool testPila()
{
    PilaMatrici* pila = new PilaMatrici (10, 40);
    pila->stampa();

    pila->next();
    pila->stampa();
    pila->next();
    pila->stampa();

    return true;
}
