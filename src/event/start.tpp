#include "start.h"

template <typename Structure>
Start<Structure>::Start(const Structure& before) :
    Backup<Structure>(before) {}
