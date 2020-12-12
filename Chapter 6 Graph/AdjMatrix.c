#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 20

typedef enum{DG,DN,UDG,UDN} GraphKind; //图饿种类
typedef char VertexData;
typedef struct ArcNode {
    int adj;
}ArcNode;
typedef struct{
    VertexData vertex[MAX_VERTICES];                //顶点表
    ArcNode arcs[MAX_VERTICES][MAX_VERTICES];       //边表
    int vertexnum,arcnum;          //顶点数和弧数
    GraphKind kind;             //图的种类
}AdjMatrix;


int locateVertex(AdjMatrix *G,VertexData V){
    int i = -1;
    for (int j = 0 ;j < G->vertexnum;j++) {
        if(G->vertex[j] == V) {
            i = j;
            break;
        }
    }
    return i;
}

int createDN(AdjMatrix *G){
    //输入图的顶点数和弧数
    fflush(stdin);
    scanf("%d %d",&G->vertexnum,&G->arcnum);
    //输入顶点表
    for(int j = 0 ;j < G->vertexnum;j++){
        fflush(stdin);
        scanf("%c",&G->vertex[j]);
    }
    //初始化边表
    for(int i = 0 ;i < G->vertexnum;i++){
        for(int j = 0 ;j < G->vertexnum;j++){
            G->arcs[i][j].adj = 0;
        }
    }
    //输入一条弧的两个顶点以及权值
    VertexData v1,v2;int weight;
    for(int j = 0 ;j < G->arcnum;j++){
        fflush(stdin);
        scanf("%c,%c,%d",&v1,&v2,&weight);
        G->arcs[locateVertex(G,v1)][locateVertex(G,v2)].adj = weight;
    }
    return 1;
}


void DFS(AdjMatrix *G,int V,int* visited) {         //递归
    printf("%c",G->vertex[V]);visited[V] = 1;
    for(int j = 0 ;j < G->vertexnum;j++){
        if(0 == visited[j]&&G->arcs[V][j].adj == 1){
            DFS(G,j,visited);
        }
    }
}

void DFS2(AdjMatrix *G,int V,int* visited){         //非递归
    int array[20] = {0};int top = -1;
    printf("%c",G->vertex[V]);visited[V] = 1;
    array[++top] = V;//push
    while(top != -1){
        int v = array[top]; //peek
        int i;
        for( i=0;i<G->vertexnum;i++){
            if(0 == visited[i]&& G->arcs[v][i].adj == 1){
                printf("%c",G->vertex[i]);visited[i]=1;
                array[++top] = i;  //push
                break;
            }
        }
        if(i == G->vertexnum){
                top--; //pop
        }
    }
}
void TraversalGraph(AdjMatrix *G) {
    int visited[MAX_VERTICES] = {0};
    for(int V = 0;V < G->vertexnum;V++){
        if(0 == visited[V]){
            DFS2(G,V,visited);
            printf("|");
        }
    }
}
int main(int argc, char* argv[]) {
    AdjMatrix G;
    createDN(&G);
    TraversalGraph(&G);
    system("pause");
}