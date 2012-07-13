#include "mainwindow.h"
#include "coltura.h"
#include <iostream>
#include <QtGui>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    GDEB(cout<<"sono nel costruttore di mainwindow"<<endl);
    int x=130,y=130;
    this->coltura = new Coltura(x,y);
    GDEB(cout<<"[mainwindow] ho creato il nuovo oggetto coltura"<<endl);


    QPushButton * stepByStep = new QPushButton("step by step");
    connect(stepByStep, SIGNAL(clicked()), coltura, SLOT(aggiorna()));

    QPushButton * play = new QPushButton("play");
    play->setCheckable(true);
    connect(play, SIGNAL(toggled(bool)), this, SLOT(play(bool)));


    this->slider = new QSlider(Qt::Horizontal);
    this->slider->setMinimum(0);
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
    if (playing == true) {
        coltura->play(slider->value());
        connect(slider,SIGNAL(valueChanged(int)),coltura,SLOT(play(int)));
    }
    else
        disconnect(slider,SIGNAL(valueChanged(int)),coltura,SLOT(play(int)));
}
