#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include "errors.h"
using namespace std;

#define DEBUG_MODE
#ifdef  DEBUG_MODE
/*
  * Per attivare i diversi livelli di debug inizializzare la maschera con i
  * seguenti valori:
  * 0   NESSUN LIVELLO
  * 1   TRACE
  * 2               GD1
  * 3   TRACE       GD1
  * 4                       GD2
  * 5   TRACE               GD2
  * 6               GD1     GD2
  * 7   TRACE       GD1     GD2
  * 8                               GD3
  * 9   TRACE                       GD3
  * 10              GD1             GD3
  * 11  TRACE       GD1             GD3
  * 12                      GD2     GD3
  * 13  TRACE               GD2     GD3
  * 14              GD1     GD2     GD3
  * 15  TRACE       GD1     GD2     GD3
  */

extern int MASK;


#define DBG(a, b)      {if ((a) & MASK) {b; }}
#else
#define DBG(a, b)
#endif

#define TRACE(a)         DBG(1, cout<<"# "<<a<<endl)
#define GD1(a)           DBG(2, a)
#define GD2(a)           DBG(4, a)
#define GD3(a)           DBG(8, a)

/*############################################################################*/

/*
  * Definisco una modalit� di log che stampa sul terminale i dati statistici
  * del programma.
  */
#define LOG_MODE
#ifdef LOG_MODE

/*
  * Per attivare o meno la modalit� di log, assegnare a LOGMASK i
  * seguenti valori:
  * 0   NO LOG
  * 1   LOG
  */

extern int LOGMASK;

#define LOGDBG(a, b)      {if ((a) & LOGMASK) {b; }}
#else
#define LOGDBG(a, b)
#endif

#define LOG(a)          LOGDBG(1, cout<<a<<endl)

/*############################################################################*/

/*
  * Serve per indicare la versione del programma al momento della carica
  */
#define versionefile 1

#endif // MAIN_H
