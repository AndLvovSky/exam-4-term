#include "book.h"
#include <QTextStream>

Book::Book(const QString& publisher,
           const QString& genre,
           int publicationYear,
           const QString& author,
           const QString& name) :
    publisher(publisher),
    genre(genre),
    publicationYear(publicationYear),
    author(author),
    name(name),
    id(counter++) {}

QString Book::getPublisher() const { return publisher; }

QString Book::getGenre() const  { return genre; }

int Book::getPublicationYear() const { return publicationYear; }

QString Book::getAuthor() const { return author; }

QString Book::getName() const { return name; }

int Book::getId() const { return id; }

QString Book::toString() {
    QString repr;
    QTextStream ss(&repr);
    ss << "book[" << id << "]";
    ss << "(publisher: " << publisher << ", ";
    ss << "genre: " << genre << ", ";
    ss << "publication-year: " << publicationYear << ", ";
    ss << "author: " << author << ", ";
    ss << "name: " << name << ", ";
    ss << "hash-code: " << getHashCode() << ")";
    return repr;
}

unsigned int Book::getHashCode() {
    if (hashCode != 0) return hashCode;
    const unsigned int Q = 65521;
    unsigned int pow = 1;
    for (QChar c : publisher) {
        hashCode += pow * c.unicode();
        pow *= Q;
    }
    for (QChar c : genre) {
        hashCode += pow * c.unicode();
        pow *= Q;
    }
    hashCode += pow * publicationYear;
    pow *= Q;
    for (QChar c : author) {
        hashCode += pow * c.unicode();
        pow *= Q;
    }
    for (QChar c : name) {
        hashCode += pow * c.unicode();
        pow *= Q;
    }
    hashCode = hashCode ? hashCode : 1;
    return hashCode;
}

bool Book::operator == (const Book& other) const {
    return publisher == other.publisher &&
        genre == other.genre &&
        publicationYear == other.publicationYear &&
        author == other.author &&
        name == other.name;
}

int Book::counter = 0;
