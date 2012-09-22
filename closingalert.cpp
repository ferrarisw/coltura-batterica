#include "closingalert.h"
#include "main.h"
#include <QtGui>

ClosingAlert::ClosingAlert(QWidget * parent):
    QWidget(parent)
{
    this->move(screenX,screenY);

    QLabel * label = new QLabel(tr("Chiudere l'applicazione?"));

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
    GD1(cout<<"[ClosingAlert:~ClosingAlert] oggetto deallocato correttamente"<<endl);
}
