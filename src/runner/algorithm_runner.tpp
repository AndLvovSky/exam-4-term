#include "algorithm_runner.h"

template <typename Structure, typename Connector>
AlgorithmRunner<Structure, Connector>::AlgorithmRunner(Structure& structure) :
    structure(structure), eventTransfer(events) {
    Connector::connect(structure, eventTransfer);
}

template <typename Structure, typename Connector>
void AlgorithmRunner<Structure, Connector>::run(
    const std::function<void (Structure&)>& algorithm) {
    algorithm(structure);
}

template <typename Structure, typename Connector>
std::shared_ptr<AlgorithmEvent>
AlgorithmRunner<Structure, Connector>::stepBack() {
    if (hasPrevious()) {
        position--;
    }
    return events[position];
}

template <typename Structure, typename Connector>
std::shared_ptr<AlgorithmEvent>
AlgorithmRunner<Structure, Connector>::stepForward() {
    if (hasNext()) {
        position++;
    }
    return events[position];
}

template <typename Structure, typename Connector>
bool AlgorithmRunner<Structure, Connector>::hasPrevious() const {
    return position != 0;
}

template <typename Structure, typename Connector>
bool AlgorithmRunner<Structure, Connector>::hasNext() const {
    return position != events.size() - 1;
}