#ifndef ALGORITHM_RUNNER_H
#define ALGORITHM_RUNNER_H

#include <QVector>
#include "event/algorithm_event.h"
#include <functional>
#include "event_transfer.h"
#include <memory>

/**
 * @brief The AlgorithmRunner used for running algorithms with possibility
 * to reproduce an algorithm steps, show step back and forth and show
 * structure current state.
 *
 * Requires using design pattern such as Memento.
 */
template <typename Structure>
struct AlgorithmRunner {

    /**
     * Makes step back in the algorithm.
     * @return previous algorithm step or nullptr if current step is the first.
     */
    virtual std::shared_ptr<AlgorithmEvent> stepBack() = 0;

    /**
     * Makes step forth in the algorithm.
     * @return next algorithm step, or nullptr if current step is the last.
     */
    virtual std::shared_ptr<AlgorithmEvent> stepForward() = 0;

    /**
     * @return true if current step is not the first, false otherwise.
     */
    virtual bool hasPrevious() const = 0;

    /**
     * @return true if current step is not the last, false otherwise.
     */
    virtual bool hasNext() const = 0;

    /**
     * @return current structure state.
     */
    virtual Structure& getStructure() = 0;

};

#endif // ALGORITHM_RUNNER_H
