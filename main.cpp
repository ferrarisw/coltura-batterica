#include "main.h"

using namespace std;

int screenX = 500;
int screenY = 250;

//TODO pulizia main
//TODO commenti
//TODO revisione classe coltura

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GD1(cout<<"[main] sto per inizializzare lo starter"<<endl);
    Starter * starter = new Starter();
    starter->show();

    return a.exec();

}

