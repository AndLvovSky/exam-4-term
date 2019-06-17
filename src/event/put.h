#ifndef PUT_H
#define PUT_H

#include "algorithm_event.h"

template <typename What, typename Where>
struct Put : AlgorithmEvent {

    const What what;

    const Where where;

    Put(const What& what, const Where& where);

};

#include "extract.tpp"

#endif // PUT_H
