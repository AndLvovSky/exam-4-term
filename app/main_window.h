#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "widget/insertion_sort_widget.h"
#include "sort/insertion_sorting.h"
#include "runner/outer_algorithm_runner.h"
#include "runner/connector/insertion_sorting_connector.h"
#include "player/algorithm_player.h"
#include "generator/book_generator.h"
#include "comparator/book_comparator_factory.h"
#include <QMap>

namespace Ui {

    class MainWindow;

}

class MainWindow : public QMainWindow {

    Q_OBJECT

    typedef BookComparatorFactory::Field Field;

    Ui::MainWindow *ui;

    QVector<Book> books;

    BookGenerator bookGenerator;

    const QMap<QString, Field> stringToField =
        {{"publisher", Field::PUBLISHER},
         {"genre", Field::GENRE},
         {"publication year", Field::PUBLICATION_YEAR},
         {"author", Field::AUTHOR},
         {"name", Field::NAME}};

    InsertionSortWidget* insertionSortWidget =
        new InsertionSortWidget();

    InsertionSorting<Book> insertionSorting;

    OuterAlgorithmRunner<InsertionSorting<Book>, QVector<Book>,
        InsertionSortingConnector> insertionSortRunner{insertionSorting, books};

    AlgorithmPlayer<QVector<Book>> insertionSortPlayer{
        insertionSortRunner, *insertionSortWidget};

public:

    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void updateBooksView();

private slots:

    void on_generateBooksButton_clicked();

    void on_sortButton_clicked();

private:

    Field sortBy();

    QString booksToString();

};

#endif // MAIN_WINDOW_H
