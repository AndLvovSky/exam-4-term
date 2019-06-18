#ifndef EVENT_CATCHER_H
#define EVENT_CATCHER_H

#include "event_transfer.h"
#include <memory>
#include <QDebug>

EventTransfer::EventTransfer(QVector<std::shared_ptr<AlgorithmEvent>>& events) :
    events(events) {}

void EventTransfer::onStep(std::shared_ptr<AlgorithmEvent> event) {
    events.push_back(event);
    qInfo() << "add event";
}

#endif // EVENT_CATCHER_H
