#include <QTest>
#include "test_sorting.h"
#include "utility/compare/greater.h"
#include "utility/compare/comparator.h"

void TestSorting::smallIntTest(Sorting<int>& sorting) {
    QVector<int> v;

    v = {2, 1, 3};
    sorting.sort(v);
    QVERIFY(v == QVector<int>({1, 2, 3}));

    v = {2, 1, 3};
    sorting.sort(v, Greater<int>());
    QVERIFY(v == QVector<int>({3, 2, 1}));

    v = {2, 1, 3};
    class CustomIntComparator : public Comparator<int> {
        int compare(const int& a, const int& b) const override {
            return a % 3 - b % 3;
        }
    };
    sorting.sort(v, CustomIntComparator());
    QVERIFY(v == QVector<int>({3, 1, 2}));

    v = {1, -4};
    sorting.sort(v);
    QVERIFY(v == QVector<int>({-4, 1}));

    v = {1, 2};
    sorting.sort(v);
    QVERIFY(v == QVector<int>({1, 2}));

    v = {7};
    sorting.sort(v);
    QVERIFY(v == QVector<int>({7}));

    v = {};
    sorting.sort(v);
    QVERIFY(v == QVector<int>({}));
}

void TestSorting::mediumIntTest(Sorting<int>& sorting) {
    QVector<int> v;

    v = {-3, 1, 6, 2, -5, 7, 6, 4, 0, 3};
    sorting.sort(v);
    QVERIFY(v == QVector<int>({-5, -3, 0, 1, 2, 3, 4, 6, 6, 7}));

    v = {-3, 1, 6, 2, -5, 7, 6, 4, 0, 3};
    sorting.sort(v, Greater<int>());
    QVERIFY(v == QVector<int>({7, 6, 6, 4, 3, 2, 1, 0, -3, -5}));

    v = {7, -3, 1, -5, 2, 8, 3, 3, 1};
    sorting.sort(v);
    QVERIFY(v == QVector<int>({-5, -3, 1, 1, 2, 3, 3, 7, 8}));

    v = {0, 5, 0, 5, 2, -4, -4, 6, -7, 1, 2, 3};
    sorting.sort(v);
    QVERIFY(v == QVector<int>({-7, -4, -4, 0, 0, 1, 2, 2, 3, 5, 5, 6}));

    v = {6, 4, 3, 7, 4, 2};
    sorting.sort(v);
    QVERIFY(v == QVector<int>({2, 3, 4, 4, 6, 7}));

    v = {5, 3, 1, 2, 4};
    sorting.sort(v);
    QVERIFY(v == QVector<int>({1, 2, 3, 4, 5}));
}

void TestSorting::mediumBookTest(Sorting<Book> &sorting) {
    class NameAscBookComparator : public Comparator<Book> {
        int compare(const Book& a, const Book& b) const override {
            if (a.getName() < b.getName()) return -1;
            if (a.getName() == b.getName()) return 0;
            return 1;
        }
    };
    class YearDescBookComparator : public Comparator<Book> {
        int compare(const Book& a, const Book& b) const override {
            return b.getPublicationYear() - a.getPublicationYear();
        }
    };
    QVector<Book> books = {
        Book("p4", "g6", 2000, "a1", "n5"), // 0
        Book("p2", "g1", 2005, "a6", "n6"), // 1
        Book("p7", "g0", 1995, "a4", "n1"), // 2
        Book("p5", "g5", 2010, "a2", "n7"), // 3
        Book("p3", "g2", 1860, "a7", "n4"), // 4
        Book("p0", "g3", 1965, "a3", "n8"), // 5
        Book("p6", "g9", 2009, "a5", "n2"), // 6
        Book("p9", "g8", 2019, "a3", "n3"), // 7
        Book("p1", "g4", 1999, "a8", "n9")  // 8
    };

    QVector<Book> booksCopy = books;
    sorting.sort(books, NameAscBookComparator());
    int order1[9] = {2, 6, 7, 4, 0, 1, 3, 5, 8};
    QVector<Book> booksCheck = {};
    for (auto i : order1) booksCheck.push_back(booksCopy[i]);
    QVERIFY(books == booksCheck);

    books = booksCopy;
    sorting.sort(books, YearDescBookComparator());
    int order2[9] = {7, 3, 6, 1, 0, 8, 2, 5, 4};
    booksCheck = {};
    for (auto i : order2) booksCheck.push_back(booksCopy[i]);
    QVERIFY(books == booksCheck);
}
