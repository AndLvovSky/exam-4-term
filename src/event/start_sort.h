#ifndef START_SORT_H
#define START_SORT_H

#include "start.h"
#include "utility/compare/comparator.h"
#include <memory>

/**
 * @brief The StartSort class represents start of an sorting algorithm.
 */
template <typename Structure, typename Element>
struct StartSort : Start<Structure> {

    const Comparator<Element>& comp;

    StartSort(const Structure& before, const Comparator<Element>& comp);

};

#include "start_sort.tpp"

#endif // START_SORT_H
