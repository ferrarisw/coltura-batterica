#include "coltura.h"
#include "cella.h"
#include <QtGui>
#include <iostream>
using namespace std;



Coltura::Coltura(int x, int y,int * mat,QWidget *parent) :
    QWidget(parent)
{
    setGeometry(375,55,x*20,y*20);
    background=Qt::black;

    this->x=x;
    this->y=y;
    this->matrice=new int [x*y];

    matrice=mat;

    GDEB(cout<<"creazione dell'oggetto coltura: controllo che l'inizializzazione sia corretta:"
          "this.x "<<this->x<<" this.y "<<this->y<<endl);
    GDEB(cout<<"stampo la matrice: "<<endl;
            for(int j=0; j<x+2; j++)
            {
                for(int i=0; i<y+2; i++)
                {
                    cout<<(matrice[i+j*(x+2)])<<" ";
                }
                cout<<endl;
            });

}

Coltura::Coltura()
{
    setGeometry(375,55,600,500);
    background=Qt::black;
    GDEB(cerr<<"questo costruttore non inizializza la matrice!")
}

Coltura::~Coltura()
{
    delete matrice;
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

    qreal altezza_cella  = static_cast<qreal>(recta->height())/(y);
    qreal larghezza_cella= static_cast<qreal>(recta->width())/(x);

    //GDEB(cout<<"disegno una matrice di dimensioni "<<x<<" "<<y<<", senza \"bordo\""<<endl);

    painter->save();

    painter->scale(larghezza_cella,altezza_cella);

    for(int j=1; j<=x; j++)
    {
        for(int i=1; i<=y; i++)
        {
            if(matrice[i+j*(x+2)])//cellula viva
                painter->setBrush(Qt::white);
            else
                painter->setBrush(Qt::red);

            painter->drawRect(-0.5,-0.5,1,1);
            painter->translate(1,0);
        }
        painter->translate(-1*(y),1);
    }

    painter->restore();
}



/* funzione di debug: disegna la matrice completa, di dimensioni fisse.
 * la costante debug viene utilizzata solo per differenziare le funzioni
 */
void Coltura::paintColtura(QPainter * painter,QPaintEvent *event, const char * debug)
{
    GDEB(cout<<"disegno una matrice di dimensioni "<<x<<" "<<y<<", con il \"bordo\""<<endl);

    GDEB(for(int j=0; j<x+2; j++)
        {
            for(int i=0; i<y+2; i++)
            {
                if(matrice[i+j*(x+2)])//cellula viva
                    painter->setBrush(Qt::white);
                else
                    painter->setBrush(Qt::red);

                painter->translate(12,0);
                painter->drawRect(10,10,10,10);
            }
            painter->translate(-12*(y+2),10);
        });

}

