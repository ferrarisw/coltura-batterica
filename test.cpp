#include "test.h"
#include "pilamatrici.h"

bool testGrafica()
{
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
