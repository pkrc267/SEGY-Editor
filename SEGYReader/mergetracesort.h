#ifndef MERGETRACESORT_H
#define MERGETRACESORT_H

#include <QWizardPage>
#include <merger.h>

namespace Ui {
class MergeTraceSort;
}

class MergeTraceSort : public QWizardPage
{
    Q_OBJECT

public:
    bool validatePage();
    void initializePage();
    explicit MergeTraceSort(Merger *_m,QWidget *parent = 0);
    ~MergeTraceSort();

private:
    Merger *m;
    Ui::MergeTraceSort *ui;
};

#endif // MERGETRACESORT_H
