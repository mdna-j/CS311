#include "sorting.h"
#include "catch.hpp"
#include "print_array.h"

#include <iostream>
using namespace std;

TEST_CASE( "Test Hybrid Time", "Assignment 3" )
{
    cout << "**** Time Tests of Hybrid quick sort ****" << endl;
    int array_size = 100000;
    cout << "Array size: " << array_size << endl;

    int* array1 = new int[array_size];
    int* array2 = new int[array_size];
    int* array3 = new int[array_size];
    for (int i = 0; i < array_size; i++) {
        array1[i] = rand() % array_size;
        array2[i] = array1[i];
        array3[i] = array1[i];
    }

    // Measure insertion sort time
    auto t1 = std::chrono::high_resolution_clock::now();
    insertionSort(array1, 0, array_size-1, false);
    auto t2 = std::chrono::high_resolution_clock::now();
    double insertion_time = (std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1)).count();
    cout << "Insertion sort time = " << insertion_time << endl;
    INFO("Insertion sort of 100000-element array should take more than 1 sec");
    REQUIRE(insertion_time > 1.0);

    // Measure quick sort time
    t1 = std::chrono::high_resolution_clock::now();
    quickSort(array2, 0, array_size-1, false);
    t2 = std::chrono::high_resolution_clock::now();
    double quick_time = (std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1)).count();
    cout << "Quick sort time = " << quick_time << endl;
    INFO("Quick sort of 100000-element array should take less than 0.1 sec");
    REQUIRE(quick_time < 0.1);

    // Measure hybrid quick sort time
    t1 = std::chrono::high_resolution_clock::now();
    hybridQuickSort(array3, 0, array_size-1, false);
    t2 = std::chrono::high_resolution_clock::now();
    double hybrid_time = (std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1)).count();
    cout << "Hybrid quick sort time = " << hybrid_time << endl;
    INFO("Hybrid quick sort of 100000-element array should take less than 0.1 sec");
    REQUIRE(hybrid_time < 0.1);

    INFO("Hybrid quick sort should run faster than regular quick sort");
    REQUIRE(hybrid_time < quick_time);
}