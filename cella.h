#ifndef CELLA_H
#define CELLA_H

#include <QtGui>

class Cella
{
public:
    Cella();
    QBrush getSfondo();
    posizioneCella getPos();
    void Paint(QPainter*);

protected:
    void paintEvent(QPaintEvent *);

private:
    posizioneCella posCella;
    QBrush coloreSfondo;
};


#endif // CELLA_H
