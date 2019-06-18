#ifndef CUSTOM_STRUCTURE_CONNECTOR_H
#define CUSTOM_STRUCTURE_CONNECTOR_H

#include <QObject>
#include "custom_structure.h"
#include "runner/event_transfer.h"

class CustomStructureConnector : public QObject {
    Q_OBJECT
public:
    static void connect(const CustomStructure& str,
                        const EventTransfer& transfer) {
        qInfo() << "connect";
        QObject::connect(&str, SIGNAL(step(std::shared_ptr<AlgorithmEvent>)),
            &transfer, SLOT(onStep(std::shared_ptr<AlgorithmEvent>)));
    }
};

#endif // CUSTOM_STRUCTURE_CONNECTOR_H
