#ifndef OUTER_ALGORITHM_RUNNER_H
#define OUTER_ALGORITHM_RUNNER_H

#include <QVector>
#include "event/algorithm_event.h"
#include <functional>
#include "event_transfer.h"
#include <memory>
#include "algorithm_runner.h"

/**
 * @brief The OuterAlgorithmRunner class used for running algorithms,
 * that take some structure as parameter.
 *
 * See more info in InnerAlgorithmRunner.
 */
template <typename Algorithm, typename Structure, typename Connector>
class OuterAlgorithmRunner : public AlgorithmRunner<Structure> {

    Algorithm& algorithm;

    Structure& structure;

    QVector<std::shared_ptr<AlgorithmEvent>> events;

    EventTransfer eventTransfer;

    int position = -1;

public:

    OuterAlgorithmRunner(Algorithm& connected, Structure& structure);

    /**
     * Calls specified method passing algorithm and structure
     * specified in constructor.
     * @param algorithmCode - function to call.
     */
    void run(const std::function<void (Algorithm&, Structure&)>& algorithmCode);

    std::shared_ptr<AlgorithmEvent> stepBack() override;

    std::shared_ptr<AlgorithmEvent> stepForward() override;

    bool hasPrevious() const override;

    bool hasNext() const override;

    Structure& getStructure() override;

private:

    void restore(int position);

};

#include "outer_algorithm_runner.tpp"

#endif // OUTER_ALGORITHM_RUNNER_H
