#ifndef START_H
#define START_H

#include "algorithm_event.h"

template <typename Structure>
struct Start : AlgorithmEvent {

    const Structure before;

    Start(const Structure& before);

};

#include "start.tpp"

#endif // START_H
