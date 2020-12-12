#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef char vertexType;
typedef struct arcNode {
    int associated;
    //other info
}arcNode;

typedef struct DG{
    vertexType vertex[MAX];
    arcNode arcs[MAX][MAX];
    int vertexNum,arcNum;
    //graphType kind;
}adjMatrixDG;

int localGraph(adjMatrixDG *G,vertexType V) {
    for (int i = 0; i < G->vertexNum; i++){
        if(V == G->vertex[i]){
            return i;
        }
    }
    return -1;
}
void createDG(adjMatrixDG *G) {
    //确定顶点以及边数
    fflush(stdin);
    scanf("%d,%d",&G->vertexNum,&G->arcNum);
    //确定顶点表
    for(int i=0;i<G->vertexNum;i++){
        fflush(stdin);
        scanf("%c",&G->vertex[i]);
    }
    //初始化边
    for(int i=0;i<G->vertexNum;i++) {
        for(int j=0;j<G->vertexNum;j++) {
            G->arcs[i][j].associated = 0;
        }
    }
    //确定关系
    int weight;vertexType v1,v2;
    for(int i = 0 ;i<G->arcNum;i++) {
        fflush(stdin);
        scanf("%c,%c,%d",&v1,&v2,&weight);
        G->arcs[localGraph(G,v1)][localGraph(G,v2)].associated = weight;
    }
}

void DFS(adjMatrixDG *G,int V,int *visited) {
    printf("%c",G->vertex[V]);visited[V] = 1;
    for(int i = 0;i<G->vertexNum;i++){
        if(!visited[i]&&G->arcs[V][i].associated){
            DFS(G,i,visited);
        }
    }
}
void traversalGraph(adjMatrixDG *G){
    int visited[MAX] = {0};
    for(int v = 0 ; v < G->vertexNum ; v++) {
        if(!visited[v]){
            DFS(G,v,visited);
            printf("\n");
        }
    }
}

int main(int argc, char* argv[]) {
    adjMatrixDG G;
    createDG(&G);
    traversalGraph(&G);
    system("pause");
}

