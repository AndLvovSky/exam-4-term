#include <QtTest/QtTest>
#include "domain/test_book.h"
#include "utility/compare/test_comparator.h"
#include "sort/test_insertion_sorting.h"
#include "runner/test_runner.h"

int main(int argc, char* argv[]) {
    int status = 0;
    {
        TestBook obj;
        status |= QTest::qExec(&obj, argc, argv);
    }
    {
        TestComparator obj;
        status |= QTest::qExec(&obj, argc, argv);
    }
    {
        TestInsertionSorting obj;
        status |= QTest::qExec(&obj, argc, argv);
    }
    {
        TestRunner obj;
        status |= QTest::qExec(&obj, argc, argv);
    }
    return status;
}
