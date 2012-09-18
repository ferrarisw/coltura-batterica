#ifndef PILAMATRICI_H
#define PILAMATRICI_H

#include <QtGui>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "main.h"
#include "popup.h"
using namespace std;

/** Descrizione della Classe PilaMatrici e delle sue strutture dati.
    La classe PilaMatrici ha una parte pubblica e privata.
    La parte pubblica contiene:
        - Un costruttore per la pila di matrici
        - Una funzione next che crea la prossima matrice apportando le giuste
            modifiche in base alla matrice precedente. Il tipo di ritorno è un
            puntatore a intero
        - Una funzione stampa con funzionalit�  di Debug che ritorna void
        - Due funzioni getDimx e getDimy che ritornano la dimensione sull'asse
            x e y della matrice. Mi servono perchè l'utente possa inserirle
            a esecuzione iniziata.

    La parte privata include:
        - Le dimensioni x e y della matrice
        - Un enumeratore per facilitare la comprensione degli stati vivo e morto
        - Una struttura Matrix contenente:
            - tabella: puntatore ad interi, vedo la matrice come un array
            - succ e prec: due puntatore a Matrix che puntano alla matrice
                successiva e precedente.
            - tempo: un intero che indica la successione delle diverse matrici.
                Mi serve quando torno indietro nelle configurazioni e nel
                salvataggio e caricamento della tabella.
        - Un puntatore a Matrix per la testa della lista di matrici
        - Un puntatore a Matrix per la coda della matrice generata
        - Un puntatore per la matrice attuale
        - Una funzione creaMatrice con valore di ritorno un puntatore a Matrix
            che inizializza una nuova matrice da cui partire a fare i calcoli
        - una funzione void riempiCasuale che riempie casualmente la matrice
            (escluso il bordo esterno).
        - una funzione getValore che ritorna un intero corrispondente al valore
            di ogni singola cella per cui lo invoco.

Commentato il 4/7/12 alle 22.00 - Davide Ferrari
  */

class PilaMatrici
{
public:
    PilaMatrici(int x, int y, int pattern);

    ~PilaMatrici();

    /** Per ritornare un puntatore alla matrice attuale.
      Questa funzione ritorna un puntatore alla tabella di matrici attuale.
      Serve per la grafica.
      */
    int* getMatrix();

    /** Per calcolare la matrice successiva.

      Questa funzione non prende in ingresso alcun parametro perchè utilizza
      ciò che è gi�  inizializzato nella classe.
      1)    Inizializza una nuova matrice dinamica come posizioneAttuale e
      setta il puntatore alla prossima matrice a NULL.
      2)    Inizializza un intero somma per eseguire il calcolo dell'algoritmo
      e inizializza anche due puntatori a intero, uno per la tabella temp appena
      creata (posizioneAttuale->tabella) e uno alla tabella temporanea
      (temp->tabella) per semplificare e rendere leggibile il codice.
      3)    Tramite la funione getValore, acquisisce e somma il valore di
      tutte le 8 caselle attorno alla casella corrente (si fa un'iterazione
      su ogni casella con un doppio ciclo for).
      L'algoritmo prevede che se una cellula è morta e ve ne sono 3 vive intorno
      questa prende vita, al contrario, se la cellula è viva e ce ne sono più
      di 3 o meno di 2 questa muore. Semplicemente sommando i valori delle
      cellule attorno alla cellula attuale ottengo il numero di cellule vive.
      Se le cellule vive sono 3 allora la cellula è viva, altrimenti morta.
      Questo si può realizzare con due semplici controlli.
      4)    Dopo aver modificato completamente la tabella temp, setta la
      posizioneAttuale a temp, così da ritornare la nuova tabella appena creata.

    @return   temp->tabella   La tabella appena modificata
      */
    int * next();

    /** Stampa su stdout la matrice.
      Semplice funzione di stampa su stdout della matrice in posizioneAttuale.
      Utilizzo per il debug.
      */
    void stampa ();

    /** Ritorna la larghezza della matrice.
      @return dimx  Lunghezza di ogni riga
      */
    int getDimx() { return dimx;}

    /** Ritorna l'altezza della matrice.
      @return dimy  Numero di righe
      */
    int getDimy() { return dimy;}

    /** Funzione Salva.

      1)    Salva la versione del file. Nel caso cambio la funzione salva,
      devo aggiornare la versione del file. Nella carica prima controllerò che
      la versione del programma sia corretta così da caricare da file i giusti
      elementi.
      2)    Salva la posizione attuale, le dimensioni della matrice e il tempo
      a cui dovrò arrivare nella rigenerazione
      3)    Dopo aver salvato su file tutti gli elementi della matrice
      chiudo il file in scrittura.
      */
    bool salva (QString file);

    //TODO Documentazione carica
    bool carica (QString file);

    /** Numero di matrici realizzate.
      Questa variabile permette semplicemente di monitorare il numero di matrici
      realizzate.
      */
    int matriciRealizzate;

    /* Funzione timeTrip.
      Questa funzione permette di tornare ad una matrice realizzata
      precedentemente o successivamente alla matrice attuale.

      @param [in]   int         Il tempo a cui si desidera arrivare
      @return       int         Ritorna dei valori che indicano cosa � successo nella funzione
      */
    int timeTrip(int);

private:

    int dimx;   //Dimensioni della matrice
    int dimy;
    int pattern;
    enum stato {morto = 0, vivo = 1};

    /**
      * La Matrice ha un puntatore ad interi per la tabella,
      * un puntatore alla tabella successiva e uno alla tabella precedente.
      * Un intero indica il tempo della matrice e uno il numero di cellule
      * vive, calcolate ogni volta.
      */
    struct Matrix {
        int* tabella;
        Matrix* succ;
        Matrix* prec;
        int tempo;
        //bool rigenerabile;
        int numeroCelleVive;
    };

    /**
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
      maggiorate di 2 perchè creo anche una cornice aggiuntiva di zeri utile
      all'algoritmo nella sua esecuzione.
      4)    Inizializza tutta la matrice a 0 e la ritorna come parametro di uscita.

      @param [in]   succ    Puntatore alla matrice successiva
      @param [in]   prec    Puntatore alla matrice precedente
      @param [in]   tempo   Indica il numero della matrice
      @param [out]  temp    Matrice appena creata ed inizializzata
      */
    Matrix* creaMatrice(Matrix* succ, Matrix* prec, int tempo);

    /* Funziona distruggiMatrice().

      1)    se la matrice attuale è la testa, aggiorna la testa alla matrice
      successiva
      2)    se la matrice attuale è la cosa, aggiorna la coda alla matrice
      precedente
      3)    se la matrice attuale è in mezzo, faccio scavalcare i puntatori
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
      2)    Genera casualmente un numero, che risulter�  sempre 0 < x < 1.
      Posso controllare la frequenza di celle settate a 1 modificando l'ultimo
      valore che sommo al risultato perchè più è vicino ad 1, più le celle
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
      Utilizzo la forma t[x + y * (dimx + 2)] perchè ho inizializzato la
      matrice come un array e non come un array di array, di conseguenza la x
      indicherebbe la colonna, cui va sommato il numero della riga moltiplicato
      per in numero di colonne aumentato di due (questo perchè devo comunque
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
      Ritorna falso se la prima tabella di confronto � anche la prima della pila
      oppure se la prima tabela di confronto � precedente alla seconda.

      @param [in]   Matrix*     Prima tabella di confronto
      @param [in]   Matrix*     Seconda tabella di confronto
      */
    bool verificaMatriciUguali(Matrix*, Matrix*);

    //TODO
    void patternModeSelector(int);

    void pattern1();
    void pattern2();
    void pattern3();
    void pattern4();
};

#endif // PILAMATRICI_H
