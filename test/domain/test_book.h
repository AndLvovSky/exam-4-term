#include <QObject>

class TestBook : public QObject {

    Q_OBJECT

public:

    TestBook();

private slots:

    void complexTest();

};
