#ifndef STARTER_H
#define STARTER_H

#include <QWidget>
#include <QtGui>
#include "mainwindow.h"
#include "main.h"
#include "cassert"

class MainWindow;
/**
 * Widget di apertura del programma.
 * Tramite esso é possibile impostare le dimensioni e il pattern della coltura.
 */
class Starter : public QWidget
{
    Q_OBJECT
public:
    /**
     * Costruttore del widget.
     * @param parent=0
     */
    explicit Starter(QWidget *parent = 0);
    ~Starter();

public slots:
    /**
     * Funzione chiamata quando premo il pulsante "ok".
     * Apre il widget MainWindow e chiude lo Starter.
     */
    void avvio();
    /**
     * Setta la larghezza della coltura.
     * Invocato ad ogni cambiamento di valore dello spinbox.
     */
    void changeXDimension(int);
    /**
     * Setta l'altezza della coltura.
     * Invocato ad ogni cambiamento di valore dello spinbox.
     */
    void changeYDimension(int);
    /**
     * Setta il pattern scelto.
     */
    void setPattern(int);

private:
    MainWindow * mainwindow;
    int x;
    int y;
    int pattern;


    
};

#endif // STARTER_H
