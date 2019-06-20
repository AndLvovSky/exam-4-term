#ifndef CUSTOM_STRUCTURE_H
#define CUSTOM_STRUCTURE_H

#include "event/responsive_entity.h"
#include "custom_event.h"
#include <QDebug>

class CustomStructure : public ResponsiveEntity {
public:
    void doSomething() {
        qInfo() << "do something";
        qInfo() << "emit 1";
        emit step(std::make_shared<CustomEvent>(1));
        qInfo() << "emit 2";
        emit step(std::make_shared<CustomEvent>(2));
        qInfo() << "emit 3";
        emit step(std::make_shared<CustomEvent>(3));
    }
    CustomStructure& operator = (const CustomStructure& other) {
        return *this;
    }
};

#endif // CUSTOM_STRUCTURE_H
