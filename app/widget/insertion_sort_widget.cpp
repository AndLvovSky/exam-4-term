#include "insertion_sort_widget.h"
#include <memory>
#include <QDebug>

void InsertionSortWidget::visualize(std::shared_ptr<AlgorithmEvent> ae) {
    qInfo() << "visualize event";
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
    QLabel::paintEvent(paintEvent);
}

void InsertionSortWidget::paint(StartPtr se) {
    qInfo() << "start event";
    setText("start");
}

void InsertionSortWidget::paint(EndPtr se) {
    qInfo() << "end event";
    setText("end");
}

void InsertionSortWidget::paint(ComparePtr se) {
    qInfo() << "compare event";
    setText("compare");
}

void InsertionSortWidget::paint(MovePtr se) {
    qInfo() << "move event";
    setText("move");
}

void InsertionSortWidget::paint(PutPtr se) {
    qInfo() << "put event";
    setText("put");
}

void InsertionSortWidget::paint(ExtractPtr se) {
    qInfo() << "extract event";
    setText("extract");
}
