#include "dialog1.h"
#include "ui_dialog1.h"
#include<graphlei.h>
#include<QPainter>
#include<QTextEdit>

extern int c[6][6]={0xffff,6,1,5,0xffff,0xffff,
             6,0xffff,5,0xffff,3,0xffff,
             1,5,0xffff,5,6,4,
             5,0xffff,5,0xffff,0xffff,2,
             0xffff,3,6,0xffff,0xffff,6,
             0xffff,0xffff,4,2,6,0xffff
            };
 extern QPointF point[6]={QPointF(200, 40),QPointF(90,100),QPointF(200,150),QPointF(310,100),QPointF(110,200),QPointF(290,200)};
 extern QString dd[6]={"V1","V2","V3","V4","V5","V6"};

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    this->setWindowTitle("邻接链表");
    this->setGeometry(100,400,400,400);
}
 void Dialog1::paintEvent(QPaintEvent *)
{
     //
           ALGraph g;
          g.arcnum=10;//10条弧
           g.kind=1;//1->无向图；0->有向图
           g.vexnum=6;//6个顶点

           ArcNode tmp1,tmp2,tmp16;


           g.vertices[0].data="V1";
           g.vertices[0].firstarc=&tmp16;

           tmp16.adjvex=1;
           tmp16.info=6;
           tmp16.nextarc=&tmp1;
           tmp1.adjvex=2;
           tmp1.info=1;
           tmp1.nextarc=&tmp2;

           tmp2.adjvex=3;
           tmp2.info=5;
           tmp2.nextarc=NULL;

           ArcNode tmp3,tmp4,tmp15;

           g.vertices[1].data="V2";
           g.vertices[1].firstarc=&tmp15;
           tmp15.adjvex=0;
           tmp15.info=6;
           tmp15.nextarc=&tmp3;

           tmp3.adjvex=2;
           tmp3.info=5;
           tmp3.nextarc=&tmp4;
           tmp4.adjvex=4;
           tmp4.info=3;
           tmp4.nextarc=NULL;


           ArcNode tmp5,tmp6,tmp7,tmp8,tmp17;
           g.vertices[2].data="V3";
           g.vertices[2].firstarc=&tmp17;

           tmp17.adjvex=0;
           tmp17.info=1;
           tmp17.nextarc=&tmp5;

           tmp5.adjvex=1;
           tmp5.info=5;
           tmp5.nextarc=&tmp6;
           tmp6.adjvex=3;
           tmp6.info=5;
           tmp6.nextarc=&tmp7;
           tmp7.adjvex=4;
           tmp7.info=6;
           tmp7.nextarc=&tmp8;
           tmp8.adjvex=5;
           tmp8.info=4;
           tmp8.nextarc=NULL;


           ArcNode tmp9,tmp10,tmp18;
           g.vertices[3].data="V4";
           g.vertices[3].firstarc=&tmp18;

           tmp18.adjvex=0;
           tmp18.info=5;
           tmp18.nextarc=&tmp9;
           tmp9.adjvex=2;
           tmp9.info=5;
           tmp9.nextarc=&tmp10;
           tmp10.adjvex=5;
           tmp10.info=2;
           tmp10.nextarc=NULL;

           ArcNode tmp11,tmp12,tmp19;
           g.vertices[4].data="V5";
           g.vertices[4].firstarc=&tmp19;

           tmp19.adjvex=1;
           tmp19.info=3;
           tmp19.nextarc=&tmp11;
           tmp11.adjvex=2;
           tmp11.info=6;
           tmp11.nextarc=&tmp12;
           tmp12.adjvex=5;
           tmp12.info=6;
           tmp12.nextarc=NULL;

           ArcNode tmp13,tmp14,tmp20;
           g.vertices[5].data="V6";
           g.vertices[5].firstarc=&tmp20;

           tmp20.adjvex=2;
           tmp20.info=4;
           tmp20.nextarc=&tmp13;

           tmp13.adjvex=3;
           tmp13.info=2;
           tmp13.nextarc=&tmp14;
           tmp14.adjvex=4;
           tmp14.info=6;
           tmp14.nextarc=NULL;
     //
       QPainter painter(this);
       painter.drawText(130,50,"邻接链表显示如下");
       for(int i=0;i<6;i++)
       {

           painter.drawText(0,80+50*i,dd[i]);
           painter.drawText(20,80+50*i,"的相邻节点是：");
           ArcNode* p;
           p=g.vertices[i].firstarc;
           int j=1;
           while(p!=NULL)
           {
               painter.drawText(150+40*j,80+50*i,dd[p->adjvex]);
               p=p->nextarc;
               j++;

           }
           delete p;

       }

 }

Dialog1::~Dialog1()
{
    delete ui;
}
