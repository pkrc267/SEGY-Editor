#include "segyfileform.h"
#include "ui_segyfileform.h"
#include <QTableWidgetItem>
#include <iostream>
#include <QScrollBar>
#include <sstream>
#include <cstring>
#include <QMessageBox>
#include <segyfilelittleendian.h>
#include <segyfilebigendian.h>
#include <algorithm>
#include <QStack>
#include <QFileDialog>
#include <QIcon>

SegyFileForm::SegyFileForm(string filename, bool BE, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SegyFileForm)
{
    ui->setupUi(this);
    if( BE){     s = new SegyFileBigEndian(filename);ui->convertButton->setVisible(false); }
    else{ s = new SegyFileLittleEndian(filename); ui->convertButton->setVisible(true); }
    connect(ui->convertButton,SIGNAL(clicked()), this, SLOT(convert()));

    p=0;

    isTraceEdited = false;
    ui->openFileLabel->setText(ui->openFileLabel->text().append(filename.data()));
    saved = true;

    QTableWidgetItem *twi;
    QString st;

    //viewing text header
    for(int i = 0; i<40; i++){
        twi = new QTableWidgetItem();
        st = QString::fromStdString(*s->getTextHeaderLine(i));
        //cout<<st.toStdString()<<endl;
        twi->setText(st);
        ui->textHeaderTable->setItem(i,0,twi);
    }
    ui->textHeaderTable->resizeColumnsToContents();
    connect(ui->textHeaderTable,SIGNAL(cellChanged(int,int)), this, SLOT(textHeaderChanged(int,int)));

    //viewing binary header
    ui->binaryHeaderTable->setRowCount(30);
    bool old = ui->binaryHeaderTable->blockSignals(true);
    for(int i = 0; i < 30; i++){
        //ui->binaryHeaderTable->insertRow(i);
        stringstream ss;
        SegyFile::HeaderInfo *hi;
        hi = s->getBinaryHeaderInfo(i);
        ss<<hi->startOffset<<'-'<<(hi->startOffset+hi->numOfBytes-1);
        twi = new QTableWidgetItem();
        st = QString::fromStdString(ss.str());
        //cout<<st.toStdString()<< " ";
        twi->setText(st);
        twi->setFlags(Qt::NoItemFlags);
        ui->binaryHeaderTable->setItem(i,0,twi);

        st = QString::fromStdString(hi->name);
        //cout<<st.toStdString()<< " ";
        twi = new QTableWidgetItem();
        twi->setText(st);
        twi->setFlags(Qt::NoItemFlags);
        ui->binaryHeaderTable->setItem(i,1, twi);


        stringstream ss1;
        ss1<<s->getBinaryHeader(i);
        st = QString::fromStdString(ss1.str());
        //cout<<st.toStdString()<<endl;
        twi = new QTableWidgetItem();
        twi->setText(st);
        ui->binaryHeaderTable->setItem(i,2, twi);
    }
    connect(ui->binaryHeaderTable,SIGNAL(cellChanged(int,int)), this, SLOT(binaryHeaderChanged(int,int)));

    //viewing the number of traces
    QListWidgetItem *lwi;
    for(int i = 0; i < s->getNumOfTraces(); i++){
        lwi = new QListWidgetItem();
        stringstream ss;
        ss<<(i+1);
        lwi->setText(QString::fromStdString(ss.str()));
        twi->setFlags(Qt::NoItemFlags);
        ui->traceList->addItem(lwi);
    }
    connect(ui->traceList,SIGNAL(clicked(QModelIndex)), this, SLOT(traceChanged(QModelIndex)));
    //viewing trace headers
    for(int i = 0; i < 89;i ++) ui->traceBinaryHeaderTable->insertRow(i);
    connect(ui->traceBinaryHeaderTable,SIGNAL(cellChanged(int,int)), this, SLOT(traceHeaderChanged(int,int)));

    openTrace(0);
    ui->binaryHeaderTable->blockSignals(old);
}

SegyFileForm::~SegyFileForm()
{
    //delete s;
    delete t;
    delete ui;
}

bool SegyFileForm::isSaved(){
    return saved;
}

void SegyFileForm::openTrace(int i){
    bool oldState = ui->traceBinaryHeaderTable->blockSignals(true);
    stringstream tl;
    tl<<"Trace Number : "<<(i+1);
    ui->traceLabel->setText(QString::fromStdString(tl.str()));
    t = s->getTraceAt(i);
    Trace::HeaderInfo *hi;
    QTableWidgetItem *twi;
    QString st;
    int sampleInterval=s->getSampleIntervalOfDataTraces();
    for(int j = 0; j < 89; j++){
        stringstream ss;
        hi = t->getBinaryHeaderInfo(j);
        ss<<hi->startOffset<<'-'<<(hi->startOffset+hi->numOfBytes-1);
        twi = new QTableWidgetItem();
        st = QString::fromStdString(ss.str());
        //cout<<st.toStdString()<< " ";
        twi->setText(st);
        twi->setFlags(Qt::NoItemFlags);
        ui->traceBinaryHeaderTable->setItem(j,0,twi);

        st = QString::fromStdString(hi->name);
        //cout<<st.toStdString()<< " ";
        twi = new QTableWidgetItem();
        twi->setText(st);
        twi->setFlags(Qt::NoItemFlags);
        ui->traceBinaryHeaderTable->setItem(j,1, twi);


        stringstream ss1;
        ss1<<t->getBinaryHeader(j);
        st = QString::fromStdString(ss1.str());
        //cout<<st.toStdString()<<endl;
        twi = new QTableWidgetItem();
        twi->setText(st);
        ui->traceBinaryHeaderTable->setItem(j,2, twi);
    }


    ui->traceDataTable->clear();
    t->resetIndex();
    for(int j = 0; j < t->getNumOfSamples() ; j++){
        ui->traceDataTable->insertRow(j);
        twi = new QTableWidgetItem();
        stringstream ss;
        ss<<(j*sampleInterval);
        twi->setText(QString::fromStdString(ss.str()));
        twi->setFlags(Qt::NoItemFlags);
        ui->traceDataTable->setItem(j,0,twi);

        twi = new QTableWidgetItem();
        stringstream ss1;
        ss1<<t->getNextSample();
        twi->setText(QString::fromStdString(ss1.str()));
        twi->setFlags(Qt::NoItemFlags);
        ui->traceDataTable->setItem(j,1,twi);
    }
    ui->traceBinaryHeaderTable->blockSignals(oldState);
}

void SegyFileForm::traceChanged(QModelIndex i){
    if(isTraceEdited){
        QMessageBox::StandardButton reply = QMessageBox::question(this,tr("Discard Changes in the Current Trace?"),tr("Are you sure you want to close this trace, without saving?"),QMessageBox::Discard | QMessageBox::Save | QMessageBox::Cancel);
        if(reply ==  QMessageBox::Save){
            Trace::HeaderInfo *hi;
            for(int i = 0; i < 89; i ++){
                hi = Trace::getBinaryHeaderInfo(i);
                t->setBinaryHeader(ui->traceBinaryHeaderTable->item(i,2)->text().toInt(),hi->startOffset, hi->numOfBytes);
            }
        }else if(reply == QMessageBox::Cancel){
            return;
        }
    }
    bool oldState = ui->traceDataTable->blockSignals(true);
    for(int j = ui->traceDataTable->rowCount() - 1; j >=0; j--){
        ui->traceDataTable->removeRow(j);
    }
    ui->traceDataTable->blockSignals(oldState);
    delete t;
    openTrace(i.row());
    isTraceEdited = false;
}

void SegyFileForm::save(string name){
    s->save(name);
    if(isTraceEdited){
        Trace::HeaderInfo *hi;
        for(int i = 0; i < 89; i ++){
            hi = Trace::getBinaryHeaderInfo(i);
            t->setBinaryHeader(ui->traceBinaryHeaderTable->item(i,2)->text().toInt(),hi->startOffset, hi->numOfBytes);
        }
        isTraceEdited=false;
    }
    if(!saved){
        //set all textHeaderLines
        for(int i = 0; i < 40; i ++){
            s->setTextHeaderLine(ui->textHeaderTable->item(i,0)->text().toStdString(),i);
        }
        //set all binaryHeaderLines
        for(int i = 0; i < 30; i++){
            s->setBinaryHeader(ui->binaryHeaderTable->item(i,2)->text().toInt(),i);
        }
        saved = true;
    }
    p=0;
}
void SegyFileForm::save(){
    save(s->getOriginalFileName());
}


void SegyFileForm::someItemChanged(QTableWidgetItem* twi){
    saved = false;
    //cout<<saved<<"\t"<<twi->text().toStdString()<<"\t"<<twi->tableWidget()->objectName().toStdString()<<endl;
}

void SegyFileForm::textHeaderChanged(int row, int column){
    //s->setTextHeaderLine(ui->textHeaderTable->item(row, column)->text().toStdString(), row);
    someItemChanged(ui->textHeaderTable->item(row,column));
}

void SegyFileForm::binaryHeaderChanged(int row, int column){
    //s->setBinaryHeader(ui->binaryHeaderTable->item(row, column)->text().toInt(),row);
    //cout<<"row:"<<row<<" col:"<<column<<"\t";
    someItemChanged(ui->binaryHeaderTable->item(row, column));
}

void SegyFileForm::traceHeaderChanged(int row, int column){
    isTraceEdited=true;
    //t->setBinaryHeader(ui->traceBinaryHeaderTable->item(row,column)->text().toInt(),row);
    someItemChanged(ui->traceBinaryHeaderTable->item(row,column));
}

/*void SegyFileForm::on_textHeaderTable_cellDoubleClicked(int row, int column)
{
    stack2.push("t1");

    p++;
    QString s;
    rowidx=ui->textHeaderTable->selectionModel()->currentIndex().row();
    stack.push(row);

QString qs=ui->textHeaderTable->model()->index(rowidx,0).data().toString();
std::string utf=qs.toUtf8().constData();
    stack1.push(utf);
}*/

void SegyFileForm::on_textHeaderTable_cellClicked(int row, int column)
{
    stack2.push("t1");

    p++;
    QString s;
    rowidx=ui->textHeaderTable->selectionModel()->currentIndex().row();
    stack.push(row);

QString qs=ui->textHeaderTable->model()->index(rowidx,0).data().toString();
std::string utf=qs.toUtf8().constData();
    stack1.push(utf);
}

void SegyFileForm::on_pushButton_clicked()
{
    QTableWidgetItem *itab1;
    if(p>0)
    {
    QString s=QString::fromStdString(stack1.pop()) ;//poping the text
    int j=stack.pop();//poping the index
    QString s1=QString::fromStdString(stack2.pop());//poping the info

        itab1=new QTableWidgetItem();
        itab1->setText(s);
        if(s1=="t1")
    {
            ui->textHeaderTable->setItem(j,0,itab1);
        }//setting undo text to 1st table
        else if(s1=="t2")
        {
            int k=stack3.pop();
           ui->binaryHeaderTable->setItem(j,k,itab1);
        }
        else if(s1=="t3")
        {
            int k=stack3.pop();
           ui->traceBinaryHeaderTable->setItem(j,2,itab1);
        }
        //setting the undo text for second table
        p--;
    }
}



void SegyFileForm::on_binaryHeaderTable_cellClicked(int row, int column)
{
    stack2.push("t2");

    p++;
    QString s;
    rowidx=ui->binaryHeaderTable->selectionModel()->currentIndex().row();
    stack.push(row);
    colidx=ui->binaryHeaderTable->selectionModel()->currentIndex().row();
    stack3.push(column);
QString qs=ui->binaryHeaderTable->model()->index(rowidx,2).data().toString();
std::string utf=qs.toUtf8().constData();
    stack1.push(utf);
}

/*void SegyFileForm::on_binaryHeaderTable_cellDoubleClicked(int row, int column)
{
    stack2.push("t2");

    p++;
    QString s;
    rowidx=ui->binaryHeaderTable->selectionModel()->currentIndex().row();
    stack.push(row);
    stack3.push(column);
QString qs=ui->binaryHeaderTable->model()->index(rowidx,0).data().toString();
std::string utf=qs.toUtf8().constData();
    stack1.push(utf);
}*/

void SegyFileForm::on_traceBinaryHeaderTable_cellClicked(int row, int column)
{ stack2.push("t3");

    p++;
    QString s;
    rowidx=ui->traceBinaryHeaderTable->selectionModel()->currentIndex().row();
    stack.push(row);
    colidx=ui->traceBinaryHeaderTable->selectionModel()->currentIndex().row();
    stack3.push(column);
QString qs=ui->traceBinaryHeaderTable->model()->index(rowidx,2).data().toString();
std::string utf=qs.toUtf8().constData();
    stack1.push(utf);

}

void SegyFileForm::convert(){
    string fileName = QFileDialog::getSaveFileName(this, tr("Open Seg-Y"),"./", tr("Seg-Y Files (*.segy *.sgy *.SEGY *.SGY)")).toStdString();
    if(fileName.empty()){
    }
    else if(fileName != s->getOriginalFileName()){
        QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("Converting..."),tr("Please wait while Conversion progresses."),QMessageBox::NoButton);
        box->show();
        s->convertToBigEndian(fileName);
        box->close();
        delete box;
        QMessageBox::information(this,"Complete","Conversion is complete.");
    }else {
        QMessageBox::warning(this, "FILE error", "Choose Another File", QMessageBox::Ok);
    }
}
