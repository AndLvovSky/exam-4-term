#include <QtTest/QtTest>
#include "domain/test_book.h"

int main(int argc, char* argv[]) {
    int status = 0;
    {
        TestBook obj;
        status |= QTest::qExec(&obj, argc, argv);
    }
    return status;
}
