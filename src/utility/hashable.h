#ifndef HASHABLE_H
#define HASHABLE_H

/**
 * @brief The Hashable class is an interface for all classes,
 * which objects can be used as keys in a hash table.
 */
template <typename T>
struct Hashable {

    /**
     * @return hash code of the object.
     *
     * If objects are equal, then their hash codes equal,
     * but not always otherwise.
     */
    virtual unsigned int getHashCode() = 0;

    /**
     * @return true if this object equals specified object.
     */
    virtual bool operator == (const T& other) const = 0;

};

#endif // HASHABLE_H
