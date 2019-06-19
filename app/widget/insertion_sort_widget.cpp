#include "insertion_sort_widget.h"
#include <memory>
#include <QDebug>
#include <algorithm>

void InsertionSortWidget::visualize(std::shared_ptr<AlgorithmEvent> ae) {
    qInfo() << "visualize event";
    this->ae = ae;
    repaint();
}

void InsertionSortWidget::paintEvent(QPaintEvent* paintEvent) {
    painter = new QPainter(this);
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
    delete painter;
}

void InsertionSortWidget::paint(StartPtr se) {
    qInfo() << "start event";
    //setText("start");
    se->restore(books);
    qInfo() << "restore";
    findHeightCoefficients(se->comp);
    qInfo() << "coef";
    paintBooks();
    qInfo() << "finish start event";
}

void InsertionSortWidget::paint(EndPtr se) {
    qInfo() << "end event";
    //setText("end");
    se->restore(books);
    paintBooks();
}

void InsertionSortWidget::paint(ComparePtr se) {
    qInfo() << "compare event";
    //setText("compare");
    paintBooks();
}

void InsertionSortWidget::paint(MovePtr se) {
    qInfo() << "move event";
    //setText("move");
    se->restore(books);
    paintBooks();
}

void InsertionSortWidget::paint(PutPtr se) {
    qInfo() << "put event";
    //setText("put");
    se->restore(books);
    paintBooks();
}

void InsertionSortWidget::paint(ExtractPtr se) {
    qInfo() << "extract event";
    //setText("extract");
    paintBooks();
}

void InsertionSortWidget::findHeightCoefficients(const Comparator<Book>& comp) {
    QVector<Book> b = books;
    qInfo() << b.size();
    qInfo() << "here";
    qInfo() << comp.compare(b[0], b[1]);
    std::sort(b.begin(), b.end(), [&comp](const Book& a, const Book& b) {
        return comp.compare(a, b) < 0;
    });
    qInfo() << "sort";
    QVector<int> pos(b.size());
    pos[0] = 1;
    int c = 1;
    for (int i = 1; i < books.size(); i++) {
        if (!(books[i - 1] == books[i])) c++;
        pos[i] = c;
    }
    qInfo() << "here a";
    for (int i = 0; i < b.size(); i++) {
        heightCoef[b[i].getId()] = (float) pos[i] / c;
    }
}

void InsertionSortWidget::paintBooks() {
    for (int i = 0; i < books.size(); i++) {
        int id = books[i].getId();
        paintColumn(i, id);
    }
}

void InsertionSortWidget::paintColumn(int pos, int id) {
    int wh = height(), ww = width();
    painter->setPen(TEXT_COLOR);
    painter->setBrush(COLUMN_COLOR);
    int h = heightCoef[id] * wh;
    int l = pos * columnWidth;
    int t = wh - h;
    painter->drawRect(l, t, columnWidth, h);
    painter->drawText(l + 5, wh - 5, QString::number(id));
}
