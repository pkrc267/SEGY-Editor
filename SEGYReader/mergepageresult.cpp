#include "mergepageresult.h"
#include "ui_mergepageresult.h"
#include <QMessageBox>


MergePageResult::MergePageResult(Merger *_m,QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::MergePageResult)
{
    m = _m;
    ui->setupUi(this);
    connect(m,SIGNAL(independentLegProgress(int)), ui->independentegProgressBar,SLOT(setValue(int)));
    //connect(m,SIGNAL(lastPage()), this, SLOT(on_start_clicked()));
    done =false;

}

MergePageResult::~MergePageResult()
{
    delete ui;
}

void MergePageResult::initializePage(){
    //emit completeChanged();
    //done = false;
    ui->finishFailureLabel->setVisible(false);
    ui->finishSuccessLabel->setVisible(false);
    ui->start->setVisible(false);
    if(m->getSuccess()){
        //ui->start->setVisible(true);
        ui->stage1->setCheckState(Qt::Unchecked);
        ui->stage2->setCheckState(Qt::Unchecked);
        ui->stage3->setCheckState(Qt::Unchecked);
        ui->stage4->setCheckState(Qt::Unchecked);
        ui->stage5->setCheckState(Qt::Unchecked);
        ui->stage6->setCheckState(Qt::Unchecked);
        ui->independentegProgressBar->reset();
        ui->independentegProgressBar->setMinimum(0);
        ui->independentegProgressBar->setMaximum(100);
        wizard()->button(QWizard::FinishButton)->setDisabled(true);

    }else{
        ui->finishFailureLabel->setVisible(false);
        m->finish();
    }
}

void MergePageResult::on_start_clicked()
{
    m->createFile();
    ui->stage1->setCheckState(Qt::Checked);
    m->writeTextualHeader();
    ui->stage2->setCheckState(Qt::Checked);
    m->writeBinaryHeader();
    ui->stage3->setCheckState(Qt::Checked);
    m->readTraces();
    ui->stage4->setCheckState(Qt::Checked);
    m->sortTraces();
    ui->stage5->setCheckState(Qt::Checked);
    m->writeTraces();
    ui->stage6->setCheckState(Qt::Checked);
    m->finish();
    ui->finishSuccessLabel->setVisible(true);
    wizard()->button(QWizard::FinishButton)->setEnabled(true);
    //done = true;
    //isComplete();
    //done = false;
}

bool MergePageResult::isComplete(){
    //if(done) emit completeChanged();
    return true;
}

bool MergePageResult::validatePage(){
    m->createFile();
    ui->stage1->setCheckState(Qt::Checked);
    m->writeTextualHeader();
    ui->stage2->setCheckState(Qt::Checked);
    m->writeBinaryHeader();
    ui->stage3->setCheckState(Qt::Checked);
    m->readTraces();
    ui->stage4->setCheckState(Qt::Checked);
    m->sortTraces();
    ui->stage5->setCheckState(Qt::Checked);
    m->writeTraces();
    ui->stage6->setCheckState(Qt::Checked);
    m->finish();
    ui->finishSuccessLabel->setVisible(true);
    wizard()->button(QWizard::FinishButton)->setEnabled(true);
    //done = true;
    //isComplete();
    //done = false;
    QMessageBox::information(0,"Done","Task Finished");
    return true;
}
