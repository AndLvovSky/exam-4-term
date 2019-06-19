#include "main_window.h"
#include "ui_main_window.h"
#include <memory>
#include <QDebug>
#include <thread>
#include "settings/settings.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->sortVisualizationLayout->addWidget(insertionSortWidget);
    insertionSortTimer = new QTimer();
    connect(insertionSortTimer, SIGNAL(timeout()), this, SLOT(insertionSortStep()));
}

MainWindow::~MainWindow() {
    delete ui;
    delete insertionSortWidget;
    delete insertionSortTimer;
}

void MainWindow::on_generateBooksButton_clicked() {
    books.clear();
    const int n = Settings::get().getBooksToGenerate();
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
    comp = BookComparatorFactory::makeComparator(sortBy());
    insertionSortRunner.run(
        [this](
        InsertionSorting<Book>& sorting, QVector<Book>& books) {
        sorting.sort(books, *comp);
    });
    const int pause = Settings::get().getPauseBetweenSteps();
    qInfo() << "start player";
    insertionSortTimer->start(pause);
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

void MainWindow::insertionSortStep() {
    if (insertionSortRunner.hasNext()) {
        insertionSortWidget->visualize(insertionSortRunner.stepForward());
    } else {
        insertionSortTimer->stop();
    }
}

void MainWindow::on_booksCountSpinBox_valueChanged(int booksCount) {
    Settings::get().setBooksToGenerate(booksCount);
}

void MainWindow::on_pauseSpinBox_valueChanged(int pause) {
    Settings::get().setPauseBetweenSteps(pause);
}
