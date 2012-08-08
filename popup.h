#ifndef POPUP_H
#define POPUP_H

#include <QWidget>

class Popup : public QWidget
{
    Q_OBJECT
public:
    explicit Popup(QWidget *parent = 0);

    void showMessagePopup(QString);

signals:
    
public slots:
    
};

#endif // POPUP_H
