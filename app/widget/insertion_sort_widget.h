#ifndef INSERTION_SORT_WIDGET
#define INSERTION_SORT_WIDGET

#include <QLabel>
#include "event/algorithm_event.h"
#include <memory>
#include "visualization/visualizator.h"
#include "domain/book.h"
#include "event/start.h"
#include "event/end.h"
#include "event/compare.h"
#include "event/move.h"
#include "event/put.h"
#include "event/extract.h"

class InsertionSortWidget : public QLabel, public Visualizator<Book> {

private:

    typedef Start<QVector<Book>> Start;

    typedef std::shared_ptr<Start> StartPtr;

    typedef End<QVector<Book>> End;

    typedef std::shared_ptr<End> EndPtr;

    typedef Compare<int, Book> Compare;

    typedef std::shared_ptr<Compare> ComparePtr;

    typedef Move<int, Book, QVector<Book>> Move;

    typedef std::shared_ptr<Move> MovePtr;

    typedef Put<int, Book, QVector<Book>> Put;

    typedef std::shared_ptr<Put> PutPtr;

    typedef Extract<Book, int> Extract;

    typedef std::shared_ptr<Extract> ExtractPtr;

    std::shared_ptr<AlgorithmEvent> ae;

protected:

    void paintEvent(QPaintEvent* paintEvent) override;

public:

    void visualize(std::shared_ptr<AlgorithmEvent> ae) override;

private:

    void paint(StartPtr se);

    void paint(EndPtr se);

    void paint(ComparePtr se);

    void paint(MovePtr se);

    void paint(PutPtr se);

    void paint(ExtractPtr se);

};

#endif // INSERTION_SORT_WIDGET
