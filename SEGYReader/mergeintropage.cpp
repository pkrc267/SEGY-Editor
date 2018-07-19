#include "mergeintropage.h"
#include "ui_mergeintropage.h"

MergeIntroPage::MergeIntroPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::MergeIntroPage)
{
    ui->setupUi(this);
    //ui->successCheck->setVisible(false);
    //ui->successCheck->setChecked(false);
    //registerField("success",ui->successCheck);
}

MergeIntroPage::~MergeIntroPage()
{
    delete ui;
}
