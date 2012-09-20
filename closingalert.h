#ifndef CLOSINGALERT_H
#define CLOSINGALERT_H

#include <QtGui>

/**
 * @brief The ClosingAlert class
 *
 *Questa classe permette di utilizzare un widget per chiudere il programma
 *durante la sua esecuzione.
 *La parte pubblica contiene:
 *  - Costruttore
 *  - QDialogButtonBox contenete i due pulsanti OK e ANNULLA
 */
class ClosingAlert : public QWidget
{
    Q_OBJECT
public:
    /**
<<<<<<< HEAD
     * @brief ClosingAlert costruttore
     * @param parent
     *
     *Il costruttore della classe ClosingAlert inizializza e disegna la
     *finestra che permette di chiudere il programma.
=======
     * Costruttore del widget ClosingAlert.
     * @param parent=0
>>>>>>> b7c5bc358b1ea1e2641a7f70ac651761ab7b057b
     */
    ClosingAlert(QWidget *parent = 0);

    /**
<<<<<<< HEAD
     * @brief PushButtons di dialogo
     *
     *Questi due bottoni sono i classici OK/ANNULLA che attivano o meno
     *la chiusura del programma.
=======
     * Variabile che definisce i bottoni del widget.
>>>>>>> b7c5bc358b1ea1e2641a7f70ac651761ab7b057b
     */
    QDialogButtonBox * buttons;


};

#endif // CLOSINGALERT_H
