#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 50

typedef char elemType; //根据需要修改栈结构

typedef struct NODE2{
    elemType array[MAXSIZE];
    int top;
}stack;

void initStack(stack* stack){
    stack->top = -1;
}
bool isEmpty(stack* stack){
    return stack->top == -1;
}
bool isFull(stack* stack){
    return stack->top == MAXSIZE;
}
bool push(stack* stack,elemType* treeNode){
    if(isFull(stack)) return false;
    stack->array[++(stack->top)] = treeNode;
    return true;
}
bool pop(stack* stack,elemType** treeNode){
    if(isEmpty(stack)) return false;
    *treeNode = stack->array[(stack->top)--];
    return true;
}
bool peek(stack* stack,elemType** treeNode){
    if(isEmpty(stack)) return false;
    *treeNode = stack->array[stack->top];
    return true;
}