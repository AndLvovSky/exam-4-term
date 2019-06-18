#include "compare.h"

template <typename What, typename Where>
Compare<What, Where>::Compare(
    const What& a, const What& b, const Where& pa, const Where& pb) :
    a(a), b(b), pa(pa), pb(pb) {}
