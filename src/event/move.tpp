#include "move.h"

template <typename What, typename Where, typename Structure>
Move<What, Where, Structure>::Move(const Where& from, const Where& to,
    const What& what, const Structure& after) :
    from(from), to(to), what(what), after(after) {}
