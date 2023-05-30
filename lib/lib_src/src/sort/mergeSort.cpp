//
// Created by skywalkerch on 5/30/2023.
//
#include "AcFly.h"

void merge(int arr[], int low, int mid, int high) {
    int* temp = new int[high - low + 1];
    //复制小区段
    for (int i = low; i <= high; i++) {
        temp[i - low] = arr[i];
    }
    int k = low;
    int i = low;
    int j = mid + 1;
    while (i <= mid && j <= high) {
        arr[k++] = temp[i - low] <= temp[j - low] ? temp[i++ - low] : temp[j++ - low];
    }
    while (i <= mid) { arr[k++] = temp[i++ - low]; }
    while (j <= high) { arr[k++] = temp[j++ - low]; }
    delete [] temp;
}
void mergeSortFunc(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSortFunc(arr, low, mid);
        mergeSortFunc(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}
void mergeSort(int arr[], int len) {
    mergeSortFunc(arr, 0, len - 1);
}