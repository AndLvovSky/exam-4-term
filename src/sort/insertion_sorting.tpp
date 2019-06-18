#include "insertion_sorting.h"
#include "event/compare.h"
#include "event/extract.h"
#include "event/move.h"
#include "event/put.h"
#include "event/start.h"
#include "event/end.h"
#include <memory>

template <typename T>
void InsertionSorting<T>::sort(QVector<T>& v,
                               const Comparator<T>& comp) {
    emit step(std::make_shared<Start<QVector<T>>>(v));
    for (int i = 1; i < v.size(); i++) {
        T cur = v[i];
        emit step(std::make_shared<Extract<T, int>>(cur, i));
        int j = i - 1;
        emit step(std::make_shared<Compare<int, T>>(i, j, cur, v[j]));
        while (j >= 0 && comp.compare(cur, v[j]) < 0){
            v[j + 1] = v[j];
            emit step(std::make_shared<Move<T, int, QVector<T>>>(j, j + 1, v[j], v));
            j--;
        }
        v[j + 1] = cur;
        emit step(std::make_shared<Put<T, int, QVector<T>>>(cur, j + 1, v));
    }
    emit step(std::make_shared<End<QVector<T>>>(v));
}
