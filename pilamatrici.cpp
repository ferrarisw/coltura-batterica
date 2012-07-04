#include "pilamatrici.h"
#include "cstdlib"
#include "ctime"
#include <iostream>

using namespace std;

PilaMatrici::PilaMatrici(int x, int y)
{
    this->dimx = x;
    this->dimy = y;

    testa = creaMatrice(NULL, NULL);
    coda = testa;
    posizioneAttuale = testa;

    riempiCasuale(posizioneAttuale);
}

PilaMatrici::Matrix* PilaMatrici::creaMatrice(Matrix *prec, Matrix *succ)
{
    Matrix* temp = new Matrix;
    temp->succ = succ;
    temp->prec = prec;

    temp->tabella = new int[(dimx+2) * (dimy+2)];

    for (int j = 0; j < (dimy + 2) * (dimy + 2); j++)
    {
        temp->tabella[j] = 0;
    }

    return temp;
}

void PilaMatrici::riempiCasuale(Matrix *pos)
{
    srand( time(0) );
    int tot = 0;

    for (int j = 1; j < dimy + 1; j++)
        for (int i = 1; i < dimx + 1; i++)
        {
            int temp = ( rand() / static_cast<float> (RAND_MAX) + 0.35);
            cout<<temp<<endl;
            tot += temp;
            pos->tabella[i + j * (dimx + 2)] = temp;
        }

    cout<<tot<<endl;

}

inline int PilaMatrici::getValore (int * t, int x, int y)
{
    return ( t[x + y * (dimx + 2)] );
}

int * PilaMatrici::next()
{
    Matrix* temp = creaMatrice(posizioneAttuale, NULL);

    int somma = 0;
    int * t1 = posizioneAttuale->tabella;
    int * t2 = temp->tabella;

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

    posizioneAttuale = temp;

    return temp->tabella;
}

void PilaMatrici::stampa()
{
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
