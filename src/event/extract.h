#ifndef EXTRACT_H
#define EXTRACT_H

#include "algorithm_event.h"

/**
 * @brief The Extract class represents keeping an object from a location.
 */
template <typename What, typename Where>
struct Extract : AlgorithmEvent {

    const What what;

    const Where where;

    Extract(const What& what, const Where& where);

};

#include "extract.tpp"

#endif // EXTRACT_H
