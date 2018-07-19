#include "mergewizard.h"
#include "ui_mergewizard.h"
#include <mergecompareproperties.h>
#include <QAbstractButton>

MergeWizard::MergeWizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::MergeWizard)
{
    ui->setupUi(this);
    QWizardPage *introPage = new MergeIntroPage(this);
    setPage(PageIntro, introPage);

    QWizardPage *fileSelection = new MergeFileSelection(&m,this);
    setPage(PageFileSelection, fileSelection);

    QWizardPage *compareProp = new MergeCompareProperties(&m,this);
    setPage(PageCompareProperties, compareProp);

    QWizardPage *textHeader = new MergeTextualHeader(&m,this);
    setPage(PageTextualHeader, textHeader);

    QWizardPage *traceSort = new MergeTraceSort(&m,this);
    setPage(PageTraceSort, traceSort);

    QWizardPage *pageResult = new MergePageResult(&m,this);
    setPage(PageResult, pageResult);

    setWizardStyle(ModernStyle);
    QPixmap *pic = new QPixmap(QString::fromStdString("./g1.jpg"));
    setPixmap(WatermarkPixmap, *pic);
    setWindowTitle("Merge Wizard");
    success = false;

//    QList<QWizard::WizardButton> button_layout;
//    button_layout << QWizard::NextButton << QWizard::CancelButton;
//    this->setButtonLayout(button_layout);
}

MergeWizard::~MergeWizard()
{
    delete ui;
}
