#ifndef END_H
#define END_H

#include "algorithm_event.h"

template <typename Structure>
struct End : AlgorithmEvent {

    const Structure after;

    End(const Structure& after);

};

#include "end.tpp"

#endif // END_H
