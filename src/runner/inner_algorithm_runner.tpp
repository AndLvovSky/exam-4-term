#include "inner_algorithm_runner.h"
#include "event/backup.h"

template <typename Structure, typename Connector>
InnerAlgorithmRunner<Structure, Connector>::InnerAlgorithmRunner(
    Structure& structure) :
    structure(structure), eventTransfer(events) {
    Connector::connect(structure, eventTransfer);
}

template <typename Structure, typename Connector>
void InnerAlgorithmRunner<Structure, Connector>::run(
    const std::function<void (Structure&)>& algorithmCode) {
    algorithmCode(structure);
}

template <typename Structure, typename Connector>
std::shared_ptr<AlgorithmEvent>
InnerAlgorithmRunner<Structure, Connector>::stepBack() {
    if (hasPrevious()) {
        position--;
    }
    restore(position);
    return events[position];
}

template <typename Structure, typename Connector>
std::shared_ptr<AlgorithmEvent>
InnerAlgorithmRunner<Structure, Connector>::stepForward() {
    if (hasNext()) {
        position++;
    }
    restore(position);
    return events[position];
}

template <typename Structure, typename Connector>
bool InnerAlgorithmRunner<Structure, Connector>::hasPrevious() const {
    return position != 0;
}

template <typename Structure, typename Connector>
bool InnerAlgorithmRunner<Structure, Connector>::hasNext() const {
    return position != events.size() - 1;
}

template <typename Structure, typename Connector>
Structure& InnerAlgorithmRunner<Structure, Connector>::getStructure() {
    return structure;
}

template <typename Structure, typename Connector>
void InnerAlgorithmRunner<Structure, Connector>::restore(int position) {
    auto event = events[position];
    if (auto backup = std::dynamic_pointer_cast<Backup<Structure>>(event)) {
        backup->restore(structure);
    }
}


