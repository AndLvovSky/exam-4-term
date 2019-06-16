#ifndef TEST_INSERTION_SORTING_H
#define TEST_INSERTION_SORTING_H

#include <QObject>
#include "sort/insertion_sorting.h"
#include "domain/book.h"

class TestInsertionSorting : public QObject {

    Q_OBJECT

private:

    InsertionSorting<int> sortingInt;

    InsertionSorting<Book> sortingBook;

public:

    TestInsertionSorting();

private slots:

    void smallIntTest();

    void mediumIntTest();

    void mediumBookTest();

};

#endif // TEST_INSERTION_SORTING_H
