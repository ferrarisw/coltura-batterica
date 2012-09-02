#include "starter.h"
#include "main.h"
#include <QtGui>
#include "cassert"


Starter::Starter(QWidget *parent) :
    QWidget(parent)
{
    GD1(cout<<"[Starter] : costruttore"<<endl);

    qreal x=500;
    qreal y=250;
    qreal width=250;
    qreal height=220;
    this->setGeometry(x,y,width,height);

    this->x=50;
    this->y=50;
    this->pattern=0;


  //  QIcon  icon;
   // icon.addFile("./batteritrasp.png",QSize(400,344));
   // icon.Active;
   // setWindowIcon(icon);

    QLabel * descrizione = new QLabel;
    descrizione->setText("inserisci le dimensioni della coltura");
    descrizione->setAlignment(Qt::AlignCenter);


    QSpinBox * xdimension = new QSpinBox();
    xdimension->setValue(50);
    xdimension->setMinimum(0);
    xdimension->setMaximum(500);
    connect(xdimension, SIGNAL(valueChanged(int)),this,SLOT(changeXDimension(int)));
    GD2(cout<<"[Starter::Starter] ho inizializzato lo spinbox e connesso i segnali"<<endl);

    QLabel * etichettaX = new QLabel;
    etichettaX->setText("larghezza");


    QSpinBox * ydimension = new QSpinBox();
    ydimension->setValue(50);
    ydimension->setMinimum(0);
    ydimension->setMaximum(500);
    connect(ydimension, SIGNAL(valueChanged(int)),this,SLOT(changeYDimension(int)));
    GD2(cout<<"[Starter::Starter] ho inizializzato lo spinbox e connesso i segnali"<<endl);

    QLabel * etichettaY = new QLabel;
    etichettaY->setText("altezza");

    GD3(cout<<"[Starter::Starter] dimensioni di x e y: "<<this->x<<" "<<this->y<<endl);

    QPushButton * ok = new QPushButton("Ok");
    connect(ok, SIGNAL(clicked()),this,SLOT(avvio()));
    GD2(cout<<"[Starter::Starter] inizializzato il pushbutton e connesso i segnali"<<endl);

    QLabel * patternDesc = new QLabel;
    patternDesc->setText("specifica la disposizione iniziale delle cellule");
    //patternDesc->setTextFormat(QTextFormat::PageBreak_Auto);

    QComboBox * patterns = new QComboBox;
    QStringList list;
    list<<"Casuale"<<
          "Pattern 1"<<
          "Pattern 2"<<
          "Pattern 3"<<
          "Pattern 4 (ideale con larghezza dispari)"<<
          "Pattern 5";
    patterns->addItems(list);
    //patterns->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
    connect(patterns,SIGNAL(activated(int)),this,SLOT(setPattern(int)));

    QGridLayout * spinboxes = new QGridLayout();
    spinboxes->addWidget(etichettaX,0,0,Qt::AlignHCenter );
    spinboxes->addWidget(etichettaY,0,1,Qt::AlignHCenter );
    spinboxes->addWidget(xdimension,1,0,Qt::AlignHCenter | Qt::AlignTop);
    spinboxes->addWidget(ydimension,1,1,Qt::AlignHCenter | Qt::AlignTop);

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget(descrizione);
    layout->addLayout(spinboxes);
    layout->addWidget(patternDesc);
    layout->addWidget(patterns);
    layout->addWidget(ok);

    setLayout(layout);
    GD3(cout<<"[Starter::Starter] sistemato il layout\n\n");

    //connect()

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


    MainWindow * finestra = new MainWindow(x,y,pattern);
    finestra->show();

    this->close();
    this->destroy();
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
    GD2(cout<<"position: "<<position);
    this->pattern=position;
}
