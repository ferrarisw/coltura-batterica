#include "main.h"

using namespace std;

//TODO pulizia main
//TODO commenti
//TODO Documentazione       aggiornata al 20/09/2012
//TODO makefile             aggiornato e funzionante al 29/08/2012
                            //15/09/2012 non funzionante
                            //20/09/2012 funzionante
//TODO revisione classe coltura

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GD1(cout<<"[main] sto per inizializzare lo starter"<<endl;)

    Starter * starter = new Starter();
    starter->show();

    return a.exec();
}

