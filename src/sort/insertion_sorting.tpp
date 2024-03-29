#include "insertion_sorting.h"
#include "event/compare.h"
#include "event/extract.h"
#include "event/move.h"
#include "event/put.h"
#include "event/start_sort.h"
#include "event/end.h"
#include <memory>

template <typename T>
void InsertionSorting<T>::sort(QVector<T>& v,
                               const Comparator<T>& comp) {
    emit step(std::make_shared<StartSort<QVector<T>, T>>(v, comp));
    for (int i = 1; i < v.size(); i++) {
        T cur = v[i];
        emit step(std::make_shared<Extract<T, int>>(cur, i));
        int j = i - 1;
        emit step(std::make_shared<Compare<T, int>>(cur, v[j], i, j));
        while (j >= 0 && comp.compare(cur, v[j]) < 0){
            v[j + 1] = v[j];
            emit step(std::make_shared<Move<T, int, QVector<T>>>(v[j], j, j + 1, v));
            j--;
        }
        v[j + 1] = cur;
        emit step(std::make_shared<Put<T, int, QVector<T>>>(cur, j + 1, v));
    }
    emit step(std::make_shared<End<QVector<T>>>(v));
}
