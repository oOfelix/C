#include<stdio.h>
#include<stdlib.h>

//希尔排序（改进的插入排序） 交换版 shell
void shellSort(int *array,int length){
    for(int gap = length >> 1; gap > 0; gap >>= 1 ){
        
        for(int i = gap ; i < length ; i++){
            for(int j = i ; j > gap-1 && array[j] < array[j-gap] ; j-=gap){
                int temp = array[j];
                array[j] = array[j-gap];
                array[j-gap] = temp;
            }
        }
    }
}

/*
//希尔排序（改进的插入排序） 交换版
void shellSort(int *array,int length){
    int d = 1;
    while(d < length / 3){
        d = (d * 3) +1 ;
    }
    for(int gap = d  ; gap > 0; gap = (gap - 1) / 3 ){
        
        for(int i = gap ; i < length ; i++){
            for(int j = i ; j > gap-1 && array[j] < array[j-gap] ; j-=gap){
                int temp = array[j];
                array[j] = array[j-gap];
                array[j-gap] = temp;
            }
        }
    }
}
*/

int main(int argc, char* argv[]){
    int array[10]={3,7,2,0,4,9,6,1,8,5};
    printf("Before:");
    for(int i=0;i<10;i++){
        printf("%d ",array[i]);
    }printf("\nAfter :");

    shellSort(array,10);

    for(int i=0;i<10;i++){
        printf("%d ",array[i]);
    }printf("\n");
    system("pause");
}