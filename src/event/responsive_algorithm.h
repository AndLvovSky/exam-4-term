#ifndef RESPONSIVE_ALGORITHM_H
#define RESPONSIVE_ALGORITHM_H

#include <QObject>
#include "algorithm_event.h"

struct ResponsiveAlgorithm {

    Q_OBJECT

signals:

    void step(const AlgorithmEvent& event);

};

#endif // RESPONSIVE_ALGORITHM_H
