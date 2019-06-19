#include "main_window.h"
#include "ui_main_window.h"
#include <memory>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->sortVisualizationLayout->addWidget(insertionSortWidget);
}

MainWindow::~MainWindow() {
    delete ui;
    delete insertionSortWidget;
}

void MainWindow::on_generateBooksButton_clicked() {
    books.clear();
    const int n = 5;
    for (int i = 0; i < n; i++) {
        books.push_back(bookGenerator.generateBook());
    }
    updateBooksView();
}

void MainWindow::updateBooksView() {
    auto v = ui->booksLabel;
    v->clear();
    QString text = "";
    for (auto book : books) {
        text += book.toString() + "\n";
    }
    v->setText(text);
}

void MainWindow::on_sortButton_clicked() {
    auto comp = BookComparatorFactory::makeComparator(sortBy());
    insertionSortRunner.run(
        [comp](
        InsertionSorting<Book>& sorting, QVector<Book>& books) {
        sorting.sort(books, *comp);
    });
    const int pause = 500;
    qInfo() << "start player";
    insertionSortPlayer.play(pause);
}

BookComparatorFactory::Field MainWindow::sortBy() {
    auto sbl = ui->sortByLayout;
    for (int i = 0; i < sbl->count(); i++) {
        auto rb = dynamic_cast<QRadioButton*>(
            sbl->itemAt(i)->widget());
        if (rb->isChecked()) {
            return stringToField[rb->text()];
        }
    }
}

QString MainWindow::booksToString() {
    QString res = "QVector(";
    for (auto book : books) {
        res += book.toString() + ", ";
    }
    res += ")";
    return res;
}
