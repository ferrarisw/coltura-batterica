#include <QtGui>
#include <QWidget>
#include "popup.h"
#include "errors.h"
#include "main.h"

Popup::Popup(QWidget *parent) :
    QWidget(parent)
{
    GD1(cout<<"[Popup::Popup] Costruttore di Popup");

    setGeometry(375, 355, 500, 120);    // Imposto la posizione dello schermo e la dimensione

    QLabel * descrizione = new QLabel;
    descrizione->setText(errorMessage);

    QPushButton * ok = new QPushButton("OK");
    connect(ok, SIGNAL(clicked()),this,SLOT(closeErrorMessage()));

    QVBoxLayout * errorLayout = new QVBoxLayout();
    errorLayout->addWidget(descrizione);
    errorLayout->addWidget(ok);

    setLayout(errorLayout);
}

Popup::~Popup()
{
    this->destroy();
}

void Popup::closeErrorMessage()
{
    this->close();
}

void Popup::showErrorMessage(Popup* popup, QString testo)
{
    popup->errorMessage = testo;

    popup->show();
}
