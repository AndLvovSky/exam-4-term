#include "book_comparator_factory.h"

std::shared_ptr<Comparator<Book>>
    BookComparatorFactory::makeComparator(Field field, Order order) {
    switch (field) {
        case PUBLISHER : {
            return std::make_shared<PublisherAsc>();
        }
        case GENRE : {
            return std::make_shared<GenreAsc>();
        }
        case PUBLICATION_YEAR : {
            return std::make_shared<PublicationYearAsc>();
        }
        case AUTHOR : {
            return std::make_shared<AuthorAsc>();
        }
        case NAME : {
            return std::make_shared<NameAsc>();
        }
    }
}
