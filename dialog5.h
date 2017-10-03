#ifndef DIALOG5_H
#define DIALOG5_H

#include <QDialog>
#include<QTimerEvent>
#include<QPaintEvent>
#include<graphlei.h>
namespace Ui {
class Dialog5;
}

class Dialog5 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog5(QWidget *parent = 0);
    ~Dialog5();
     void Floyd();
     int path[6][6];
     int distance[6][6];

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


private:
    Ui::Dialog5 *ui;

};

#endif // DIALOG5_H
