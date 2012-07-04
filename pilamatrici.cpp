#include "pilamatrici.h"
#include "cstdlib"
#include "ctime"
#include <iostream>

using namespace std;

#define DEB(a)  {a;}

PilaMatrici::PilaMatrici(int x, int y)
{
    this->dimx = x;
    this->dimy = y;

    testa = creaMatrice(NULL, NULL);
    coda = testa;
    posizioneAttuale = testa;

    DEB(cout<<"Inizio il riempimento casuale dei valori nella matrice attuale."<<endl);

    riempiCasuale(posizioneAttuale);

    DEB(cout<<"Riempimento casuale completato con successo."<<endl);
}

PilaMatrici::Matrix* PilaMatrici::creaMatrice(Matrix *prec, Matrix *succ)
{
    Matrix* temp = new Matrix;

    DEB(cout<<"Ho creato una nuova matrice allocata dinamicamente.");

    temp->succ = succ;
    temp->prec = prec;

    temp->tabella = new int[(dimx+2) * (dimy+2)];

    DEB(cout<<"Ho assegnato la matrice dinamica con le dimensioni "<<dimx);
    DEB(cout<<" e "<<dimy<<" correttamente."<<endl);

    for (int j = 0; j < (dimy + 2) * (dimy + 2); j++)
    {
        temp->tabella[j] = 0;
    }

    DEB(cout<<"Ho inizializzato a 0 tutti gli elementi della matrice"<<endl);

    return temp;
}

void PilaMatrici::riempiCasuale(Matrix *pos)
{
    srand( time(0) );
    int tot = 0;

    DEB(cout<<"Ora inizializzo casualmente gli elementi interni della matrice"<<endl);

    for (int j = 1; j < dimy + 1; j++)
        for (int i = 1; i < dimx + 1; i++)
        {
            int temp = ( rand() / static_cast<float> (RAND_MAX) + 0.35);
            tot += temp;
            pos->tabella[i + j * (dimx + 2)] = temp;
        }

    DEB(cout<<"Ho inizializzato tutta la matrice esclusa la cornice esterna."<<endl);
    DEB(cout<<"La somma dei valori delle caselle è "<<tot<<" (utilizzo statistico)."<<endl);
}

inline int PilaMatrici::getValore (int * t, int x, int y)
{
    return ( t[x + y * (dimx + 2)] );
}

int * PilaMatrici::next()
{
    DEB(cout<<"Sto per inizializzare la prossima matrice."endl);

    Matrix* temp = creaMatrice(posizioneAttuale, NULL);

    DEB(cout<<"Ora inizializzo due puntatori a intero, uno alla tabella attuale"<<endl);
    DEB(cout<<"e uno alla nuova tabella. Mi serve per semplificare il codice"<<endl);

    int somma = 0;
    int * t1 = posizioneAttuale->tabella;
    int * t2 = temp->tabella;

    DEB(cout<<"Sommo tutte le 8 caselle attorno alla casella attuale."<<endl);

    for (int j = 1; j < dimy + 1; j++)
        for (int i = 1; i < dimx + 1; i++)
        {
            somma = ( getValore(t1, i - 1, j - 1) +
                      getValore(t1, i    , j - 1) +
                      getValore(t1, i + 1, j - 1) +
                      getValore(t1, i - 1, j    ) +
                      getValore(t1, i + 1, j    ) +
                      getValore(t1, i - 1, j + 1) +
                      getValore(t1, i    , j + 1) +
                      getValore(t1, i + 1, j + 1)
                      );

            if (somma == 3)
                t2 [i + j * (dimx + 2)] = vivo;
            else if (somma < 2 || somma > 3)
                t2 [i + j * (dimx + 2)] = morto;
        }

    DEB(cout<<"Rendo la matrice appena creata, quella attuale."<<endl);
    posizioneAttuale = temp;

    return temp->tabella;
}

void PilaMatrici::stampa()
{
    DEB(cout<<"Stampo la matrice. Questa è solo una funzione per il debug."<<endl);

    cout<<endl;
    for (int j = 0; j < dimy + 2; j++)
    {
        for (int i = 0; i < dimx + 2; i++)
        {
            cout<<getValore(posizioneAttuale->tabella, i, j)<<" ";
        } cout<<endl;
    }
    cout<<endl;
}
