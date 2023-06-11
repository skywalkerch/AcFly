//
// Created by skywalkerch on 6/1/2023.
//
#include  "AcFly_Sort.h"

void quickSortfunc(int arr[], int index1, int index2) {
    if (index2 <= index1) { return; }
    int pivot = arr[index1];
    int i = index1;
    int j = index2;
    //右向左找小于pivot的值
    while (i < j) {
        for (; i < j; j--) {
            if (arr[j] < pivot) {
                arr[i]=arr[j]; i++;
                break;
            }
        }
        for (; i < j; i++) {
            if (arr[i] > pivot) {
                arr[j]=arr[i]; j--;
                break;
            }
        }
    }
    arr[i] = pivot;
    quickSortfunc(arr, index1, i - 1);
    quickSortfunc(arr, i + 1, index2);
}
void quickSort(int arr[], int len) {
    quickSortfunc(arr, 0, len - 1);
}