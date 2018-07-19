#include "mergetracesort.h"
#include "ui_mergetracesort.h"

MergeTraceSort::MergeTraceSort(Merger *_m, QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::MergeTraceSort)
{
    ui->setupUi(this);
    m = _m;
}

MergeTraceSort::~MergeTraceSort()
{
    delete ui;
}

void MergeTraceSort::initializePage(){

}

bool MergeTraceSort::validatePage(){
    if(ui->time->isChecked()){
        m->setTraceSortType(Merger::Time);
    }else if(ui->lineSequenceNumber->isChecked()){
        m->setTraceSortType(Merger::LineNumberSeq);
    }else{
        m->setTraceSortType(Merger::None);
    }
}
