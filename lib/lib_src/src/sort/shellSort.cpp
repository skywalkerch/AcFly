#include  "AcFly_Sort.h"
//
// Created by skywalkerch on 5/26/2023.
//
void  shellSort(int arr[],int len){
//初始步长为数组长度的一半
for(int dk=len/2;dk>=1;dk=dk/2){
for(int i=dk;i<len;i++){
    //子表待插入元素为arr[i]
    int temp=arr[i];
    int j;
    //找到子表插入位置
    for(j=i-dk;j>=0&&arr[j]>temp;j=j-dk){
        arr[j+dk]=arr[j];
    }
    arr[j+dk]=temp;
}
}
}