#include "about.h"
#include "main.h"
using namespace std;

About::About(QWidget *parent) :
    QWidget(parent)
{

    QLabel * label = new QLabel(tr("Life Runner (v 1.0)\n"
                                   "Davide Ferrari e Serena Ziviani."));
    label->setAlignment(Qt::AlignCenter);



    QPushButton * ok = new QPushButton(tr("OK"));
    connect(ok,SIGNAL(clicked()),this,SLOT(hide()));

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget(label);
    layout->addWidget(ok);

    this->setLayout(layout);

    this->move(screenX/2 - this->sizeHint().width()/2,
               screenY/2 - this->sizeHint().height()/2);

    setWindowTitle(tr("Informazioni"));
}

About::~About()
{
    GD1(cout<<"[About:~About] oggetto deallocato correttamente"<<endl);
}
