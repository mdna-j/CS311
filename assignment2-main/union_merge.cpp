/**
 * @brief Implementation of unionLinkedList and mergeLinkedList functions
 */
//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.

#include "linkedlist.h"

/**
    * @brief Assume two linked lists that represent Set A and Set B respectively.
    * Compute the union A U B and return the result as a new linked list.
    *
    * @param LA Input linkedlist A as a set (no duplicated element)
    * @param LB Input linkedlist B as a set (no duplicated element)
    * @return LinkedList return the unioned linkedlist 
    */
LinkedList unionLinkedList(const LinkedList& LA, const LinkedList& LB) {
    // TODO: Add your implementation here
     LinkedList result;

    // Step 1: Copy all elements of LA to the result list
    Node* currentA = LA.front;
    while (currentA != nullptr) {
        result.addRear(currentA->val); // Directly add to result since LA has no duplicates
        currentA = currentA->next;
    }

    // Step 2: Assign front of LB to temp
    Node* currentB = LB.front;

    // Step 3: Traverse LB and add elements to result if not already present
    while (currentB != nullptr) {
        // Step 4: Check if the value is not in result
        if (!result.search(currentB->val)) {
            result.addRear(currentB->val); // Step 5: Add to result if not found
        }
        currentB = currentB->next; // Step 6: Move to the next node in LB
    }

    return result; // Step 7: Return the unioned list

}

/**
     * @brief Assume two input linked lists, LA and LB, whose elements are both in the non-descending order.
     * This function merges LA and LB into a new linked list (as the return value).
     * The elements in the new list should still be in the non-descending order.
     *
     * @param LA
     * @param LB
     * @return LinkedList
     */
LinkedList mergeLinkedList(const LinkedList& LA, const LinkedList& LB) {
    // TODO: Add your implementation 
 LinkedList result;

    Node* currentA = LA.front;
    Node* currentB = LB.front;

  // Step 1: Traverse both lists until one of them reaches nullptr
    while (currentA != nullptr && currentB != nullptr) {
        // Step 2: Compare the values and add the smaller one to the result
        if (currentA->val <= currentB->val) {
            result.addRear(currentA->val);
            currentA = currentA->next; // Move to the next node in A
        } else {
            result.addRear(currentB->val);
            currentB = currentB->next; // Move to the next node in B
        }
    }

    // Step 3: If there are remaining elements in LA, add them to the result
    while (currentA != nullptr) {
        result.addRear(currentA->val);
        currentA = currentA->next;
    }

    // Step 4: If there are remaining elements in LB, add them to the result
    while (currentB != nullptr) {
        result.addRear(currentB->val);
        currentB = currentB->next;
    }

    return result; // Step 5: Return the merged list
}