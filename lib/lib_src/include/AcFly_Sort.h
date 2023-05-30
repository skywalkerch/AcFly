//
// Created by skywalkerch on 5/25/2023.
//

#ifndef ACFLY_ACFLY_SORT_H
#define ACFLY_ACFLY_SORT_H
//#排序算法
//##快速排序 参数1 待排序数组 参数2 待排序数组长度
void selectionSort(int arr[], int len);

//##直接插入排序
void directlyInsertSort(int arr[], int len);


//##折半查找插入排序
void binaryInsertionSort(int arr[],int len);
//##希尔排序
void shellSort(int arr[],int len);




//##堆排序
void heapSort(int arr[], int len);

//##归并排序
void mergeSort(int arr[],int len);
//##基数排序
void radixSort(int arr[],int len);
#endif //ACFLY_ACFLY_SORT_H
