#include "cella.h"
#include <QtGui>

Cella::Cella()
{
    coloreSfondo = QBrush(QColor(166,219,119));
}

QBrush Cella::getSfondo()
{
    return this->coloreSfondo;
}

int Cella::getPos()
{
    return this->posizioneCella;
}

void Cella::Paint(QPainter *painter)
{
    painter->save();
    painter->translate(-0.5,-0.5);

    painter->setBrush(getSfondo());
    painter->drawRect(QRectF(0,0,1,1));

//    painter->scale(.1,.1);
//    painter->setPen(QPen(Qt::red));
//    QFont merda;
//    merda.setPointSizeF(4);
//    painter->setFont(merda);
//    painter->setBrush(Qt::red);
//    painter->drawText(QPointF(0,7),"Qt");

    painter->restore();

}

void Cella::Converti(int elem)
{
    if(elem)
        coloreSfondo==Qt::white;
}


