#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 50

typedef struct NODE{
    char data;
    struct NODE *lChild,*rChild;
}BTree;

typedef BTree* elemType;
typedef struct NODE2{
    elemType array[MAXSIZE];
    int top;
}Stack;

void initStack(Stack* stack){
    stack->top = -1;
}
bool isEmpty(Stack* stack){
    return stack->top == -1;
}
bool isFull(Stack* stack){
    return stack->top == MAXSIZE;
}
bool push(Stack* stack,BTree* treeNode){
    if(isFull(stack)) return false;
    stack->array[++(stack->top)] = treeNode;
    return true;
}
bool pop(Stack* stack,BTree** treeNode){
    if(isEmpty(stack)) return false;
    *treeNode = stack->array[(stack->top)--];
    return true;
}
bool peek(Stack* stack,BTree** treeNode){
    if(isEmpty(stack)) return false;
    *treeNode = stack->array[stack->top];
    return true;
}

elemType findFather(elemType treeRoot, elemType treeNode1,elemType treeNode2){
    if(!treeRoot || !treeNode1 || !treeNode2) return NULL;
    Stack stack1;initStack(&stack1);elemType node1 = treeRoot;int count1 = 0;
    Stack stack2;initStack(&stack2);elemType node2 = treeRoot;int count2 = 0;
    while((node1!=NULL||isEmpty(&stack1)!= NULL)&&treeNode1!=node1){
        if(node1){
            push(&stack1,node1);count1++;node1=node1->lChild;
        }else{
            pop(&stack1,&node1);count1--;node1=node1->rChild;
        }
    }  
}



void createBTree(BTree** root){
    char ch =getchar();
    if(ch == '#'){
        *root = NULL;
        return;
    }else{
        *root = (BTree*)malloc(sizeof(BTree));
        (*root)->data = ch;
        createBTree(&((*root)->lChild));
        createBTree(&((*root)->rChild));
    }
}

void PreOrdertravesal(BTree* root){
    if(NULL==root)  return;
    printf("%c",root->data);
    inOrdertravesal(root->lChild);
    inOrdertravesal(root->rChild);
}

int main(int argc, char* argv[]){
    BTree* root = NULL;createBTree(&root);
    PreOrdertravesal(root);
    system("pause");
}