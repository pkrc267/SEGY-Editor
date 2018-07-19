#include "mergetextualheader.h"
#include "ui_mergetextualheader.h"

MergeTextualHeader::MergeTextualHeader(Merger *_m, QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::MergeTextualHeader)
{
    ui->setupUi(this);
    m = _m;

}

void MergeTextualHeader::initializePage(){
    m->setRequiredHeader();
    FileData *filedata;
    QListWidgetItem *lwi;
    for(int i = 0; i < m->getNumOfFiles(); i++){
        filedata = m->getFile(i);
        lwi = new QListWidgetItem();
        lwi->setText(filedata->name);
        lwi->setFlags(lwi->flags() & (~(Qt::ItemIsEditable)));
        ui->fileListWidget->addItem(lwi);
    }
    QTableWidgetItem *twi;
    for( int j = 0; j < 40; j++){
        twi = new QTableWidgetItem();
        twi->setText(QString::fromStdString(*m->getFile(0)->sf->getTextHeaderLine(j)));
        ui->tableWidget->setItem(j,0,twi);
        m->setTextualHeaderLine(j, twi->text());
    }
    ui->tableWidget->resizeColumnsToContents();
}

MergeTextualHeader::~MergeTextualHeader()
{
    delete ui;
}

void MergeTextualHeader::on_fileListWidget_clicked(const QModelIndex &index)
{
    int i = index.row();
    QTableWidgetItem *twi;
    for( int j = 0; j < 40; j++){
        twi = new QTableWidgetItem();
        twi->setText(QString::fromStdString(*m->getFile(i)->sf->getTextHeaderLine(j)));
        ui->tableWidget->setItem(j,0,twi);
        m->setTextualHeaderLine(j, twi->text());
    }
}

void MergeTextualHeader::on_tableWidget_cellChanged(int row, int column)
{
    m->setTextualHeaderLine(row,ui->tableWidget->item(row, column)->text());
}
