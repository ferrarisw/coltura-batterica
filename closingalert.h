#ifndef CLOSINGALERT_H
#define CLOSINGALERT_H

#include <QtGui>


class ClosingAlert : public QWidget
{
    Q_OBJECT
public:
    ClosingAlert(QWidget *parent = 0);
    QDialogButtonBox * buttons;
};

#endif // CLOSINGALERT_H
