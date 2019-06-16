#include <QTest>
#include "test_comparator.h"
#include "utility/compare/comparator.h"
#include "utility/compare/less.h"
#include "utility/compare/greater.h"
#include <memory>
#include "domain/book.h"

TestComparator::TestComparator() {}

void TestComparator::testInt() {
    std::unique_ptr<Comparator<int>> comp;

    comp = std::make_unique<Less<int>>();
    QVERIFY(comp->compare(1, 2) < 0);
    QVERIFY(comp->compare(2, 1) > 0);
    QVERIFY(comp->compare(1, 1) == 0);

    comp = std::make_unique<Greater<int>>();
    QVERIFY(comp->compare(1, 2) > 0);
    QVERIFY(comp->compare(2, 1) < 0);
    QVERIFY(comp->compare(1, 1) == 0);

    class CustomIntComparator : public Comparator<int> {
        int compare(const int& a, const int& b) const override {
            return a % 3 - b % 3;
        }
    };
    comp = std::make_unique<CustomIntComparator>();
    QVERIFY(comp->compare(3, 1) < 0);
    QVERIFY(comp->compare(5, 7) > 0);
    QVERIFY(comp->compare(4, 4) == 0);
}

void TestComparator::testBook() {
    std::unique_ptr<Comparator<Book>> comp;
    class CustomBookComparator : public Comparator<Book> {
        int compare(const Book& a, const Book& b) const override {
            if (a.getGenre() < b.getGenre()) return -1;
            if (a.getGenre() == b.getGenre()) return 0;
            return 1;
        }
    };
    QVector<Book> books = {
        Book("publiser1", "genre2", 2018, "author2", "name1"),
        Book("publiser2", "genre1", 2019, "author1", "name2")
    };
    comp = std::make_unique<CustomBookComparator>();
    QVERIFY(comp->compare(books[1], books[0]) < 0);
    QVERIFY(comp->compare(books[0], books[1]) > 0);
    QVERIFY(comp->compare(books[0], books[0]) == 0);
}
