#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include<QLabel>
#include<graphlei.h>
#include<QTextEdit>
#include<QTimer>
#include <QtGui>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("数据结构课程设计");


    this->resize(420,290);
 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//克鲁斯卡尔算法
{
   w2.show();
}

void MainWindow::on_pushButton_2_clicked()//显示临街
{


    w1.show();

}

void MainWindow::on_pushButton_3_clicked()//prim算法
{
   w3.show();
}

void MainWindow::on_pushButton_4_clicked()//Floyd算法(动态规划的算法）
{

   w4.show();
}

void MainWindow::on_pushButton_5_clicked()//迪杰斯特拉算法或者使用之前得到的Floyd算法结果
{
    w5.show();
}

void MainWindow::on_pushButton_6_clicked()
{
    w1.close();
    w2.close();
    w3.close();
    w4.close();
    w5.close();
    this->close();
}
