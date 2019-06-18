#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include <QObject>
#include <QDebug>
#include "event/algorithm_event.h"
#include "runner/connector/qvector_connector.h"
#include "event/responsive_algorithm.h"
#include <memory>

class CustomEvent : public AlgorithmEvent {
public:
    int a;
    CustomEvent(int a) : a(a) {}
};

class CustomStructure : public ResponsiveAlgorithm {
public:
    void doSomething() {
        qInfo() << "do something";
        qInfo() << "emit 1";
        emit step(std::make_shared<CustomEvent>(1));
        qInfo() << "emit 2";
        emit step(std::make_shared<CustomEvent>(2));
        qInfo() << "emit 3";
        emit step(std::make_shared<CustomEvent>(3));
    }
};

class CustomStructureConnector : public QObject {
    Q_OBJECT
public:
    static void connect(const CustomStructure& str,
                        const EventTransfer& transfer) {
        qInfo() << "connect";
        QObject::connect(&str, SIGNAL(step(std::shared_ptr<AlgorithmEvent>)),
            &transfer, SLOT(onStep(std::shared_ptr<AlgorithmEvent>)));
    }
};

class TestRunner : public QObject {

    Q_OBJECT

private slots:

    void basicTest();

};

#endif // TEST_RUNNER_H
