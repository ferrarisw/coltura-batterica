#include "coltura.h"


bool Coltura::save(QString s)
{
    if(!(pila->salva(s)))
        return false;
    return true;
}


bool Coltura::load(QString s)
{

    pila->carica(s);

    ifstream fcin (s.toStdString().data());
    cout<<s.toStdString().data()<<endl;
    fcin>>x>>y;

    delete matrice;
    matrice = new int[x*2+y*2];
    matrice = pila->getMatrix();

    pila->stampa();

    GD2(cout<<"[Coltura::load] nuova matrice:"<<endl;
            for(int j=1; j<y+1; j++)
            {
                for(int i=1; i<x+1; i++)
                {
                    cout<<(matrice[i+j*(x+2)])<<" ";
                }
                cout<<endl;
            });

    setMinimumSize(3*x,3*y);

    int attuale;
    fcin>>attuale;

    timeSlider->setMaximum(attuale);
    timeSlider->setValue(attuale);

    repaint();

    return true;
}
