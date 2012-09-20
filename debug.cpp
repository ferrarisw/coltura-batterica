#include "main.h"
#include"debug.h"
int MASK = 0;
int LOGMASK = 0;

Debug::Debug(QWidget *parent) :
  QWidget(parent)
{

    QLabel * DBGLabel = new QLabel;
    DBGLabel->setText("Stabilire:\n\n Livello di Debug (0 - 15)");
    DBGLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    QSpinBox * maskValue = new QSpinBox();
    maskValue->setValue(0);
    maskValue->setMinimum(0);
    maskValue->setMaximum(15);
    connect(maskValue, SIGNAL(valueChanged(int)),this,SLOT(changeMaskValue(int)));
    GD2(cout<<"[Debug::Debug] ho inizializzato lo spinbox e connesso i segnali"<<endl);

    QLabel * LDBGLabel = new QLabel;
    LDBGLabel->setText("Livello di Log (0 - 1)");
    LDBGLabel->setAlignment(Qt::AlignCenter | Qt::AlignBottom);

    QSpinBox * logMaskValue = new QSpinBox();
    logMaskValue->setValue(0);
    logMaskValue->setMinimum(0);
    logMaskValue->setMaximum(1);
    connect(logMaskValue, SIGNAL(valueChanged(int)), this,SLOT(changeLogMaskValue(int)));
    GD2(cout<<"[Debug::Debug] ho inizializzato lo spinbox  e connesso i segnali"<<endl);

    QWidget * spacer = new QWidget();
    QWidget * spacer2 = new QWidget();

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget(DBGLabel);
    layout->addWidget(maskValue);
    layout->addWidget(LDBGLabel);
    layout->addWidget(logMaskValue);
    layout->addWidget(spacer);
    layout->addWidget(spacer2);
    //TODO soluzione migliore per lo spazio

    setLayout(layout);

}

void Debug::changeMaskValue(int value)
{
    assert(value >= 0);

    MASK = value;

    GD2(cout<<"[Debug::changeMaskValue] Valore di MASK: "<<MASK<<endl);
}

void Debug::changeLogMaskValue(int value)
{
    assert(value >= 0);

    LOGMASK = value;

    GD2(cout<<"[Debug::changeLogMaskValue] Valore di LOGMASK: "<<LOGMASK<<endl);
}

void Debug::releaseVersion()
{
    MASK = 0;
    LOGMASK = 0;

    GD2(cout<<"[Debug::releaseVersion] Valore di MASK: "<<MASK<<endl);
    GD2(cout<<"[Debug::releaseVersion] Valore di LOGMASK: "<<LOGMASK<<endl);
}

