#ifndef COLTURA_H
#define COLTURA_H
#include <QtGui>
#include "pilamatrici.h"

class Coltura : public QWidget
{
    Q_OBJECT

public:
    Coltura(int x,int y,QWidget * parent=0);
    int getMaxTime();


protected:
    void paintEvent(QPaintEvent *);

private:
    QBrush background;
    void paintColtura(QPainter *, QPaintEvent *);
    void paintColtura(QPainter *, QPaintEvent *,const char *);
    int x,y;
    int * matrice;
    PilaMatrici *pila;
    QTimer *timer;
    int maxTime;

public slots:
    void aggiorna();
    void play(int scatti);


};

#endif // COLTURA_H
