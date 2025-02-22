#include "linkedlist.h"
#include "catch.hpp"

TEST_CASE( "Test 01", "Assignment 1" )
{
    LinkedList L;   // this is my list
    int x;     // to hold a removed element

    REQUIRE(L.isEmpty());
    L.addRear(1);
    L.addRear(2);
    L.addRear(3);
    L.addRear(4);
    REQUIRE(L.length() == 4);
    L.displayAll();
    L.deleteFront(x);
    REQUIRE(x == 1);
    L.deleteFront(x);
    REQUIRE(x == 2);

    REQUIRE(!L.isEmpty());
    L.deleteRear(x);
    REQUIRE(x == 4);
    L.deleteRear(x);
    REQUIRE(x == 3);
    L.addFront(9);
    L.addFront(8);
    L.addFront(6);
    L.addFront(5);
    REQUIRE(L.length() == 4);

    L.deleteRear(x);
    REQUIRE(x == 9);
    L.deleteRear(x);
    REQUIRE(x == 8);
    L.deleteRear(x);
    REQUIRE(x == 6);
    L.deleteRear(x);
    REQUIRE(x == 5);

    REQUIRE(L.isEmpty());
    bool success = L.deleteFront(x);
    REQUIRE(!success);
    success = L.deleteRear(x);
    REQUIRE(!success);
}