#ifndef MERGEPAGERESULT_H
#define MERGEPAGERESULT_H

#include <QWizardPage>
#include <merger.h>

namespace Ui {
class MergePageResult;
}

class MergePageResult : public QWizardPage
{
    Q_OBJECT

public:
    bool validatePage();
    bool isComplete();
    void initializePage();
    explicit MergePageResult(Merger *_m,QWidget *parent = 0);
    ~MergePageResult();

private slots:
    void on_start_clicked();

private:
    bool done;
    Merger *m;
    Ui::MergePageResult *ui;
};

#endif // MERGEPAGERESULT_H
