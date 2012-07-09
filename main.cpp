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
    setDebug(true);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    testPila();

    return a.exec();
}

void setDebug(bool debug)
{
    DEBUG = debug;
}
