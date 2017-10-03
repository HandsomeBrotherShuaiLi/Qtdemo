#include "dialog5.h"
#include "ui_dialog5.h"
#include <QtGui>
#include<QMessageBox>
#include<QStack>
#include<QString>
extern int arc[6][6];
Dialog5::Dialog5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog5)
{
    ui->setupUi(this);
    this->setWindowTitle("查询界面");
    Floyd();
    this->setGeometry(400,300,400,300);
}

Dialog5::~Dialog5()
{
    delete ui;
}
void Dialog5::Floyd()
{

   //int numE=10;
   int numV=6;
    for(int i=0;i<numV;i++)
        for(int j=0;j<numV;j++)
           {Dialog5::path[i][j]=i;
             Dialog5::distance[i][j]=arc[i][j];
            }
    //Floyd算法动态规划计算最短路径
    for(int k=0;k<numV;k++)
    {
        for(int i=0;i<numV;i++)
            for(int j=0;j<numV;j++)
            {
                if(Dialog5::distance[i][k]+Dialog5::distance[k][j]<Dialog5::distance[i][j])
                {
                   Dialog5::distance[i][j]=Dialog5::distance[i][k]+Dialog5::distance[k][j];
                    Dialog5::path[i][j]=Dialog5::path[k][j];
                }
            }
    }

}

void Dialog5::on_pushButton_2_clicked()//退出键
{
   this->close();
}

void Dialog5::on_pushButton_clicked()//开始键
{




    if(
       (Dialog5::ui->startlineEdit->text()==tr("V1")||
        Dialog5::ui->startlineEdit->text()==tr("V2")||
        Dialog5::ui->startlineEdit->text()==tr("V3")||
        Dialog5::ui->startlineEdit->text()==tr("V4")||
        Dialog5::ui->startlineEdit->text()==tr("V5")||
        Dialog5::ui->startlineEdit->text()==tr("V6"))&&
        (Dialog5::ui->endlineEdit->text()==tr("V1")||
         Dialog5::ui->endlineEdit->text()==tr("V2")||
         Dialog5::ui->endlineEdit->text()==tr("V3")||
         Dialog5::ui->endlineEdit->text()==tr("V4")||
         Dialog5::ui->endlineEdit->text()==tr("V5")||
         Dialog5::ui->endlineEdit->text()==tr("V6"))
            )
       {
        accept();
        if(Dialog5::ui->startlineEdit->text()==Dialog5::ui->endlineEdit->text())
         QMessageBox::information(this,tr("路径"),tr("同一顶点不存在路径"),QMessageBox::Yes);
        int m,n;
        if(Dialog5::ui->startlineEdit->text()==tr("V1"))
            m=0;
        if(Dialog5::ui->startlineEdit->text()==tr("V2"))
            m=1;
        if(Dialog5::ui->startlineEdit->text()==tr("V3"))
            m=2;
        if(Dialog5::ui->startlineEdit->text()==tr("V4"))
            m=3;
        if(Dialog5::ui->startlineEdit->text()==tr("V5"))
            m=4;
        if(Dialog5::ui->startlineEdit->text()==tr("V6"))
            m=5;


        if(Dialog5::ui->endlineEdit->text()==tr("V1"))
            n=0;
        if(Dialog5::ui->endlineEdit->text()==tr("V2"))
            n=1;
        if(Dialog5::ui->endlineEdit->text()==tr("V3"))
            n=2;
        if(Dialog5::ui->endlineEdit->text()==tr("V4"))
            n=3;
        if(Dialog5::ui->endlineEdit->text()==tr("V5"))
            n=4;
        if(Dialog5::ui->endlineEdit->text()==tr("V6"))
            n=5;




         if(Dialog5::path[m][n]>=0xffff)
              QMessageBox::warning(this,tr("路径"),tr("该路径不存在"),QMessageBox::Yes);
         else
         {
             QStack<QString> ss;
             int k=n;
             QString tmp1;
             tmp1.setNum(n+1);
             QString tmp3="V"+tmp1;
             ss.push(tmp3);
             do{
                 k=Dialog5::path[m][k];
                 QString tmp;
                  tmp.setNum(k+1);
                 QString tmp2="V"+tmp;
                 ss.push(tmp2);
             }while(k!=m);
             QString str;
             str=ss.top();
             ss.pop();
             while(ss.empty()!=true)
             {
                 str+="-->";
                 str+=ss.top();
                 ss.pop();
             }
             QString pp;
             pp.setNum(Dialog5::distance[m][n]);
             str+="      \n  最短长度是：  ";
             str+=pp;
              QMessageBox::information(this,tr("路径"),str,QMessageBox::Yes);

         }
       }

    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("输入错误！请输入V1,V2,V3,V4,V5,V6."),QMessageBox::Yes);
    }

}
