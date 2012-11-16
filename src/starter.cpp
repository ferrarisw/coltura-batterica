#include "starter.h"
#include "debug.h"
#include "about.h"
using namespace std;

Starter::Starter(QWidget *parent) :
    QMainWindow(parent)
{

    GD1(cout<<"[Starter::Starter]"<<endl);



    this->dx=100;
    this->dy=75;
    this->pattern=0;

    file = new QMenu();
    file = menuBar()->addMenu(tr("&File"));
    file->addAction(tr("&Carica"),      this,   SLOT(load()     ));
    file->addAction(tr("&Chiudi"),      this,   SLOT(closing()  ));

    menuBar()->addAction(tr("&About"),  this,   SLOT(openAbout()   ));

    QLabel      * descrizione   =   new QLabel;
    descrizione->setText(tr("Inserisci le dimensioni della coltura"));
    descrizione->setAlignment(Qt::AlignCenter);


    QSpinBox    * xdimension    =   new QSpinBox();
    xdimension->setRange(0,600);
    xdimension->setValue(dx);
    connect(xdimension, SIGNAL(valueChanged(int)),this,SLOT(changeXDimension
                                                            (int)));

    GD2(cout<<"[Starter::Starter] ho inizializzato lo spinbox e connesso i segnali"<<endl);


    QLabel      * etichettaX    =   new QLabel;
    etichettaX->setText(tr("Larghezza"));


    QSpinBox    * ydimension    =   new QSpinBox();
    ydimension->setRange(0,400);
    ydimension->setValue(dy);
    connect(ydimension, SIGNAL(valueChanged(int)),this,SLOT(changeYDimension
                                                            (int)));

    GD2(cout<<"[Starter::Starter] ho inizializzato lo spinbox e connesso segnali"<<endl);


    QLabel      * etichettaY    =   new QLabel;
    etichettaY->setText(tr("Altezza"));

    GD3(cout<<"[Starter::Starter] dimensioni di x e y: "<<this->dx<<" "<<
        this->dy<<endl);


    QPushButton * ok            =   new QPushButton(tr("Ok"));
    connect(ok, SIGNAL(clicked()),this,SLOT(avvio()));

    GD2(cout<<"[Starter::Starter] inizializzato il pushbutton e connesso i segnali"<<endl);


    QLabel      * patternDesc   =   new QLabel;
    patternDesc->setText(tr("Specifica la disposizione iniziale delle cellule"
                            ));

    QComboBox   * patterns      =   new QComboBox;
    QStringList list;
    list<<"Casuale"<<
          "Righe Verticali (ideale con larghezza pari)"<<
          "Diagonali"<<
          "Righe Verticali Spesse (ideale con larghezza pari)"<<
          "Linea Retta (ideale con altezza dispari)";

    patterns->addItems(list);
    patterns->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
    connect(patterns,SIGNAL(activated(int)),this,SLOT(setPattern(int)));

    QGridLayout * spinboxes     =   new QGridLayout();
    spinboxes->addWidget(etichettaX,0,0,Qt::AlignHCenter );
    spinboxes->addWidget(etichettaY,0,1,Qt::AlignHCenter );
    spinboxes->addWidget(xdimension,1,0,Qt::AlignHCenter | Qt::AlignTop);
    spinboxes->addWidget(ydimension,1,1,Qt::AlignHCenter | Qt::AlignTop);

    QVBoxLayout * layout        =   new QVBoxLayout();
    layout->addWidget(descrizione,Qt::AlignCenter);
    layout->addLayout(spinboxes);
    layout->addWidget(patternDesc);
    layout->addWidget(patterns);
    layout->addWidget(ok);

    QHBoxLayout * setting       =   new QHBoxLayout();
    setting->addLayout(layout);
#ifdef DEBUG_MODE
    debug = new Debug();
    setting->addWidget(debug);
#endif

    QWidget * central = new QWidget();
    central->setLayout(setting);

    this->setCentralWidget(central);


    GD3(cout<<"[Starter::Starter] layout settato\n\n");

    /*sposto il widget al centro dello schermo*/
    int x = screenX/2 - this->sizeHint().width()/2;
    int y = screenY/2 - this->sizeHint().height()/2;
    this->move(x,y);
    GD2(cout<<"[Starter::Starter] dimensioni this: "<<this->sizeHint().width()<<"*"
        <<this->sizeHint().height());

    closingalert = new ClosingAlert(x + this->sizeHint().width(), y);
    about = new About();
    GD1(cout<<"[Starter::Starter] ho creato i widget about e closingalert");

    setWindowTitle(tr("Life Runner: nuova partita"));
}

Starter::~Starter()
{
    delete closingalert;
    delete about;
    delete file;
    GD1(cout<<"[Starter:~Starter] oggetto deallocato correttamente"<<endl);
}

void Starter::avvio()
{

    GD2(cout<<x<<" "<<y<<endl);

    assert(dx>0);
    assert(dy>0);
    assert(pattern>=0);

    mainwindow = new MainWindow(dx,dy,pattern);
    mainwindow->show();

    this->deleteLater();
}

void Starter::changeXDimension(int dim)
{
    this->dx=dim;
    GD2(cout<<"modificato x: "<<dx<<endl);
}

void Starter::changeYDimension(int dim)
{
    this->dy=dim;
    GD2(cout<<"modificato y: "<<dy<<endl);
}

void Starter::setPattern(int position)
{
    this->pattern=position;
    GD2(cout<<"position: "<<position);
}


void Starter::load()
{
    mainwindow = new MainWindow(1,1,99);
    if(mainwindow->load())
    {
        mainwindow->show();
        this->deleteLater();
    }
    else
    {
        delete mainwindow;
    }
}


void Starter::openAbout()
{
    about->show();
}

void Starter::closeEvent(QCloseEvent * closeEvent)
{
    closeEvent->ignore();

    TRACE("[Starter::closeEvent]");

    connect(closingalert->buttons,SIGNAL(accepted()),this,SLOT(closing()));
    connect(closingalert->buttons,SIGNAL(rejected()),closingalert,
            SLOT(close()));

    closingalert->show();

}

void Starter::closing()
{
    this->deleteLater();
    closingalert->deleteLater();
    about->deleteLater();
}

