#ifndef COMPARE_H
#define COMPARE_H

#include "algorithm_event.h"

/**
 * @brief The Compare class represents comparing of 2 objects,
 * that located somewhere.
 */
template <typename What, typename Where>
struct Compare : AlgorithmEvent {

    const What a;

    const What b;

    const Where pa;

    const Where pb;

    Compare(const What& a, const What& b, const Where& pa, const Where& pb);

};

#include "compare.tpp"

#endif // COMPARE_H
