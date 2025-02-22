#include "sorting.h"
#include "catch.hpp"
#include "print_array.h"

#include <iostream>
using namespace std;

TEST_CASE( "Test Basic", "Assignment 3" )
{
    int array[] = {6, 3, 2, 4, 5, 0, -1, -3, -5, -4};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Test insertion sort ***" << endl;
    insertionSort(array, 0, size-1, false);
    REQUIRE(ArrayToString(array, 0, size-1) == "[-5, -4, -3, -1, 0, 2, 3, 4, 5, 6]");
    insertionSort(array, 0, size-1, true);
    REQUIRE(ArrayToString(array, 0, size-1) == "[6, 5, 4, 3, 2, 0, -1, -3, -4, -5]");

}