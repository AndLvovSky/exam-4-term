#include <QTest>
#include "test_player.h"
#include "player/algorithm_player.h"
#include "runner/outer_algorithm_runner.h"
#include "visualization/insertion_sort_int_visualizator.h"
#include "runner/connector/insertion_sorting_connector.h"
#include "sort/insertion_sorting.h"

void TestPlayer::basicTest() {
    QVector<int> v = {3, 1, 2};
    InsertionSorting<int> sorting;
    OuterAlgorithmRunner<InsertionSorting<int>, QVector<int>,
        InsertionSortingConnector> runner(sorting, v);
    InsertionSortIntVisualizator visualizator;
    AlgorithmPlayer<QVector<int>> player(runner, visualizator);
    runner.run([](InsertionSorting<int>& sorting, QVector<int>& v) { sorting.sort(v); });
    player.play();
}
