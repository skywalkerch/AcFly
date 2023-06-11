#include  "AcFly_Sort.h"

//交换数组中两个索引处的元素
void swap(int arr[], int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

//建立大根堆
void buildMaxHeap(int arr[], int index1, int index2) {
//判断需要建堆数组是不是只有一个元素了
    if (index1 == index2) { return; }
    else {

        int len = index2 - index1 + 1;
        int i = len / 2 - 1;
        while (i >= 0) {
            //先找出子结点最大值和其索引
            int biggersonindex = i;
            int biggerson = arr[i];

            if (2 * i + 2 <= index2 && 2 * i + 1 <= index2) {
                biggersonindex = arr[2 * i + 1] >= arr[2 * i + 2] ? 2 * i + 1 : 2 * i + 2;
                biggerson = arr[2 * i + 1] >= arr[2 * i + 2] ? arr[2 * i + 1] : arr[2 * i + 2];
            } else if (2 * i + 2 > index2 && 2 * i + 1 <= index2) {
                biggersonindex = 2 * i + 1;
                biggerson = arr[2 * i + 1];
            }
            if (arr[i] < biggerson) {
                swap(arr, i, biggersonindex);
                i = len / 2 - 1;
                continue; //调动了一个 就要从最后一个非叶结点重新调
            }
            i--;
        }
    }
};

void heapSort(int arr[], int len) {

    for (int index = len - 1; index >= 0; index--) {
        buildMaxHeap(arr, 0, index);
        //堆顶与最后一个元素交换
        swap(arr, 0, index);
    }
}
