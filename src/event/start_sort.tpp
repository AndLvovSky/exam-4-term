#include "start_sort.h"

template <typename Structure, typename Element>
StartSort<Structure, Element>::StartSort(
    const Structure& before, const Comparator<Element>& comp) :
    Start<Structure>(before), comp(comp) {}
