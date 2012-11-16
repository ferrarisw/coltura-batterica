#ifndef CLOSINGALERT_H
#define CLOSINGALERT_H

#include <QtGui>

/**
 *  The ClosingAlert class
 *
 * Questa classe permette di utilizzare un widget per chiudere il programma
 * durante la sua esecuzione.
 *  La parte pubblica contiene:
 *      - ClosingAlert(int x, inty, QWidget parent = 0), costruttore
 *      - ~ClosingAlert(), decostruttore
 *      - QDialogButtonBox * buttons, contenente i due pulsanti "Ok" e "Annulla"
 */
class ClosingAlert : public QWidget
{
    Q_OBJECT
public:
    /**
     *  Costruttore della classe ClosingAlert
     * @param parent 0
     *
     * Il costruttore della classe ClosingAlert inizializza e disegna la
     * finestra che permette di chiudere il programma.
     */
    ClosingAlert(int x, int y, QWidget *parent = 0);

    ~ClosingAlert();

    /**
     *  Variabile che definisce i bottoni del widget
     *
     * Questi due bottoni sono i classici "Ok/Annulla", che in questo caso
     * attivano o meno la chiusura del programma.
     */
    QDialogButtonBox * buttons;


};

#endif // CLOSINGALERT_H
