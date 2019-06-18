#ifndef INSERTION_SORT_INT_VISUALIZATOR_H
#define INSERTION_SORT_INT_VISUALIZATOR_H

#include "visualizator.h"
#include "sort/insertion_sorting.h"

class InsertionSortIntVisualizator : public Visualizator<QVector<int>> {

    void visualize(std::shared_ptr<AlgorithmEvent> event) override;

};

#include "insertion_sort_int_visualizator.tpp"

#endif // INSERTION_SORT_INT_VISUALIZATOR_H
