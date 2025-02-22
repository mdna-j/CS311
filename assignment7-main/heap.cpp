#include "heap.h"
#include <cstring>

// @brief gets the maximum value in the heap
// @return the highest value integer in the heap
int Heap::getMax() const {
    if (count == 0)
        return -1;
    return heaparray[0];
}


// @brief default constructor. Construct an empty heap with initial capacity
Heap::Heap(int size) {
    capacity = size;
    heaparray = new int[size];
    count = 0;
}

// @brief destructor
Heap::~Heap() {
    if(heaparray != NULL){
        delete[] heaparray; 
    }

}

/**
 * @brief constructor to build a heap from an array of values
 * @param values array of values to be added to the heap
 * @param length the size of the array
 */
Heap::Heap(int *values, int length) {
    this->capacity = length;
    this->heaparray = new int[length]; 
    this->count = length;

    for(int i = 0; i < length; i++){
        this->heaparray[i] = values[i];
    }
}

/**
 * @brief Copy constructor to build a heap from another heap
 * @param the heap to be copied
 */
Heap::Heap(const Heap& heap) {
    capacity = heap.capacity;
    for (int i = 1; i <= heap.count; i++)
    {
        heaparray[i - 1] = heap.heaparray[i - 1];
    }
    count = heap.count;
}

/**
  * @brief assignment operator to set one heap to another
  * @param the heap that you want to set your heap to
  */
Heap& Heap::operator = (const Heap& heap)
{
    if (this != &heap)
    {
        capacity = heap.capacity;
        for (int i = 1; i <= heap.count; i++)
        {
            heaparray[i - 1] = heap.heaparray[i - 1];
        }
        count = heap.count;
    }
    return *this;
}

/**
 * @brief   organizes the values in the heap to satisfy heap property.
 */
void Heap::heapify() {

    // TODO: Organize the heap values by percolating through the heap
    int i;
    for (i = (count / 2) - 1; i >= 0; i--) {
        percolateDown(i);
    }

}

/**
 * @brief  Runs percolate down on the heap for the node stored in index.
 */
void Heap::percolateDown(int index) {

    // TODO: check the values at index in the heap and decide whether they need to be swapped.
    // Run recursively until the current node is bigger than its children
    int max;

    if((2 *index + 2) <= count)
    {
        if(index == 0)
        {
            if(heaparray[2 *index + 1] > heaparray[2 *index + 2])
                max = 2 *index + 1;
            else
                max = 2 *index + 2;
        }
        else
        {
            if(heaparray[2 *index] > heaparray[2 *index + 1])
                max = 2 *index;
            else
                max = 2 *index + 1; 

        }

        if(heaparray[index] < heaparray[max])
        {
            swap(index, max);

            percolateDown(max);
        }
    }

    else if(count == 2 *index + 1) 
    {
        if(heaparray[index] > heaparray[2 *index])
            swap(index, 2 *index);
    }
}

/**
 * @brief  Runs percolate up on the heap for the node stored in index.
 */
void Heap::percolateUp(int index) {

    // TODO: check the value of the parents of index in the heap and swap them if they are smaller
    // run recursively until the current node is small than its parent
    if((index > 0) && (heaparray[index] > heaparray[parent(index)])){
        swap(index, parent(index));
        percolateUp(parent(index));
    }
}

/**
 * @brief  inserts a value into the heap
 *
 */
void Heap::insert(int value) {
    // TODO: resize the Heap array if neccessary and insert the value into the heap.
    // TODO: percolate the Heap to rearange after the value is inserted
      if(count == capacity){
        if(heaparray == NULL) return;
        int *newarray = new int[2 *capacity];
        
        // Use std::memcpy instead of memcpy
        memcpy(newarray, heaparray, sizeof(int) * (capacity));
        
        delete[] heaparray;
        heaparray = newarray;

        capacity *= 2;
    }
    count++;
    heaparray[count - 1] = value;
    percolateUp(count - 1);
    return;
}

/**
 * @brief  Removes the max value from the heap
 * @return the value that was removed
 */
int Heap::removeMax() {
    // TODO: remove the max value from the heap and then percolate the heap to rearrange values
    int retval;

    if(count > 0){
        retval = heaparray[0];
        heaparray[0] = heaparray[count - 1];
        count--;
        percolateDown(0);
        return retval;

    }
    else 
        return -1;
}

/**
 * @brief  Prints the values in the heap
 */
void Heap::printHeap() {
    int i;
    cout << "[ ";
    for (i = 0; i < count; i++)
        cout << heaparray[i] << " ";
    cout << "]\n";
}

/**
 * @brief  Prints the values in an array
 */
void printArray(int values[], int length) {
    int i;
    cout << "[ ";
    for (i = 0; i < length; i++) {
        cout << values[i] << " ";
    }
    cout << "]\n";
}

/**
 * @brief  Swaps the values in the heap at index1 and index2
 */
void Heap::swap(int index1, int index2) {
    int temp = heaparray[index1];
    heaparray[index1] = heaparray[index2];
    heaparray[index2] = temp;
}

/**
 * @brief  Sorts the values of an array by using the heap
 */
void Heap::heapSort(int values[], int length) {
    cout << "Array Before Sorting: \n";
    printArray(values, length);

    // TODO Create a heap from the array and then remove them from the heap into the array in order 
    
    Heap heap(values, length);
    heap.heapify();
    for (int i = length - 1; i >= 0; i--) {
        values[i] = heap.removeMax();
    }

    cout << "Array After Sorting: \n";
    printArray(values, length);

    return;
}

/**
     * @brief Change the key of the element at position i to the new value.
     *        It maintains the heap property.
     * @param i the position of the element to be decreased
     * @param value the new value
     */
void Heap::changeKey(int i, int new_val) {
    if (i < 0 || i >= count) {
        cout << "Index out of bounds." << endl;
        return;
    }

    int old_val = heaparray[i];
    heaparray[i] = new_val;

    if (new_val > old_val) {
        percolateUp(i);
    } else if (new_val < old_val) {
        percolateDown(i);
    }
}


