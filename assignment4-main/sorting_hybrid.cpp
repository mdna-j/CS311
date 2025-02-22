/**@brief You will implement the "optimized" quick sort 
algorithms for a linked list in this file
You must complete the TODO parts and then complete 
LinkedList.cpp. Delete "TODO" after you are done.
You should always comments to each function to 
describe its PURPOSE and PARAMETERS */
#include "sorting.h"

/**Implement a hybrid of insertion sort and quick sort algorithm. 
 *The algorithm is based on the idea that if the array is short,
 *it is better to use insertion sort.
 *It uses quicksort until the list gets small enough, and then 
 *uses insertion sort or another sort to sort the small lists*/
void hybridQuickSort(int array[], int lowindex, int highindex, bool reversed){
	// TODO: Add your code here
	const int THRESHOLD = 10;  // Threshold for switching to insertion sort

    // Base case: If the subarray size is below the threshold, use insertion sort
    if (highindex - lowindex + 1 <= THRESHOLD) {
        insertionSort(array, lowindex, highindex, reversed);  // Use insertion sort for small arrays
        return;
    }

    // Recursive case: Continue using quicksort for larger arrays
    if (lowindex < highindex) {
        int pivotIndex = partition(array, lowindex, highindex, reversed);  // Partition the array

        // Recursively sort elements before and after the partition
        hybridQuickSort(array, lowindex, pivotIndex - 1, reversed);  // Sort the left partition
        hybridQuickSort(array, pivotIndex + 1, highindex, reversed);  // Sort the right partition
    }
}
