#include "qvector_connector.h"

template <typename T>
void QVectorConnector::connect(const QVector<T>& v,
                               const EventTransfer& transfer) {
    QObject::connect(&v, SIGNAL(step(std::shared_ptr<AlgorithmEvent>)),
        &transfer, SLOT(onStep(std::shared_ptr<AlgorithmEvent>)));
}
