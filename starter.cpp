#include "starter.h"
#include "main.h"
#include <QtGui>
#include "cassert"

Starter::Starter(QPaintEvent * event, QWidget *parent) :
    QWidget(parent)
{
    GD2(cout<<"costruttore di starter"<<endl);

    const QRect *recta = &event->rect();
    qreal x=300;
    qreal y=250;
    qreal width=recta->width()/2-x;
    qreal height=recta->height()/2 -y;
    this->setGeometry(x,y,width,height);


    QSpinBox * dimension = new QSpinBox();
    connect(dimension, SIGNAL(valueChanged(int)),mainwindow,SLOT(changeDimension(int)));

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(dimension);

    setLayout(layout);
}

Starter::Starter(QWidget *parent) :
    QWidget(parent)
{
    GD1(cout<<"[Starter] : costruttore"<<endl);

    qreal x=300;
    qreal y=250;
    qreal width=300;
    qreal height=250;
    this->setGeometry(x,y,width,height);

    //this->x=10;
   // this->y=5;


    QSpinBox * xdimension = new QSpinBox();
    xdimension->setValue(50);
    xdimension->setMinimum(0);
    xdimension->setMaximum(500);
    connect(xdimension, SIGNAL(valueChanged(int)),this,SLOT(changeXDimension(int)));
    GD2(cout<<"[Starter::Starter] ho inizializzato lo spinbox e connesso i segnali"<<endl);

    QSpinBox * ydimension = new QSpinBox();
    ydimension->setValue(50);
    ydimension->setMinimum(0);
    ydimension->setMaximum(500);
    connect(ydimension, SIGNAL(valueChanged(int)),this,SLOT(changeYDimension(int)));
    GD2(cout<<"[Starter::Starter] ho inizializzato lo spinbox e connesso i segnali"<<endl);

    GD3(cout<<"[Starter::Starter] dimensioni di x e y: "<<this->x<<" "<<this->y<<endl);

    QPushButton * ok = new QPushButton("Ok");
    connect(ok, SIGNAL(clicked()),this,SLOT(avvio()));
    GD2(cout<<"[Starter::Starter] inizializzato il pushbutton e connesso i segnali"<<endl);

    QHBoxLayout * spinboxes = new QHBoxLayout();
    spinboxes->addWidget(xdimension);
    spinboxes->addWidget(ydimension);

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addLayout(spinboxes);
    layout->addWidget(ok);

    setLayout(layout);
    GD3(cout<<"[Starter::Starter] sistemato il layout"<<endl;)
}

void Starter::avvio()
{

    GD2(cout<<x<<" "<<y<<endl);

    assert(x>0);
    assert(y>0);


    MainWindow * finestra = new MainWindow(x,y);
    finestra->show();

    this->close();
}

void Starter::changeXDimension(int dim)
{

    this->x=dim;
}

void Starter::changeYDimension(int dim)
{
    GD2(cout<<"valore di y"<<y<<endl);
    this->y=dim;
}
