/**
 * This file tests the implementation of "optimized" quick sort.
 * It will compare its performance to that of a standard quick sort algorithm
 */
#include "sorting.h"
#include "print_array.h"
#include<iomanip>
#include <chrono>


void runExperiment(int size) {
    int* array1 = new int[size];
    int* array2 = new int[size];

    char orders[] = {'a', 'd', 'r'};
    const char* orderNames[] = {"Ascending", "Descending", "Random"};

    std::cout << "\nArray size: " << size << "\n";
    std::cout << "---------------------------------------\n";

    for (int i = 0; i < 3; i++) {
        fillArray(array1, size, orders[i]);
        std::copy(array1, array1 + size, array2);

        // Timing Insertion Sort
        std::cout << orderNames[i] << " (insertion sort): ";
        clock_t start = clock();
        insertionSort(array1, 0, size - 1, false); 
        clock_t end = clock();
        double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        std::cout << std::fixed << std::setprecision(10);
        std::cout << "Time for insertion sort: " << cpu_time_used << " seconds\n";

        // Timing Quick Sort
        std::cout << orderNames[i] << " (quick sort): ";
        start = clock();
        quickSort(array2, 0, size - 1, false); 
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        std::cout << "Time for quick sort: " << cpu_time_used << " seconds\n";

        std::cout << "---------------------------------------\n";
    
    }

    delete[] array1;
    delete[] array2;
}
  

int main() {
    int sizes[] = {10, 100, 500, 1000, 1500, 2000, 2500, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 50000, 100000, 150000, 200000,250000};

    for (int size : sizes) {
        runExperiment(size);
    }

    return 0;
}