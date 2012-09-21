#include "starter.h"
#include "debug.h"

Starter::Starter(QWidget *parent) :
    QMainWindow(parent)
{
    GD1(cout<<"[Starter] : costruttore"<<endl);

    qreal x=500;
    qreal y=250;
    qreal width=20;
    qreal height=10;
    this->setGeometry(x,y,width,height);

    this->x=50;
    this->y=50;
    this->pattern=0;

    menuBar()->addAction(tr("&Carica.."),       this,   SLOT(load()     ));

    menuBar()->addAction(tr("&About"),          this,   SLOT(about()     ));

    QLabel      * descrizione   =   new QLabel;
    descrizione->setText(tr("inserisci le dimensioni della coltura"));
    descrizione->setAlignment(Qt::AlignCenter);


    QSpinBox    * xdimension    =   new QSpinBox();
    xdimension->setValue(50);
    xdimension->setMinimum(0);
    xdimension->setMaximum(500);
    connect(xdimension, SIGNAL(valueChanged(int)),this,SLOT(changeXDimension(int)));

    GD2(cout<<"[Starter::Starter] ho inizializzato lo spinbox e connesso i segnali"<<endl);


    QLabel      * etichettaX    =   new QLabel;
    etichettaX->setText(tr("larghezza"));


    QSpinBox    * ydimension    =   new QSpinBox();
    ydimension->setValue(50);
    ydimension->setMinimum(0);
    ydimension->setMaximum(500);
    connect(ydimension, SIGNAL(valueChanged(int)),this,SLOT(changeYDimension(int)));

    GD2(cout<<"[Starter::Starter] ho inizializzato lo spinbox e connesso i segnali"<<endl);


    QLabel      * etichettaY    =   new QLabel;
    etichettaY->setText(tr("altezza"));

    GD3(cout<<"[Starter::Starter] dimensioni di x e y: "<<this->x<<" "<<this->y<<endl);


    QPushButton * ok            =   new QPushButton(tr("Ok"));
    connect(ok, SIGNAL(clicked()),this,SLOT(avvio()));

    GD2(cout<<"[Starter::Starter] inizializzato il pushbutton e connesso i segnali"<<endl);


    QLabel      * patternDesc   =   new QLabel;
    patternDesc->setText(tr("specifica la disposizione iniziale delle cellule"));
    //patternDesc->setTextFormat(QTextFormat::PageBreak_Auto);

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


}

Starter::~Starter()
{

}

void Starter::avvio()
{

    GD2(cout<<x<<" "<<y<<endl);

    assert(x>0);
    assert(y>0);
    assert(pattern>=0);

    mainwindow = new MainWindow(x,y,pattern);
    mainwindow->show();

    this->deleteLater();
}


void Starter::changeXDimension(int dim)
{
    this->x=dim;
    GD2(cout<<"modificato x: "<<x<<endl);
}


void Starter::changeYDimension(int dim)
{
    this->y=dim;
    GD2(cout<<"modificato y: "<<y<<endl);
}


void Starter::setPattern(int position)
{
    this->pattern=position;
    GD2(cout<<"position: "<<position);
}

//TODO non funziona
void Starter::load()
{
    mainwindow = new MainWindow(1,1,99);
    mainwindow->load();
    mainwindow->show();

    this->deleteLater();
}

//TODO lo trasformo in widget?
void Starter::about()
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

void Starter::closeEvent(QCloseEvent * closeEvent)
{
    closeEvent->ignore();

    TRACE("[Starter::closeEvent]");

    closingalert = new ClosingAlert();

    connect(closingalert->buttons,SIGNAL(accepted()),this,SLOT(closing()));
    connect(closingalert->buttons,SIGNAL(rejected()),closingalert,SLOT(close()));

    closingalert->show();

}

void Starter::closing()
{
    this->deleteLater();
    closingalert->deleteLater();
}

