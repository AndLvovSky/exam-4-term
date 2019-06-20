#ifndef GREATER_H
#define GREATER_H

#include "comparator.h"

template <typename T>
class Greater : public Comparator<T> {

public:

    /**
     * Uses operator '<' and '=='.
     */
    int compare(const T& a, const T& b) const override;

};

#include "greater.tpp"

#endif // GREATER_H
