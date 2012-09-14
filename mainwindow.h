#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pilamatrici.h"
#include <QtGui>
#include <iostream>
#include "coltura.h"
using namespace std;

class Coltura;

/**
 *
 */
class MainWindow : public QWidget
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
    ~MainWindow();

private slots:
    void play(bool toggled);
    void newGame();
    void save();
    void load();
   /* void about();
    void guide();*/

private:
    QSlider * slider;
    Coltura * coltura;
    QMenu * file;
    QMenu * help;
    QMenuBar * menu;
    QPushButton * stepByStep;
    QPushButton * playButton;
    QHBoxLayout * buttonLayout;
    QVBoxLayout * layout;
    int x,y;
    bool playing;
};

#endif // MAINWINDOW_H
