#ifndef HASHABLE_H
#define HASHABLE_H

template <typename T>
struct Hashable {

    virtual unsigned int getHashCode() = 0;

    virtual bool operator == (const T& other) const = 0;

};

#endif // HASHABLE_H
