#include <QtGui>
#include <QWidget>
#include "popup.h"
#include "main.h"

Popup::Popup(QWidget *parent) :
    QWidget(parent)
{
    GD1(cout<<"[Popup::Popup] Costruttore di Popup");

    setGeometry(375, 355, 500, 120);    // Imposto la posizione dello schermo e la dimensione
}

Popup::~Popup()
{
    this->destroy();
}

void Popup::closeErrorMessage()
{
    this->close();
}

void Popup::showErrorMessage(QString testo)
{
    //Popup* popup = new Popup;

    QLabel * descrizione = new QLabel;
    descrizione->setText(testo);

    QPushButton * ok = new QPushButton("OK");
    connect(ok, SIGNAL(clicked()),this,SLOT(closeErrorMessage()));

    QVBoxLayout * errorLayout = new QVBoxLayout();
    errorLayout->addWidget(descrizione);
    errorLayout->addWidget(ok);

    setLayout(errorLayout);

    this->show();
}
