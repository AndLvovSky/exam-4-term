#ifndef INNER_ALGORITHM_RUNNER_H
#define INNER_ALGORITHM_RUNNER_H

#include <QVector>
#include "event/algorithm_event.h"
#include <functional>
#include "event_transfer.h"
#include <memory>
#include "utility/none.h"
#include "algorithm_runner.h"

// Observer
template <typename Structure, typename Connector>
class InnerAlgorithmRunner : public AlgorithmRunner<Structure> {

    Structure& structure;

    QVector<std::shared_ptr<AlgorithmEvent>> events;

    EventTransfer eventTransfer;

    int position = -1;

public:

    InnerAlgorithmRunner(Structure& structure);

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
