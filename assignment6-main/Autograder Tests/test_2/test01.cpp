#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_set>
#include "BST.h"
using namespace std;
#include "catch.hpp"

TEST_CASE( "Test 01", "Assignment 5" )
{
    // randomly sample a bunch of integers
    //srand(time(NULL));
    int nums[] = {12, -29, -1, 42, 43, -15, 27, 36, -35, 33};
    unsigned int size = sizeof(nums) / sizeof(nums[0]);

    BST bst;
    
    for(int num : nums) {
        cout << "Inserting " << num << endl;
        bst.insert(num);
        cout << "Height of BST: " << bst.height() << endl;
    }

    cout << "Leftmost value = " << bst.getLeftMostNode()->data << endl;
    REQUIRE(bst.getLeftMostNode()->data == -35);

    // Inorder traversal of the BST
    cout << "Inorder traversal: ";
    bst.printInorder(bst.getRoot());
    cout << endl;
    cout << "BST tree size = " << bst.size() << endl;
    REQUIRE(bst.size() == size);
    // Preorder traversal of the BST
    cout << "Preorder traversal: ";
    bst.printPreorder(bst.getRoot());
    cout << endl;
    // check the height of the tree
    cout << "Height of the tree: " << bst.height() << endl;
    REQUIRE(bst.height() == 4);
}