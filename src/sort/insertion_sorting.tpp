#include "insertion_sorting.h"
#include "event/compare.h"
#include "event/extract.h"
#include "event/move.h"
#include "event/put.h"

template <typename T>
void InsertionSorting<T>::sort(QVector<T>& v,
                               const Comparator<T>& comp) {
    for (int i = 1; i < v.size(); i++) {
        T cur = v[i];
        emit step(Extract<T, int>(cur, i));
        int j = i - 1;
        emit step(Compare<T, int>(cur, v[j], i, j));
        while (j >= 0 && comp.compare(cur, v[j]) < 0){
            v[j + 1] = v[j];
            emit step(Move<T, int, QVector<T>>(v[j], j, j + 1, v));
            j--;
        }
        v[j + 1] = cur;
        emit step(Put<T, int>(cur, j + 1));
    }
}
