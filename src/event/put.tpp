#include "put.h"

template <typename What, typename Where, typename Structure>
Put<What, Where, Structure>::Put(const What& what, const Where& where,
    const Structure& after) :
    Backup<Structure>(after), what(what), where(where) {}
