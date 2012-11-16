#ifndef MAIN_H
#define MAIN_H

#ifndef DEBUG_MODE
#define NDEBUG
#endif

#include <iostream>
#include <fstream>
#include <QtGui>
#include "mainwindow.h"
#include "pilamatrici.h"
#include "coltura.h"
#include "starter.h"
#include "debug.h"

extern int screenX;
extern int screenY;


/**
 * @mainpage Il gioco della Vita: Natura e Matematica
 * Questo programma utilizza l'algoritmo della vita ideato da John Conway verso
 * la fine degli anni sessanta. Sfrutta semplici calcoli matematici per
 * simulare l'evoluzione e la crescita di una coltura cellulare dalle semplici
 * regole.\n Si veda il ::main per cominciare a navigare nel programma.\n
 * In una matrice cellulare costituita da cellule vive e morte,
 * ad ogni istante la configurazione cambia a seconda della configurazione
 * precedente.\n Le transizioni di stato dipendono unicamente dal
 * numero di vicini vivi:\n
 *  - Una cella morta con esattamente 3 vicini vivi nasce, diventando viva.
 *  - Una cella viva con 2 o 3 vicini vivi sopravvive; altrimenti muore.
 * Queste transizioni vengono implementate in PilaMatrici::next
 * 
 * Il programma utilizza una matrice di numeri interi rappresentanti le cellule
 * vive (1) e morte (0), descritte da una semplice interfaccia grafica a quadri,
 * disegnata da Coltura::paintColtura\n
 * Questa versione del programma include diverse funzionalità che permettono di
 * agire sulla coltura di cellule. Con la possibilità di scegliere la
 * dimensione della coltura (Starter) e la velocità con cui questa si aggiornerà
 * nel corso della riproduzione, abbiamo anche aggiunto una funzionalità che
 * permette di tornare indietro nel tempo tramite uno slider, così da poter
 * ripercorrere tutta l'evoluzione della coltura ad elaborazione già avvenuta.
 * 
 * Sono presenti anche le funzionalità di salvataggio (PilaMatrici::salva) su 
 * file e di caricamento.\n Il salvataggio scrive su file le dimensioni della
 * coltura e la configurazione intera.\n Il caricamento (PilaMatrici::carica)
 * li ripristina nel programma e crea una nuova coltura di quelle dimensioni 
 * e di quella configurazione.\n Utilizzando il caricamento da file, è anche
 * possibile importare configurazioni non casuali corrispondenti a pattern 
 * grafici interessanti.\n Legati ai pattern, abbiamo introdotto la possibilita'
 * di iniziare una coltura con configurazioni semplici come linee oblique
 * o verticali simmetriche e no (PilaMatrici::patternModeSelector).\n
 * Questo permette di ricreare effetti grafici semplici indipendentemente 
 * dalla dimensione della coltura.\n
 */
#ifdef  DEBUG_MODE

/**
 *  Maschera di bit per i livelli di debug
 *
 * Questa maschera abilita o disabilita i livelli di debug a seconda del
 * valore che assume:
 * 0   NESSUN LIVELLO;
 * 1   TRACE;
 * 2               GD1;
 * 3   TRACE       GD1;
 * 4                       GD2;
 * 5   TRACE               GD2;
 * 6               GD1     GD2;
 * 7   TRACE       GD1     GD2;
 * 8                               GD3;
 * 9   TRACE                       GD3;
 * 10              GD1             GD3;
 * 11  TRACE       GD1             GD3;
 * 12                      GD2     GD3;
 * 13  TRACE               GD2     GD3;
 * 14              GD1     GD2     GD3;
 * 15  TRACE       GD1     GD2     GD3;
 */
extern int MASK;

#define DBG(a, b)      {if ((a) & MASK) {b; }}
#define TRACE(a)         DBG(1, std::cout<<"# "<<a<<endl)
#define GD1(a)           DBG(2, std::cout<<"G1 ";{a;})
#define GD2(a)           DBG(4, std::cout<<"G2 ";{a;})
#define GD3(a)           DBG(8, std::cout<<"G3 ";{a;})
#else
#define DBG(a, b)
#define TRACE(a)
#define GD1(a)
#define GD2(a)
#define GD3(a)
#endif


/*############################################################################*/

 /*
  * Definisco una modalità di log che stampa sul terminale i dati statistici
  * del programma.
  */
#ifdef DEBUG_MODE

/**
 *  Maschera di bit per le funzioni di log
 *
 * Se questa maschera e' settata a 1 allora il log statistico e' abilitato,
 * altrimenti no.
 */
extern int LOGMASK;

#define LOGDBG(a, b)      {if ((a) & LOGMASK) {b; }}
#define LOG(a)          LOGDBG(1, std::cout<<a<<endl)
#else
#define LOGDBG(a, b)
#define LOG(a)
#endif




#endif // MAIN_H
