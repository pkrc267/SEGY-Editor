#ifndef MERGETEXTUALHEADER_H
#define MERGETEXTUALHEADER_H

#include <QWizardPage>
#include <merger.h>
#include <QModelIndex>

namespace Ui {
class MergeTextualHeader;
}

class MergeTextualHeader : public QWizardPage
{
    Q_OBJECT

public:
    void initializePage();
    explicit MergeTextualHeader(Merger *_m,QWidget *parent = 0);
    ~MergeTextualHeader();

private slots:
    void on_fileListWidget_clicked(const QModelIndex &index);

    void on_tableWidget_cellChanged(int row, int column);

private:
    Merger *m;
    Ui::MergeTextualHeader *ui;
};

#endif // MERGETEXTUALHEADER_H
