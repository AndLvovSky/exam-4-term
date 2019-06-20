#ifndef LESS_H
#define LESS_H

#include "comparator.h"

template <typename T>
class Less : public Comparator<T> {

public:

    /**
     * Uses operator '<' and '=='.
     */
    int compare(const T& a, const T& b) const override;

};

#include "less.tpp"

#endif // LESS_H
