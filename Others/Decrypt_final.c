#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 50

typedef struct Node{
    char data[MAX]; 
    int top;
}Stack;
bool BracketMatch(char *string);
void initStack(Stack *stack){
    stack->top = -1;
}
bool isFull(Stack *stack) {
    return stack->top == 50?true:false;
}
bool isEmpty(Stack *stack) {
    return stack->top == 0?true:false;
}
bool push(Stack *stack,char x){
    if(isFull) return false;
    stack->data[++stack->top]=x;
}
bool pop(Stack *stack,char *x){
    if(isEmpty) return false;
    *x = stack->data[stack->top--];
}

int main(int argc, char *argv[]){
    char *string = "{()[]}";
    BracketMatch(string);
    system("pause");
    return 0;
}

bool BracketMatch(char *string){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    initStack(stack);
    int i=0;
    while(string[i]!='\0'){
        char ch = string[i];
        switch(ch){
            case '{':case '[':case '(':push(stack,ch); break;
            case '}':case ']':case ')':
                if(isEmpty) return false;
                char left;pop(stack,&left);
                if(left=='(' && ch==')') continue;
                if(left=='{' && ch=='}') continue;
                if(left=='[' && ch==']') continue;
                return false;
        }
    }
    return isEmpty(stack);
}