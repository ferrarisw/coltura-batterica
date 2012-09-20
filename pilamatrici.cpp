#include "pilamatrici.h"

using namespace std;

PilaMatrici::PilaMatrici(int x, int y, int pattern)
{
    assert(x > 0);
    assert(y > 0);

    this->dimx = x;
    this->dimy = y;

    testa = creaMatrice(NULL, NULL, 0);
    coda = testa;
    posizioneAttuale = testa;

    patternModeSelector(pattern);

    TRACE("[PilaMatrici::PilaMatrici] PatternMode Selezionata.");

    matriciRealizzate = 0;
}

PilaMatrici::~PilaMatrici()
{
    if (posizioneAttuale->tempo != 0) {
        posizioneAttuale = posizioneAttuale->prec;
        for (; posizioneAttuale->tempo <= 0; posizioneAttuale = posizioneAttuale->prec) {
            delete posizioneAttuale->succ->tabella;
            delete posizioneAttuale->succ;
        }
    } else if (posizioneAttuale->tempo == 0) {
        delete posizioneAttuale->tabella;
        delete posizioneAttuale;
    }

}

PilaMatrici::Matrix* PilaMatrici::creaMatrice(Matrix *prec, Matrix *succ, int tempo)
{
    Matrix* temp = new Matrix;

    TRACE("[PilaMatrici::creaMatrice] Ho creato una nuova matrice allocata dinamicamente.");

    temp->succ = succ;
    temp->prec = prec;

    temp->tabella = new int[(dimx+2) * (dimy+2)];

    TRACE("[PilaMatrici::creaMatrice] Ho assegnato la matrice dinamica con le dimensioni "<<dimx<<
          " e "<<dimy<<" correttamente.")

    inizializzaTabella(temp, 0);

    temp->tempo = tempo;

    TRACE("[PilaMatrici::creaMatrice] Ho inizializzato a 0 tutti gli elementi della matrice e aggiornato"
          " il tempo.");

    return temp;
}

int* PilaMatrici::getMatrix()
{
    return posizioneAttuale->tabella;
}

void PilaMatrici::riempiCasuale(Matrix *pos)
{
    srand( time(0) );
    int tot = 0;

    TRACE("[PilaMatrici::riempiCasuale] Ora inizializzo casualmente gli elementi interni della matrice.");

    for (int j = 1; j < dimy + 1; j++)
        for (int i = 1; i < dimx + 1; i++)
        {
            int temp = ( rand() / static_cast<float> (RAND_MAX) + 0.5);
            tot += temp;
            pos->tabella[i + j * (dimx + 2)] = temp;
        }

    TRACE("[PilaMatrici::riempiCasuale] Ho inizializzato tutta la matrice esclusa la cornice esterna.");
}

void PilaMatrici::inizializzaTabella(Matrix *tabellaAttuale, int valore)
{
    for (int j = 0; j < (dimx + 2) * (dimy + 2); j++)
    {
        tabellaAttuale->tabella[j] = valore;
    }
}

inline bool PilaMatrici::inizializzaCasella(Matrix *tabellaAttuale, int casella, int valore)
{
    if (casella > (dimx + 2) * (dimy + 2) || casella < 0)
        return false;
    else tabellaAttuale->tabella[casella] = valore;
    return true;
}

inline int PilaMatrici::getValore(int * t, int x, int y)
{
    return ( t[x + y * (dimx + 2)] );
}

int * PilaMatrici::next()
{
    TRACE("[PilaMatrici::next] Sto per inizializzare la prossima matrice.");

    Matrix* temp = creaMatrice(posizioneAttuale, NULL, posizioneAttuale->tempo + 1);
    matriciRealizzate += 1;

    TRACE("[PilaMatrici::next] Ora inizializzo due puntatori a intero, uno alla tabella attuale\n"
          "e uno alla nuova tabella. Mi serve per semplificare il codice");

    int somma = 0;
    int * t1 = posizioneAttuale->tabella;
    int * t2 = temp->tabella;

    TRACE("[PilaMatrici::next] Sommo tutte le 8 caselle attorno alla casella attuale.");

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
                t2[i + j * (dimx + 2)] = t1 [i + j * (dimx + 2)];
            }
            if (somma == 3) {
                t2 [i + j * (dimx + 2)] = vivo;
            }
            else if (somma < 2 || somma > 3) {
                t2 [i + j * (dimx + 2)] = morto;
            }
        }

    TRACE("[PilaMatrici::next] Rendo la matrice appena creata, quella attuale.");

    /*
      * Aggiorno i puntatori della matrice attuale e quella successiva.
      * Aggiorno il tempo della nuova matrice.
      */
    posizioneAttuale->succ = temp;
    temp->prec = posizioneAttuale;
    temp->tempo = (posizioneAttuale->tempo + 1);


    double numeroCelluleVive = static_cast<double> ( contaCelluleVive(temp) );
    double numeroCelluleVivePrecedente = static_cast<double> ( contaCelluleVive(posizioneAttuale) );

    assert(numeroCelluleVive >= 0);

    posizioneAttuale = temp;

    LOG("Il numero di cellule vive e': " << numeroCelluleVive << " / " << dimx * dimy << ". "
        "( " << (numeroCelluleVive * 100 / (dimx*dimy) ) << " % )\n"
        "Questa e' la matrice numero: " << posizioneAttuale->tempo << "\n"
        "Confronto con la matrice precedente: " << numeroCelluleVive - numeroCelluleVivePrecedente << " ("
        << ( numeroCelluleVive * 100 / numeroCelluleVivePrecedente ) - 100 << " % )"<<endl );

    /*
      * Ritorno la nuova posizione attuale, appena aggiornata. Prima era next.
      */
    return posizioneAttuale->tabella;
}

void PilaMatrici::stampa()
{
    cout<<"[PilaMatrici::stampa] Stampo la matrice. Questa è solo una funzione per il DBGug.\n";

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

int PilaMatrici::contaCelluleVive(Matrix* & matrice)
{
    matrice->numeroCelleVive = 0;

    for (int j = 0; j < (dimx + 2) * (dimy + 2); j++)
    {
        if (matrice->tabella[j] == vivo)
            matrice->numeroCelleVive++;
    }
    assert (matrice->numeroCelleVive >= 0);
    return matrice->numeroCelleVive;
}

bool PilaMatrici::verificaMatriciUguali(Matrix* tabellaAttuale, Matrix* tabellaConfronto)
{
    if (tabellaAttuale->tempo == 0 || tabellaAttuale->tempo < tabellaConfronto->tempo)
        return false;

    for (int i = 0; i < (dimx + 2) * (dimy + 2); i++)
    {
        if (tabellaAttuale->tabella[i] != tabellaConfronto->tabella[i])
            return false;
    }
    return true;
}

bool PilaMatrici::timeTrip(int tempoDesiderato)
{
    /*
      * Se il tempo desiderato è maggiore della matrice attuale, allora....
      */
    if (posizioneAttuale->tempo < tempoDesiderato) {
        if (posizioneAttuale->succ == NULL) {
            return false;
        }
        posizioneAttuale = posizioneAttuale->succ;
        return timeTrip(tempoDesiderato);
    }

    /*
      * Se il tempo desiderato è maggiore di 0 (controllo precedente) e minore
      * del tempo attuale, allora la matrice esiste e aggiorno la matrice attuale
      * a quella precedente fino a che non arrivo alla condizione in cui il
      * tempo desiderato è uguale al tempo attuale.
      */
    else if (posizioneAttuale->tempo > tempoDesiderato) {
        if (posizioneAttuale->prec == NULL) {
            return false;
        }
        posizioneAttuale = posizioneAttuale->prec;
        return timeTrip(tempoDesiderato);
    }

    return true;
}

void PilaMatrici::patternModeSelector(int selector)
{
    switch (selector) {
    case 0:
        inizializzaTabella(posizioneAttuale, 0);
        riempiCasuale(posizioneAttuale);
        break;

    case 1:
        pattern1();
        break;

    case 2:
        pattern2();
        break;

    case 3:
        pattern3();
        break;

    case 4:
        pattern4();
        break;

        /*
          * Questo caso serve per quando carico la matrice dal file.
          * Invocando di nuovo il costruttore, devo garantire che la selezione
          * del pattern non modifichi la matrice caricata, altrimenti non
          * servirebbe più a nulla.
          */
    case 99:
        break;

    default:
        cout<<"[patternModeSelector] errore: numero pattern non corretto "<<selector<<endl;
        exit(-1);
    }
}

void PilaMatrici::pattern1()
{
    for (int j = 0; j < (dimx + 2) * (dimy + 2); ) {
        posizioneAttuale->tabella[j] = 1;
        j += 2;
    }
}

void PilaMatrici::pattern2()
{
    for (int j = 0; j < (dimx + 2) * (dimy + 2); ) {
        posizioneAttuale->tabella[j] = 1;
        j += (dimx + 1);
    }

    for (int j = 0; j < (dimx + 2) * (dimy + 2); ) {
        posizioneAttuale->tabella[j] = 1;
        j += (dimx + 3);
    }
}

void PilaMatrici::pattern3()
{
    for (int i = 0; (i + 15) < (dimx + 2) * (dimy + 2); ) {
        posizioneAttuale->tabella[i] = 1;
        posizioneAttuale->tabella[i + 15] = 1;
        i += 4;
    }
}

void PilaMatrici::pattern4()
{
    for (int i = ((dimx + 2) * (dimy + 2) / 2 ) - (dimx / 2) , j = 0;
         j < dimx;
         i++, j++) {
        posizioneAttuale->tabella[i] = 1;
    }
}
