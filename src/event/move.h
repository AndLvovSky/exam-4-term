#ifndef SHIFT_H
#define SHIFT_H

#include "algorithm_event.h"

template <typename What, typename Where, typename Structure>
struct Move : AlgorithmEvent {

    const Where from;

    const Where to;

    const What what;

    const Structure after;

    Move(const Where& from, const Where& to, const What& what,
        const Structure& after);

};

#endif // SHIFT_H
