#include "closingalert.h"
#include "main.h"
#include <QtGui>
using namespace std;

ClosingAlert::ClosingAlert(int x, int y, QWidget * parent):
    QWidget(parent)
{

    QLabel * label = new QLabel(tr("Chiudere l'applicazione?\nI file non "
                                   "salvati saranno persi per sempre!"));

    buttons = new QDialogButtonBox(QDialogButtonBox::Ok |
                                   QDialogButtonBox::Cancel);

    QVBoxLayout * alertlayout = new QVBoxLayout();
    alertlayout->addWidget(label);
    alertlayout->addWidget(buttons);

    setLayout(alertlayout);

    this->move(x/2 + this->sizeHint().width(), y - this->sizeHint().height()/2);

    setWindowTitle(tr("Sicuro?"));
}

ClosingAlert::~ClosingAlert()
{
    delete buttons;
    GD1(cout<<"[ClosingAlert:~ClosingAlert] oggetto deallocato correttamente"
        <<endl);
}
