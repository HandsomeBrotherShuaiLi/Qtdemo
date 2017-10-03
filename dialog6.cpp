#include "dialog6.h"
#include "ui_dialog6.h"
#include <QtGui>
#include<QMessageBox>
#include<QString>
#include<QStack>
extern int arc[6][6];
Dialog6::Dialog6(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog6)
{
    ui->setupUi(this);

    this->setWindowTitle("一个顶点到其他所有顶点的最短距离");
    this->setGeometry(400,600,400,300);

}
void Dialog6::Dijkstra(int v,int* dist)
{
    //int dist[6];
     int pre[6];
     bool s[6];
     int c[6][6];
     for(int i=0;i<6;i++)
         for(int j=0;j<6;j++)
         {
             c[i][j]=arc[i][j];
             if(i==j)
                 c[i][j]=0xffff;//本项目中大数设为0xffff
         }
     for(int i=0;i<6;i++)
     {
         dist[i]=c[v][i];
         s[i]=false;
         if(dist[i]==0xffff)
             pre[i]=0;
         else
             pre[i]=v;

      }
     dist[v]=0;
     s[v]=true;
     for(int i=0;i<=4;i++)
     {
         int tmp=0xffff;
         int u=v;
         for(int j=0;j<6;j++)
         {
             if((!s[j])&&(dist[j]<tmp)){
                 u=j;
                 tmp=dist[j];
             }
         }
             s[u]=true;
             for(int j=0;j<6;j++)
                 if((!s[j])&&(c[u][j]<0xffff))
                 {
                     int newdist=dist[u]+c[u][j];
                     if(newdist<dist[j])
                     {
                         dist[j]=newdist;
                         pre[j]=u;

                     }
                 }
         }
}




Dialog6::~Dialog6()
{
    delete ui;
}

void Dialog6::on_pushButton_2_clicked()
{
    this->close();
}

void Dialog6::on_pushButton_clicked()
{
    if(
        Dialog6::ui->startlineEdit->text()==tr("V1")||
        Dialog6::ui->startlineEdit->text()==tr("V2")||
        Dialog6::ui->startlineEdit->text()==tr("V3")||
        Dialog6::ui->startlineEdit->text()==tr("V4")||
        Dialog6::ui->startlineEdit->text()==tr("V5")||
        Dialog6::ui->startlineEdit->text()==tr("V6")
        )

       {
        accept();

        int m;
        if(Dialog6::ui->startlineEdit->text()==tr("V1"))
            m=0;
        if(Dialog6::ui->startlineEdit->text()==tr("V2"))
            m=1;
        if(Dialog6::ui->startlineEdit->text()==tr("V3"))
            m=2;
        if(Dialog6::ui->startlineEdit->text()==tr("V4"))
            m=3;
        if(Dialog6::ui->startlineEdit->text()==tr("V5"))
            m=4;
        if(Dialog6::ui->startlineEdit->text()==tr("V6"))
            m=5;
           int dis[6];
           Dijkstra(m,dis);
           QString str;
           for(int i=0;i<6;i++)
           {
               str+=tr("该点与V");
               QString tmep;
               tmep.setNum(i+1);
               str+=tmep;
               str+="的最短路径是：";
               tmep.setNum(dis[i]);
               str+=tmep;
               str+="\n";
             }
           QMessageBox::information(this,tr("路径"),str,QMessageBox::Yes);
    }



    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("输入错误！请输入V1,V2,V3,V4,V5,V6."),QMessageBox::Yes);
    }

}
