#ifndef BACKUP_H
#define BACKUP_H

template <typename T>
class Backup {

    T obj;

public:

    Backup(const T& obj);

    void restore(T& obj);

};

#include "backup.tpp"

#endif // BACKUP_H
