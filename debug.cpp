#include"debug.h"

int MASK = 0;
int LOGMASK = 0;

Debug::Debug(QWidget *parent) :
  QWidget(parent)
{
    QLabel * DBGLabel = new QLabel;
    DBGLabel->setText("Stabilire i livelli di Debug (0 - 15)");
    DBGLabel->setAlignment(Qt::AlignCenter);

    QSpinBox * maskValue = new QSpinBox();
    maskValue->setValue(0);
    maskValue->setMinimum(0);
    maskValue->setMaximum(15);
    connect(maskValue, SIGNAL(valueChanged(int)),this,SLOT(changeMaskValue(int)));
    GD2(cout<<"[Debug::Debug] ho inizializzato lo spinbox e connesso i segnali"<<endl);

    QLabel * LDBGLabel = new QLabel;
    LDBGLabel->setText("Stabilire il livello di Log (0 - 1)");
    LDBGLabel->setAlignment(Qt::AlignCenter);

    QSpinBox * logMaskValue = new QSpinBox();
    logMaskValue->setValue(0);
    logMaskValue->setMinimum(0);
    logMaskValue->setMaximum(1);
    connect(logMaskValue, SIGNAL(valueChanged(int)), this,SLOT(changeLogMaskValue(int)));
    GD2(cout<<"[Debug::Debug] ho inizializzato lo spinbox  e connesso i segnali"<<endl);

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget(DBGLabel);
    layout->addWidget(maskValue);
    layout->addWidget(LDBGLabel);
    layout->addWidget(logMaskValue);

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
