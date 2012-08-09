#include <QtGui>
#include "popup.h"

Popup::Popup(QWidget *parent) :
    QWidget(parent)
{
    setGeometry(375, 355, 500, 120);    // Imposto la posizione dello schermo e la dimensione

    QTextEdit * error = new QTextEdit(); // Alloco dinamicamente

    error->setReadOnly(true);   // Imposto la sola lettura

    error->setText("ciao");
    error->show();
}

void showMessagePopup(char*)
{

}
