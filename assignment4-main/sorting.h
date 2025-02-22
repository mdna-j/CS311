/**
* @brief Header file for various sorting functions
*/

#ifndef ASSIGN_3_SORTING_H
#define ASSIGN_3_SORTING_H



/**
 * @brief Insertion sort algorithm
 * @param array Array to be sorted. The array is modified in place.
 * @param lowindex Lowest index of the array
 * @param highindex Highest index of the array
 * @param reversed If reversed = true, the array should be sorted in descending order, otherwise in ascending order
 */
void insertionSort(int array[], int lowindex, int highindex, bool reversed = false);

/**
 * @brief Selection sort algorithm
 * @param array Array to be sorted. The array is modified in place.
 * @param lowindex Lowest index of the array
 * @param highindex Highest index of the array
 * @param reversed If reversed = true, the array should be sorted in descending order, otherwise in ascending order
 */
void selectionSort(int array[], int lowindex, int highindex, bool reversed = false);

/**
 * @brief The partition function used by quick sort 
 * 
 * @param array Array to be partitioned.
 * @param lowindex Lowest index of the array
 * @param highindex Highest index of the array
 * @param reversed If reversed = true, the array should be sorted in descending order, otherwise in ascending order
 * @return int The pivot index
 */
int partition(int array[], int lowindex, int highindex, bool reversed);

/**
 * @brief Quick sort algorithm
 * 
 * @param array Array to be sorted. The array is modified in place.
 * @param lowindex Lowest index of the array
 * @param highindex Highest index of the array
 * @param reversed If reversed = true, the array should be sorted in descending order, otherwise in ascending order
 */
void quickSort(int array[], int lowindex, int highindex, bool reversed = false);

/**
 * @brief A hybrid of insertion sort and quick sort algorithm. The algorithm is based on the idea that if the array is short, it is better to use insertion sort.
 * It uses quicksort until the list gets small enough, and then uses insertion sort or another sort to sort the small lists
 * 
 * @param array The array to be sorted. The array is modified in place.
 * @param lowindex The lowest index of the array
 * @param highindex The highest index of the array
 * @param reversed If reversed = true, the array should be sorted in descending order, otherwise in ascending order
 */
void hybridQuickSort(int array[], int lowindex, int highindex, bool reversed = false);

/**
 * @brief Fill the array with random values based on the specified order
 * @param array The array to be filled
 * @param size The size of the array
 * @param order 'a' for ascending, 'd' for descending, or 'r' for random
 */
void fillArray(int array[], int size, char order);

#endif // ASSIGN_3_SORTING_H