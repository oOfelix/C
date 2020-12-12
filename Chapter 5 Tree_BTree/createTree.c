#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
    char data;
    struct NODE *lChild,*rChild;
}BTree;

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
void inOrdertravesal(BTree* root){
    if(NULL==root)  return;
    inOrdertravesal(root->lChild);
    printf("%c",root->data);
    inOrdertravesal(root->rChild);
}

void PreOrdertravesal(BTree* root){
    if(NULL==root)  return;
    printf("%c",root->data);
    inOrdertravesal(root->lChild);
    inOrdertravesal(root->rChild);
}

int main(int argc, char* argv[]){
    BTree* root = NULL;createBTree(&root);
    inOrdertravesal(root);
    PreOrdertravesal(root);
    getchar();
    getchar();
}
