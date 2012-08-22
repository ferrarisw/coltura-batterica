#ifndef DEBUG_H
#define DEBUG_H

#include<QtGui>
#include<QWidget>

class Debug : public QWidget
{
    //Q_OBJECT
public:
    explicit Debug(QWidget *parent = 0);

public slots:
    //TODO Documentazione changeMaskValue
    void changeMaskValue(int);
    void changeLogMaskValue(int);
    void releaseVersion();
};

#endif // DEBUG_H
