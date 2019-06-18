#include "move.h"

template <typename What, typename Where, typename Structure>
Move<What, Where, Structure>::Move(const What& what,
    const Where& from, const Where& to, const Structure& after) :
    Backup<Structure>(after), what(what), from(from), to(to) {}
