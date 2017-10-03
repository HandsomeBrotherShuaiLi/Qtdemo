#include "dialog3.h"
#include "ui_dialog3.h"
#include<graphlei.h>
#include<QPainter>
#include <windows.h>
#include <QThread>
#include <QEventLoop>
#include <QTimer>
#include<QTime>
#include<QWaitCondition>
#include <QtCore>
#include<sleeper.h>
#include<QWidget>
#include<QLabel>
#include<QFont>
extern QString dd[6];
extern int c[6][6];
extern QPointF point[6];
int lowcost[6];
int closest[6];
bool s[6];
node suzu[5];
int h=-2;
void prim();

Dialog3::Dialog3(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
        prim();
        ui->setupUi(this);
        this->setWindowTitle("普利姆算法动态过程");
        startTimer(1000);
        this->setGeometry(700,300,400,300);

}
void Dialog3::paintEvent(QPaintEvent *)
{

        QPainter painter(this);

       // 反走样
        painter.setRenderHint(QPainter::Antialiasing, true);

        //设置画笔颜色、宽度
       painter.setPen(QPen(QColor(0, 160, 230), 2));
        // 设置画刷颜色
        painter.setBrush(QColor(255, 160, 90));

        // 绘制圆
          painter.drawEllipse(QPointF(200, 40), 30, 30);//坐标（200,40）

        painter.setPen(QColor(0, 160, 230));
        QFont font;
        font.setFamily("Microsoft YaHei");
        font.setPointSize(10);
        painter.setFont(font);
        painter.drawText(190,40,"V1");//坐标（190,40）
        painter.drawEllipse(QPointF(90,100),30,30);//(90,100)
        painter.setFont(font);
        painter.drawText(80,100,"V2");
        painter.drawEllipse(QPointF(310,100),30,30);
        painter.drawText(300,100,"V4");
        painter.drawEllipse(QPointF(200,150),30,30);
        painter.drawText(190,150,"V3");
        painter.drawEllipse(QPointF(110,200),30,30);
        painter.drawText(100,200,"V5");
        painter.drawEllipse(QPointF(290,200),30,30);
        painter.drawText(280,200,"V6");


    for(int w=0;w<=h;w++)
    {

        QPainter painter(this);
        painter.setPen(Qt::red);
        painter.drawLine(point[suzu[w].x],point[suzu[w].y]);

     }

}

void Dialog3::timerEvent(QTimerEvent *)
{
    if(h==4)
        h=-2;
     else
     h=(h+1)%5;

    this->update();
}

Dialog3::~Dialog3()
{
    delete ui;
}


void prim()
{
    s[0]=true;

    for(int i=1;i<6;i++)
    {
        lowcost[i]=c[0][i];
        closest[i]=0;
        s[i]=false;
    }
    for(int i=0;i<5;i++)
    {

       int min =0xffff;
        int j=0;
        for(int k=1;k<6;k++)
        {
            if((lowcost[k]<min)&&(!s[k]))
            {
                min=lowcost[k];
                j=k;
            }

        }


        node tp;
        tp.x=j;
        tp.y=closest[j];
        suzu[i]=tp;
        s[j]=true;
         for(int k=1;k<6;k++)
         {
             if((c[j][k]<lowcost[k])&&(!s[k]))
             {
                 lowcost[k]=c[j][k];
                 closest[k]=j;
             }
         }

    }
}




