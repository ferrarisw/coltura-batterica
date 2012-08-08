#ifndef COLTURA_H
#define COLTURA_H
#include <QtGui>
#include "pilamatrici.h"

/** @brief The Coltura class
 *Descrizione della classe Coltura e delle sue strutture dati.
    La parte pubblica contiene:
        - Il costruttore, che prende in ingresso x e y.
        - Una funzione getMaxTime, che restituisce la variabile maxTime.
    La parte protected contiene:
        - La funzione paintEvent, chiamata ogni volta che si necessita di un
            refresh dello schermo.
    La parte privata include:
        - Le dimensioni x e y della matrice.
        - Un array di interi, utilizzato per memorizzare lo stato attuale della
            coltura.
        - Un elemento Pilamatrici.
        - Un QBrush che definisce il colore di background del widget.
        - Una funzione paintColtura che traduce l'array di interi in una "matrice
            grafica".
        - Un oggetto QTimer, utilizzato per simulare lo scorrere del tempo.
        - Una variabile maxTime, che determina la velocità massima di
            aggiornamento.
    I public slots sono:
        - aggiorna(), che fa scorrere il tempo di un unità soltanto.
        - play(int), che fa scorrere il tempo (indefinitamente) della velocità
            voluta se impostato ad un qualsiasi valore diverso da zero,
            altrimenti "ferma il tempo".

Commentato il 3/8/12 alle 17.30 - Serena Ziviani
  */

class Coltura : public QWidget
{
    Q_OBJECT

public:
    Coltura(int x,int y,QWidget * parent=0);
    int getMaxTime();
    int getMinTime();


protected:
    void paintEvent(QPaintEvent *);

private:
    int x,y;
    int * matrice;
    PilaMatrici *pila;
    QBrush background;
    QBrush colore;
    void paintColtura(QPainter *, QPaintEvent *);
    QTimer *timer;
    int minTime;
    int maxTime;

public slots:
    void aggiorna();
    void play(int scatti);
    void changeDimension(int);


};

#endif // COLTURA_H
