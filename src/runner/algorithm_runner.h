#ifndef ALGORITHM_RUNNER_H
#define ALGORITHM_RUNNER_H

#include <QVector>
#include "event/algorithm_event.h"
#include <functional>
#include "event_transfer.h"
#include <memory>
#include "utility/none.h"

template <typename Structure>
struct AlgorithmRunner {

    virtual std::shared_ptr<AlgorithmEvent> stepBack() = 0;

    virtual std::shared_ptr<AlgorithmEvent> stepForward() = 0;

    virtual bool hasPrevious() const = 0;

    virtual bool hasNext() const = 0;

    virtual Structure& getStructure() = 0;

};

#endif // ALGORITHM_RUNNER_H
