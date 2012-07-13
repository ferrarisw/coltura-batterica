#ifndef MAIN_H
#define MAIN_H

#include <iostream>
using namespace std;

//#define DEBUG false
extern bool DEBUG;

#define DBG(a)  {if (DEBUG) {a;}}


#define TRACE(a)    DBG(cout<<"# "<<a<<endl)

/*
  * Serve per indicare che versione del programma al momento della carica
  */
#define versionefile 1

#endif // MAIN_H
