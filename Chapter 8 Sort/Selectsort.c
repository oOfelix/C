#include<stdio.h>
#include<stdlib.h>

void selectsort(int *array,int length){
    for(int i=0;i<length-1;i++){
        int minpos = i;        for(int j=i+1;j<length;j++){
            minpos = array[minpos]>array[j]?j:minpos;
        }
        int temp = array[minpos];
        array[minpos] = array[i];
        array[i] = temp;
    }
}

int main(int argc, char* argv[]){
    int array[10]={3,7,2,0,4,9,6,1,8,5};
    printf("Before:");
    for(int i=0;i<10;i++){
        printf("%d ",array[i]);
    }printf("\nAfter :");
    selectsort(array,10);
     for(int i=0;i<10;i++){
        printf("%d ",array[i]);
    }printf("\n");
    system("pause");
}