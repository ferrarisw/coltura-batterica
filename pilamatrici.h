#ifndef PILAMATRICI_H
#define PILAMATRICI_H

#include <QtGui>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "main.h"
using namespace std;

/** La parte pubblica contiene:
        - Un costruttore e un decostruttore per la pila di matrici
        - Una funzione next che crea la prossima matrice apportando le giuste
            modifiche in base alla matrice precedente.
        - Una funzione stampa con funzionalita' di Debug.
        - Due funzioni getDimx e getDimy che ritornano la dimensione sull'asse
            x e y della matrice.
        - Una funzione Salva e una Carica per gestire i file.
        - Una funzione timeTrip che permette di passare a matrici precedenti o successive

    @brief The PilaMatrici class
  */

class PilaMatrici
{
public:
    /**
     * @brief PilaMatrici costruttore
     *
     * Il costruttore inizializza una nuova matrice settando opportunamente tutti
     * i puntatori e il pattern da applicarvi.
     *
     * @param x La larghezza della matrice
     * @param y L'altezza della matrice
     * @param pattern Il pattern da applicare alla matrice
     */
    PilaMatrici(int x, int y, int pattern);

    /**
     * @brief PilaMatrici decostruttore
     *
     *Il decostruttore controlla a che punto della lista di matrici e' la
     *posizione attuale. Se e' maggiore di zero, allora sposta la posizione
     *attuale alla matrice precedente per non perdere l'aggancio alla lista
     *ed elimina iterativamente la matrice posizione attuale dell'iterazione
     *precedente.
     *Se il primo controllo non ha successo, si verifica il caso in cui la
     *posizione attuale sia l'ultima matrice della lista. In questo caso posso
     *deallocare dalla memoria dinamica tutti gli oggetti allocati senza problemi
     *di pending pointer.
     */
    ~PilaMatrici();

    /**
     * @brief Per ottenere la tabella attuale
     * @return Ritorna un puntatore ad intero
     */
    int * getMatrix();

    /**
     *Questa funzione non prende in ingresso alcun parametro perche' utilizza
      cio' che e' gia'  inizializzato nella classe.
      1)    Inizializza una nuova matrice dinamica come posizioneAttuale e
      setta il puntatore alla prossima matrice a NULL.
      2)    Inizializza un intero somma per eseguire il calcolo dell'algoritmo
      e inizializza anche due puntatori a intero, uno per la tabella temp appena
      creata (posizioneAttuale->tabella) e uno alla tabella temporanea
      (temp->tabella) per semplificare e rendere leggibile il codice.
      3)    Tramite la funione getValore, acquisisce e somma il valore di
      tutte le 8 caselle attorno alla casella corrente (si fa un'iterazione
      su ogni casella con un doppio ciclo for).
      L'algoritmo prevede che se una cellula e' morta e ve ne sono 3 vive intorno
      questa prende vita, al contrario, se la cellula e' viva e ce ne sono piu'
      di 3 o meno di 2 questa muore. Semplicemente sommando i valori delle
      cellule attorno alla cellula attuale ottengo il numero di cellule vive.
      Se le cellule vive sono 3 allora la cellula e' viva, altrimenti morta.
      Questo si puu' realizzare con due semplici controlli.
      4)    Dopo aver modificato completamente la tabella temp, setta la
      posizioneAttuale a temp, cosi' da ritornare la nuova tabella appena creata.

      @brief    Premette di avanzare alla matrice successiva
      @return   temp->tabella   La tabella appena modificata
      */
    int * next();

    /**
     * @brief Stampa su stdout l'intera tabella
     * @return void
     */
    void stampa ();

    /**
     * @brief Ritorna la dimensione orizzontale della matrice
     * @return dimx
     */
    int getDimx() { return dimx;}

    /**
     * @brief Ritorna la dimensione verticale della matrice
     * @return dimy
     */
    int getDimy() { return dimy;}

    /**
     * @brief Salvataggio su File della matrice
     * @param File Nome del file su cui salvare
     * @return True se il salvataggio termina correttamente
     * @return False se l'input stream non si apre correttamente
     *
     *La funzione utilizza la QString passatagli per argomento come
     *percorso e il nome del file da salvare.
     *Salva le dimensioni della matrice, il numero della matrice
     *e l'intera tabella.
     *Ritorna true se la funzione termina correttamente, falso se
     *lo stream in uscita non viene creato correttamente.
     */
    bool salva (QString file);

    /**
     * @brief Caricamento da File della matrice
     * @param File Nome del file da caricare
     * @return True se la carica e' avvenuta correttamente
     * @return False se l'output stream non si apre correttamente
     *
     *La funzione apre uno stream in input utilizzando come file
     *la QString passata per argomento. Dopo aver caricato le dimensioni
     *la funzione crea una nuova lista di matrici con le opportune
     *inizializzazioni e carica l'intera matrice di input.
     *Il valore di ritorno e' true se la carica si conclude con successo
     *e false se lo stream in input non viene creato correttamente.
     */
    bool carica (QString file);

    /**
     * @brief Numero di matrici realizzate (utilita' statistica)
     *
     *Questa e' una variabile statistica
     */
    int matriciRealizzate;

    /**
     * @brief Viaggio nel tempo
     * @return True se il viaggio nel tempo termina correttamente
     * @return False se il tempo desiderato passato per argomento non rispetta
     *le condizioni di esistenza
     *
     *La funzione controlla che il tempo desiderato sia nel range delle matrici
     *realizzate. In tal caso valuta se deve andare avanti o indietro nella lista.
     *Lo spostamento avviene tramite i puntatori della lista e chiamate ricorsive.
     *Nel caso i controlli di esistenza della matrice richiesta diano errore, la
     *funzione ritorna falso.
     */
    bool timeTrip(int);

private:

    int dimx;   //Dimensioni della matrice
    int dimy;
    int pattern;
    enum stato {morto = 0, vivo = 1};

    /**
     * @brief The Matrix struct
     *
     * La struttura matrice e' ciò su cui si basa la parte computazionale del
     * programma. Contiene un puntatore ad interi che rappresenta la tabella,
     * due puntatori a Matrix per collegare ogni oggetto in una lista doppia,
     * un tempo caratteristico di ogni matrice e il numero di cellule vive.
     */
    struct Matrix {
        int* tabella;
        Matrix* succ;
        Matrix* prec;
        int tempo;
        int numeroCelleVive;
    };

    /*
      * Due puntatori, uno alla testa e uno alla coda della lista di matrici
      * Un puntatore alla matrice attuale
      */
    Matrix* testa;
    Matrix* coda;
    Matrix* posizioneAttuale;

    /* Funzione creaMatrice().

      1)    Alloca dinamicamente una matrice temporanea delle dimensioni passate
      dall'utente.
      2)    Aggancia la matrice allocata dinamicamente alle due matrici passate come
      parametro.
      3)    Inizializza il campo tabella della matrice creata, le dimensioni sono
      maggiorate di 2 perche' creo anche una cornice aggiuntiva di zeri utile
      all'algoritmo nella sua esecuzione.
      4)    Inizializza tutta la matrice a 0 e la ritorna come parametro di uscita.

      @param [in]   succ    Puntatore alla matrice successiva
      @param [in]   prec    Puntatore alla matrice precedente
      @param [in]   tempo   Indica il numero della matrice
      @param [out]  temp    Matrice appena creata ed inizializzata
      */
    Matrix* creaMatrice(Matrix* succ, Matrix* prec, int tempo);

    /* Funziona distruggiMatrice().

      1)    se la matrice attuale e' la testa, aggiorna la testa alla matrice
      successiva
      2)    se la matrice attuale e' la coda, aggiorna la coda alla matrice
      precedente
      3)    se la matrice attuale e' in mezzo, faccio scavalcare i puntatori
      della precedente e della successiva.
      4)    dealloca la tabella allocata dinamicamente
      5)    dealloca la matrice allocata dinamicamante

      @param [in]   Matrix*      Matrice da eliminare e deallocare
      */
    bool distruggiMatrice(Matrix*);

    /* Funzione riempiCasuale.

      1)    Utilizzando le funzioni di cstdlib setta il seme da cui calcolare
      i numeri random tramite la funzione rand() e inizializza un intero tot
      da utilizzare per debug.
      2)    Genera casualmente un numero, che risultera'  sempre 0 < x < 1.
      Posso controllare la frequenza di celle settate a 1 modificando l'ultimo
      valore che sommo al risultato perche' piu' e' vicino ad 1, piu' le celle
      settate saranno frequenti, altrimenti le celle settate saranno in minor
      numero.

      @param [in]   Matrix*     Puntatore alla matrice attuale
      */
    void riempiCasuale(Matrix*);

    /* Funzione inizializzaTabella.

      Assegna ad ogni elemento della tabella il valore passato come
      parametro

      @param [in]   Matrix*     Matrice della posizione attuale
      @param [in]   int         Valore da applicare a tutti gli elementi
      */
    void inizializzaTabella(Matrix*, int);

    /* Funzione inizializzaCasella.

      Assegna all'elemento della tabella indicato dal secondo parametro,
      il valore passato come terzo parametro

      @param [in]   pos     Matrice della posizione attuale
      @param [in]   casella Casella di cui modificare il valore
      @param [in]   valore  Valore da applicare a tutti gli elementi
      */
    inline bool inizializzaCasella(Matrix* pos, int casella, int valore);

    /* Funzione getValore.

      1)    Ritorna il valore della casella passata dai tre parametri
      Utilizzo la forma t[x + y * (dimx + 2)] perche' ho inizializzato la
      matrice come un array e non come un array di array, di conseguenza la x
      indicherebbe la colonna, cui va sommato il numero della riga moltiplicato
      per in numero di colonne aumentato di due (questo perche' devo comunque
      considerare la cornice esterna.

      @param [in]   cella   Puntatore alla cella corrente
      @param [in]   x       Colonna della cella
      @param [in]   y       Riga della cella
      */
    int getValore(int * cella, int x, int y);

    /* Funzione contaCelleVive.
      Per ogni matrice, setta a 0 il numero di cellule vive, e la scorre
      completamente incrementando di 1 il numero di cellule vive ogni volta che
      ne incontra una viva.

      @param    [in]    Matrix*&    Matrice della quale contare le cellule vive
      */
    int contaCelluleVive(Matrix * &);

    /* Funzione verificamatriciUguali.
      Questa funzione confronta due matrici e ritorna vero se sono uguali.
      Ritorna falso se la prima tabella di confronto è anche la prima della pila
      oppure se la prima tabela di confronto è precedente alla seconda.

      @param [in]   Matrix*     Prima tabella di confronto
      @param [in]   Matrix*     Seconda tabella di confronto
      */
    bool verificaMatriciUguali(Matrix*, Matrix*);

    void patternModeSelector(int);

    void pattern1();
    void pattern2();
    void pattern3();
    void pattern4();
};

#endif // PILAMATRICI_H
