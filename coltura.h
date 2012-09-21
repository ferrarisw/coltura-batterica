#ifndef COLTURA_H
#define COLTURA_H
#include <QtGui>
#include "pilamatrici.h"
#include "main.h"

class PilaMatrici;

class PilaMatrici;

/**
 * @brief The Coltura class.
 *
 * La classe coltura si occupa della visualizzazione grafica della coltura.
 *   La parte pubblica contiene:
 *       - Coltura(int x, int y, int pattern, Qwidget * parent=0), costruttore
 *       - ~Coltura().
 *       - int getMaxTime(), che restituisce la variabile maxTime.
 *       - int getMinTime(), che restituisce la variabile minTime.
 *       - QSlider * timeSlider, che gestisce il tempo.
 *       - bool save(QString s), che gestisce il salvataggio su file.
 *       - bool load(QString s), che gestisce il caricamento su file.
 *
 *   I public slots sono:
 *       - void aggiorna(), che fa scorrere il tempo di un unità soltanto.
 *       - void play(int) , che fa scorrere il tempo (indefinitamente) della
 *           velocità voluta se impostato ad un qualsiasi valore diverso da
 *           zero, altrimenti "ferma il tempo".
 *       - void timeTrip(int), che gestisce il salto nel tempo.
 *
 *   La parte protected contiene:
 *       - void paintEvent(QPaintEvent * event), chiamata ad ogni necessità di
 *           ridisegnare il widget sullo schermo.
 *
 *   La parte privata contiene:
 *       - int x,y, le dimensioni della coltura.
 *       - int pattern, il tipo di coltura che voglio ottenere.
 *       - int * matrice, la rappresentazione in 0 e 1 della coltura.
 *       - int magnifier, la "dimensione" delle singole caselle.
 *       - PilaMatrici * pila, variabile della classe PilaMatrici.
 *       - void paintColtura(QPainter * painter, QPaintEvent * event),
 *          che gestisce la visualizzazione grafica della coltura.
 *       - void paintColtura(QPainter * painter, QPaintEvent * event,
 *                           const char * debug),
 *          come sopra ma utilizzata solamente nel debug.
 *       - void draw(QPainter * painter), che gestisce i dettagli relativi al
 *          disegno delle singole cellule.
 *       - QBrush colore, il colore attribuito ad ogni casella.
 *       - QTimer * timer, che gestisce la velocità del tempo.
 *       - int minTime, il valore minimo della velocità del tempo.
 *       - int maxTime, il valore massimo della velocità del tempo.
 */
class Coltura : public QWidget
{
    Q_OBJECT

public:
    /** 
     * @brief Costruttore della classe Coltura
     * @param x Larghezza della matrice
     * @param y Altezza della matrice
     * @param pattern Determina la disposizione iniziale delle cellule
     * @param parent 0, nullo
     *
     * Inizializza la lista Pilamatrici e gestisce l'inizializzazione
     * della barra relativa all'istante di tempo.
     */
    Coltura(int x,int y, int pattern, QWidget * parent=0);

    ~Coltura();

    /**
      * @brief Ritorna la velocità massima di play
      * @return maxTime
      */
     int getMaxTime();

     /**
      * @brief Ritorna la velocità minima di play
      * @return minTime
      */
     int getMinTime();

     /**
     * @brief Slider che gestisce la possibilità di tornare indietro nel tempo
     */
    QSlider * timeSlider;

    /**
     * @brief Funzionalita' di salvataggio su file
     * @param s File su cui salvare la sessione
     * @return True se il salvataggio avviene correttamente
     * @return False se il salvataggio non avviene
     *
     * Questa funzione chiama la funzione salva della classe PilaMatrici, ma
     * serve per connetterla ad una voce del menu.
     */
    bool save(QString s);

    /**
     * @brief Funzionalita' di caricamento da file
     * @param s File da cui caricare la sessione
     * @return True se il caricamento avviene correttamente
     * @return False se il caricamento non avviene
     *
     * Questa funzione chiama la funzione carica della classe PilaMatrici e
     * reistanzia le parti critiche della classe Coltura
     */
    bool load(QString s);

public slots:
    /**
     * @brief Slot che determina il passaggio in un quanto di tempo
     *
     * Utilizzando la funzione next della classe PilaMatrici, realizza
     * l'elemento successivo della lista di matrici e aggiorna la grafica
     * rappresentando la matrice successiva.
     * Aggiorna inoltre il timeSlider affinchè possa mantenere il valore
     * corretto.
     */
    void aggiorna();

    /**
     * @brief Slot che gestisce lo scorrere del tempo
     * @param scatti sono gli intervalli di aggiornamento
     *
     * Questo slot utilizza un timer e il valore impostato da
     * MainWindow::slider per settare la velocita' di aggiornamento della pila
     * di matrici.
     * Se la velocità impostata è nulla mette in pausa il tempo.
     */
    void play(int);

    /**
     * @brief Slot che gestisce il salto nel tempo
     * @param time Tempo di arrivo desiderato della timeTrip
     *
     * Questo slot abilita la funzione PilaMatrici->timeTrip
     * e la rende effettiva nella grafica.
     */
    void timeTrip(int);

protected:
    /**
     * @brief Imposta i dati necessari per disegnare la coltura
     * @param *event evento generato automaticamente
     */
    void paintEvent(QPaintEvent * event);

private:
    int x,y;
    int pattern;
    int * matrice;
    int magnifier;
    /*
     * @param painter
     * @param event
     * Funzione che disegna la coltura in base alla matrice generata da
     * pilaMatrici->next.
     * In particolare, prende l'oggetto locale matrice e lo scorre fino alla fine,
     * impostando il pennello a seconda del valore della cella.
     *
     */
    void paintColtura(QPainter *, QPaintEvent *);
    void paintColtura(QPainter *, QPaintEvent *, const char *);
    PilaMatrici *pila;
    QBrush colore;
    QTimer *timer;
    int minTime;
    int maxTime;
    /*
     * @brief Funzione di appoggio a paintColtura.
     * Gestisce i dettagli riguardanti le dimensioni del widget sullo schermo.
     * (!!pre-alpha!!)
     */
    void draw(QPainter *);
};

#endif // COLTURA_H
