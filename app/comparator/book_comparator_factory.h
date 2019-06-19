#ifndef BOOK_COMPARATOR_H
#define BOOK_COMPARATOR_H

#include "utility/compare/comparator.h"
#include "domain/book.h"
#include <QString>
#include <memory>

// Abstract Factory
class BookComparatorFactory {

public:

    enum Field {
        PUBLISHER,
        GENRE,
        PUBLICATION_YEAR,
        AUTHOR,
        NAME
    };

    enum Order {
        ASCENDING,
        DESCENDING
    };

    static std::shared_ptr<Comparator<Book>>
        makeComparator(Field field, Order order = Order::ASCENDING);

private:

    struct PublisherAsc : Comparator<Book> {
        int compare(const Book& a, const Book& b) const override {
            if (a.getPublisher() < b.getPublisher()) return -1;
            if (a.getPublisher() == b.getPublisher()) return 0;
            return 1;
        }
    };

    struct GenreAsc : Comparator<Book> {
        int compare(const Book& a, const Book& b) const override {
            if (a.getGenre() < b.getGenre()) return -1;
            if (a.getGenre() == b.getGenre()) return 0;
            return 1;
        }
    };

    struct PublicationYearAsc : Comparator<Book> {
        int compare(const Book& a, const Book& b) const override {
            if (a.getPublicationYear() < b.getPublicationYear()) return -1;
            if (a.getPublicationYear() == b.getPublicationYear()) return 0;
            return 1;
        }
    };

    struct AuthorAsc : Comparator<Book> {
        int compare(const Book& a, const Book& b) const override {
            if (a.getAuthor() < b.getAuthor()) return -1;
            if (a.getAuthor() == b.getAuthor()) return 0;
            return 1;
        }
    };

    struct NameAsc : Comparator<Book> {
        int compare(const Book& a, const Book& b) const override {
            if (a.getName() < b.getName()) return -1;
            if (a.getName() == b.getPublisher()) return 0;
            return 1;
        }
    };

};

#endif // BOOK_COMPARATOR_H
