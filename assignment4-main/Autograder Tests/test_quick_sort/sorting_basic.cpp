/**
 * Implemention of selected sorting algorithms
 * @file sorting.cpp
 */

#include "sorting.h"
#include <iostream>
using namespace std;

/**
 * @brief Insertion sort algorithm
 * @param array Array to be sorted. The array is modified in place.
 * @param lowindex Lowest index of the array
 * @param highindex Highest index of the arra
 * @param reversed If reversed = true, the array should be sorted in descending order, otherwise in ascending order
 */
void insertionSort(int array[], int lowindex, int highindex, bool reversed) {
    // TODO: Add your code here
    int i, j, key;
    for (i = lowindex + 1; i <= highindex; i++) {
        key = array[i];
        j = i - 1;
        if (reversed) {
            while (j >= lowindex && array[j] < key) {
                array[j + 1] = array[j];
                j = j - 1;
            }
        } else {
            while (j >= lowindex && array[j] > key) {
                array[j + 1] = array[j];
                j = j - 1;
            }
        }
        array[j + 1] = key;
    }
}

int partition(int array[], int lowindex, int highindex) {
    int pivot = array[highindex];
    int i = lowindex - 1;
    for (int j = lowindex; j < highindex; j++) {
        if (array[j] <= pivot) {
            i++;
            //swap(array[i], array[j]);
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    //swap(array[i + 1], array[highindex]);
    int temp = array[i + 1];
    array[i + 1] = array[highindex];
    array[highindex] = temp;
    return i + 1;
}

/*int partition(int array[], int lowindex, int highindex, bool reversed) {
    int key = array[highindex];
    int i = lowindex - 1;
    for (int j = lowindex; j < highindex; j++) {
        if (reversed) {
            if (array[j] >= key) {
                i = i + 1;
                //swap(array[i], array[j]);
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        } else {
            if (array[j] <= key) {
                i = i + 1;
                //swap(array[i], array[j]);
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    //swap(array[i + 1], array[highindex]);
    int temp = array[i + 1];
    array[i + 1] = array[highindex];
    array[highindex] = temp;
    return i + 1;
}*/

/**
 * @brief 
 * 
 * @param array 
 * @param lowindex 
 * @param highindex 
 * @param reversed 
 * @return int 
 */
int partition(int array[], int lowindex, int highindex, bool reversed) {
    int midpoint =lowindex + (highindex - lowindex) / 2;
    int key = array[midpoint];
    int i = lowindex;
    int j = highindex;
    while (true) {
        if(!reversed) {
            while (array[i] < key) {
                i = i + 1;
            }
            while (array[j] > key) {
                j--;
            }
        } else { // reversed = true
            while (array[i] > key) {
                i = i + 1;
            }
            while (array[j] < key) {
                j--;
            }
        } 
        
        if (i >= j) {
            break;
        } else {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    //cout << "key = " << key << endl;
    //cout << "i = " << i << " j = " << j << endl;
    //printArray(array, lowindex, i);
    return j;
}

/**
 * @brief Quick sort algorithm
 * 
 * @param array Array to be sorted. The array is modified in place.
 * @param lowindex Lowest index of the array
 * @param highindex Highest index of the array
 * @param reversed If reversed = true, the array should be sorted in descending order, otherwise in ascending order
 */
void quickSort(int array[], int lowindex, int highindex, bool reversed) {
    // TODO: Add your code here
    if (lowindex < highindex) {
        int pivot = partition(array, lowindex, highindex, reversed);
        quickSort(array, lowindex, pivot, reversed);
        quickSort(array, pivot + 1, highindex, reversed);
    }
}


