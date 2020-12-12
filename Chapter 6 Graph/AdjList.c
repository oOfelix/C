#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef enum{DG,DN,UDG,UDN} GraphKind; //图饿种类
typedef char VertexDataType;
typedef struct ArcNode {
    int adjvertex;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VertexNode {
    VertexDataType Data;
    ArcNode *firstarc;
    //otherInfo info;
}VertexNode;

typedef struct{
    VertexNode vertex[MAX];
    int vertexNum,arcNum;       //图的顶点数和弧数
    GraphKind   kind;
}AdjList;



void createAdjList(AdjList *g){
    //确定顶点数目，弧数
    scanf("%d %d",&g->vertexNum,&g->arcNum);
    //顺序输入邻接表  
    for(int i=0;i<g->vertexNum;i++){
         //输入数组顶点
        fflush(stdin);
        scanf("%c",&g->vertex[i].Data);
        //otherInfo  此处可输入顶点其他信息
        //输入与该顶点相邻的顶点下标，以-1结尾
        int adj = -1;scanf("%d",&adj);
        if(adj != -1){
            g->vertex[i].firstarc = (ArcNode*)malloc(sizeof(ArcNode));
            g->vertex[i].firstarc->adjvertex = adj;
        }else{
            g->vertex[i].firstarc = NULL;
            break;
        }
        ArcNode *p = g->vertex[i].firstarc;
        scanf("%d",&adj);
        while(adj != -1){
            p = (p->nextarc = (ArcNode*)malloc(sizeof(ArcNode)));
            p->adjvertex = adj;
            scanf("%d",&adj);
        }p->nextarc = NULL;
    }
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              









void DFS(AdjList *G,int V,int* visited) {
    printf("%c",G->vertex[V]);visited[V] = 1;
    ArcNode* p = G->vertex[V].firstarc;
    while(p) {
        if(!visited[p->adjvertex]) {
            DFS(G,p->adjvertex,visited);
        }
        p=p->nextarc;
    }
}
void DFS2(AdjList *G,int V,int* visited) {
    printf("%c",G->vertex[V]);visited[V] = 1;
    int array[MAX] = {0}; int top = -1;
    array[++top] = V;   //push
    while(top != -1) {
        int v = array[top]; //peek
        ArcNode *p = G->vertex[v].firstarc;
        while(p!=NULL) {
            if(!visited[p->adjvertex]){
                printf("%c",G->vertex[p->adjvertex]);visited[p->adjvertex] = 1;
                array[++top] = p->adjvertex;
                break;
            }else{
                p = p->nextarc;
            }
        }
        if(p ==NULL){
            top--;  //Pop
        }
        
    }
}
void TraversalGraph(AdjList *G) {
    int visited[MAX] = {0};
    for(int V = 0;V < G->vertexNum;V++){
        if(0 == visited[V]){
            DFS(G,V,visited);
            printf("|");
        }
    }
}
