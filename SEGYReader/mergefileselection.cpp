#include "mergefileselection.h"
#include "ui_mergefileselection.h"
#include <QMessageBox>
#include <QFileDialog>
#include <iostream>
#include <isledialog.h>
#include <fstream>
#define FILE 0
#define LOC 1
#define BIGE 2
#define VIEW 3
#define REM 4
using namespace std;
MergeFileSelection::MergeFileSelection(Merger *_m, QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::MergeFileSelection)
{
    ui->setupUi(this);
    m = _m;
    registerField("filesTable", ui->filesTable);
    registerField("saveFileEdit", ui->saveFileEdit);
    if(ui->showLocationCheck->isChecked()){
        ui->filesTable->setColumnHidden(LOC, false);
    }else{
        ui->filesTable->setColumnHidden(LOC, true);
    }
    filesPutIn = 0;
    connect(ui->filesTable,SIGNAL(cellClicked(int,int)), this, SLOT(on_cell_clicked(int, int)));
}

MergeFileSelection::~MergeFileSelection()
{
    delete ui;
}

void MergeFileSelection::on_addFileManual_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this,"Open Files", "", "Seg-Y Files (*.segy *.sgy *.SEGY *.SGY)");
    addFiles(files);
}

void MergeFileSelection::addFiles(QStringList files){
    QTableWidgetItem *twi;
    int in;
    for(int i = 0; i < files.size() ; i++){
        QString str = files.at(i);
        in = str.lastIndexOf('/');
        //cout<<in<<endl;
        //cout<<str.toStdString()<<endl;
        QString name = str.right(str.size() - in - 1);
        //cout<<name.toStdString()<<endl;
        ui->filesTable->insertRow(filesPutIn);
        twi = new QTableWidgetItem(name);
        twi->setFlags(twi->flags() & (~(Qt::ItemIsEditable & Qt::ItemIsSelectable)));
        ui->filesTable->setItem(filesPutIn,FILE,twi);

        twi = new QTableWidgetItem(str);
        twi->setFlags(twi->flags() & (~(Qt::ItemIsEditable & Qt::ItemIsSelectable)));
        ui->filesTable->setItem(filesPutIn, LOC, twi);

        twi = new QTableWidgetItem();
        twi->setCheckState(Qt::Checked);
        ui->filesTable->setItem(filesPutIn, BIGE, twi);

        twi = new QTableWidgetItem("View Header");
        twi->setFlags(twi->flags() & (~(Qt::ItemIsEditable)));
        ui->filesTable->setItem(filesPutIn, VIEW, twi);

        twi = new QTableWidgetItem("Remove");
        twi->setFlags(twi->flags() & (~(Qt::ItemIsEditable)));
        ui->filesTable->setItem(filesPutIn, REM, twi);

        filesPutIn++;

        m->addFile(str,true);
    }
}

void MergeFileSelection::on_cell_clicked(int row, int col){
    if(col == VIEW){//view file
        IsLEDialog dialog (ui->filesTable->item(row, LOC)->text().toStdString(),this);
        dialog.exec();
        if(dialog.BE) ui->filesTable->item(row, BIGE)->setCheckState(Qt::Checked);
        else ui->filesTable->item(row, BIGE)->setCheckState(Qt::Unchecked);
    }else if( col == REM){//remove file
        ui->filesTable->removeRow(row);
        m->removeFile(row);
        filesPutIn--;
    }
    else if(col == BIGE){
        m->setFileBE(row,ui->filesTable->item(row,col)->checkState()==Qt::Checked?true:false);
    }
}

bool MergeFileSelection::validatePage(){
    if(ui->filesTable->rowCount() < 2){
        QMessageBox::information(this, "Error", "There should be more than 1 files selected.");
        return false;
    }
    if(ui->saveFileEdit->text().isEmpty() || ui->saveFileEdit->text().size()<1 ){
        QMessageBox::information(this,"Error", "Enter save File name.");
        ui->saveFileEdit->setFocus();
        return false;
    }
    return true;
}

void MergeFileSelection::on_showLocationCheck_toggled(bool checked)
{
    if(checked){
        ui->filesTable->setColumnHidden(1, false);
    }else{
        ui->filesTable->setColumnHidden(1, true);
    }
}

void MergeFileSelection::on_saveFileButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save as", "./", "Seg-Y Files (*.segy *.sgy *.SEGY *.SGY)");
    ui->saveFileEdit->setText(filename);
    m->setSaveFileName(filename);
}

void MergeFileSelection::on_addFilesTextFile_clicked()
{
    QString tf = QFileDialog::getOpenFileName(this,"Text File", "./", "Text File (*.txt *.TXT)");
    QStringList files;
    char buffer[2049];
    fstream f;
    f.open(tf.toStdString().data(), ios_base::in);
    if(f.is_open()){
        while(!f.eof()){
            f.getline(buffer,2049);
            files.append(QString::fromLatin1(buffer));
        }
    }
    files.removeDuplicates();
    files.removeAll(QString::fromStdString(""));
    addFiles(files);
}
