#include "coltura.h"


bool Coltura::save(QString s)
{
    if(!(pila->salva(s)))
        return false;
    return true;
}


bool Coltura::load(QString s)
{
    if(!pila->carica(s))
        return false;

    ifstream fcin (s.toStdString().data());
    GD1(cout<<"file caricato"<<s.toStdString().data()<<endl);
    fcin>>x>>y;

    matrice = pila->getMatrix();

    GD3(pila->stampa());

    GD2(cout<<"[Coltura::load] nuova matrice:"<<endl;
            for(int j=1; j<y+1; j++)
            {
                for(int i=1; i<x+1; i++)
                {
                    cout<<(matrice[i+j*(x+2)])<<" ";
                }
                cout<<endl;
            });

    setMagnifier();

    setMinimumSize(magnifier*x,magnifier*y);
    this->resize(minimumSize());

    int attuale;
    fcin>>attuale;

    timeSlider->setMaximum(attuale);
    timeSlider->setValue(attuale);

    repaint();

    return true;
}
