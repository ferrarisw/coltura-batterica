/*#include "cella.h"
#include <QtGui>
#include <iostream>
using namespace std;

Cella::Cella()
{
    coloreSfondo = QBrush(QColor(166,219,119));
    cout<<"cella inizializzata"<<endl;
}

QBrush Cella::getSfondo()
{
    return this->coloreSfondo;
}

void Cella::Paint(QPainter *painter,int elem)
{

    if(elem)
        coloreSfondo==Qt::white;

    painter->save();

    painter->translate(-0.5,-0.5);

    painter->setBrush(getSfondo());
    painter->drawRect(QRectF(0,0,1,1));

    painter->restore();

}

void Cella::Converti(int elem)
{
    if(elem)
        coloreSfondo==Qt::white;
}


*/
