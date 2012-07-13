#include "pilamatrici.h"
#include "cstdlib"
#include "ctime"
#include "main.h"
#include <iostream>
using namespace std;

PilaMatrici::PilaMatrici(int x, int y)
{
    this->dimx = x;
    this->dimy = y;

    testa = creaMatrice(NULL, NULL, 0);
    coda = testa;
    posizioneAttuale = testa;

    TRACE("Riempimento casuale dei valori nella matrice attuale.");

    riempiCasuale(posizioneAttuale);

    TRACE("Riempimento casuale completato con successo.");
}

PilaMatrici::Matrix* PilaMatrici::creaMatrice(Matrix *prec, Matrix *succ, int tempo)
{
    Matrix* temp = new Matrix;

    TRACE("Ho creato una nuova matrice allocata dinamicamente.");

    temp->succ = succ;
    temp->prec = prec;

    temp->tabella = new int[(dimx+2) * (dimy+2)];

    TRACE("Ho assegnato la matrice dinamica con le dimensioni "<<dimx);
    TRACE(" e "<<dimy<<" correttamente.")

    inizializzaTabella(temp, 0);

    temp->tempo = tempo;
    temp->rigenerabile = false;

    TRACE("Ho inizializzato a 0 tutti gli elementi della matrice e aggiornato"
          " il tempo.");

    return temp;
}

void PilaMatrici::riempiCasuale(Matrix *pos)
{
    srand( time(0) );
    int tot = 0;

    TRACE("Ora inizializzo casualmente gli elementi interni della matrice.");

    for (int j = 1; j < dimy + 1; j++)
        for (int i = 1; i < dimx + 1; i++)
        {
            int temp = ( rand() / static_cast<float> (RAND_MAX) + 0.35);
            tot += temp;
            pos->tabella[i + j * (dimx + 2)] = temp;
        }

    TRACE("Ho inizializzato tutta la matrice esclusa la cornice esterna.");
    TRACE("La somma dei valori delle caselle è "<<tot<<" (utilizzo statistico).");
}

void PilaMatrici::inizializzaTabella(Matrix *tabellaAttuale, int valore)
{
    for (int j = 0; j < (dimx + 2) * (dimy + 2); j++)
    {
        tabellaAttuale->tabella[j] = valore;
    }
}

inline int PilaMatrici::getValore (int * t, int x, int y)
{
    return ( t[x + y * (dimx + 2)] );
}

int * PilaMatrici::next()
{
    TRACE("Sto per inizializzare la prossima matrice.");

    Matrix* temp = creaMatrice(posizioneAttuale, NULL, posizioneAttuale->tempo + 1);

    TRACE("Ora inizializzo due puntatori a intero, uno alla tabella attuale\n"
          "e uno alla nuova tabella. Mi serve per semplificare il codice");

    int somma = 0;
    int * t1 = posizioneAttuale->tabella;
    int * t2 = temp->tabella;

    TRACE("Sommo tutte le 8 caselle attorno alla casella attuale.");

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

            if (somma == 2) {
                t2[i + j * (dimx + 2)]  = t1 [i + j * (dimx + 2)];
            }
            if (somma == 3)
                t2 [i + j * (dimx + 2)] = vivo;
            else if (somma < 2 || somma > 3)
                t2 [i + j * (dimx + 2)] = morto;
        }

    TRACE("Rendo la matrice appena creata, quella attuale.");

    posizioneAttuale->succ = temp;
    posizioneAttuale = temp;

    return temp->tabella;
}

void PilaMatrici::stampa()
{
    TRACE("Stampo la matrice. Questa è solo una funzione per il DBGug.");

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

bool PilaMatrici::distruggiMatrice (Matrix* matrice)
{
    if (matrice->prec == NULL) {
        testa = matrice->succ;
    } else matrice->prec->succ = matrice->succ;

    if (matrice->succ == NULL) {
        coda = matrice->prec;
    } else matrice->succ->prec = matrice->prec;

    delete matrice->tabella;
    delete matrice;

    return true;
}
