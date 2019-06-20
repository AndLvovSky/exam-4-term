#ifndef INSERTION_SORT_WIDGET
#define INSERTION_SORT_WIDGET

#include <QLabel>
#include "event/algorithm_event.h"
#include <memory>
#include "visualization/visualizator.h"
#include "domain/book.h"
#include "event/start_sort.h"
#include "event/end.h"
#include "event/compare.h"
#include "event/move.h"
#include "event/put.h"
#include "event/extract.h"
#include <QMap>
#include <QPainter>

/**
 * @brief The InsertionSortWidget used for insertion sort visualization.
 */
class InsertionSortWidget :
    public QLabel, public Visualizator<QVector<Book>> {

private:

    typedef StartSort<QVector<Book>, Book> Start;

    typedef std::shared_ptr<Start> StartPtr;

    typedef End<QVector<Book>> End;

    typedef std::shared_ptr<End> EndPtr;

    typedef Compare<Book, int> Compare;

    typedef std::shared_ptr<Compare> ComparePtr;

    typedef Move<Book, int, QVector<Book>> Move;

    typedef std::shared_ptr<Move> MovePtr;

    typedef Put<Book, int, QVector<Book>> Put;

    typedef std::shared_ptr<Put> PutPtr;

    typedef Extract<Book, int> Extract;

    typedef std::shared_ptr<Extract> ExtractPtr;

    const QColor COLUMN_COLOR = QColor(0, 0, 255);

    const QColor TEXT_COLOR = QColor(0, 0, 0);

    QPainter* painter;

    std::shared_ptr<AlgorithmEvent> ae;

    QVector<Book> books;

    QMap<int, float> heightCoef;

    int columnWidth = 50;

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

    void findHeightCoefficients(const Comparator<Book>& comp);

    void paintBooks();

    void paintColumn(int pos, int id);

};

#endif // INSERTION_SORT_WIDGET
