#ifdef DEBUG_MODE
#ifndef DEBUG_H
#define DEBUG_H

#include "main.h"
#include <QtGui>
#include <iostream>
using namespace std;

/**
 *  The WDebug class.
 *
 * La parte pubblica contiene:
 *      - WDebug(Qwidget *parent = 0), costruttore
 *      - ~WDebug(), decostruttore
 * I public slots sono:
 *      - void changeMaskValue(int value), che cambia il livello di debug
 *      - void changeLogMaskValue(int value), che attiva/disattiva il log
 */
class WDebug : public QWidget
{
    Q_OBJECT
public:
    /**
     *  Costruttore della classe WDebug
     * @param parent 0
     *
     * Il costruttore della classe WDebug inizializza la finestra che permette
     * di attivare, disattivare o modificare le funzionalita' di debug.
     */
    explicit WDebug(QWidget *parent = 0);

    ~WDebug();

public slots:
    /**
     *  Settaggio del valore della maschera di bit per il WDebug
     * @param value valore da assegnare alla maschera
     *
     * Chiamando questo slot si ha la possibilita' di settare il valore
     * della maschera di bit per attivare o disattivare i diversi livelli
     * di debug.
     */
    void changeMaskValue(int value);

    /**
     *  Settaggio del valore della maschera di bit per il log statistico
     * @param value valore da assegnare alla maschera
     *
     *Chiamando questo slot si ha la possibilita' di settare il valore
     *della maschera di bit per attivare o disattivare il log statistico.
     */
    void changeLogMaskValue(int value);

};

#endif // DEBUG_H
#endif
