#include<stdio.h>
#include<stdlib.h>

void bubblesort(int *array,int length){
    for(int i=0;i<length-1;i++){
        for(int j=0;j<length-i-1;j++){
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}

int main(int argc, char* argv[]){
    int array[10]={3,7,2,0,4,9,6,1,8,5};
    printf("before:");
    for(int i=0;i<10;i++){
        printf("%d ",array[i]);
    }
    printf("\nafter:");
    bubblesort(array,10);
     for(int i=0;i<10;i++){
        printf("%d ",array[i]);
    }printf("\n");
    system("pause");
}
