#ifndef INSERTION_SORTING_H
#define INSERTION_SORTING_H

#include "sorting.h"
#include "utility/compare/comparator.h"
#include "utility/compare/less.h"
#include "event/responsive_entity.h"

/**
 * @brief The InsertionSorting class represents responsive
 * insertion sort algorithm, that can be visualized.
 */
template <typename T>
class InsertionSorting : public Sorting<T>, public ResponsiveEntity {

public:

    void sort(QVector<T>& v,
              const Comparator<T>& comp = Less<T>()) override;

};

#include "insertion_sorting.tpp"

#endif // INSERTION_SORTING_H
