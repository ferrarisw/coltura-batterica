#include "main.h"

using namespace std;

MainWindow::MainWindow(int x, int y, int pattern, QWidget *parent)
    : QWidget(parent)
{
    GD1(cout<<"[MainWindow::MainWindow] dimensioni della matrice: "<<x<<" "<<y<<endl) ;

    this->coltura = new Coltura(x,y,pattern);
    GD1(cout<<"[MainWindow::MainWindow] ho creato il nuovo oggetto coltura"<<endl) ;

    QMenu * file = new QMenu(tr("&File"));
    file->addAction(tr("&Nuova partita"),this,SLOT(newGame()));
    file->addAction(tr("&Salva"),this,SLOT(save()));

    QMenuBar * menu = new QMenuBar();
    menu->addMenu(file);
    menu->addMenu("Modifica");
    menu->addMenu("Help");
    
    QPushButton * stepByStep = new QPushButton(tr("step by step"));
    connect(stepByStep, SIGNAL(clicked()), coltura, SLOT(aggiorna()));

    QPushButton * play = new QPushButton(tr("play"));
    play->setCheckable(true);
    connect(play, SIGNAL(toggled(bool)), this, SLOT(play(bool)));


    this->slider = new QSlider(Qt::Horizontal);
    this->slider->setMinimum(coltura->getMinTime());
    this->slider->setMaximum(coltura->getMaxTime());


    QHBoxLayout * buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(play);
    buttonLayout->addWidget(stepByStep);

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(menu);
    layout->addWidget(coltura->timeSlider);
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
    {
        coltura->play(slider->value());
        connect(slider,SIGNAL(valueChanged(int)),coltura,SLOT(play(int)));
    }
    else
    {
        coltura->play(0);
        disconnect(slider,SIGNAL(valueChanged(int)),coltura,SLOT(play(int)));
    }

}
void MainWindow::newGame()
{
    this->deleteLater();

    Starter * starter = new Starter();
    starter->show();
}

void MainWindow::save()
{
    QString s = QFileDialog::getSaveFileName();
    coltura->save(s);
}
