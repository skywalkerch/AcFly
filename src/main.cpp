//
// Created by skywalkerch on 5/22/2023.
//


#include <iostream>
#include "AcFly.h"
#include <gtest/gtest.h>
using namespace std;


//
// Created by skywalkerch on 5/29/2023.
//
void quickTest(void (*func)(int arr[], int len),int k) {
#define num 20 //测20组用例
#define LEN 100 //每组用例长100
    int *a = randomPositiveArray(LEN);
    int *b;
    for (int i = 0; i < num; i++) {
        b = randomArrayGenerator(a, LEN);
        func(b, LEN);
        for (int j = 0; j < LEN; j++) {
            EXPECT_EQ(a[j], b[j]);
        }
    }
}

