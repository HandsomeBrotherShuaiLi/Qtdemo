#ifndef DIALOG4_H
#define DIALOG4_H

#include <QDialog>
#include<QTimerEvent>
#include<QPaintEvent>
namespace Ui {
class Dialog4;
}

class Dialog4 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog4(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void kruskal();
    void timerEvent(QTimerEvent*);
    ~Dialog4();

private:
    Ui::Dialog4 *ui;
};

#endif // DIALOG4_H
