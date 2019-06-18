#include "insertion_sorting_connector.h"

template <typename T>
void InsertionSortingConnector::connect(
    const InsertionSorting<T>& v, const EventTransfer& transfer) {
    QObject::connect(&v, SIGNAL(step(std::shared_ptr<AlgorithmEvent>)),
        &transfer, SLOT(onStep(std::shared_ptr<AlgorithmEvent>)));
}
