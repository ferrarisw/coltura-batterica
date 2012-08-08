#include <iostream>
#include <QtGui>
#include "main.h"
#include "mainwindow.h"
#include "coltura.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    GD1(cout<<"sono nel costruttore di mainwindow"<<endl) ;
    dim=500;

    this->coltura = new Coltura(dim,dim);
    GD1(cout<<"[mainwindow] ho creato il nuovo oggetto coltura"<<endl) ;


    QPushButton * stepByStep = new QPushButton("step by step");
    connect(stepByStep, SIGNAL(clicked()), coltura, SLOT(aggiorna()));

    QPushButton * play = new QPushButton("play");
    play->setCheckable(true);
    connect(play, SIGNAL(toggled(bool)), this, SLOT(play(bool)));


    this->slider = new QSlider(Qt::Horizontal);
    this->slider->setMinimum(coltura->getMinTime());
    this->slider->setMaximum(coltura->getMaxTime());


    QHBoxLayout * buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(play);
    buttonLayout->addWidget(stepByStep);

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(coltura);
    layout->addWidget(slider);
    layout->addLayout(buttonLayout);


    setLayout(layout);


    setWindowTitle(tr("Coltura batterica"));
}

MainWindow::~MainWindow()
{

}

void MainWindow::play(bool toggled)
{
    playing = toggled;

    if (playing == true)
        coltura->play(slider->value());
    else
        coltura->play(0);

    connect(slider,SIGNAL(valueChanged(int)),coltura,SLOT(play(int)));
}

void MainWindow::changeDimension(int dim)
{
    this->dim=dim;

}
