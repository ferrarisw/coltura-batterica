#include <QtGui/QApplication>
#include "mainwindow.h"
#include "pilamatrici.h"
#include "test.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    testGrafica();

    return a.exec();
}
