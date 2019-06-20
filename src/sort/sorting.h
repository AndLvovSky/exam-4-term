#ifndef SORTING_H
#define SORTING_H

#include <QVector>
#include "utility/compare/comparator.h"
#include "utility/compare/less.h"

/**
 * @brief The Sorting is an inteface for all sorting algorithms.
 */
template <typename T>
struct Sorting  {

    /**
     * Sorts vector using specified comparator.
     * By default uses comparator Less<T>.
     * @param v - vector to sort.
     * @param comp - comparator.
     */
    virtual void sort(QVector<T>& v,
                      const Comparator<T>& comp = Less<T>()) = 0;

};

#endif // SORTING_H
