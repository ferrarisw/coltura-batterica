#include "main.h"

using namespace std;


//TODO pulizia main
//TODO commenti
//TODO revisione classe coltura
qreal x=500;
qreal y=250;
qreal width=20;
qreal height=10;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GD1(cout<<"[main] sto per inizializzare lo starter"<<endl;)

    Starter * starter = new Starter();
    starter->show();

    return a.exec();
}

