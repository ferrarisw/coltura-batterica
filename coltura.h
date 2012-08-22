#ifndef COLTURA_H
#define COLTURA_H
#include <QtGui>
#include "pilamatrici.h"

/**
 * Widget di visualizzazione della coltura.
 *   La parte pubblica contiene:
 *       - Il costruttore, che prende in ingresso le dimensioni e il pattern.
 *       - Una funzione getMaxTime(), che restituisce la variabile maxTime.
 *       - Una funzione getMinTime(), che restituisce la variabile minTime.
 *       - Lo slider timeSlider, che gestisce il tempo.
 *
 *   I public slots sono:
 *       - aggiorna(), che fa scorrere il tempo di un unità soltanto.
 *       - play(int), che fa scorrere il tempo (indefinitamente) della velocità
 *           voluta se impostato ad un qualsiasi valore diverso da zero,
 *           altrimenti "ferma il tempo".
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
     * //TODO scrivere documentazione su timetrip
     */
    void timeTrip(int);


protected:
    void paintEvent(QPaintEvent *);


private:
    int x,y;
    int pattern;
    int * matrice;
    PilaMatrici *pila;
    QBrush background;
    QBrush colore;
    void paintColtura(QPainter *, QPaintEvent *);
    void paintColtura(QPainter *, QPaintEvent *, char * debug);
    QTimer *timer;
    int minTime;
    int maxTime;


};

#endif // COLTURA_H
