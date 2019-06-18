#ifndef EVENT_TRANSFER_H
#define EVENT_TRANSFER_H

#include <QObject>
#include <QVector>
#include "event/algorithm_event.h"
#include <memory>

class EventTransfer : public QObject {

Q_OBJECT

    QVector<std::shared_ptr<AlgorithmEvent>>& events;

public:

    EventTransfer(QVector<std::shared_ptr<AlgorithmEvent>>& events);

private slots:

    void onStep(std::shared_ptr<AlgorithmEvent> event);

};

#endif // EVENT_TRANSFER_H
