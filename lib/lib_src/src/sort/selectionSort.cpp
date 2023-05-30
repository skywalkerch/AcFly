//
// Created by skywalkerch on 5/23/2023.
// 简单选择排序算法

#include "AcFly.h"
void selectionSort(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (i != minIndex) {

            arr[i] = arr[i] ^ arr[minIndex];
            arr[minIndex] = arr[i] ^ arr[minIndex];
            arr[i] = arr[i] ^ arr[minIndex];
        }
    }
}