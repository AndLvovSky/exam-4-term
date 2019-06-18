#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include <QDebug>

class TestRunner : public QObject {

    Q_OBJECT

private slots:

    void basicTest();

};

#endif // TEST_RUNNER_H
