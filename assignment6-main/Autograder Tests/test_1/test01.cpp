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
    srand(1);
    unordered_set<int> nums;
    while(nums.size() < 100) {
        nums.insert((rand() % 10000) - 5000);
    }

    // create and populate BST
    BST bst;
    unsigned int count = 0;
    for(int num : nums) {
        bst.insert(num);
        //bst.printInorder(bst.getRoot());
        //cout << bst.size() << endl;
        INFO("Incorrect tree size");
        ++count;
        REQUIRE(bst.size() == count);
    }

    // clear and repopulate BST
    bst.clear();
    count = 0;
    for(int num : nums) {
        bst.insert(num);
        INFO("Incorrect tree size");
        ++count;
        REQUIRE(bst.size() == count);
    }
    cout << "BST size = " << bst.size() << endl;

    // check if numbers exist
    for(int num : nums) {
        cout << "Checking if " << num << " exists" << endl;
        bool found = bst.find(num);
        INFO("BST find returned false when element actually existed");
        REQUIRE(found);
    }

    // check numbers that shouldn't exist
    for(int i = 0; i < 100; ++i) {
        int num = (rand() % 10000) - 5000;
        while(nums.find(num) != nums.end()) {
            num = (rand() % 10000) - 5000;
        }
        bool found = bst.find(num);
        INFO("BST find returned true when element didn't actually exist");
        REQUIRE(!found);
    }
}