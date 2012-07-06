#ifndef COLTURA_H
#define COLTURA_H
#include <QtGui>
#include "cella.h"

#define GDEB(a) {a; }

class Coltura : public QWidget
{
public:
    Coltura(int x,int y,int *,QWidget * parent=0);
    Coltura();
    ~Coltura();


protected:
    void paintEvent(QPaintEvent *);

private:
    QBrush background;
    void paintColtura(QPainter *, QPaintEvent *);
    void paintColtura(QPainter *, QPaintEvent *,const char *);
    int x,y;
    int * matrice;


};

#endif // COLTURA_H
