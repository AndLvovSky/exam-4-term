#include "less.h"

template <typename T>
int Less<T>::compare(const T& a, const T& b) const {
    if (a < b) return -1;
    if (a == b) return 0;
    return 1;
}
