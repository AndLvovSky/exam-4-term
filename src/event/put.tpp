#include "put.h"

template <typename What, typename Where>
Put<What, Where>::Put(const What& what, const Where& where) :
    what(what), where(where) {}
