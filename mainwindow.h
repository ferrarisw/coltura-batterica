#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pilamatrici.h"
#include "coltura.h"
#include "closingalert.h"
#include "about.h"
#include <QtGui>
#include <iostream>
using namespace std;

class Coltura;

/**
 *  The MainWindow class.
 *
 * La classe MainWindow si occupa di gestione e coordinazione dei widget.
 *
 *  La parte pubblica contiene:
 *      - MainWindow(int x, int y, int pattern, QWidget *parent = 0),
 *          costruttore
 *      - ~MainWindow(), decostruttore
 *
 *  La parte protected contiene:
 *      - void closeEvent(QCloseEvent *closeEvent), evento generato al click
 *          della "x"
 *
 *  I private slots sono:
 *      - void play(bool toggled), che gestisce il bottone playButton
 *      - void newGame(), che crea una nuova partita, eliminando l'attuale
 *      - void save(), che salva la coltura attuale su un file .runner
 *      - void closing(), che gestisce la chiusura del programma
 *      - void openAbout(), che mostra informazioni sul programma
 *
 *  I public slots sono:
 *      - void load(), che carica una coltura da un file .runner
 *
 *  La parte privata contiene:
 *      - QSlider * slider
 *      - ClosingAlert * closingalert
 *      - About * about
 *      - Coltura * coltura
 *      - QMenu * file
 *      - QMenu * help
 *      - QPushButton * stepByStep
 *      - QPushButton * playButton
 *      - QHBoxLayout * buttonLayout
 *      - QWidget * central;
 *      - int x,y
 *      - bool playing
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * Costruttore della classe MainWindow.
     * Inizializza il widget Coltura e gestisce le modifiche effettuate
     * dall'utente delle barre relative a velocità e istante di tempo.
     * @param x Larghezza della coltura
     * @param y Altezza della coltura
     * @param pattern Determina la disposizione iniziale delle cellule
     * @param parent 0
     */
    MainWindow(int, int, int, QWidget *parent = 0);

    /**
     * Decostruttore.
     */
    ~MainWindow();

protected:
    /**
     * Funzione chiamata ogni volta che si genera un evento di chiusura.
     * Apre il widget ClosingAlert.
     * @param closeEvent
     */
    void closeEvent(QCloseEvent *closeEvent);

private slots:
    /**
     * Gestisce il bottone playButton.
     * @param toggled
     */
    void play(bool toggled);

    /**
     *  Crea una nuova partita, eliminando l'attuale.
     */
    void newGame();

    /**
     *  Salva la coltura attuale su un file .runner.
     */
    void save();

    /**
     *  Gestisce la chiusura del programma.
     */
    void closing();

    /**
     *  Mostra informazioni sul programma.
     */
    void openAbout();

public slots:
    /**
     *  Carica una coltura da un file .runner.
     */
    bool load();

private:
    ClosingAlert * closingalert;
    About * about;
    QSlider * slider;
    Coltura * coltura;
    QMenu * file;
    QMenu * help;
    QPushButton * stepByStep;
    QPushButton * playButton;
    QWidget * central;
    QHBoxLayout * buttonLayout;
    QVBoxLayout * layout;
    int x,y;
    bool playing;

};

#endif // MAINWINDOW_H
