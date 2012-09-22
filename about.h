#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>

/**
 * The About class.
 *
 * Widget di visualizzazione delle informazioni sul programma.
 *  La parte pubblica contiene:
 *      - About(QWidget * parent = 0), costruttore
 *      - ~About(), decostruttore
 */
class About : public QWidget
{
    Q_OBJECT
    
public:
    explicit About(QWidget *parent = 0);
    ~About();
        
};

#endif // ABOUT_H
