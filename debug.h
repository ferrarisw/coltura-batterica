#ifndef DEBUG_H
#define DEBUG_H

#include <QtGui>
#include <iostream>
#include "main.h"
using namespace std;

/**
 * @brief The Debug class
 */
class Debug : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Debug costruttore
     * @param parent
     *
     *Il costruttore della classe Debug inizializza tutta la parte grafica
     *riguardante la finestra che permette di attivare, disattivare o modificare
     *le funzionalita' di debug.
     */
    explicit Debug(QWidget *parent = 0);

public slots:
    /**
     * @brief Settaggio del valore della maschera di bit per il Debug
     * @param valore da assegnare alla maschera
     *
     *Chiamando questo slot si ha la possibilita' di settare il valore
     *della maschera di bit per attivare o disattivare i diversi livelli
     *di debug in tracing.
     */
    void changeMaskValue(int);
    /**
     * @brief Settaggio del valore della maschera di bit per il log statistico
     * @param valore da assegnare alla maschera
     *
     *Chiamando questo slot si ha la possibilita' di settare il valore
     *della maschera di bit per attivare o disattivare il log statistico.
     */
    void changeLogMaskValue(int);
    /**
     * @brief releaseVersion
     */
    void releaseVersion();
};

#endif // DEBUG_H
