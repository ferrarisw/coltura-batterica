#ifndef CLOSINGALERT_H
#define CLOSINGALERT_H

#include <QtGui>

/**
 * Widget di conferma della chiusura del programma.
 *  Membri pubblici:
 *      -Il costruttore
 *      -Il QDialogButtonBox buttons, che definisce i bottoni "ok" e "annulla".
 */
class ClosingAlert : public QWidget
{
    Q_OBJECT
public:
    ClosingAlert(QWidget *parent = 0);
    QDialogButtonBox * buttons;


};

#endif // CLOSINGALERT_H
