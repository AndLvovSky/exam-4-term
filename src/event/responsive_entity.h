#ifndef RESPONSIVE_ENTITY_H
#define RESPONSIVE_ENTITY_H

#include <QObject>
#include "algorithm_event.h"
#include <memory>

/**
 * @brief The ResponsiveEntity represents entities,
 * that emit signals with algorithm events and make it possible to
 * show an algorithm step by step.
 */
struct ResponsiveEntity : public QObject {

Q_OBJECT

signals:

    /**
     * Signal that contains algorithm event.
     */
    void step(std::shared_ptr<AlgorithmEvent> event);

};

#endif // RESPONSIVE_ENTITY_H
