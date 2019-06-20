#ifndef START_H
#define START_H

#include "algorithm_event.h"
#include "backup.h"

/**
 * @brief The Start class represents start of an algorithm.
 */
template <typename Structure>
struct Start : AlgorithmEvent, Backup<Structure> {

    Start(const Structure& before);

};

#include "start.tpp"

#endif // START_H
