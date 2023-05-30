//
// Created by skywalkerch on 5/26/2023.
//
#include"AcFly.h"

void binaryInsertionSort(int arr[], int len) {
//依次将arr[2]---arr[len-1]的元素 插入到前面
    for (int i = 1; i < len; i++) {
        int temp=arr[i];
        int low = 0, high = i - 1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] > arr[i]) high = mid - 1;
            else if (arr[mid] <= arr[i]) low = mid + 1;
        }
        for (int j = i; j > high + 1; j--) {
            arr[j] = arr[j - 1];
        }
        arr[high + 1] = temp;
    }
}