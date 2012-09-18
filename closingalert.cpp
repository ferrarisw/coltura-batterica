#include "closingalert.h"
#include <QtGui>

ClosingAlert::ClosingAlert(QWidget * parent):
    QWidget(parent)
{
    QLabel * label = new QLabel("Vuoi veramente chiudere l'applicazione?");
    buttons = new QDialogButtonBox(QDialogButtonBox::Ok |
                                                      QDialogButtonBox::Cancel);

    QVBoxLayout * alertlayout = new QVBoxLayout();
    alertlayout->addWidget(label);
    alertlayout->addWidget(buttons);

    setLayout(alertlayout);

}

