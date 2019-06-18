#ifndef ALGORITHM_RUNNER_H
#define ALGORITHM_RUNNER_H

#include <QVector>
#include "event/algorithm_event.h"
#include <functional>
#include "event_transfer.h"
#include <memory>

template <typename Structure, typename Connector>
class AlgorithmRunner {

    Structure& structure;

    QVector<std::shared_ptr<AlgorithmEvent>> events;

    EventTransfer eventTransfer;

    int position = -1;

public:

    AlgorithmRunner(Structure& structure);

    void run(const std::function<void (Structure&)>& algorithm);

    std::shared_ptr<AlgorithmEvent> stepBack();

    std::shared_ptr<AlgorithmEvent> stepForward();

    bool hasPrevious() const;

    bool hasNext() const;

};

#include "algorithm_runner.tpp"

#endif // ALGORITHM_RUNNER_H
