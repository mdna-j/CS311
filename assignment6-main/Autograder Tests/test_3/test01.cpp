#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_set>
#include "BST.h"
using namespace std;
#include "catch.hpp"

TEST_CASE( "Test 01", "Assignment 5" )
{
    int nums[] = {12, -29, -1, 42, 43, -15, 27, 36, -35, 33, 78};
    int sorted[] = {-35, -29, -15, -1, 12, 27, 33, 36, 42, 43, 78};
    unsigned int size = sizeof(nums) / sizeof(nums[0]);
    
    // Insert the random numbers into a BST
    BST bst;
    for(int num : nums) {
        cout << "Inserting " << num << endl;
        bst.insert(num);
    }
    cout << "BST size = " << bst.size() << endl;
    REQUIRE(bst.size() == size);
   
   // Print out the successors of BST tree nodes
   // staring at the left most node
    BST::Node * node = bst.getLeftMostNode();
    REQUIRE(node->data == sorted[0]);
    int next = 1;
    while(node != nullptr) {
        cout << node->data << " has ";
        node = bst.successor(node);
        
        if (node != nullptr) {
            cout << "successor " << node->data << endl;
            REQUIRE(node->data == sorted[next++]);
        } else {
            cout << "no sucessor" << endl;
        }
    }
}