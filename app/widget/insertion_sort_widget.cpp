#include "insertion_sort_widget.h"
#include <memory>

void InsertionSortWidget::visualize(std::shared_ptr<AlgorithmEvent> ae) {
    this->ae = ae;
    repaint();
}

void InsertionSortWidget::paintEvent(QPaintEvent* paintEvent) {
    if (auto se = std::dynamic_pointer_cast<Start>(ae)) {
        paint(se);
    } else if (auto se = std::dynamic_pointer_cast<End>(ae)) {
        paint(se);
    } else if (auto se = std::dynamic_pointer_cast<Compare>(ae)) {
        paint(se);
    } else if (auto se = std::dynamic_pointer_cast<Move>(ae)) {
        paint(se);
    } else if (auto se = std::dynamic_pointer_cast<Put>(ae)) {
        paint(se);
    } else if (auto se = std::dynamic_pointer_cast<Extract>(ae)) {
        paint(se);
    }
}

void InsertionSortWidget::paint(StartPtr se) {
    setText("start");
}

void InsertionSortWidget::paint(EndPtr se) {
    setText("end");
}

void InsertionSortWidget::paint(ComparePtr se) {
    setText("compare");
}

void InsertionSortWidget::paint(MovePtr se) {
    setText("move");
}

void InsertionSortWidget::paint(PutPtr se) {
    setText("put");
}

void InsertionSortWidget::paint(ExtractPtr se) {
    setText("extract");
}
