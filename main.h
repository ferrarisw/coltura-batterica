#ifndef MAIN_H
#define MAIN_H

//#define DEBUG false
extern bool DEBUG;

#define DBG(a)  {if (DEBUG) {a;}}

#define TRACE(a)    DBG(cout<<"# "<<a<<endl)

#endif // MAIN_H
