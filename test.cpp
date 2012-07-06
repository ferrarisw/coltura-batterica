#include "test.h"
#include "pilamatrici.h"
#include "cella.h"
#include "coltura.h"
#include "iostream"
using namespace std;

bool testGrafica()
{
    int x=40,y=40;

    PilaMatrici* pila=new PilaMatrici (x,y);

    int * prova=pila->next();
    //ho una matrice 10x10 costituita da un array singolo. modalita` di accesso: j+(i*x)

    pila->stampa();

    Coltura *coltura=new Coltura(x,y,prova);
    coltura->show();


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
