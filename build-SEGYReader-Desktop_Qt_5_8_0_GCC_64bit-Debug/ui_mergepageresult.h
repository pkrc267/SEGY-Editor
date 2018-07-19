/********************************************************************************
** Form generated from reading UI file 'mergepageresult.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MERGEPAGERESULT_H
#define UI_MERGEPAGERESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_MergePageResult
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *start;
    QCheckBox *stage1;
    QCheckBox *stage2;
    QCheckBox *stage3;
    QCheckBox *stage4;
    QCheckBox *stage5;
    QCheckBox *stage6;
    QProgressBar *independentegProgressBar;
    QLabel *finishSuccessLabel;
    QLabel *finishFailureLabel;

    void setupUi(QWizardPage *MergePageResult)
    {
        if (MergePageResult->objectName().isEmpty())
            MergePageResult->setObjectName(QStringLiteral("MergePageResult"));
        MergePageResult->resize(400, 300);
        verticalLayout = new QVBoxLayout(MergePageResult);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        start = new QPushButton(MergePageResult);
        start->setObjectName(QStringLiteral("start"));

        verticalLayout->addWidget(start);

        stage1 = new QCheckBox(MergePageResult);
        stage1->setObjectName(QStringLiteral("stage1"));

        verticalLayout->addWidget(stage1);

        stage2 = new QCheckBox(MergePageResult);
        stage2->setObjectName(QStringLiteral("stage2"));

        verticalLayout->addWidget(stage2);

        stage3 = new QCheckBox(MergePageResult);
        stage3->setObjectName(QStringLiteral("stage3"));

        verticalLayout->addWidget(stage3);

        stage4 = new QCheckBox(MergePageResult);
        stage4->setObjectName(QStringLiteral("stage4"));

        verticalLayout->addWidget(stage4);

        stage5 = new QCheckBox(MergePageResult);
        stage5->setObjectName(QStringLiteral("stage5"));

        verticalLayout->addWidget(stage5);

        stage6 = new QCheckBox(MergePageResult);
        stage6->setObjectName(QStringLiteral("stage6"));

        verticalLayout->addWidget(stage6);

        independentegProgressBar = new QProgressBar(MergePageResult);
        independentegProgressBar->setObjectName(QStringLiteral("independentegProgressBar"));
        independentegProgressBar->setValue(0);

        verticalLayout->addWidget(independentegProgressBar);

        finishSuccessLabel = new QLabel(MergePageResult);
        finishSuccessLabel->setObjectName(QStringLiteral("finishSuccessLabel"));
        finishSuccessLabel->setWordWrap(true);

        verticalLayout->addWidget(finishSuccessLabel);

        finishFailureLabel = new QLabel(MergePageResult);
        finishFailureLabel->setObjectName(QStringLiteral("finishFailureLabel"));

        verticalLayout->addWidget(finishFailureLabel);


        retranslateUi(MergePageResult);

        QMetaObject::connectSlotsByName(MergePageResult);
    } // setupUi

    void retranslateUi(QWizardPage *MergePageResult)
    {
        MergePageResult->setWindowTitle(QApplication::translate("MergePageResult", "WizardPage", Q_NULLPTR));
        MergePageResult->setTitle(QApplication::translate("MergePageResult", "Finished", Q_NULLPTR));
        start->setText(QApplication::translate("MergePageResult", "Start", Q_NULLPTR));
        stage1->setText(QApplication::translate("MergePageResult", "File Created", Q_NULLPTR));
        stage2->setText(QApplication::translate("MergePageResult", "Text Headers Written", Q_NULLPTR));
        stage3->setText(QApplication::translate("MergePageResult", "Binary Headers Written", Q_NULLPTR));
        stage4->setText(QApplication::translate("MergePageResult", "Reading Traces", Q_NULLPTR));
        stage5->setText(QApplication::translate("MergePageResult", "Sorting Traces", Q_NULLPTR));
        stage6->setText(QApplication::translate("MergePageResult", "Writing Traces", Q_NULLPTR));
        finishSuccessLabel->setText(QApplication::translate("MergePageResult", "File created successfully", Q_NULLPTR));
        finishFailureLabel->setText(QApplication::translate("MergePageResult", "<font color='red'>File creation was unsuccessful.</font>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MergePageResult: public Ui_MergePageResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERGEPAGERESULT_H
