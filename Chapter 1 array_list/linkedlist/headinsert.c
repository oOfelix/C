#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
    int date;
    struct NODE* next;
}node;

node* headinsert(node* head);
void tailinsert(node** head,node** tail);


int main(){
    int count = 5;
    node* head = NULL; //头插法指针
    node* phead = NULL,*ptail = NULL;  //尾插法 指针
    for(int i = 1;i <= count;i++){
        head = headinsert(head);
        head->date = i;

        tailinsert(&phead,&ptail);
        ptail->date = i;
    }
    while(head != NULL){
        printf("%d ",head->date);
        head = head->next;
    }
    printf("\n=========================\n");
    while(phead != NULL){
        printf("%d ",phead->date);
        phead = phead->next;
    }
    system("pause");
}

//头插
node* headinsert(node* head){
    node* new = (node*)malloc(sizeof(node));
    new->next = head;
    head = new;
    return head;
}

//尾插
void tailinsert(node** head,node** tail){
    node* new = (node*)malloc(sizeof(node));
    
    if(*head == NULL)
        *head = new;
    else 
        (*tail)->next = new;
    *tail = new;(*tail)->next = NULL;

}