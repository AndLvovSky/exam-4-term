#ifndef TEST_BOOK_H
#define TEST_BOOK_H

#include <QObject>

class TestBook : public QObject {

    Q_OBJECT

public:

    TestBook();

private slots:

    void complexTest();

};

#endif // TEST_BOOK_H
