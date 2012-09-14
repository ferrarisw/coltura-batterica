#ifndef POPUP_H
#define POPUP_H

#include <QWidget>
#include <QtGui>

class Popup : public QWidget
{
    Q_OBJECT
public:
    explicit Popup(QWidget *parent = 0);
    ~Popup();
    //void changeErrorMessage(QString);
    void showErrorMessage(Popup*, QString);
    QString errorMessage;

private:

signals:
    
public slots:
    void closeErrorMessage();
    
};

#endif // POPUP_H
