#ifndef MERGEFILESELECTION_H
#define MERGEFILESELECTION_H

#include <QWizardPage>
#include <merger.h>

namespace Ui {
class MergeFileSelection;
}

class MergeFileSelection : public QWizardPage
{
    Q_OBJECT

public:
    //void initializePage();
    bool validatePage();
    int filesPutIn;
    explicit MergeFileSelection(Merger *_m,QWidget *parent = 0);

    ~MergeFileSelection();

private slots:
    void on_addFileManual_clicked();
    void on_cell_clicked(int row, int col);
    
    void on_showLocationCheck_toggled(bool checked);

    void on_saveFileButton_clicked();

    void on_addFilesTextFile_clicked();

private:
    Merger *m;
    Ui::MergeFileSelection *ui;
    void addFiles(QStringList files);
};

#endif // MERGEFILESELECTION_H
