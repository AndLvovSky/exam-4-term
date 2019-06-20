#ifndef INNER_ALGORITHM_RUNNER_H
#define INNER_ALGORITHM_RUNNER_H

#include <QVector>
#include "event/algorithm_event.h"
#include <functional>
#include "event_transfer.h"
#include <memory>
#include "algorithm_runner.h"

/**
 * @brief The InnerAlgorithmRunner class used for running algorithms,
 * that are methods of the structure.
 *
 * Because of QObject restriction of template classes it use 2
 * additional classes: EventTransfer and Connector to save algorithm events
 * emited while running algorithm code in events container.
 * Design patterns used here are Observer (signals - slots) and
 * Facade (hiding from user events catching).
 */
template <typename Structure, typename Connector>
class InnerAlgorithmRunner : public AlgorithmRunner<Structure> {

    Structure& structure;

    QVector<std::shared_ptr<AlgorithmEvent>> events;

    EventTransfer eventTransfer;

    int position = -1;

public:

    InnerAlgorithmRunner(Structure& structure);

    /**
     * Calls specified method passing structure specified in constructor.
     * @param algorithmCode - function to call.
     */
    void run(const std::function<void (Structure&)>& algorithmCode);

    std::shared_ptr<AlgorithmEvent> stepBack() override;

    std::shared_ptr<AlgorithmEvent> stepForward() override;

    bool hasPrevious() const override;

    bool hasNext() const override;

    Structure& getStructure() override;

private:

    void restore(int position);

};

#include "inner_algorithm_runner.tpp"

#endif // INNER_ALGORITHM_RUNNER_H
