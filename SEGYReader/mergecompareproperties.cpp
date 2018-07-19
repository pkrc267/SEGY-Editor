#include "mergecompareproperties.h"
#include "ui_mergecompareproperties.h"
#include <iostream>
#include <mergewizard.h>
#include <segyfileRevised.h>
#include <sstream>
#include <QAbstractButton>
using namespace std;

MergeCompareProperties::MergeCompareProperties(Merger *_m, QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::MergeCompareProperties)
{
    ui->setupUi(this);
    m = _m;
    registerField("binaryValuesTable", ui->binaryValuesTable);
    notEditable.setNamedColor(QString::fromStdString("azure"));
    notMatching.setNamedColor(QString::fromStdString("red"));

}

MergeCompareProperties::~MergeCompareProperties()
{
    delete ui;
}

void MergeCompareProperties::on_binaryValuesTable_cellClicked(int row, int column)
{
    if(column > 1){
        ui->binaryValuesTable->item(row,1)->setText(
                    ui->binaryValuesTable->item(row,column)->text());
        m->setBinaryHeader(ui->binaryValuesTable->item(row,1)->text().toInt(),row);
    }
}

bool MergeCompareProperties::getValid() const
{
    return valid;
}

void MergeCompareProperties::setValid(bool value)
{
    valid = value;
}


void MergeCompareProperties::initializePage(){
    valid = true;
    ui->errorLabel->setVisible(false);

    wizard()->button(QWizard::BackButton)->setDisabled(true);
    wizard()->button(QWizard::BackButton)->hide();

    QTableWidgetItem *twi;

    //stringstream ss;
    SegyFile *sf;


    m->initializeFiles();
    ui->binaryValuesTable->setColumnCount(m->getNumOfFiles()+2);
    for(int i = 0 ; i <30 ; i ++){//setting the 0th column to binary header names.
        //twi = ui->binaryValuesTable->verticalHeaderItem(i);
        twi = new QTableWidgetItem();
        twi->setText(QString::fromStdString(SegyFile::headerArrayInfo[i].name));
        twi->setFlags(twi->flags() &(~(Qt::ItemIsSelectable | Qt::ItemIsEditable)));
        if(!SegyFile::headerArrayInfo[i].editable){
            twi->setBackgroundColor(notEditable);
        }
        ui->binaryValuesTable->setItem(i,0,twi);

        //setting empty twi in 1st column
        twi = new QTableWidgetItem();
        if(!SegyFile::headerArrayInfo[i].editable){
            twi->setFlags(twi->flags() &(~(Qt::ItemIsSelectable | Qt::ItemIsEditable)));
            twi->setBackgroundColor(notEditable);
        }
        ui->binaryValuesTable->setItem(i, 1, twi);
    }
    //naming the column headers with segyFile names
    for( int i = 0; i < m->getNumOfFiles(); i++){
        twi = new QTableWidgetItem();
        twi->setText((m->getFileNameAt(i)));
        ui->binaryValuesTable->setHorizontalHeaderItem(i+2, twi);
        //populating values from each segyfile to its corresponding header.
        sf = m->getFile(i)->sf;
        for( int j = 0 ; j < 30 ; j++){
            stringstream ssbh;
            ssbh<<sf->getBinaryHeader(j);
            twi = new QTableWidgetItem();
            twi->setText(QString::fromStdString(ssbh.str()));
            if(!SegyFile::headerArrayInfo[j].editable){
                twi->setFlags(twi->flags() &(~(Qt::ItemIsSelectable | Qt::ItemIsEditable)));
                twi->setBackgroundColor(notEditable);
            }else{
                twi->setFlags(twi->flags() &(~(Qt::ItemIsEditable)));
            }
            ui->binaryValuesTable->setItem(j, i + 2, twi);
        }
    }
    //copying editable contents from the first file onto the 1st column
    for( int i = 0 ; i < 30 ; i++){
        if(SegyFile::headerArrayInfo[i].editable){
            ui->binaryValuesTable->item(i,1)->setText(
                        ui->binaryValuesTable->item(i,2)->text());
        }
    }
    //checking of important properties match or not.
    //eg. sample interval
    valid = true;
    for( int i = 0; i < 30; i++){
        if(SegyFile::headerArrayInfo[i].mustMatch){
            QString text =  ui->binaryValuesTable->item(i, 2)->text();
            for( int j = 3; j <  ui->binaryValuesTable->columnCount(); j++){
                if(text != ui->binaryValuesTable->item(i, j)->text()){
                    valid = false;
                    for( int k = 0; k < ui->binaryValuesTable->columnCount(); k++){
                        if(ui->binaryValuesTable->item(i, k)!=0)
                            ui->binaryValuesTable->item(i,k)->setBackgroundColor(notMatching);
                    }
                }
            }
        }
    }
    if(!valid){
        ui->errorLabel->setVisible(true);
        m->setSuccess(false);
        //wizard()->button(QWizard::NextButton)->setDisabled(true);
    }
}

void MergeCompareProperties::on_binaryValuesTable_cellChanged(int row, int column)
{
    if(column==1){
        m->setBinaryHeader(ui->binaryValuesTable->item(row, 1)->text().toInt(),row);
    }
}

bool MergeCompareProperties::validatePage(){
    return valid;
}

int MergeCompareProperties::nextId(){
    if( valid){
        return MergeWizard::PageTextualHeader;
    }else
        return MergeWizard::PageResult;
}
