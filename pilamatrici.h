#ifndef PILAMATRICI_H
#define PILAMATRICI_H

/*  Commentato il 4/7/12 alle 22.00 - Davide Ferrari
    La classe PilaMatrici ha una parte pubblica e privata.
    La parte pubblica contiene:
        - Un costruttore per la pila di matrici
        - Una funzione next che crea la prossima matrice apportando le giuste
            modifiche in base alla matrice precedente. Il tipo di ritorno è un
            puntatore a intero
        - Una funzione stampa con funzionalità di Debug che ritorna void
        - Due funzioni getDimx e getDimy che ritornano la dimensione sull'asse
            x e y della matrice. Mi servono perchè l'utente possa inserirle
            a esecuzione iniziata.
        - Due funzioni Salva e Carica per salvare lo stato attuale e caricarne
            uno precedente, da cui ricominciare nel calcolo di qualsiasi stato
            precedente
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
        - Un puntatore a Matrix per l'ultima matrice generata
        - Un puntatore per la matrice attuale
        - Una funzione creaMatrice con valore di ritorno un puntatore a Matrix
            che inizializza una nuova matrice da cui partire a fare i calcoli
        - una funzione void che riempie casualmente la matrice (escluso il
            bordo esterno).
        - una funzione che ritorna un intero corrispondente al valore di ogni
            singola cella per cui lo invoco.
  */

class PilaMatrici
{
public:
    PilaMatrici(int x, int y);
    int * next();
    void stampa ();
    int getDimx() { return dimx;}
    int getDimy() { return dimy;}
    void salvaMatrice();
    void caricaMatrice();

private:

    int dimx;   //Dimensioni della matrice
    int dimy;
    enum stato {morto = 0, vivo = 1};

    /*
      * La Matrice ha un puntatore a puntatore di interi per la tabella,
      * un puntatore alla tabella successiva e uno alla tabella precedente.
      */
    struct Matrix {
        int* tabella;
        Matrix* succ;
        Matrix* prec;
        int tempo;
    };

    /*
      * Due puntatori, uno alla testa e uno alla coda della lista di matrici
      */
    Matrix* testa;
    Matrix* coda;
    Matrix* posizioneAttuale;

    Matrix* creaMatrice(Matrix* succ, Matrix* prec);
    void riempiCasuale(Matrix* pos);
    int getValore(int * cella, int , int);
};

#endif // PILAMATRICI_H
