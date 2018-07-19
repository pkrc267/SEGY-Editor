#ifndef SEGYFILEFORM_H
#include <QWidget>
#include <segyfileRevised.h>
#include <QModelIndex>
#include <traceRevised.h>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTableWidgetItem>
#include <string>
#include <QStack>
#define SEGYFILEFORM_H


using namespace std;

namespace Ui {
class SegyFileForm;
}

class SegyFileForm : public QWidget
{
    Q_OBJECT

public:
    explicit SegyFileForm(string filename, bool BE, QWidget *parent = 0);
    ~SegyFileForm();
    bool isSaved();
    void save(string name);
    void save();

private:
    SegyFile *s;
    bool saved;
    bool isTraceEdited;
    Ui::SegyFileForm *ui;
    void openTrace(int i);
    Trace *t;
    QStack<int>stack;//storing index of item
    QStack<string>stack1;//storing data
    QStack<string>stack2;//storing table info
    QStack<int>stack3;//storing column info
    int p;
    int rowidx;
    int colidx;

private slots:
    void traceChanged(QModelIndex i);
    void someItemChanged(QTableWidgetItem *twi);
    void textHeaderChanged(int row, int column);
    void binaryHeaderChanged(int row, int column);
    void traceHeaderChanged(int row, int column);
    void on_textHeaderTable_cellDoubleClicked(int row, int column);
    void on_pushButton_clicked();
    void on_textHeaderTable_cellClicked(int row, int column);
    void on_binaryHeaderTable_cellClicked(int row, int column);
    void on_binaryHeaderTable_cellDoubleClicked(int row, int column);
    void on_traceBinaryHeaderTable_cellClicked(int row, int column);
    void convert();
};

#endif // SEGYFILEFORM_H
