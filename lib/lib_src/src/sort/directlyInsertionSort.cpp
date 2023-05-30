//
// Created by skywalkerch on 5/24/2023.
//
#include "AcFly.h"

void directlyInsertSort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int temp = arr[i + 1];
        //第二层循环，找插入位置k
        for (int k = 0; k <= i; k++) {
            if (temp < arr[k]) {
                //将k至i对应的元素整体右移一位
                for (int m = i; m > k - 1; m--) {
                    arr[m + 1] = arr[m];
                }
                arr[k] = temp;
                break; //找到插入位置之后就停止寻找插入位置的这一层循环
            }
        }
    }
}