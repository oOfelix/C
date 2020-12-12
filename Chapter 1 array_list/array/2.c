#include<stdio.h>

void binSort(int* a,int len,int x);

int main(){
    int a[5]={1,2,4,5,7};
    int x =4;
    binSort(a,5,x);
    for(int i =0;i<=5;i++){
        printf("%d ",a[i]);
    }
getchar();
getchar();

}

void binSort(int* a,int len,int x){
    int left = 0,right = len,mid = (left+right)/2;

    while(left<=right)
        {
            mid = (left+right)/2;//计算中间位置
            if(x<a[mid])
            {
                right = mid-1;//如果比中间位置小则缩小右边的范围为mid-1
            }
            else
            {
                left = mid+1;//如果比中间位置大则扩大左边的范围为mid+1，
            }
        }
        for(int j=len-1;j>=left;j--)
        {
            a[j+1] = a[j];//将大于等于左边界值的元素全部后移
        }
            a[left] = x;//待插入元素插入位置不等于现在所处位置时，则插入空处

}