#ifndef COMPARE_H
#define COMPARE_H

#include "algorithm_event.h"

template <typename Where, typename What>
struct Compare : AlgorithmEvent {

    const Where pa;

    const Where pb;

    const What a;

    const What b;

    Compare(const Where& pa, const Where& pb, const What& a, const What& b);

};

#include "compare.tpp"

#endif // COMPARE_H
