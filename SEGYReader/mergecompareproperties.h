#ifndef MERGECOMPAREPROPERTIES_H
#define MERGECOMPAREPROPERTIES_H

#include <QWizardPage>
#include <QTableWidget>
#include <segyfileRevised.h>
#include <segyfilebigendian.h>
#include <segyfilelittleendian.h>
#include <vector>
#include <merger.h>

namespace Ui {
class MergeCompareProperties;
}

class MergeCompareProperties : public QWizardPage
{
    Q_OBJECT

public:
    explicit MergeCompareProperties(Merger *_m, QWidget *parent = 0);
    ~MergeCompareProperties();
    void initializePage();

    bool getValid() const;
    void setValid(bool value);

    bool validatePage();
    int nextId();

private slots:
    void on_binaryValuesTable_cellClicked(int row, int column);

    void on_binaryValuesTable_cellChanged(int row, int column);

private:
    bool valid;
    QColor notEditable;
    QColor notMatching;
    Merger *m;
    Ui::MergeCompareProperties *ui;
    vector<SegyFile> *segylist;
    //MergeWizard *mw;
    void copyContentsColumn(int from);
};

#endif // MERGECOMPAREPROPERTIES_H
