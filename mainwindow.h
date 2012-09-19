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
 *
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
    MainWindow(int, int, int, QWidget *debug, QWidget *parent = 0);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *closeEvent);

private slots:
    void play(bool toggled);
    void newGame();
    void save();
    void load();
    void closing();
   /* void about();
    void guide();*/

private:
    QSlider * slider;
    ClosingAlert * closingalert;
    Coltura * coltura;
    QMenu * file;
    QMenu * help;
    QPushButton * stepByStep;
    QPushButton * playButton;
    QHBoxLayout * buttonLayout;
    QVBoxLayout * layout;
    int x,y;
    bool playing;
};

#endif // MAINWINDOW_H
