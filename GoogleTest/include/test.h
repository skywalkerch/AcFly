//
// Created by skywalkerch on 5/30/2023.
//

#ifndef ACFLY_TEST_H
#define ACFLY_TEST_H
#include <gtest/gtest.h>
#include "AcFly.h"
#include <random>
//生成一个被打乱顺序的数组，用来测试
int* randomArrayGenerator(int arr[],int len){
    //复制传入的数组
    int *b=new int[len];
    for(int i=0;i<len;i++){
        b[i]=arr[i];
    }
    //来len次循环，每次循环生成两个在数组长度范围
    for(int i=0;i<len;i++){
        std::random_device rd;   // non-deterministic generator
        std::mt19937 gen(rd());  // to seed mersenne twister.
        std::uniform_int_distribution<> dist(0,len-1);
        int index1=dist(gen);
        int index2=dist(gen);
        int temp=b[index1];
        b[index1]=b[index2];
        b[index2]=temp;
    }
    return b;
}

int randomPlus(){
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<> dist(0,100);
    return dist(gen);
}
int randomStart(){
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<> dist(-1000,1000);
    return dist(gen);
}

int *randomPositiveArray(int len) {
    int *a = new int[len];
    a[0] = randomStart();
    for (int i = 0; i < len - 1; i++) {
        a[i + 1] = a[i] + randomPlus();
    }
    return a;
}


void quickTest(void (*Sort)(int arr[], int len)) {
#define num 20 //测20组用例
#define LEN 100 //每组用例长100
    int *a = randomPositiveArray(LEN);
    int *b;
    for (int i = 0; i < num; i++) {
        b = randomArrayGenerator(a, LEN);
        Sort(b, LEN);
        for (int j = 0; j < LEN; j++) {
            EXPECT_EQ(a[j], b[j]);
        }
    }
}
#endif //ACFLY_TEST_H
