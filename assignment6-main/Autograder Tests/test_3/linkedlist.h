//CS311 LinkedList.h
//INSTRUCTION:
//Linkedlist class - header file template 
//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.
//You should always comments to each function to describe its PURPOSE and PARAMETERS 
#pragma once

// =======================================================
// Your name: ??? (TODO: Add your name)
// Compiler:  g++ 
// File type: headher file  linkedlist.h
//=======================================================
#include <string>
using namespace std;

// Datatype T : element type definition
typedef int T;  // int for now but can change later

//a list node is defined here as a struct Node for now
struct Node {
    T val;   // stored value
    Node *next;  // pointer to the next node

    // Constructor
    Node(T val = 0, Node *next = nullptr) {
        this->val = val;
        this->next = next;
    }
};
//---------------------------------------------------------

class LinkedList {

public:
    Node *front;       // pointer to the front node
    Node *rear;        // pointer to the rear node
    int count;        // the number of nodes in the list


    LinkedList() {     // constructor to create an empty list
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    ~LinkedList();     // destructor to destroy all nodes and release memory

    /**
     * @brief Copy Constructor to allow pass by value and return by value of a LinkedList
     * @param other LinkedList to be copied
     */
    LinkedList(const LinkedList &other);

    /**
     * @brief Overloading of = (returns a reference to a LinkedList)
     * @param other LinkedList to be copied
     * @return reference to a LinkedList
     */
    LinkedList &operator=(const LinkedList &other);


    /**
     * @brief Purpose: Checks if the list is empty
     * @return true if the list is empty, false otherwise
     */
    bool isEmpty();

    /**
     * @brief  Get the number of nodes in the list
     * @return int The number of nodes in the list
     */
    int length();

    /**
     * @brief Convert the contents of the list to a string
     */
    string toString();

    /**
     * @brief  Displays the contents of the list
     *
     */
    void displayAll();

    //TODO: Add comments
    void addFront(T val);

    //TODO: Add comments
    void addRear(T val);

    //TODO: Add comments
    bool deleteFront(T &val);

    //TODO: Add comments
    bool deleteRear(T &val);

    /**
     * @brief Delete a node at a given position from the list. The
     * node at position pos is deleted and the value of the deleted node is returned in val.
     * The valid range of pos is 1 to count. pos = 1 is the first node, and pos = count is the last node.
     * @param pos: position of the node to be deleted
     * @param val: it is set to the value of the node to be deleted
     * @return true: if the node was deleted successfully
     * @return false: if the node was not deleted successfully because the position was out of range
    */
    bool deleteAt(int pos, T &val);

    /**
     * @brief Insert a value at a specified position in the list. The valid pos is in the range of 1 to count+1.
     * The value will be inserted before the node at the specified position. if pos = 1, the value will be inserted
     * at the front of the list. if pos = count+1, the value will be inserted at the rear of the list.
     * @param pos: position to insert the value at.
     * @param val: value to insert.
     * @return true: if the value was inserted.
     * @return false: if the value was not inserted because pos is out of the range.
     */
    bool insertAt(int pos, T val);
};
