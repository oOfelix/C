#include<stdio.h>
void combinearray(int* a,int m,int* b,int n);
int main(){
    int arrayA[8] = {1,1,5,0,0,0,0,0};
    int arrayB[3] = {2,4,6};
    combinearray(arrayA,3,arrayB,3);
    for(int i = 0;i < 6;i++){
        printf("%d ",arrayA[i]);
    }
    getchar();
    getchar();
}

void combinearray(int* a,int m,int* b,int n){
    int k = m+n-1;
    m = m-1;
    n = n-1;
    while(m >= 0 && n >= 0){
        if(a[m] > b[n]){
            a[k--] = a[m--];
        }else{
            a[k--] = b[n--];
        }
    }
}