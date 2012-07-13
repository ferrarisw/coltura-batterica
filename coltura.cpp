#include <iostream>
#include <QtGui>
#include <cmath>
#include "main.h"
#include "coltura.h"
#include "pilamatrici.h"
using namespace std;


Coltura::Coltura(int x, int y,QWidget *parent) :
    QWidget(parent)
{
    this->x=x;
    this->y=y;
    GD1(cout<<"sono nel costruttore di coltura: this.x "<<this->x<<" this.y "<<this->y<<endl);
    pila=new PilaMatrici (x,y);
    GD1(cout<<"ho creato un nuovo oggetto PilaMatrici");


    maxTime=1000;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(aggiorna()));


    setGeometry(375,55,x*15,y*15);
    setMinimumSize(5*x,5*y);
    background=Qt::black;

    matrice=new int[(x+2)*(y+2)];
    pila->stampa();
    matrice=pila->next();


    GD1(cout<<"stampo la matrice manualmente"<<endl;)
    for(int j=1; j<y+1; j++)
    {
        for(int i=1; i<x+1; i++)
        {
            GD1(cout<<(matrice[i+j*(x+2)])<<" ");
        }
        GD1(cout<<endl);
    }

    GD2(cout<<"stampo la matrice utilizzando pila.stampa: "<<endl;
        pila->stampa());

}

void Coltura::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    //painter.setRenderHint(QPainter::Antialiasing);
    paintColtura(&painter, event);
    painter.end();
}

void Coltura::paintColtura(QPainter * painter,QPaintEvent *event)
{

    const QRect *recta = &event->rect();
    painter->fillRect(event->rect(), background);

    qreal altezza_cella  = static_cast<qreal>(recta->height())/(y);
    qreal larghezza_cella= static_cast<qreal>(recta->width())/(x);

    painter->save();

    painter->scale(larghezza_cella,altezza_cella);

    GD2(cout<<"[Coltura::paintColtura] stampo la matrice mentre disegno il widget"<<endl)
    for(int j=1; j<y+1; j++)
    {
        for(int i=1; i<x+1; i++)
        {
            if(matrice[i+j*(x+2)]==1)//cellula viva
                painter->setBrush(Qt::white);
            else
                painter->setBrush(QBrush(QColor(0,0,30)));

            GD2(cout<<(matrice[i+j*(x+2)])<<" ");
            painter->drawRect(-0.5,-0.5,1,1);
            painter->translate(1,0);
        }
        GD2(cout<<endl);
        painter->translate(-1*(y),1);
    }

    painter->restore();
}



/* funzione di debug: disegna la matrice completa, di dimensioni fisse.
 * la costante debug viene utilizzata solo per differenziare le funzioni
 *
void Coltura::paintColtura(QPainter * painter, QPaintEvent *event, const char *debug)
{
    GD1(cout<<"disegno una matrice di dimensioni "<<x<<" "<<y<<", con il \"bordo\""<<endl);

    GD1(for(int j=0; j<x+2; j++)
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

}*/

int Coltura::getMaxTime ()
{
    return maxTime;
}


void Coltura::aggiorna()
{
    matrice=pila->next();

    this->repaint();
}


void Coltura::play(int scatti)
{
    if (scatti == 0)
        timer->stop();
    else {
        timer->start(-((1./maxTime)*scatti*scatti)+maxTime);
        GD1(cout<<"valore "<<(-((1./maxTime)*scatti*scatti)+maxTime)<<"\tscatti "<<scatti<<endl);
    }

}
