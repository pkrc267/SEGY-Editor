#ifndef MERGEWIZARD_H
#include <QWizard>
//#include <mergecompareproperties.h>
#include <mergefileselection.h>
#include <mergeintropage.h>
#include <mergepageresult.h>
#include <mergetextualheader.h>
#include <mergetracesort.h>
#include <merger.h>
#define MERGEWIZARD_H

namespace Ui {
class MergeWizard;
}

class MergeWizard : public QWizard
{
    Q_OBJECT

public:
    bool success;
    enum {PageIntro, PageFileSelection, PageCompareProperties, PageTextualHeader, PageTraceSort, PageResult };
    explicit MergeWizard(QWidget *parent = 0);
    ~MergeWizard();
private:
    Merger m;
    Ui::MergeWizard *ui;
};

#endif // MERGEWIZARD_H
