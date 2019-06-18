#ifndef RESPONSIVE_ALGORITHM_H
#define RESPONSIVE_ALGORITHM_H

#include <QObject>
#include "algorithm_event.h"
#include <memory>

struct ResponsiveAlgorithm : public QObject {

Q_OBJECT

signals:

    void step(std::shared_ptr<AlgorithmEvent> event);

};

#endif // RESPONSIVE_ALGORITHM_H
