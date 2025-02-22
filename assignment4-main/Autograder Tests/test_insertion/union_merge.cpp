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
    * @return LinkedList* return a pointer to linkedlist of the union
    */
LinkedList unionLinkedList(const LinkedList& LA, const LinkedList& LB) {
    LinkedList list(LA);
    Node* ptr = LB.front;
    while(ptr != nullptr) {
        if(! LA.search(ptr->val)) {
            list.addRear(ptr->val);
        }
        ptr = ptr->next;
    }
    return list;
}

/**
     * @brief Assume two input linked lists, LA and LB, whose elements are both in the non-descending order.
     * This function merges LA and LB into a new linked list (as the return value).
     * The elements in the new list should still be in the non-descending order.
     *
     * @param LA
     * @param LB
     * @return LinkedList*
     */
LinkedList mergeLinkedList(const LinkedList& LA, const LinkedList& LB) {
    // TODO: Add your implementation here
    LinkedList list;
    Node *pa= LA.front;
    Node *pb = LB.front;
    while(pa != nullptr | pb != nullptr) {
        if(pa == nullptr) { // LA is empty, add next element in LB
            list.addRear(pb->val);
            pb = pb->next;
        } else if (pb == nullptr) { // LB is empty, add next element in LA
            list.addRear(pa->val);
            pa = pa->next;
        } else { // There are still elements in both lists
            if(pa->val <= pb->val) { // LA value <= LB value, add LA value
                list.addRear(pa->val);
                pa = pa->next;
            } else {    // Add LB value
                list.addRear(pb->val);
                pb = pb->next;
            }
        }
    }
    return list;
}