#ifndef CUSTOM_EVENT_H
#define CUSTOM_EVENT_H

#include "event/algorithm_event.h"

class CustomEvent : public AlgorithmEvent {
public:
    int a;
    CustomEvent(int a) : a(a) {}
};

#endif // CUSTOM_EVENT_H
