#ifndef PILAMATRICI_H
#define PILAMATRICI_H

#include "QString"

/** Descrizione della Classe PilaMatrici e delle sue strutture dati.
    La classe PilaMatrici ha una parte pubblica e privata.
    La parte pubblica contiene:
        - Un costruttore per la pila di patrici
        - Una funzione next che crea la prossima matrice apportando le giuste
            modifiche in base alla matrice precedente. Il tipo di ritorno è un
            puntatore a intero
        - Una funzione stampa con funzionalità di Debug che ritorna void
        - Due funzioni getDimx e getDimy che ritornano la dimensione sull'asse
            x e y della matrice. Mi servono perchè l'utente possa inserirle
            a esecuzione iniziata.
        - Due funzioni salvaMatrice e caricaMatrice per salvare lo stato
            attuale e caricarne uno precedente, da cui ricominciare nel calcolo
            di qualsiasi stato precedente.
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
    PilaMatrici(int x, int y);

    /** Funzione next().

      Questa funzione non prende in ingresso alcun parametro perchè utilizza
      ciò che è già inizializzato nella classe.
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

    /** Funzione stampa().
      Semplice funzione di stampa su stdout della matrice in posizioneAttuale.
      Utilizzo per il debug.
      */
    void stampa ();

    /** Funzione getDimx().
      @return dimx  Lunghezza di ogni riga
      */
    int getDimx() { return dimx;}

    /** Funzione getDimy().
      @return dimy  Numero di righe
      */
    int getDimy() { return dimy;}

    //TODO DOcumentazione salva
    bool salva (QString file);

    //TODO Documentazione carica
    static PilaMatrici* carica (QString file);

private:

    int dimx;   //Dimensioni della matrice
    int dimy;
    enum stato {morto = 0, vivo = 1};

    /*
      * La Matrice ha un puntatore ad interi per la tabella,
      * un puntatore alla tabella successiva e uno alla tabella precedente.
      * Utilizzo un singolo puntatore perchè vedo la matrice come un array
      */
    struct Matrix {
        int* tabella;
        Matrix* succ;
        Matrix* prec;
        int tempo;
        bool rigenerabile;
    };

    /*
      * Due puntatori, uno alla testa e uno alla coda della lista di matrici
      */
    Matrix* testa;
    Matrix* coda;
    Matrix* posizioneAttuale;

    /** Funzione creaMatrice.

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

    //TODO Documentazione distruggiMatrice
    bool distruggiMatrice(Matrix* matrice);

    /** Funzione riempiCasuale.

      1)    Utilizzando le funzioni di cstdlib setta il seme da cui calcolare
      i numeri random tramite la funzione rand() e inizializza un intero tot
      da utilizzare per debug.
      2)    Genera casualmente un numero, che risulterà sempre 0 < x < 1.
      Posso controllare la frequenza di celle settate a 1 modificando l'ultimo
      valore che sommo al risultato perchè più è vicino ad 1, più le celle
      settate saranno frequenti, altrimenti le celle settate saranno in minor
      numero.

      @param [in]   pos     Puntatore alla matrice attuale
      */
    void riempiCasuale(Matrix* pos);

    //TODO Documentazione InizializzaTabella
    void inizializzaTabella(Matrix* pos, int valore);

    /** Funzione getValore.

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
};

#endif // PILAMATRICI_H
