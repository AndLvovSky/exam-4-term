#include <QTest>
#include "test_runner.h"
#include "runner/inner_algorithm_runner.h"
#include "player_set/custom_event.h"
#include "player_set/custom_structure.h"
#include "player_set/custom_structure_connector.h"

void TestRunner::basicTest() {
    CustomStructure str;
    InnerAlgorithmRunner<CustomStructure, CustomStructureConnector> runner(str);
    runner.run([](CustomStructure& str) { str.doSomething(); });
    int e1 = std::static_pointer_cast<CustomEvent>(runner.stepForward())->a;
    int e2 = std::static_pointer_cast<CustomEvent>(runner.stepForward())->a;
    int e3 = std::static_pointer_cast<CustomEvent>(runner.stepForward())->a;
    QVERIFY(e1 == 1);
    QVERIFY(e2 == 2);
    QVERIFY(e3 == 3);
}
