#include "compare.h"

template <typename Where, typename What>
Compare<Where, What>::Compare(
    const Where& pa, const Where& pb, const What& a, const What& b) :
    pa(pa), pb(pb), a(a), b(b) {}
