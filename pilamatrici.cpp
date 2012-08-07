#include <iostream>
#include <ctime>
#include <cstdlib>
#include "pilamatrici.h"
#include "main.h"
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

    memoriaOccupata = (sizeof(Matrix) + sizeof(int)*dimx*dimy);
    matriciRealizzate = 0;
}

PilaMatrici::Matrix* PilaMatrici::creaMatrice(Matrix *prec, Matrix *succ, int tempo)
{
    Matrix* temp = new Matrix;

    TRACE("Ho creato una nuova matrice allocata dinamicamente.");

    temp->succ = succ;
    temp->prec = prec;

    temp->tabella = new int[(dimx+2) * (dimy+2)];

    TRACE("Ho assegnato la matrice dinamica con le dimensioni "<<dimx<<
          " e "<<dimy<<" correttamente.")

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
            int temp = ( rand() / static_cast<float> (RAND_MAX) + 0.5);
            tot += temp;
            pos->tabella[i + j * (dimx + 2)] = temp;
        }

    TRACE("Ho inizializzato tutta la matrice esclusa la cornice esterna.");
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
                t2[i + j * (dimx + 2)] = t1 [i + j * (dimx + 2)];
            }
            if (somma == 3)
                t2 [i + j * (dimx + 2)] = vivo;
            else if (somma < 2 || somma > 3)
                t2 [i + j * (dimx + 2)] = morto;
        }

    TRACE("Rendo la matrice appena creata, quella attuale.");

    /*
      * Aggiorno i puntatori della matrice attuale e quella successiva.
      * Aggiorno il tempo della nuova matrice.
      */
    posizioneAttuale->succ = temp;
    temp->prec = posizioneAttuale;
    temp->tempo = (posizioneAttuale->tempo + 1);

    posizioneAttuale = temp;

    int numeroCelluleVive = contaCelluleVive(posizioneAttuale);
    int numeroCelluleVivePrecedente = contaCelluleVive(posizioneAttuale->prec);

    incrementaMemoriaOccupata(memoriaOccupata, (sizeof(Matrix) + dimx*dimy*sizeof(int)));

    LOG("Il numero di cellule vive e': " << numeroCelluleVive << " / " << dimx * dimy << ". "
        "( " << (numeroCelluleVive * 100 / (dimx*dimy) ) << "% )\n"
        "La memoria occupata dalle matrici fino ad ora e': " << ( memoriaOccupata / 1000 ) << " KB.\n"
        "Questa e' la matrice numero: " << posizioneAttuale->tempo << "\n"
        "Confronto con la matrice precedente: " << ( numeroCelluleVive * 100 / numeroCelluleVivePrecedente ) - 100 << "%\n" );

    /*
      * Ritorno la nuova posizione attuale, appena aggiornata. Prima era next.
      */
    return posizioneAttuale->tabella;
}

void PilaMatrici::stampa()
{
    GD3(cout<<"Stampo la matrice. Questa è solo una funzione per il DBGug.";

    for (int j = 0; j < dimy + 2; j++)
    {
        for (int i = 0; i < dimx + 2; i++)
        {
            cout<<getValore(posizioneAttuale->tabella, i, j)<<" ";
        } cout<<endl;
    }
    cout<<endl;
    );  //Fine di GD3
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

int PilaMatrici::incrementaMemoriaOccupata(int & memoriaOccupata, int valore)
{
    TRACE("Incremento la memoria occupata.")
    memoriaOccupata += valore;
    TRACE("Memoria incrementata.")
    return memoriaOccupata;
}

int PilaMatrici::contaCelluleVive(Matrix* & matrice)
{
    matrice->numeroCelleVive = 0;

    for (int j = 0; j < (dimx + 2) * (dimy + 2); j++)
    {
        if (matrice->tabella[j] == vivo)
            matrice->numeroCelleVive++;
    }
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

//TODO Controllare funzione viaggioNelTempo
PilaMatrici::Matrix* PilaMatrici::viaggioNelTempo(Matrix* attuale, int tempoDesiderato)
{
    /*
      * Se il tempo desiderato è maggiore o uguale al tempo della matrice
      * attuale, allora ritorno la matrice attuale
      */
    if (attuale->tempo == tempoDesiderato || tempoDesiderato < 0)
        return attuale;

    if (attuale->tempo < tempoDesiderato) {
        if (tempoDesiderato > matriciRealizzate)
            return attuale;

        else if (tempoDesiderato <= matriciRealizzate)
            return viaggioNelTempo(attuale->succ, tempoDesiderato);
    }

    if (attuale->tempo > tempoDesiderato)
        return viaggioNelTempo(attuale->prec, tempoDesiderato);

    return attuale;
}

/*
  * L'idea è quella di utilizzare una modalità godMode. Questa è disabilitata
  * di default, ma può essere attivata tramite l'apposito pulsante.
  * Quando questa è attivata, la riproduzione termina e possiamo modificare la
  * matrice che vediamo. La presenza di due funzioni ne prevede una che assegna
  * un valore specifico alla variabile booleana godModeActivity, l'altra invece
  * assegna il valore opposto a quello già attivo (se falso diventa vero e vice
  * versa).
  * La funzione godMode() viene invocata solo se la godModeActivity è vera e,
  * una volta terminata, setta a falso godModeActivity, così da poter riprendere
  * la riproduzione dalla matrice modificata.
  */
int godModeActivityChanges(bool & godModeActivity, bool value)
{
    godModeActivity = value;
    return godModeChangesActivitySucc;
}

int godModeActivityChanges(bool & godModeActivity)
{
    if (godModeActivity == false)
        godModeActivity = true;
    else godModeActivity = false;

    return godModeChangesActivitySwitched;
}

inline int PilaMatrici::godMode (Matrix* & matriceDaModificare, int cellaDaModificare, int valoreDaAssegnare)
{
    /*
      * Generalmente la matrice da modificare è quella attuale, quindi dovrebbe
      * per lo meno esistere, però questa implementazione estende la funzione
      * a più utilizzi, per esempio la modifica di tabelle precedenti o future
      * a quella attuale (sempre ammesso che esistano).
      */

    if (matriceDaModificare->tempo < 0 || matriceDaModificare->tempo > matriciRealizzate)
        return notExistingMatrix;

    if (cellaDaModificare > (dimx * dimy))
        return cellsNumberOverflow;



    /*
      * In questo caso non apparirà un popup di errore, ma verrà aggiornata
      * la grafica per visualizzare la tabella modificata.
      */
    matriceDaModificare->tabella[cellaDaModificare] = valoreDaAssegnare;
    return changesOccurred;
}
