#include "coltura.h"
#include <cmath>
#include <cassert>
#include <iostream>
using namespace std;

Coltura::Coltura(int x, int y, int pattern, QWidget *parent) :
    QWidget(parent)
{
    GD1(cout<<"[Coltura::Coltura] x "<<x<<" y "<<y<<endl);
    this->x=x;
    this->y=y;
    assert(x>0);
    assert(y>0);

    pila=new PilaMatrici (x,y,pattern);
    GD1(cout<<"[Coltura::Coltura] ho creato un nuovo oggetto PilaMatrici\n");

    minTime=30;
    maxTime=1000+minTime;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(aggiorna()));


    setMinimumSize(3*x,3*y);
    background=Qt::black;

    matrice=new int[(x+2)*(y+2)];
    matrice=pila->getMatrix();

    timeSlider = new QSlider(Qt::Horizontal);
    timeSlider->setMaximumHeight(20);
    timeSlider->setMinimumHeight(20);
    timeSlider->setMinimum(0);
    timeSlider->setMaximum(0);
    timeSlider->setValue(0);
    //connect(timeSlider,SIGNAL(sliderMoved(int)),this,SLOT(timeTrip(int)));
    connect(timeSlider,SIGNAL(valueChanged(int)),this,SLOT(timeTrip(int)));
    GD3(cout<<"[Coltura::Coltura] stampo la matrice manualmente"<<endl;

    for(int j=1; j<y+1; j++)
    {
        for(int i=1; i<x+1; i++)
        {
            cout<<(matrice[i+j*(x+2)])<<" ";
        }
        cout<<endl;
    }
)
    GD2(cout<<"[Coltura::Coltura] stampo la matrice utilizzando pila.stampa: "<<endl;
        pila->stampa());

}

Coltura::~Coltura()
{
    delete pila;
    delete timer;
    delete timeSlider;
}

void Coltura::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    //painter.setRenderHint(QPainter::Antialiasing);

    if(MASK>=8)//livello GD3 attivo
        paintColtura(&painter, event, "debug");
    else
        paintColtura(&painter, event);
    painter.end();
}

void Coltura::paintColtura(QPainter * painter,QPaintEvent *event)
{
    matrice=pila->getMatrix();

    const QRect *recta = &event->rect();
    painter->fillRect(event->rect(), background);

    qreal altezza_cella  = static_cast<qreal>(recta->height())/(y);
    qreal larghezza_cella= static_cast<qreal>(recta->width())/(x);

    painter->save();

    painter->scale(larghezza_cella,altezza_cella);

    for(int j=1; j<y+1; j++)
    {
        for(int i=1; i<x+1; i++)
        {
            if(matrice[i+j*(x+2)]==1)//cellula viva
                colore=(Qt::white);
            else
                colore=(QBrush(QColor(0,0,30)));


            //painter->fillRect(-0.5,-0.5,1,1,colore);
            painter->setBrush(colore);
            painter->drawRect(-0.5,-0.5,1,1);
            painter->translate(1,0);
        }

        painter->translate(-x,1);
    }

    painter->restore();
}

void Coltura::paintColtura(QPainter * painter, QPaintEvent *event, const char *)
{

    const QRect *recta = &event->rect();
    painter->fillRect(event->rect(), background);

    qreal altezza_cella  = static_cast<qreal>(recta->height())/(y+2);
    qreal larghezza_cella= static_cast<qreal>(recta->width())/(x+2);

    painter->save();

    painter->scale(larghezza_cella,altezza_cella);

    for(int j=0; j<y+2; j++)
    {
        for(int i=0; i<x+2; i++)
        {
            if(matrice[i+j*(x+2)]==1)//cellula viva
                colore=(Qt::white);
            else
                colore=(QBrush(QColor(0,0,30)));

            painter->fillRect(-0.5,-0.5,1,1,colore);
            //painter->setBrush(colore);
            //painter->drawRect(-0.5,-0.5,1,1);
            painter->translate(1,0);
        }

        painter->translate(-x-2,1);
    }

    painter->restore();
}

void Coltura::draw(QPainter * painter)
{

   /* if(3*x>screen_width || 3*y>screen_height)
        painter->fillRect(-0.5,-0.5,1,1,colore);
    else
    {
        painter->setBrush(colore);
        painter->drawRect(-0.5,-0.5,1,1);
    }*/
}

void Coltura::aggiorna()
{
    matrice=pila->next();
    int value=timeSlider->value();
    int max=timeSlider->maximum();

    if(value==max)
    {
        timeSlider->setMaximum(++max);
        timeSlider->setValue(++value);
    }
    else
    {
        timeSlider->setValue(++value);
    }
    GD3(cout<<"[Coltura::aggiorna] value: "<<value<<" maximum: "<<max<<endl);
    this->repaint();
}

int Coltura::getMaxTime ()
{
    return maxTime;
}

int Coltura::getMinTime()
{
    return minTime;
}

void Coltura::play(int scatti)
{
    if (scatti == 0)
        timer->stop();
    else {
        timer->start(-((1./maxTime)*scatti*scatti)+maxTime);

        GD1(cout<<"[Coltura::play] millisecondi "<<
            (-((1./maxTime)*scatti*scatti)+maxTime)<<
            "\tvalore slider "<<scatti<<endl);
    }

}

void Coltura::timeTrip(int time)
{
    GD2(cout<<"[Coltura::timeTrip] time "<<time<<endl);
    pila->timeTrip(time);
    repaint();
}
