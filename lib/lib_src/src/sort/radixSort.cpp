//
// Created by skywalkerch on 5/30/2023.
//
#include  "AcFly_Sort.h"
#include <math.h>
#include <stack>

//实现基数排序
void radixSort(int arr[],int len,int maxnr){
    auto *s=new std::stack<int>[10];
    #define max (maxnr-1)
    for(int k=0;k<max;k++) {
        for (int i = 0; i < len; i++) {
            int t=arr[i]/pow(10,k);
            int c = t % 10;
            s[c].push(arr[i]);
        }
        for (int i = 0, num = 0; i < 10; i++) {
            while (!s[i].empty()) {
                arr[num++] = s[i].top();
                s[i].pop();
            }
        }
    }
}