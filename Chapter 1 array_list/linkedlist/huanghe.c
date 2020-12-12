#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
    int date;
    struct NODE* next;
}node;

node* creatlist(node* head,int length);


int main(){
    int T,length;
    scanf("%d",&T);
    node* array[T];
}


node* creatlist(node* head,int length){
    node *tail = NULL;int i = 0;
    while(i++ < length){
        node* newnode = (node*)malloc(sizeof(node));
        scanf("%d",&newnode->date);
        if(head == NULL){
            head = newnode;
        }
        else
            tail->next = newnode;
        tail;
    }
}