#ifndef MAIN_H
#define MAIN_H

#include <iostream>
using namespace std;

#define DEBUG_MODE

#ifdef  DEBUG_MODE
#define MASK 1

#define DBG(a, b)      {if ((a) & MASK) {b; }}
#else
#define DBG(a, b)
#endif

#define TRACE(a)         DBG(1, cout<<"# "<<a<<endl)
#define GD1(a)           DBG(1, a)
#define GD2(a)           DBG(2, a)

/*
  * Serve per indicare la versione del programma al momento della carica
  */
#define versionefile 1

#endif // MAIN_H
