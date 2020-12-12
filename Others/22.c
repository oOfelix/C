#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 1000
#define VertexType int
//弧
typedef struct arc{
    VertexType start;
    VertexType end;
    VertexType weight;
}arc;
//顶点
typedef struct vertex{
    VertexType value;//顶点数据
    int degree;//顶点的度数
    int sign;//标记每个顶点所属的集合
}vertex;
//图
typedef struct {
    vertex vertexes[MAX_VERTEX_NUM+1];    //所以顶点
    arc arcs[MAX_VERTEX_NUM*3+1];        //所有边
    int vertexnum,arcnum;               //顶点数，弧数
}graph;

//初始化连通网
void CreateUDN(graph *g){
    //输入连通网的顶点数以及弧数
    scanf("%d %d",&g->vertexnum,&g->arcnum);
    //初始化顶点，方便起见按自然顺序
    for (int i = 1; i <= g->vertexnum; i++) {
        g->vertexes[i].value = i;
        g->vertexes[i].sign = i;
        g->vertexes[i].degree = 0;
    }
    //输入各边的起始点和终点
    for (int i = 1 ; i <= g->arcnum; i++) {
        scanf("%d %d",&g->arcs[i].start,&g->arcs[i].end);
    }
}
//在顶点数组中找到顶点point对应的位置下标
int Locatevex(graph *g,VertexType point){
    for (int i = 1; i <= g->vertexnum; i++) {
        if (g->vertexes[i].value == point) {
            return i;
        }
    }
    return -1;
}

int main(){
    graph g;CreateUDN(&g);
    for(int i = 1 ; i<= g.arcnum;i++){
        int start = Locatevex(&g,g.arcs[i].start);
        int end = Locatevex(&g,g.arcs[i].end);
        if (start!=-1 &&  end!=-1) {
            g.vertexes[start].degree++;
            g.vertexes[end].degree++;
            for (int k=1; k<= g.vertexnum;k++) {
                if (g.vertexes[k].sign==g.vertexes[end].sign||g.vertexes[k].sign==g.vertexes[start].sign) {
                    g.vertexes[k].sign=-1;
                }
            }
        }
    }
    for(int i = 1;i<=g.vertexnum;i++){
        if(g.vertexes[i].sign!=-1||g.vertexes[i].degree%2!=0)
            printf("0");
     //   return 0;
    }
    printf("1");
    system("pause");
    return 0;
}