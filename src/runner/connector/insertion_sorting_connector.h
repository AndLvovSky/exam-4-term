#ifndef INSERTION_SORTING_CONNECTOR_H
#define INSERTION_SORTING_CONNECTOR_H

#include <QObject>
#include "sort/insertion_sorting.h"
#include "runner/event_transfer.h"

/**
 * @brief The InsertionSortingConnector connects
 * InsertionSorting<T> and EventTransfer.
 */
struct InsertionSortingConnector : public QObject {

    Q_OBJECT

public:

    template <typename T>
    static void connect(
        const InsertionSorting<T>& v, const EventTransfer& transfer);

};

#include "insertion_sorting_connector.tpp"

#endif // INSERTION_SORTING_CONNECTOR_H
