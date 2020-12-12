#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 20

typedef int VertexType;
typedef struct ArcNode {
    int weight;
}ArcNode;
typedef struct{
    VertexType vertex[MAX_VERTICES];                //顶点表
    ArcNode arcs[MAX_VERTICES][MAX_VERTICES];       //边表
    int vertexnum;          //顶点数
}AdjMatrix;


int locateVertex(AdjMatrix *G,VertexType V){
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
    //输入图的顶点数
    scanf("%d",&G->vertexnum);
    //0-N-1顶点表
    for(int j = 0 ;j < G->vertexnum;j++){
        G->vertex[j] = j;
    }
    //矩阵
    for(int j = 0 ;j < G->vertexnum;j++){
        for(int i = 0 ;i < G->vertexnum;i++){
            scanf("%d",&G->arcs[j][i]);
        }
    }
    return 1;
}

void DFS(AdjMatrix *G,int V,int* visited,int* count) {         //递归
    visited[V] = 1;
    for(int j = 0 ;j < G->vertexnum;j++){
        if(0 == visited[j]&&G->arcs[V][j].weight == 1){
            *count++;
            DFS(G,j,visited,count);
        }
    }
}


void isArrived(AdjMatrix *G,int V,int R,int* visited){         //非递归
    int array[20] = {0};int top = -1;
    if(V==R){
        printf("YES");
        return 0;
    }
    visited[V] = 1;
    array[++top] = V;//push
    while(top != -1){
        int v = array[top]; //peek
        if(v==R){
            printf("YES");
            return 0;
        }
        int i;
        for( i=0;i<G->vertexnum;i++){
            if(0 == visited[i]&& G->arcs[v][i].weight == 1){
                visited[i]=1;
                array[++top] = i;  //push
                break;
            }
        }
        if(i == G->vertexnum){
                top--; //pop
        }
    }
}
void Traversal(AdjMatrix *G,VertexType V,VertexType R) {
    int visited[MAX_VERTICES] = {0};
    isArrived(G,V,R,visited);
}
int main(int argc, char* argv[]) {
    AdjMatrix G;
    createDN(&G);
    int start,end;
    scanf("%d %d",&start,&end);
    printf("%d\n",TraversalGraph(&G,start));
    printf("%d\n",TraversalGraph(&G,end));
    Traversal(&G,start,end);
    system("pause");
}