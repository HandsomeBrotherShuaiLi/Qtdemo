#include "dialog4.h"
#include "ui_dialog4.h"
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
Kgraph k;
Edges edge[20];
node pathr[max_vertex_num];
extern QPointF point[6];
int z=-2;
extern int arc[6][6]={0,6,1,5,0xffff,0xffff,
             6,0,5,0xffff,3,0xffff,
             1,5,0,5,6,4,
             5,0xffff,5,0,0xffff,2,
             0xffff,3,6,0xffff,0,6,
             0xffff,0xffff,4,2,6,0};
Dialog4::Dialog4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog4)
{
    ui->setupUi(this);
    this->setWindowTitle("克鲁斯卡尔算法过程");
     kruskal();
     startTimer(1000);
    this->setGeometry(600,400,400,300);
}
void Dialog4::paintEvent(QPaintEvent *)
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

    for(int i=0;i<=z;i++)
    {
        QPainter painter(this);
        painter.setPen(Qt::red);
        painter.drawLine(point[pathr[i].x],point[pathr[i].y]);

    }

}
int Find(int *parent ,int f)//返回这个点的根节点
{
    while(parent[f]>0)
    {
        f=parent[f];
    }
    return f;
}

//快速排序法
int part(Edges* a,int p,int r)//找到基准
{
    int i=p;
    int j=r+1;
    Edges x=a[p];
    while(true){
        while(a[++i].weight<x.weight&&i<r);
        while(a[--j].weight>x.weight);
        if(i>=j)
            break;
        Edges tmp;
        tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
        }
    a[p]=a[j];
    a[j]=x;
    return j;
}
void Quicksort(Edges* a,int p,int r)
{
    if(p<r)
    {
        int q=part(a,p,r);
        Quicksort(a,p,q-1);
        Quicksort(a,q+1,r);
    }
}

void Dialog4::kruskal()
{
    k.numVertexes=6;
    k.numEdges=10;
   int parent[20]; //用于寻找根节点的数组
   int t=0;
    for(int i=0;i<k.numVertexes;i++)
    {
        for(int j=i+1;j<k.numVertexes;j++)
        {
            if(arc[i][j]<0xffff)
            {
            edge[t].begin=i;
            edge[t].end=j;
            edge[t].weight=arc[i][j];
            t++;
            }
        }
    }
    Quicksort(edge,0,t-1);//快速排序
    for(int i=0;i<k.numVertexes;i++)//初始各自独立
    {
        parent[i]=0;
    }
    int startpoint;
    int endpoint;
    int pt=0;
    for(int i=0;i<k.numEdges;i++)
    {
        startpoint=Find(parent,edge[i].begin);
        endpoint =  Find(parent,edge[i].end);
        if(startpoint!=endpoint)//不是同一个根节点
        {
            parent[startpoint]=endpoint;
            pathr[pt].x=edge[i].begin;
            pathr[pt].y=edge[i].end;
            pt++;
        }
    }

    
    
}
void Dialog4::timerEvent(QTimerEvent *)
{
    if(z==4)
       z=-2;
     else
     z=(z+1)%5;

    this->update();
}

Dialog4::~Dialog4()
{
    delete ui;
}
