#ifndef DIALOG3_H
#define DIALOG3_H

#include <QDialog>
#include<QTimerEvent>
#include<QPaintEvent>
namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QDialog *parent = 0);
    ~Dialog3();
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent*);


private:
    Ui::Dialog3 *ui;
};

#endif // DIALOG3_H
