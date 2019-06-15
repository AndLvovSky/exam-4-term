#include <QString>
#include "utility/hashable.h"

class Book : Hashable<Book> {

private:

    QString publisher;

    QString genre;

    int publicationYear;

    QString author;

    QString name;

    int id;

    unsigned int hashCode = 0;

    static int counter;

public:

    Book(const QString& publisher,
         const QString& genre,
         int publicationYear,
         const QString& author,
         const QString& name);

    QString getPublisher();

    QString getGenre();

    int getPublicationYear();

    QString getAuthor();

    QString getName();

    int getId();

    QString toString();

    unsigned int getHashCode() override;

    bool operator == (const Book& other) override;

};
