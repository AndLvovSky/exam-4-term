#include "test_insertion_sorting.h"
#include "test_sorting.h"

TestInsertionSorting::TestInsertionSorting() {}

void TestInsertionSorting::smallIntTest() {
    TestSorting::smallIntTest(sortingInt);
}

void TestInsertionSorting::mediumIntTest() {
    TestSorting::mediumIntTest(sortingInt);
}

void TestInsertionSorting::mediumBookTest() {
    TestSorting::mediumBookTest(sortingBook);
}
