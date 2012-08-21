#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "coltura.h"

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

private:
    QSlider * slider;
    Coltura * coltura;
    int x,y;
    bool playing;
};

#endif // MAINWINDOW_H
