#include "end.h"

template <typename Structure>
End<Structure>::End(const Structure& after) :
    Backup<Structure>(after) {}
