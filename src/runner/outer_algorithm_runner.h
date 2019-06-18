#ifndef OUTER_ALGORITHM_RUNNER_H
#define OUTER_ALGORITHM_RUNNER_H

#include <QVector>
#include "event/algorithm_event.h"
#include <functional>
#include "event_transfer.h"
#include <memory>
#include "utility/none.h"
#include "algorithm_runner.h"

template <typename Algorithm, typename Structure, typename Connector>
class OuterAlgorithmRunner : public AlgorithmRunner<Structure> {

    Algorithm& algorithm;

    Structure& structure;

    QVector<std::shared_ptr<AlgorithmEvent>> events;

    EventTransfer eventTransfer;

    int position = -1;

public:

    OuterAlgorithmRunner(Algorithm& connected, Structure& structure);

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
