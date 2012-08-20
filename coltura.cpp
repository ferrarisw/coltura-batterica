#include <iostream>
#include <QtGui>
#include <cmath>
#include "main.h"
#include "coltura.h"
#include "pilamatrici.h"
#include <cassert>
using namespace std;


Coltura::Coltura(int x, int y, int pattern, QWidget *parent) :
    QWidget(parent)
{
    this->x=x;
    this->y=y;
    GD1(cout<<"sono nel costruttore di coltura: this.x "<<this->x<<" this.y "<<this->y<<endl);
    assert(x>0);
    assert(y>0);
    pila=new PilaMatrici (x,y,pattern);
    GD1(cout<<"ho creato un nuovo oggetto PilaMatrici\n");


    minTime=30;
    maxTime=1000+minTime;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(aggiorna()));


    setGeometry(375,55,x*15,y*15);
    setMinimumSize(3*x,3*y);
    background=Qt::black;

    matrice=new int[(x+2)*(y+2)];
    matrice=pila->getMatrix();


    GD3(cout<<"stampo la matrice manualmente"<<endl;
    for(int j=1; j<y+1; j++)
    {
        for(int i=1; i<x+1; i++)
        {
            cout<<(matrice[i+j*(x+2)])<<" ";
        }
        cout<<endl;
    }
)
    GD2(cout<<"stampo la matrice utilizzando pila.stampa: "<<endl;
        pila->stampa()
            );
}

/**
 * @brief Coltura::paintEvent
 * @param event
 * Funzione chiamata ogni volta che avviene un evento sullo schermo.
 */
void Coltura::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    //painter.setRenderHint(QPainter::Antialiasing);
    paintColtura(&painter, event);
    painter.end();
}

/**
 * @brief Coltura::paintColtura
 * @param painter
 * @param event
 * Funzione che disegna il widget Coltura in base alla matrice generata da
 * pilaMatrici->next.
 * In particolare, prende l'oggetto locale @var matrice e lo scorre fino alla fine,
 * impostando diversamente il pennello a seconda del valore della cella, ovviamente
 * non prima di aver correttamente impostato le dimensioni delle caselle.
 */
void Coltura::paintColtura(QPainter * painter,QPaintEvent *event)
{

    const QRect *recta = &event->rect();
    painter->fillRect(event->rect(), background);

    qreal altezza_cella  = static_cast<qreal>(recta->height())/(y);
    qreal larghezza_cella= static_cast<qreal>(recta->width())/(x);

    painter->save();

    painter->scale(larghezza_cella,altezza_cella);

    GD3(cout<<"[Coltura::paintColtura] stampo la matrice mentre disegno il widget"<<endl)
    for(int j=1; j<y+1; j++)
    {
        for(int i=1; i<x+1; i++)
        {
            if(matrice[i+j*(x+2)]==1)//cellula viva
                colore=(Qt::white);
            else
                colore=(QBrush(QColor(0,0,30)));

            GD3(cout<<(matrice[i+j*(x+2)])<<" ");

            //painter->fillRect(-0.5,-0.5,1,1,colore);
            painter->setBrush(colore);
            painter->drawRect(-0.5,-0.5,1,1);
            painter->translate(1,0);
        }
        GD2(cout<<endl);
        painter->translate(-1*(x),1);
    }

    painter->restore();
}

//TODO: funzione paintColtura di debug

/**
 * @brief Coltura::getMaxTime
 * @return maxTime
 */
int Coltura::getMaxTime ()
{
    return maxTime;
}

/**
 * @brief Coltura::getMinTime
 * @return
 */
int Coltura::getMinTime()
{
    return minTime;
}

/**
 * @brief Coltura::aggiorna
 *
 */
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
        GD1(cout<<"millisecondi "<<(-((1./maxTime)*scatti*scatti)+maxTime)<<"\tvalore slider "<<scatti<<endl);
    }

}

void Coltura::changeDimension(int x)
{
    this->x=this->y=x;
}
