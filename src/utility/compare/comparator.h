#ifndef COMPARATOR_H
#define COMPARATOR_H

template <typename T>
struct Comparator {

    virtual int compare(const T& a, const T& b) const = 0;

};

#endif // COMPARATOR_H
