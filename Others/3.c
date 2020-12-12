#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

    char a,b,c;
    scanf("%c", &a);
    fflush(stdin);
    scanf("%c,%c", &b, &c);
    printf("%c|%c|%c",a,b,c);
    system("pause");
}