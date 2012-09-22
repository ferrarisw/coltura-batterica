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
#else
#define DBG(a, b)
#endif

#define TRACE(a)         DBG(1, std::cout<<"# "<<a<<endl)
#define GD1(a)           DBG(2, std::cout<<"G1 ";{a;})
#define GD2(a)           DBG(4, std::cout<<"G2 ";{a;})
#define GD3(a)           DBG(8, std::cout<<"G3 ";{a;})

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
#else
#define LOGDBG(a, b)
#endif

#define LOG(a)          LOGDBG(1, std::cout<<a<<endl)



#endif // MAIN_H
