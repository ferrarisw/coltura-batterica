#include "main.h"
using namespace std;

MainWindow::MainWindow(int dx, int dy, int pattern, QWidget *parent):
    QMainWindow(parent)
{

    file = menuBar()->addMenu(tr("&File"));
    file->addAction(tr("&Nuova partita"),   this,   SLOT(newGame()  ));
    file->addAction(tr("&Salva"),           this,   SLOT(save()     ));
    file->addAction(tr("&Carica"),          this,   SLOT(load()     ));
    file->addAction(tr("&Chiudi"),          this,   SLOT(closing()  ));

    help = menuBar()->addMenu(tr("&Aiuto"));
    help->addAction(tr("&About"),          this,   SLOT(openAbout()     ));

    QLabel * tempo = new QLabel(tr("Timeline"));
    tempo->setAlignment(Qt::AlignCenter);
    tempo->setFixedHeight(tempo->minimumSizeHint().height());

    GD1(cout<<"[MainWindow::MainWindow] dimensioni della matrice: "
        <<dx<<" "<<dy<<endl) ;
    this->coltura = new Coltura(dx,dy,pattern);
    GD1(cout<<"[MainWindow::MainWindow] ho creato il nuovo oggetto coltura"
        <<endl) ;

    QLabel * velocita = new QLabel(tr("Velocita`"));
    velocita->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
    velocita->setFixedHeight(velocita->minimumSizeHint().height());

    slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(coltura->getMinTime());
    slider->setMaximum(coltura->getMaxTime());
    slider->setFixedHeight(slider->minimumSizeHint().height());

    stepByStep = new QPushButton(tr("passo passo"));
    connect(stepByStep, SIGNAL(clicked()), coltura, SLOT(aggiorna()));

    playButton = new QPushButton(tr("play"));
    playButton->setCheckable(true);
    connect(playButton, SIGNAL(toggled(bool)), this, SLOT(play(bool)));

    buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(playButton);
    buttonLayout->addWidget(stepByStep);

    layout = new QVBoxLayout;
    layout->addWidget(tempo);
    layout->addWidget(coltura->timeSlider);
    layout->addWidget(coltura);
    layout->addWidget(velocita);
    layout->addWidget(slider);
    layout->addLayout(buttonLayout);

    central = new QWidget();

#ifdef DEBUG_MODE
    Debug * debug = new Debug();

    QHBoxLayout * setting = new QHBoxLayout();
    setting->addLayout(layout);
    setting->addWidget(debug);

    central->setLayout(setting);
#else
    central->setLayout(layout);
#endif

    this->setCentralWidget(central);
    coltura->resize(coltura->minimumSize());
    this->resize(minimumSize());

    /*sposto il widget al centro dello schermo*/
    int x = screenX/2 - this->sizeHint().width()/2;
    int y = screenY/2 - this->sizeHint().height()/2;
    this->move(x,y);
    GD2(cout<<"[Starter::Starter] dimensioni this: "<<this->sizeHint().width()<<"*"
        <<this->sizeHint().height());

    closingalert = new ClosingAlert(x + this->sizeHint().width(), y);
    about = new About();

    setWindowTitle(tr("Life Runner"));
}

MainWindow::~MainWindow()
{
    delete coltura;
    delete slider;
    delete file;
    delete help;
    delete stepByStep;
    delete playButton;
    delete buttonLayout;
    delete layout;
    delete closingalert;
    delete about;
    delete central;
    GD1(cout<<"[MainWindow:~MainWindow] oggetto deallocato correttamente"
        <<endl);
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
    QString s = QFileDialog::getSaveFileName(this, tr("Salva"),"saves",
                                        "Runner file (*.runner);;all (*.*)");
    coltura->save(s);
}

bool MainWindow::load()
{
    QString s = QFileDialog::getOpenFileName(this, tr("Carica"),"saves",
                                        "Runner file (*.runner);;all (*.*");
    bool ret = coltura->load(s);
    GD1(cout<<"[MainWindow::load] stato load: "<<ret<<endl;)
    this->resize(minimumSize());
    return ret;
}

void MainWindow::openAbout()
{
    about->show();
}

void MainWindow::closeEvent(QCloseEvent * closeEvent)
{
    closeEvent->ignore();

    TRACE("[MainWindow::closeEvent]");

    connect(closingalert->buttons,SIGNAL(accepted()),this,SLOT(closing()));
    connect(closingalert->buttons,SIGNAL(rejected()),closingalert,
            SLOT(close()));

    closingalert->show();
}

void MainWindow::closing()
{
    this->deleteLater();
    closingalert->deleteLater();
}
