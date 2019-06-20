#ifndef BOOK_GENERATOR_H
#define BOOK_GENERATOR_H

#include "domain/book.h"
#include <QRandomGenerator>

/**
 * @brief The BookGenerator generates books.
 */
class BookGenerator {

private:

    static QRandomGenerator gen;

public:

    static Book generateBook();

private:

    static QString generateString();

    static int generateInt();

};

#endif // BOOK_GENERATOR
