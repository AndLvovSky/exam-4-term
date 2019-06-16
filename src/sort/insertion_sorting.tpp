#include "insertion_sorting.h"

template <typename T>
void InsertionSorting<T>::sort(QVector<T>& v,
                               const Comparator<T>& comp) {
    for (int i = 1; i < v.size(); i++) {
        T cur = v[i];
        int j = i - 1;
        while (j >= 0 && comp.compare(cur, v[j]) < 0){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = cur;
    }
}
