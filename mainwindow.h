#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDialog>
#include<dialog1.h>
#include<dialog3.h>
#include<dialog4.h>
#include<dialog5.h>
#include<dialog6.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Dialog1 w1;
    Dialog3 w3;
    Dialog4 w2;//克鲁斯卡尔算法
    Dialog5 w4;//Floyd算法
    Dialog6 w5;//迪杰斯特拉算法
private slots:
    void on_pushButton_clicked();//克鲁斯卡尔算法槽函数
    void on_pushButton_2_clicked();//进入显示邻接链表
    void on_pushButton_3_clicked();//prim算法
    void on_pushButton_4_clicked();//Floyd算法
    void on_pushButton_5_clicked();//迪杰斯特拉算法对应槽函数
    void on_pushButton_6_clicked();
};

#endif // MAINWINDOW_H
