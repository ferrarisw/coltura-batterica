#ifndef CELLA_H
#define CELLA_H

#include <QtGui>

class Cella
{
public:
    Cella();
    QBrush getSfondo();
    int getPos();
    void Paint(QPainter*);
    void Converti(int);

protected:
    void paintEvent(QPaintEvent *);

private:
    int posizioneCella;
    QBrush coloreSfondo;
};


#endif // CELLA_H
