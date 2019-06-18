#include "backup.h"

template <typename T>
Backup<T>::Backup(const T& obj) {
    this->obj = obj;
}

template <typename T>
void Backup<T>::restore(T& obj) {
    obj = this->obj;
}
