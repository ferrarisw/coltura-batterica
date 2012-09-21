#ifndef COLTURA_H
#define COLTURA_H
#include <QtGui>
#include "pilamatrici.h"
#include "main.h"

class PilaMatrici;

/**
 * @author Serena Ziviani.
 * @brief The Coltura class
 *
 * La classe coltura si occupa della visualizzazione grafica della coltura.
 *   La parte pubblica contiene:
 *       - Coltura(int x, int y, int pattern, Qwidget * parent=0).
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
 *       - void paintColtura(QPainter *, QPaintEvent *), che gestisce la
 *          visualizzazione grafica della coltura.
 *       - void paintColtura(QPainter *, QPaintEvent *, const char * debug),
 *          come sopra ma utilizzata solamente nel debug.
 *       - PilaMatrici * pila, variabile della classe PilaMatrici.
 *       - QBrush colore, il colore attribuito ad ogni casella.
 *       - QBrush background, il colore di sfondo. //TODO elimina
 *       - QTimer * timer, che gestisce la velocità del tempo.
 *       - int minTime, il valore minimo della velocità del tempo.
 *       - int maxTime, il valore massimo della velocità del tempo.
 *       - void draw(QPainter *), che gestisce i dettagli relativi al disegno
 *          delle singole cellule.
  */

class PilaMatrici;

class Coltura : public QWidget
{
    Q_OBJECT

public:
    /** 
     * @brief Coltura costruttore
     * @param Larghezza della matrice
     * @param Altezza della matrice
     * @param pattern di disposizione iniziale delle cellule
     * @param parent=0
     *
     *Costruttore della classe Coltura.
     *Inizializza la lista Pilamatrici e gestisce l'inizializzazione
     *della barra relativa all'istante di tempo.
     */
    Coltura(int x,int y, int pattern, QWidget * parent=0);

    ~Coltura();

    /**
      * @brief Ritorna il valore della velocità massima di play
      * @return ::maxTime
      */
     int getMaxTime();

     /**
      * @brief Ritorna il valore della velocità minima di play
      * @return ::minTime
      */
     int getMinTime();

     /**
     * @brief Lo slider che gestisce il valore della velocità del play
     */
    QSlider *timeSlider;

    /**
     * @brief Funzionalita' di salvataggio su file
     * @param File su cui salvare la sessione
     * @return True se il salavataggio avviene correttamente
     * @return False se il salvataggio non avviene
     *
     *Questa funzione chiama la funzione salva della classe PilaMatrici, ma serve
     *per connetterla ad una voce del menu.
     */
    bool save(QString);

    /**
     * @brief Funzionalita' di caricamento da file
     * @param File da cui caricare la sessione
     * @return True se il caricamento avviene correttamente
     * @return False se il caricamento non avviene
     *
     *Questa funzione chiama la funzione carica della classe PilaMatrici, ma serve
     *per connetterla ad una voce del menu.
     */
    bool load(QString s);

public slots:
    /**
     * @brief Slot che determina il passaggio in un quanto di tempo
     *
     *Utilizzando la funzione next della classe ::PilaMatrici, realizza l'elemento
     *successivo della lista di matrici e aggiorna la grafica rappresentando
     *la matrice successiva.
     */
    void aggiorna();

    /**
     * @brief Slot che gestisce lo scorrere del tempo
     * @param scatti sono gli intervalli di aggiornamento
     *
     * Questo slot utilizza un timer e il valore impostato da timeSlider per settare
     * una velocita' di aggiornamento della pila di matrici.
     * Quindi e' possibile mettere in play con una velocita' positiva e stop con
     * una velocita' nulla.
     */
    void play(int);

    /**
     * @brief Slot che gestisce la possibilità di tornare indietro nel tempo
     * @param Tempo di arrivo desiderato della timeTrip
     *
     *Questo slot si aggancia alla funzione timeTrip per abilitarla e renderla
     *effettiva nella grafica.
     */
    void timeTrip(int);

protected:
    /**
     * @brief Disegna l'interfaccia della coltura
     */
    void paintEvent(QPaintEvent *);

private:
    int x,y;
    int pattern;
    int * matrice;
    /*
     * @param painter
     * @param event
     * Funzione che disegna il widget Coltura in base alla matrice generata da
     * pilaMatrici->next.
     * In particolare, prende l'oggetto locale matrice e lo scorre fino alla fine,
     * impostando diversamente il pennello a seconda del valore della cella.
     *
     */
    void paintColtura(QPainter *, QPaintEvent *);
    void paintColtura(QPainter *, QPaintEvent *, const char *);
    PilaMatrici *pila;
    QBrush colore;
    QBrush background;
    QTimer *timer;
    int minTime;
    int maxTime;
    void draw(QPainter *);
};

#endif // COLTURA_H
