#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_set>
#include "heap.h"
using namespace std;
#include "catch.hpp"

TEST_CASE( "Test 01", "Assignment 7" )
{
    Heap* heapPtr = new Heap;
    int removed;
    int max;
    heapPtr->printHeap();
    // test insert
    max = heapPtr->getMax();
    if (max != -1)
    {
        INFO("heap should be able to handle getMax calls on empty array");
    }
    REQUIRE(max == -1);
    removed = heapPtr->removeMax();
    if (removed != -1)
    {
        INFO("heap should be able to handle removeMax calls on empty array");
    }
    REQUIRE(removed == -1);
    heapPtr->insert(3);
    heapPtr->insert(2);
    heapPtr->insert(1);
    heapPtr->insert(15);
    heapPtr->printHeap();
    max = heapPtr->getMax();
    if (max != 15) {
        cout << "heap max was the incorrect max value" << endl;
    }
    REQUIRE(max == 15);
    heapPtr->insert(5);
    heapPtr->insert(4);
    heapPtr->insert(45);
    heapPtr->printHeap();
    max = heapPtr->getMax();
    if (max != 45) {
        INFO("heap max was the incorrect value");
    }
    REQUIRE(max == 45);
    // testing remove
    removed = heapPtr->removeMax();
    if (removed != 45)
    {
        INFO("heap removed the incorrect value");
    }
    REQUIRE(removed == 45);
    heapPtr->printHeap();
    heapPtr->changeKey(2, 60);
    heapPtr->printHeap();
    max = heapPtr->getMax();
    if (max != 60)
    {
        INFO("heap max was the incorrect value");
    }
    REQUIRE(max == 60);
    removed = heapPtr->removeMax();
    if (removed != 60) {
        INFO("heap removed the incorrect value");
    }
    REQUIRE(removed == 60);
    delete heapPtr;
}