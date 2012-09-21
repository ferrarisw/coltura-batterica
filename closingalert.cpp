#include "closingalert.h"
#include <QtGui>

ClosingAlert::ClosingAlert(QWidget * parent):
    QWidget(parent)
{
    this->setGeometry(500,250,1,1);
    QLabel * label = new QLabel(tr("Vuoi veramente chiudere l'applicazione?"));

    buttons = new QDialogButtonBox(QDialogButtonBox::Ok |
                                                    QDialogButtonBox::Cancel);

    QVBoxLayout * alertlayout = new QVBoxLayout();
    alertlayout->addWidget(label);
    alertlayout->addWidget(buttons);

    setLayout(alertlayout);

}

ClosingAlert::~ClosingAlert()
{
    delete buttons;
}
