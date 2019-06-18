#ifndef END_H
#define END_H

#include "algorithm_event.h"
#include "backup.h"

template <typename Structure>
struct End : AlgorithmEvent, Backup<Structure> {

    End(const Structure& after);

};

#include "end.tpp"

#endif // END_H
