#include "about.h"
#include "main.h"

About::About(QWidget *parent) :
    QWidget(parent)
{
    this->move(screenX + 50,  screenY - 20);

    QLabel * label = new QLabel(tr("Life Runner (v 1.0)\n"
                                   "Davide Ferrari e Serena Ziviani."));
    label->setAlignment(Qt::AlignCenter);



    QPushButton * ok = new QPushButton(tr("OK"));
    connect(ok,SIGNAL(clicked()),this,SLOT(hide()));

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget(label);
    layout->addWidget(ok);

    this->setLayout(layout);

}

About::~About()
{
    GD1(cout<<"[About:~About] oggetto deallocato correttamente"<<endl);
}
