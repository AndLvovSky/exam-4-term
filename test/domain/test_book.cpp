#include <QTest>
#include "test_book.h"
#include "domain/book.h"

TestBook::TestBook() {}

void TestBook::complexTest() {
    QString publisher = "publisher";
    QString genre = "genre";
    int publicationYear = 2019;
    QString author = "author";
    QString name = "name";
    Book book(publisher, genre, publicationYear, author, name);
    QVERIFY(book.getPublisher() == publisher);
    QVERIFY(book.getGenre() == genre);
    QVERIFY(book.getPublicationYear() == publicationYear);
    QVERIFY(book.getAuthor() == author);
    QVERIFY(book.getName() == name);
    Book book2(publisher, genre, publicationYear, author, name);
    QVERIFY(book == book2);
    QVERIFY(book.getId() + 1 == book2.getId());
    QVERIFY(book.toString() != book2.toString());
    QVERIFY(book.getHashCode() == book2.getHashCode());
    qInfo() << book.toString();
    qInfo() << book2.toString();
}
