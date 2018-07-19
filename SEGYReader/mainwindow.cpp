#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sys/stat.h>
#include <QFileDialog>
#include <QMessageBox>
#include <segyfileRevised.h>
#include <segyfileform.h>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <iostream>
#include <mergewizard.h>
#include <isledialog.h>
using namespace std;
inline bool exists(const std::string& name){
    struct stat buffer;
    return(stat(name.c_str(), &buffer) != -1);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionClose->setDisabled(true);
    ui->actionUndo->setDisabled(true);
    ui->actionSave->setDisabled(true);
    ui->actionSave_As->setDisabled(true);
    ui->actionRedo->setDisabled(true);
    connect(ui->actionOpen,SIGNAL(triggered()), this, SLOT(open()));
    connect(ui->actionClose,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(save()));
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(saveAs()));
    connect(ui->actionMerge,SIGNAL(triggered()), this, SLOT(merge()));
    numOfWindowsOpen = 0;
    connect(ui->actionExit, SIGNAL(triggered(bool)),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open(){
    string filename = (QFileDialog::getOpenFileName(this, tr("Open Seg-Y"),"./", tr("Seg-Y Files (*.segy *.sgy *.SEGY *.SGY)"))).toStdString();
    if(exists(filename)){
        IsLEDialog dialog (filename, this);
        int result = dialog.exec();
        if(result != QDialog::Rejected){
            SegyFileForm *sff;
            //cout<<dialog.BE<<endl;
            if(dialog.BE)sff = new SegyFileForm (filename,true,this);
            else sff = new SegyFileForm (filename,false,this);
            QMdiSubWindow *sub = new QMdiSubWindow(ui->mdiArea,Qt::CustomizeWindowHint | Qt::WindowMinMaxButtonsHint);
            sub->setWidget(sff);
            QString s = QString::fromStdString(filename);
            QList<QString> sl = s.split("/");
            sub->setWindowTitle(sl.back());
            ui->mdiArea->addSubWindow(sub,Qt::CustomizeWindowHint | Qt::WindowMinMaxButtonsHint);
            //sub->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinMaxButtonsHint);
            sub->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinMaxButtonsHint );
            sub->show();
            numOfWindowsOpen++;
            ui->actionSave->setEnabled(true);
            ui->actionSave_As->setEnabled(true);
            ui->actionClose->setEnabled(true);
        }
    }else {
        QMessageBox b;
        b.setText("File cannot be opened.");
        b.exec();        
    }
}

void MainWindow::close(){
    if(numOfWindowsOpen>0){
        QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
        SegyFileForm *f = static_cast<SegyFileForm *>(ui->mdiArea->activeSubWindow()->widget());
        if(!f->isSaved()){
            QMessageBox::StandardButton reply = QMessageBox::question(this,tr("Discard Changes?"),tr("Are you sure you want to close this file, without saving?"),QMessageBox::Discard | QMessageBox::Save | QMessageBox::Cancel);
            if(reply == QMessageBox::Save){
                f->save();
            }else if(reply == QMessageBox::Cancel) return;
        }
        sub->close();
        //cout<<"Reached"<<endl;
        numOfWindowsOpen--;
        //cout<<"Num of Windows "<<numOfWindowsOpen<<endl;
        if(numOfWindowsOpen == 0){
            ui->actionSave->setDisabled(true);
            ui->actionSave_As->setDisabled(true);
            ui->actionClose->setDisabled(true);
        }
    }
}
void MainWindow::closeWithTitleBar(){
    numOfWindowsOpen--;
    //cout<<"Num of Windows "<<numOfWindowsOpen<<endl;
    if(numOfWindowsOpen == 0){
        ui->actionSave->setDisabled(true);
        ui->actionSave_As->setDisabled(true);
        ui->actionClose->setDisabled(true);
    }
}

void MainWindow::save(){
    SegyFileForm *f = static_cast<SegyFileForm *>(ui->mdiArea->activeSubWindow()->widget());
    f->save();
}

void MainWindow::saveAs(){
    SegyFileForm *f = (SegyFileForm *)(ui->mdiArea->activeSubWindow()->widget());
    string filename = (QFileDialog::getSaveFileName(this,tr("Save As Seg-Y"),"./",tr("Seg-Y Files (*.segy *.sgy *.SEGY *.SGY)"))).toStdString();
    //cout<<"reached mainWindow"<<endl;
    //cout<<"reached after mainWindow"<<endl;
    f->save(filename);
}

void MainWindow::merge(){
    ui->actionMerge->setDisabled(true);
    wiz = new MergeWizard(this);
    wiz->show();
    connect(wiz,SIGNAL(finished(int)),this,SLOT(mergeDone()));
    connect(wiz,SIGNAL(rejected()),this,SLOT(mergeDone()));
}


void MainWindow::mergeDone(){
    ui->actionMerge->setEnabled(true);
}
