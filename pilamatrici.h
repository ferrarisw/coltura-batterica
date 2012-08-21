#ifndef PILAMATRICI_H
#define PILAMATRICI_H

#include <QtGui>

/** Descrizione della Classe PilaMatrici e delle sue strutture dati.
    La classe PilaMatrici ha una parte pubblica e privata.
    La parte pubblica contiene:
        - Un costruttore per la pila di matrici
        - Una funzione next che crea la prossima matrice apportando le giuste
            modifiche in base alla matrice precedente. Il tipo di ritorno √® un
            puntatore a intero
        - Una funzione stampa con funzionalit√  di Debug che ritorna void
        - Due funzioni getDimx e getDimy che ritornano la dimensione sull'asse
            x e y della matrice. Mi servono perch√® l'utente possa inserirle
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

    /** Funzione getMatrix.
      Questa funzione ritorna un puntatore alla tabella di matrici attuale.
      Serve per la grafica.
      */
    int* getMatrix();

    /** Funzione next().

      Questa funzione non prende in ingresso alcun parametro perch√® utilizza
      ci√≤ che √® gi√  inizializzato nella classe.
      1)    Inizializza una nuova matrice dinamica come posizioneAttuale e
      setta il puntatore alla prossima matrice a NULL.
      2)    Inizializza un intero somma per eseguire il calcolo dell'algoritmo
      e inizializza anche due puntatori a intero, uno per la tabella temp appena
      creata (posizioneAttuale->tabella) e uno alla tabella temporanea
      (temp->tabella) per semplificare e rendere leggibile il codice.
      3)    Tramite la funione getValore, acquisisce e somma il valore di
      tutte le 8 caselle attorno alla casella corrente (si fa un'iterazione
      su ogni casella con un doppio ciclo for).
      L'algoritmo prevede che se una cellula √® morta e ve ne sono 3 vive intorno
      questa prende vita, al contrario, se la cellula √® viva e ce ne sono pi√π
      di 3 o meno di 2 questa muore. Semplicemente sommando i valori delle
      cellule attorno alla cellula attuale ottengo il numero di cellule vive.
      Se le cellule vive sono 3 allora la cellula √® viva, altrimenti morta.
      Questo si pu√≤ realizzare con due semplici controlli.
      4)    Dopo aver modificato completamente la tabella temp, setta la
      posizioneAttuale a temp, cos√¨ da ritornare la nuova tabella appena creata.

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

    /** Funzione Salva.

      1)    Salva la versione del file. Nel caso cambio la funzione salva,
      devo aggiornare la versione del file. Nella carica prima controller√≤ che
      la versione del programma sia corretta cos√¨ da caricare da file i giusti
      elementi.
      2)    Salva la posizione attuale, le dimensioni della matrice e il tempo
      a cui dovr√≤ arrivare nella rigenerazione
      3)    Dopo aver salvato su file tutti gli elementi della matrice
      chiudo il file in scrittura.
      */
    //bool salva (QString file);

    //TODO Documentazione carica
    //static PilaMatrici* carica (QString file);

    /** Variabile memoriaOccupata
      Questa variabile viene utilizzata per statistiche e indica quanta mamoria
      viene occupata dalle matrici in ogni punto del programma. Si puÚ vedere
      questa statistica attivando il livello di debug LOG
      */
    long int memoriaOccupata;

    /** Funzione incrementaMemoriaOccupata(long int &, int)
      Incrementa il valore passatogli per riferimento al primo parametro
      del secondo valore passato per valore al secondo parametro

      @param [in]   intero&    Int che indica la memoria da incrementare
      @param [in]   intero     Valore da aggiungere alla memoria occupata
      */
    int incrementaMemoriaOccupata(long int &, int);

    /** Variabile matriciRealizzate
      Questa variabile permette semplicemente di monitorare il numero di matrici
      realizzate.
      */
    int matriciRealizzate;

private:

    int dimx;   //Dimensioni della matrice
    int dimy;
    int pattern;
    enum stato {morto = 0, vivo = 1};

    /**
      * La Matrice ha un puntatore ad interi per la tabella,
      * un puntatore alla tabella successiva e uno alla tabella precedente.
      * Utilizzo due puntatori alla matrice parallela successiva e precedente
      * causati dall'utilizzo della godMode.
      * Un intero indica il tempo della matrice e uno il numero di cellule
      * vive, calcolate ogni volta.
      */
    struct Matrix {
        int* tabella;
        Matrix* succ;
        Matrix* prec;
        Matrix* parallelForward;
        Matrix* parallelBackward;
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

    /** Funzione creaMatrice().

      1)    Alloca dinamicamente una matrice temporanea delle dimensioni passate
      dall'utente.
      2)    Aggancia la matrice allocata dinamicamente alle due matrici passate come
      parametro.
      3)    Inizializza il campo tabella della matrice creata, le dimensioni sono
      maggiorate di 2 perch√® creo anche una cornice aggiuntiva di zeri utile
      all'algoritmo nella sua esecuzione.
      4)    Inizializza tutta la matrice a 0 e la ritorna come parametro di uscita.

      @param [in]   succ    Puntatore alla matrice successiva
      @param [in]   prec    Puntatore alla matrice precedente
      @param [in]   tempo   Indica il numero della matrice
      @param [out]  temp    Matrice appena creata ed inizializzata
      */
    Matrix* creaMatrice(Matrix* succ, Matrix* prec, int tempo);

    /** Funziona distruggiMatrice().

      1)    se la matrice attuale √® la testa, aggiorna la testa alla matrice
      successiva
      2)    se la matrice attuale √® la cosa, aggiorna la coda alla matrice
      precedente
      3)    se la matrice attuale √® in mezzo, faccio scavalcare i puntatori
      della precedente e della successiva.
      4)    dealloca la tabella allocata dinamicamente
      5)    dealloca la matrice allocata dinamicamante

      @param [in]   Matrix*      Matrice da eliminare e deallocare
      */
    bool distruggiMatrice(Matrix*);

    /** Funzione riempiCasuale.

      1)    Utilizzando le funzioni di cstdlib setta il seme da cui calcolare
      i numeri random tramite la funzione rand() e inizializza un intero tot
      da utilizzare per debug.
      2)    Genera casualmente un numero, che risulter√  sempre 0 < x < 1.
      Posso controllare la frequenza di celle settate a 1 modificando l'ultimo
      valore che sommo al risultato perch√® pi√π √® vicino ad 1, pi√π le celle
      settate saranno frequenti, altrimenti le celle settate saranno in minor
      numero.

      @param [in]   Matrix*     Puntatore alla matrice attuale
      */
    void riempiCasuale(Matrix*);

    /** Funzione inizializzaTabella.

      Assegna ad ogni elemento della tabella il valore passato come
      parametro

      @param [in]   Matrix*     Matrice della posizione attuale
      @param [in]   int         Valore da applicare a tutti gli elementi
      */
    void inizializzaTabella(Matrix*, int);

    /** Funzione inizializzaCasella.

      Assegna all'elemento della tabella indicato dal secondo parametro,
      il valore passato come terzo parametro

      @param [in]   pos     Matrice della posizione attuale
      @param [in]   casella Casella di cui modificare il valore
      @param [in]   valore  Valore da applicare a tutti gli elementi
      */
    inline bool inizializzaCasella(Matrix* pos, int casella, int valore);

    /** Funzione getValore.

      1)    Ritorna il valore della casella passata dai tre parametri
      Utilizzo la forma t[x + y * (dimx + 2)] perch√® ho inizializzato la
      matrice come un array e non come un array di array, di conseguenza la x
      indicherebbe la colonna, cui va sommato il numero della riga moltiplicato
      per in numero di colonne aumentato di due (questo perch√® devo comunque
      considerare la cornice esterna.

      @param [in]   cella   Puntatore alla cella corrente
      @param [in]   x       Colonna della cella
      @param [in]   y       Riga della cella
      */
    int getValore(int * cella, int x, int y);

    /** Funzione contaCelleVive.
      Per ogni matrice, setta a 0 il numero di cellule vive, e la scorre
      completamente incrementando di 1 il numero di cellule vive ogni volta che
      ne incontra una viva.

      @param    [in]    Matrix*&    Matrice della quale contare le cellule vive
      */
    int contaCelluleVive(Matrix * &);

    /** Funzione verificamatriciUguali.
      Questa funzione confronta due matrici e ritorna vero se sono uguali.
      Ritorna falso se la prima tabella di confronto Ë anche la prima della pila
      oppure se la prima tabela di confronto Ë precedente alla seconda.

      @param [in]   Matrix*     Prima tabella di confronto
      @param [in]   Matrix*     Seconda tabella di confronto
      */
    bool verificaMatriciUguali(Matrix*, Matrix*);

    /** Funzione timeTripAbilitation.
      Questa funzione controlla se Ë possibile attivare il timeTrip.
      Esegue i controlli e ritorna degli interi che indicano gli eventuali
      errori riscontrati. Altrimenti ritorna un intero che indica il successo
      della verifica.

      @param [in]   Matrix*&    La matrice attuale
      @param [in]   int         Il tempo a cui si desidera arrivare
      @return       int         Ritorna dei valori che indicano cosa Ë successo nella funzione
      */
    int timeTripAbilitation(Matrix* &, int);

    /** Funzione timeTrip.
      Questa funzione permette di tornare ad una matrice realizzata
      precedentemente o successivamente alla matrice attuale.

      @param [in]   Matrix*&    La matrice attuale
      @param [in]   int         Il tempo a cui si desidera arrivare
      @return       int         Ritorna dei valori che indicano cosa Ë successo nella funzione
      */
    int timeTrip(Matrix* &, int);

    /** Variabile bool godModeActivation
      Questa variabile determina se la godMode Ë attiva o no
      */
    bool godModeActivation;

    /** Funzione godModeActivityEnabler.
      QUeste funzioni settano o resettano il booleano che determina l'attivit‡
      della funzione godMode.

      @param    [in]    bool&   Valore booleano modificabile
      @param    [in]    bool    Valore da assegnare al precedente parametro
      @return           int     Ritorna degli interi che indicano cosa Ë successo
      */
    int godModeActivityEnabler(bool &, const bool);
    int godModeActivityEnabler(bool &);

    /** Funzione godModeInitalizer.
      Questa funzione prepara la nuova matrice in parallelo alla linea principale
      per la godMode. Provvede a tutti gli agganci dei puntatori, in modo che
      si possa sempre viaggiare nel tempo tramite le diverse linee parallele di
      modifica della godMode.

      @return       int     Ritorna degli interi che indicano cosa Ë successo
      */
    int godModeInitializer();

    /** Funzione godModeApplicator.
      Questa funzione sfrutta l'operato della funzione godModeInitializer, che
      ha modificato la posizioneAttuale e ne modifica la matrice.

      @return       int     Ritorna un intero nel caso tutto abbia avuto successo
      */
    int godModeApplicator(int &, int);

    /** Funzione returnToMainLine.
      Questa funzione permette di ritornare alla linea principale, prima della
      modifica della godMode. Viene chiamata ricorsivamente finchË non trovo un
      puntatone non nullo alla matrice parallelBackward.

      @return       int     ritorna un intero che descrive cosa Ë successo
      */
    int returnToMainLine(Matrix *&);

    //TODO
    void patternModeSelector(int);
};

#endif // PILAMATRICI_H
