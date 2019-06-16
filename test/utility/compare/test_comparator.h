#ifndef TEST_COMPARATOR_H
#define TEST_COMPARATOR_H

#include <QObject>

class TestComparator : public QObject {

    Q_OBJECT

public:

    TestComparator();

private slots:

    void testInt();

    void testBook();

};

#endif // TEST_COMPARATOR_H
