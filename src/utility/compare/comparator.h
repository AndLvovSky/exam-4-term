#ifndef COMPARATOR_H
#define COMPARATOR_H

/**
 * The Comparator interface imposes some ordering.
 */
template <typename T>
struct Comparator {

    /**
     * @return negative number if a < b, positive number if a > b, otherwise 0.
     */
    virtual int compare(const T& a, const T& b) const = 0;

};

#endif // COMPARATOR_H
