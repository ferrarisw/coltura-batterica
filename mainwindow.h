#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pilamatrici.h"
#include "coltura.h"
#include "closingalert.h"
#include <QtGui>
#include <iostream>
using namespace std;

class Coltura;

/**
 * @brief The MainWindow class
 * La classe MainWindow si occupa di gestione e coordinazione dei widget.
 * La parte pubblica contiene:
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * Costruttore del widget.
     * Inizializza il widget Coltura e gestisce le modifiche effettuate
     * dall'utente delle barre relative a velocità e istante di tempo.
     * @param x
     * @param y
     * @param pattern
     * @param parent
     */
    MainWindow(int, int, int, QWidget *parent = 0);
    MainWindow(QWidget *parent = 0);
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
     * Crea una nuova partita, eliminando l'attuale.
     */
    void newGame();

    /**
     * Salva la coltura attuale su un file .runner.
     */
    void save();

    /**
     * Carica una coltura da un file .runner.
     */
    void load();

    /**
     * Gestisce la chiusura del programma.
     */
    void closing();
   /* void about();
    void guide();*/

private:
    void struttura();
    QSlider * slider;
    ClosingAlert * closingalert;
    Coltura * coltura;
    QMenu * file;
    QMenu * modifica;
    QMenu * help;
    QPushButton * stepByStep;
    QPushButton * playButton;
    QHBoxLayout * buttonLayout;
    QVBoxLayout * layout;
    int x,y;
    bool playing;
};

#endif // MAINWINDOW_H
