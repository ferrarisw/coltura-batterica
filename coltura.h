#ifndef COLTURA_H
#define COLTURA_H
#include <QtGui>

class Coltura : public QWidget
{
public:
    Coltura(QWidget * parent=0);
    ~Coltura();

protected:
    void paintEvent(QPaintEvent *);

private:
    QBrush background;
    void paintColtura(QPainter*, QPaintEvent *);
    void Converti(int * matrice);
};

#endif // COLTURA_H
