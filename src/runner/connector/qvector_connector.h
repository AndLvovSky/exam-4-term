#ifndef QVECTOR_CONNECTOR_H
#define QVECTOR_CONNECTOR_H

#include <QObject>
#include <QVector>
#include "runner/event_transfer.h"

struct QVectorConnector : public QObject {

    Q_OBJECT

public:

    template <typename T>
    static void connect(const QVector<T>& v, const EventTransfer& transfer);

};

#endif // QVECTOR_CONNECTOR_H
