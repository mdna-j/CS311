#include <iostream>
#include "linkedlist.h"
#include "catch.hpp"
using namespace std;

//PURPOSE: to test copy constructor which gets called automatically.
// Adds 6 to the rear of the copiedList and displays the list.
//PARAMETER: list passed by value becomes copiedList via your copy constructor
void CopyTest(LinkedList copiedList) {
    cout << "in copy test" << endl;
    copiedList.addRear(6);
    copiedList.displayAll();
    cout << "finished" << endl;
}

TEST_CASE( "Test 03", "Assignment 1" )
{
    LinkedList L1, L2; // two lists needed
    int x;        // local for removed element

    for(int i = 1; i <= 5; i++) {
        L1.addRear(i);
    }
    REQUIRE(L1.length() == 5);

    CopyTest(L1);
    REQUIRE(L1.length() == 5);

    L1.displayAll();

    L1 = L1;
    REQUIRE(L1.length() == 5);


    //6. Create a 4 element list L2 with 7,8,9,10.
    for(int i = 7; i <= 10; i++) {
        L2.addRear(i);
    }

    REQUIRE(L2.length() == 4);

    L2 = L1;

    REQUIRE(L2.length() == 5);

    L1.deleteRear(x);
    REQUIRE(x == 5);
    REQUIRE(L1.length() == 4);


    //13. Display L2 again. (still 5 elements 1,2,3,4,5)
    REQUIRE(L2.length() == 5);
}