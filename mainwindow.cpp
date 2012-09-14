#include "main.h"

using namespace std;

MainWindow::MainWindow(int x, int y, int pattern, QWidget *parent)
    : QWidget(parent)
{
    GD1(cout<<"[MainWindow::MainWindow] dimensioni della matrice: "<<x<<" "<<y<<endl) ;

    this->coltura = new Coltura(x,y,pattern);
    GD1(cout<<"[MainWindow::MainWindow] ho creato il nuovo oggetto coltura"<<endl) ;

    file = new QMenu(tr("&File"));
    file->addAction(tr("&Nuova partita"),   this,   SLOT(newGame()  ));
    file->addAction(tr("&Salva"),           this,   SLOT(save()     ));
    //file->addAction(tr("&Carica"),          this,   SLOT(load()     ));

    help = new QMenu(tr("&Aiuto"));
    help->addAction(tr("&About"),          this,   SLOT(about()     ));
    help->addAction(tr("&Guida"),           this,   SLOT(guide()    ));

    menu = new QMenuBar();
    menu->addMenu(file);
    menu->addMenu("Modifica");
    menu->addMenu(help);
    
    stepByStep = new QPushButton(tr("passo passo"));
    connect(stepByStep, SIGNAL(clicked()), coltura, SLOT(aggiorna()));

    playButton = new QPushButton(tr("play"));
    playButton->setCheckable(true);
    connect(playButton, SIGNAL(toggled(bool)), this, SLOT(play(bool)));


    this->slider = new QSlider(Qt::Horizontal);
    this->slider->setMinimum(coltura->getMinTime());
    this->slider->setMaximum(coltura->getMaxTime());


    buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(playButton);
    buttonLayout->addWidget(stepByStep);

    layout = new QVBoxLayout;
    layout->addWidget(menu);
    layout->addWidget(coltura->timeSlider);
    layout->addWidget(coltura);
    layout->addWidget(slider);
    layout->addLayout(buttonLayout);


    setLayout(layout);


    setWindowTitle(tr("Coltura batterica"));
}

MainWindow::~MainWindow()
{//TODO memory leak!
    delete coltura;
    delete slider;
    delete file;
    delete help;
    delete menu;
    delete stepByStep;
    delete playButton;
    delete buttonLayout;
    delete layout;
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

void MainWindow::load()
{
    QString s = QFileDialog::getOpenFileName(0,"",tr("../saves"),"txt");
    coltura->load(s);
}
