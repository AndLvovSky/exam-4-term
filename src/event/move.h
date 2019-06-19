#ifndef MOVE_H
#define MOVE_H

#include "algorithm_event.h"
#include "backup.h"

template <typename What, typename Where, typename Structure>
struct Move : AlgorithmEvent, Backup<Structure> {

    const What what;

    const Where from;

    const Where to;

    Move(const What& what, const Where& from, const Where& to,
        const Structure& after);

};

#include "move.tpp"

#endif // MOVE_H
