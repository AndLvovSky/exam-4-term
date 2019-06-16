#ifndef TEST_SORTING_H
#define TEST_SORTING_H

#include <QObject>
#include "sort/sorting.h"
#include "domain/book.h"

class TestSorting : public QObject {

    Q_OBJECT

public:

    static void smallIntTest(Sorting<int>& sorting);

    static void mediumIntTest(Sorting<int>& sorting);

    static void mediumBookTest(Sorting<Book>& sorting);

};

#endif // TEST_SORTING_H
