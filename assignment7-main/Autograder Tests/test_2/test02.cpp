#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_set>
#include "heap.h"
using namespace std;
#include "catch.hpp"

TEST_CASE( "Test 01", "Assignment 7" )
{
      
    Heap* heapPtr = new Heap;
    int arr1[] = { 1, 6, 8, 2, 7, 11, 4, 9, 13, 5, 12 };
    int arr1_solved[] = { 1, 2, 4, 5, 6, 7, 8, 9, 11, 12, 13};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    heapPtr->heapSort(arr1, n1);
    printArray(arr1,n1);
    for(int i = 0; i < n1; i++)
    {
        REQUIRE(arr1[i] == arr1_solved[i]);
    }
    int arr2[] = { 1, 3, 5, 10, 9, 8, 15, 17 };
    int arr2_solved[] = { 1, 3, 5, 8, 9, 10, 15, 17};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    heapPtr->heapSort(arr2, n2);
    printArray(arr2,n2);
    for(int i = 0; i < n2; i++)
    {
        REQUIRE(arr2[i] == arr2_solved[i]);
    }
    int arr3[] = { 10, 21, 11, 2, 5, 6, 1, 7, 20, 19, 16 };
    int arr3_solved[] = {1, 2, 5, 6, 7, 10, 11, 16, 19, 20, 21};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    heapPtr->heapSort(arr3, n3);
    printArray(arr3,n3);
    for(int i = 0; i < n3; i++)
    {
        REQUIRE(arr3[i] == arr3_solved[i]);
    }
    int arr4[] = { 2, 3, 13, 22, 8, 5, 4, 7, 20, 1 };
    int arr4_solved[] = { 1, 2, 3, 4, 5, 7, 8, 13, 20, 22};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    heapPtr->heapSort(arr4, n4);
    printArray(arr4,n4);
    for(int i = 0; i < n4; i++)
    {
        REQUIRE(arr4[i] == arr4_solved[i]);
    }
    delete heapPtr;
}