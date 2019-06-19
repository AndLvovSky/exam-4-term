#include "book_generator.h"

QRandomGenerator BookGenerator::gen(100);

Book BookGenerator::generateBook() {
    QString publisher = generateString();
    QString genre = generateString();
    int publicationYear = generateInt();
    QString author = generateString();
    QString name = generateString();
    return Book(publisher, genre, publicationYear, author, name);
}

QString BookGenerator::generateString() {
    QString letters = "qwertyuiopasdfghjklzxcvbnm";
    const int maxSize = 5;
    int size = gen.generate() % maxSize + 1;
    QString s = "";
    for (int i = 0; i < size; i++) {
        s += letters[gen.generate() % letters.size()];
    }
    return s;
}

int BookGenerator::generateInt() {
    const int min = 1900, max = 2019;
    int d = max - min + 1;
    return gen.generate() % d + min;
}
