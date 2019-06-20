#ifndef VISUALIZATOR_H
#define VISUALIZATOR_H

#include "event/algorithm_event.h"
#include <memory>

/**
 * @brief The Visualizator used for visualization of algorithm steps.
 */
template <typename Structure>
struct Visualizator {

    virtual void visualize(std::shared_ptr<AlgorithmEvent> event) = 0;

};

#endif // VISUALIZATOR_H
