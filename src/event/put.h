#ifndef PUT_H
#define PUT_H

#include "algorithm_event.h"
#include "backup.h"

/**
 * @brief The Put class represents puting object in a location.
 */
template <typename What, typename Where, typename Structure>
struct Put : AlgorithmEvent, Backup<Structure> {

    const What what;

    const Where where;

    Put(const What& what, const Where& where, const Structure& after);

};

#include "put.tpp"

#endif // PUT_H
