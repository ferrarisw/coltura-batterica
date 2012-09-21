#include "main.h"

#ifdef DEBUG_MODE
#ifndef DEBUG_H
#define DEBUG_H

#include <QtGui>
#include <iostream>
using namespace std;

/**
 * @brief The Debug class.
 * La parte pubblica contiene:
 *      - Debug(Qwidget *parent = 0), costruttore
 *      - ~Debug(), decostruttore
 * I public slots sono:
 *      - void changeMaskValue(int value), che cambia il livello di debug
 *      - void changeLogMaskValue(int value), che attiva/disattiva il log
 *      - void releaseVersion()
 */
class Debug : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Costruttore della classe Debug
     * @param parent 0
     *
     * Il costruttore della classe Debug inizializza la finestra che permette
     * di attivare, disattivare o modificare le funzionalita' di debug.
     */
    explicit Debug(QWidget *parent = 0);

    ~Debug();

public slots:
    /**
     * @brief Settaggio del valore della maschera di bit per il Debug
     * @param value valore da assegnare alla maschera
     *
     * Chiamando questo slot si ha la possibilita' di settare il valore
     * della maschera di bit per attivare o disattivare i diversi livelli
     * di debug.
     */
    void changeMaskValue(int value);

    /**
     * @brief Settaggio del valore della maschera di bit per il log statistico
     * @param value valore da assegnare alla maschera
     *
     *Chiamando questo slot si ha la possibilita' di settare il valore
     *della maschera di bit per attivare o disattivare il log statistico.
     */
    void changeLogMaskValue(int value);
    /**
     * @brief scrive informazioni sulla versione di release
     */
    void releaseVersion();
};

#endif // DEBUG_H
#endif
