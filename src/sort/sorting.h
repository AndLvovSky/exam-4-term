#ifndef SORTING_H
#define SORTING_H

#include <QVector>
#include "utility/compare/comparator.h"
#include "utility/compare/less.h"

template <typename T>
struct Sorting {

    virtual void sort(QVector<T>& v,
                      const Comparator<T>& comp = Less<T>()) = 0;

};

#endif // SORTING_H
