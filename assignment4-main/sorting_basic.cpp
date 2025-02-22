/**
 *Implemention of selected sorting algorithms
 *@file sorting.cpp
 */
#include <algorithm>
#include <iostream>
#include <chrono>
#include <cstdlib> // For rand()
#include <ctime>   // For time()
#include "sorting.h"
using namespace std;

/**
 *Implement the insertionSort algorithm correctly
 */
void insertionSort(int array[], int lowindex, int highindex, bool reversed){
	// TODO: Add your code here
	for (int i = lowindex + 1; i <= highindex; i++) {
        int key = array[i];
        int j = i - 1;
        
        // Ascending order by default
        if (!reversed) {
            while (j >= lowindex && array[j] > key) {
                array[j + 1] = array[j];
                j--;
            }
        }
        // Descending order if reversed is true
        else {
            while (j >= lowindex && array[j] < key) {
                array[j + 1] = array[j];
                j--;
            }
        }
        array[j + 1] = key;
    }
}

/**
 *@brief Implementation of the partition function used by quick sort
 *
 */
int partition(int array[], int lowindex, int highindex, bool reversed){
	// TODO: Add your code here
	int pivot = array[highindex];
    int i = lowindex - 1;

    // Ascending order by default
    if (!reversed) {
        for (int j = lowindex; j < highindex; j++) {
            if (array[j] < pivot) {
                i++;
                swap(array[i], array[j]);
            }
        }
    }
    // Descending order if reversed is true
    else {
        for (int j = lowindex; j < highindex; j++) {
            if (array[j] > pivot) {
                i++;
                swap(array[i], array[j]);
            }
        }
    }
    swap(array[i + 1], array[highindex]);
    return i + 1;
}

/**
 *Implement the quickSort algorithm correctly
 */
void quickSort(int array[], int lowindex, int highindex, bool reversed){
	// TODO: Add your code here
	if (lowindex < highindex) {
        // Partition the array based on ascending or descending order
        int pivotIndex = partition(array, lowindex, highindex, reversed);

        // Recursively sort elements before and after partition
        quickSort(array, lowindex, pivotIndex - 1, reversed);
        quickSort(array, pivotIndex + 1, highindex, reversed);
    }
}

void selectionSort(int array[], int lowindex, int highindex, bool reversed) {
    for (int i = lowindex; i < highindex; i++) {
        int index = i;
        for (int j = i + 1; j <= highindex; j++) {
            if ((reversed && array[j] > array[index]) || (!reversed && array[j] < array[index])) {
                index = j;
            }
        }
        std::swap(array[i], array[index]);
    }
}

void fillArray(int array[], int size, char order) {
    if (order == 'a') {
        for (int i = 0; i < size; i++) {
            array[i] = i; // Fill with ascending values
        }
    } else if (order == 'd') {
        for (int i = 0; i < size; i++) {
            array[i] = size - i; // Fill with descending values
        }
    } else if (order == 'r') {
        std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for randomization
        for (int i = 0; i < size; i++) {
            array[i] = std::rand() % 100; // Fill with random values between 0 and 99
        }
    }
}
