#include "starter.h"
#include "main.h"

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

    mainwindow = new MainWindow;

    QSpinBox * dimension = new QSpinBox();
    connect(dimension, SIGNAL(valueChanged(int)),mainwindow,SLOT(changeDimension(int)));

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(dimension);

    setLayout(layout);
}

Starter::Starter(QWidget *parent) :
    QWidget(parent)
{
    GD2(cout<<"costruttore di starter"<<endl);

    qreal x=300;
    qreal y=250;
    qreal width=300;
    qreal height=250;
    this->setGeometry(x,y,width,height);

    mainwindow = new MainWindow;

    QSpinBox * dimension = new QSpinBox();
    connect(dimension, SIGNAL(valueChanged(int)),mainwindow,SLOT(changeDimension(int)));

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(dimension);

    setLayout(layout);
}
