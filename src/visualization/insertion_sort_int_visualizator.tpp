#include "insertion_sort_int_visualizator.h"
#include <QDebug>
#include "event/start_sort.h"
#include "event/end.h"
#include "event/compare.h"
#include "event/move.h"
#include "event/put.h"
#include "event/extract.h"
#include <memory>

void InsertionSortIntVisualizator::visualize(
    std::shared_ptr<AlgorithmEvent> event) {
    QVector<int> v;
    if (auto se = std::dynamic_pointer_cast<StartSort<QVector<int>, int>>(event)) {
        se->restore(v);
        qInfo() << "start sort:";
        qInfo() << v;
    }
    if (auto se = std::dynamic_pointer_cast<End<QVector<int>>>(event)) {
        se->restore(v);
        qInfo() << "end sort:";
        qInfo() << v;
    }
    if (auto se = std::dynamic_pointer_cast<Compare<int, QVector<int>>>(event)) {
        qInfo() << "compare " << se->a << " and " << se->b <<
            " at positions " << se->pa << " and " << se->pb;
    }
    if (auto se = std::dynamic_pointer_cast<Move<int, int, QVector<int>>>(event)) {
        se->restore(v);
        qInfo() << "move " << se->what << " from " <<
            se->from << " to " << se->to << ":";
        qInfo() << v;
    }
    if (auto se = std::dynamic_pointer_cast<Put<int, int, QVector<int>>>(event)) {
        se->restore(v);
        qInfo() << "put " << se->what << " at position " << se->where << ":";
        qInfo() << v;
    }
    if (auto se = std::dynamic_pointer_cast<Extract<int, int>>(event)) {
        qInfo() << "extract " << se->what << " from position " << se->where;
    }
}
