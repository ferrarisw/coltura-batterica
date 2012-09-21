#include "main.h"


using namespace std;

MainWindow::MainWindow(int x, int y, int pattern, QWidget *parent):
    QMainWindow(parent)
{
    this->setGeometry(500,250,1,1);
    GD1(cout<<"[MainWindow::MainWindow] dimensioni della matrice: "<<x<<" "<<y<<endl) ;

    this->coltura = new Coltura(x,y,pattern);
    GD1(cout<<"[MainWindow::MainWindow] ho creato il nuovo oggetto coltura"<<endl) ;

    file = menuBar()->addMenu(tr("&File"));
    file->addAction(tr("&Nuova partita"),   this,   SLOT(newGame()  ));
    file->addAction(tr("&Salva"),           this,   SLOT(save()     ));
    file->addAction(tr("&Carica"),          this,   SLOT(load()     ));

    help = menuBar()->addMenu(tr("&Aiuto"));
    help->addAction(tr("&About"),          this,   SLOT(about()     ));

    
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

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(coltura->timeSlider);
    layout->addWidget(coltura);
    layout->addWidget(slider);
    layout->addLayout(buttonLayout);

    QWidget * central = new QWidget();

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
    this->resize(minimumSize());

    setWindowTitle(tr("Coltura batterica"));
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
    QString s = QFileDialog::getSaveFileName(this, tr("Apri File"),"./saves",tr("Runner file (*.runner)"));
    coltura->save(s);
}

void MainWindow::load()
{
    QString s = QFileDialog::getOpenFileName(this, tr("Apri File"),"./saves",tr("Runner file (*.runner)"));
    coltura->load(s);
    this->resize(minimumSize());
}

void MainWindow::about()
{
    QWidget * about = new QWidget();
    about->setGeometry(500,250,1,1);
    QLabel * label = new QLabel(tr("//TODO about"));
    QPushButton * ok = new QPushButton(tr("ok"));
    connect(ok,SIGNAL(clicked()),about,SLOT(deleteLater()));

    QVBoxLayout layout;
    layout.addWidget(label);
    layout.addWidget(ok);

    about->setLayout(&layout);
    about->show();

}

void MainWindow::closeEvent(QCloseEvent * closeEvent)
{
    closeEvent->ignore();

    TRACE("[MainWindow::closeEvent]");
    closingalert = new ClosingAlert();

    connect(closingalert->buttons,SIGNAL(accepted()),this,SLOT(closing()));
    connect(closingalert->buttons,SIGNAL(rejected()),closingalert,SLOT(close()));

    closingalert->show();
}

void MainWindow::closing()
{
    this->deleteLater();
    closingalert->deleteLater();
}
