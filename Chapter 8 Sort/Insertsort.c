#include<stdio.h>
#include<stdlib.h>

//直接插入排序  设置监视哨array[0]
void insertsort_flag(int *array, int length){         
    for(int i=2;i<length;i++) {
        array[0] = array[i];int j = i-1;
        while(array[0] < array[j]) {
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = array[0];
    }
}

/*
//变种插入排序  以交换代替后移
void insertsort(int *array,int length){
    for(int i=1;i<length;i++) {
        for(int j=i;j>0 && array[j]<array[j-1];j--) {
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] =temp;
        }
    }
}
*/
int main(int argc, char* argv[]){
    int array[10]={3,7,2,0,4,9,6,1,8,5};
    printf("Before:");
    for(int i=0;i<10;i++){      //排序前
        printf("%d ",array[i]);
    }printf("\nAfter :");

    insertsort_flag(array,10);  //排序函数

    for(int i=0;i<10;i++){      //排序后
        printf("%d ",array[i]);
    }printf("\n");
    system("pause");
}