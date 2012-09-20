#ifndef NEWGAME_H
#define NEWGAME_H

#include <QWidget>
#include <QtGui>
#include "mainwindow.h"
#include "main.h"
#include "cassert"
#include "debug.h"
#include "closingalert.h"

class MainWindow;
class Debug;

/**
 * Widget di apertura del programma.
 * Tramite esso é possibile impostare le dimensioni e il pattern della coltura.
 *@brief The NewGame class
 */
class NewGame : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * Costruttore del widget.
     * @param parent=0
     */
    explicit NewGame(QWidget *parent = 0);
    ~NewGame();

public slots:
    /**
     * Funzione chiamata quando premo il pulsante "ok".
     * Apre il widget MainWindow e chiude lo NewGame.
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

protected:
    void closeEvent(QCloseEvent *);

private:
    MainWindow * mainwindow;
    int x;
    int y;
    int pattern;
    ClosingAlert * closingalert;
    Debug * debug;

private slots:
    void closing();
    
};

#endif // NEWGAME_H
