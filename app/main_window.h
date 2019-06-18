#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "widget/insertion_sort_widget.h"

namespace Ui {

    class MainWindow;

}

class MainWindow : public QMainWindow {

    Q_OBJECT

    Ui::MainWindow *ui;

    InsertionSortWidget* insertionSortWidget;

public:

    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

};

#endif // MAIN_WINDOW_H
