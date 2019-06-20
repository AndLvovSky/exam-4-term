#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include "utility/hashable.h"

/**
 * @brief The Book class represents a book.
 */
class Book : Hashable<Book> {

private:

    QString publisher;

    QString genre;

    int publicationYear;

    QString author;

    QString name;

    int id; /** determined by counter value at the creation time */

    unsigned int hashCode = 0; /** calculated only once */

    static int counter; /** number of created books */

public:

    Book(const QString& publisher,
         const QString& genre,
         int publicationYear,
         const QString& author,
         const QString& name);

    Book() = default;

    QString getPublisher() const;

    QString getGenre() const;

    int getPublicationYear() const;

    QString getAuthor() const;

    QString getName() const;

    int getId() const;

    QString toString();

    unsigned int getHashCode()  override;

    bool operator == (const Book& other) const override;

};

#endif // BOOK_H
