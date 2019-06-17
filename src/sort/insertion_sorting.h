#ifndef INSERTION_SORTING_H
#define INSERTION_SORTING_H

#include "sorting.h"
#include "utility/compare/comparator.h"
#include "utility/compare/less.h"
#include "event/responsive_algorithm.h"

template <typename T>
class InsertionSorting : public Sorting<T>, public ResponsiveAlgorithm {

public:

    void sort(QVector<T>& v,
              const Comparator<T>& comp) override;

};

#include "insertion_sorting.tpp"

#endif // INSERTION_SORTING_H
