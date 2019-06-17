#include "extract.h"

template <typename What, typename Where>
Extract<What, Where>::Extract(const What& what, const Where& where) :
    what(what), where(where) {}
