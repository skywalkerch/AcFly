//
// Created by skywalkerch on 6/1/2023.
//
#include "AcFly.h"

void bubbleSort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1-i; j++) {
            if (arr[j + 1] < arr[j]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}