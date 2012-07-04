#include <QtGui/QApplication>
#include "mainwindow.h"
#include "pilamatrici.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    PilaMatrici* pila = new PilaMatrici (40, 40);
    pila->stampa();
    pila->next();
    pila->stampa();
    pila->next();
    pila->stampa();
    return a.exec();
}
