#include "coltura.h"
#include <QtGui>

Coltura::Coltura(QWidget *parent) :
    QWidget(parent)
{
    setGeometry(375,55,600,500);
}

Coltura::~Coltura()
{

}

void Coltura::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    paintColtura(&painter, event);
    painter.end();
}

void Coltura::paintColtura(QPainter * painter,QPaintEvent *event)
{
    const QRect *recta = &event->rect();
    painter->fillRect(event->rect(), background);

    //sezione disegno caselle
    qreal scale = 1;
    qreal avanzo_scale = scale-1;
    qreal num_caselle_piccole=9;

    qreal altezza_casella = ((qreal)recta->height())/(num_caselle_piccole+scale*2);
    qreal larghezza_casella = ((qreal)recta->width())/(num_caselle_piccole+scale*2);

    qreal H_casellaColonna = altezza_casella;
    qreal W_casellaColonna = larghezza_casella*scale;
    qreal H_casellaRiga    = altezza_casella*scale;
    qreal W_casellaRiga    = larghezza_casella;

    for(int i=1; i<=dimx; i++)
        for(int j=1; j<=dimy; j++)
        {
            painter->save();
            painter->translate(recta->width()-W_casellaColonna/2,recta->height()-H_casellaRiga/2);
            painter->scale(W_casellaColonna,H_casellaRiga);
            cella->Paint(painter);
            painter->restore();
        }

}

void Coltura::Converti(int * matrice)
{
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            cella->Converti(j+(i*12));
}
