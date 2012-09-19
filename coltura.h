#ifndef COLTURA_H
#define COLTURA_H
#include <QtGui>
#include "pilamatrici.h"
#include "main.h"


class PilaMatrici;
/**
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
 * @author Serena Ziviani.
  */

class Coltura : public QWidget
{
    Q_OBJECT

public:
    /** 
     * Costruttore della classe Coltura.
     * Inizializza la lista Pilamatrici e gestisce l'inizializzazione
     * della barra relativa all'istante di tempo.
     * @param x larghezza
     * @param y altezza
     * @param pattern disposizione iniziale delle cellule
     * @param parent=0
     */
    Coltura(int x,int y, int pattern, QWidget * parent=0);

    //TODO documentazione
    ~Coltura();

    /**
     * Ritorna la velocità massima del tempo.
     * @return ::maxTime
     */
     int getMaxTime();

    /**
     * Ritorna la velocità minima del tempo.
     * @return minTime
     */
     int getMinTime();

    /**
     * Slider che gestisce il salto nel tempo.
     */
    QSlider *timeSlider;

    /**
     * Gestisce il salvataggio della coltura su file.
     * @param s
     * @return bool
     */
    bool save(QString s);

    /**
     * Gestisce il caricamento da file della coltura.
     * @param s
     * @return
     */
    bool load(QString s);


public slots:
    /**
     * Slot che determina il passaggio in un quanto di tempo.
     * Gestisce sia il timeSlider, modificandone sia valore che valore massimo,
     * che l'effettivo passaggio al nuovo stato, sia che si stia seguendo il
     * normale scorrere del tempo sia che si stia viaggiando nel tempo.
     */
    void aggiorna();

    /**
     * Slot che gestisce lo scorrere del tempo.
     * Modifica il quanto di tempo del timer, utilizzando come input la
     * posizione dello slider, tramite l'algoritmo (-1/maxTime*scatti^2+maxTime)
     * @param scatti
     */
    void play(int);

    /**
     * Slot che gestisce la possibilità di tornare indietro nel tempo
     */
    void timeTrip(int);


protected:
    void paintEvent(QPaintEvent * event);


private:
    int x,y;
    int pattern;
    int * matrice;
    void paintColtura(QPainter *, QPaintEvent *);
    void paintColtura(QPainter *, QPaintEvent *, const char *);
    PilaMatrici *pila;
    QBrush colore;
    QBrush background;
    QTimer *timer;
    int minTime;
    int maxTime;
    void draw(QPainter *);
    //void setMinimumSize(int minw);


};

#endif // COLTURA_H
