#ifndef GRAPHLEI_H
#define GRAPHLEI_H


#include<QString>

//建立邻接表结构
#define max_vertex_num 20
//最大20个顶点
typedef struct ArcNode{
    int adjvex;//该边的另一个顶点的位置
    struct ArcNode *nextarc;
    int info;//该边的权重
}ArcNode;
typedef struct VNode{
    QString data;//顶点信息是字母V1,V2.......
    ArcNode* firstarc;//指向第一条依附于该顶点的的指针
}VNode,AdjList[max_vertex_num];
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
    int kind;//图的种类标志->本例无向图
 }ALGraph;
struct node{
    int x;
    int y;
};
typedef int hh[max_vertex_num][max_vertex_num];
//Kruskal创建的结构体：
typedef struct {

    int  numVertexes, numEdges;//顶点数，边数
}Kgraph;
typedef struct {
    int begin;//开始点
    int  end;//结束点
    int weight;//权重
}Edges;
#endif // GRAPHLEI_H
