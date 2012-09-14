#ifndef DEBUG_H
#define DEBUG_H

#include <QtGui>
#include <iostream>
#include "main.h"
using namespace std;

class Debug : public QWidget
{
    Q_OBJECT
public:
    explicit Debug(QWidget *parent = 0);

public slots:
    //TODO Documentazione
    void changeMaskValue(int value);
    void changeLogMaskValue(int);
    void releaseVersion();
};

#endif // DEBUG_H
