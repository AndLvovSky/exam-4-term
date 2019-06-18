#include <QTest>
#include "test_runner.h"
#include "runner/algorithm_runner.h"

void TestRunner::basicTest() {
    CustomStructure str;
    AlgorithmRunner<CustomStructure, CustomStructureConnector> runner(str);
    runner.run([](CustomStructure& str) { str.doSomething(); });
    int e1 = std::static_pointer_cast<CustomEvent>(runner.stepForward())->a;
    int e2 = std::static_pointer_cast<CustomEvent>(runner.stepForward())->a;
    int e3 = std::static_pointer_cast<CustomEvent>(runner.stepForward())->a;
    QVERIFY(e1 == 1);
    QVERIFY(e2 == 2);
    QVERIFY(e3 == 3);
}
