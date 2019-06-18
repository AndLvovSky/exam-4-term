#include "outer_algorithm_runner.h"
#include "event/backup.h"

template <typename Algorithm, typename Structure, typename Connector>
OuterAlgorithmRunner<Algorithm, Structure, Connector>::OuterAlgorithmRunner(
    Algorithm& algorithm, Structure& structure) :
    algorithm(algorithm), structure(structure), eventTransfer(events) {
    this->structure = structure;
    Connector::connect(algorithm, eventTransfer);
}

template <typename Algorithm, typename Structure, typename Connector>
void OuterAlgorithmRunner<Algorithm, Structure, Connector>::run(
    const std::function<void (Algorithm&, Structure&)>& algorithmCode) {
    algorithmCode(algorithm, structure);
}

template <typename Algorithm, typename Structure, typename Connector>
std::shared_ptr<AlgorithmEvent>
OuterAlgorithmRunner<Algorithm, Structure, Connector>::stepBack() {
    if (hasPrevious()) {
        position--;
    }
    restore(position);
    return events[position];
}

template <typename Algorithm, typename Structure, typename Connector>
std::shared_ptr<AlgorithmEvent>
OuterAlgorithmRunner<Algorithm, Structure, Connector>::stepForward() {
    if (hasNext()) {
        position++;
    }
    restore(position);
    return events[position];
}

template <typename Algorithm, typename Structure, typename Connector>
bool OuterAlgorithmRunner<Algorithm, Structure, Connector>::hasPrevious() const {
    return position != 0;
}

template <typename Algorithm, typename Structure, typename Connector>
bool OuterAlgorithmRunner<Algorithm, Structure, Connector>::hasNext() const {
    return position != events.size() - 1;
}

template <typename Algorithm, typename Structure, typename Connector>
Structure&
OuterAlgorithmRunner<Algorithm, Structure, Connector>::getStructure() {
    return structure;
}

template <typename Algorithm, typename Structure, typename Connector>
void OuterAlgorithmRunner<Algorithm, Structure, Connector>::restore(int position) {
    auto event = events[position];
    if (auto backup = std::dynamic_pointer_cast<Backup<Structure>>(event)) {
        backup->restore(structure);
    }
}
