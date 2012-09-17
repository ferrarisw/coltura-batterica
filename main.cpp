#include "main.h"
using namespace std;

//TODO widget di apertura
//TODO pulizia main
//TODO commenti
//TODO Documentazione       aggiornata al 22/08/2012
//TODO makefile             aggiornato e funzionante al 29/08/2012
                          //15/09/2012 non funzionante
//TODO revisione classe coltura
//TODO modalita` dio        Funzione implementata ma da completare
//TODO indietro nel tempo   Funzione implementata, meglio controllarla
//TODO restart, new
//TODO barra del tempo      Esistente ma non funzionante

//Idee sulla gestione degli errori con popup, soprattutto nella modalità Dio


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GD1(cout<<"[main] sto per inizializzare lo starter"<<endl;)
    Starter * starter = new Starter();
    starter->show();

#ifdef DEBUG_MODE
#endif
   /* Popup * popup = new Popup();
    popup->showErrorMessage(popup, "CIAO");*/

    return a.exec();
}

