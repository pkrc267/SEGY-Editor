/********************************************************************************
** Form generated from reading UI file 'mergeintropage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MERGEINTROPAGE_H
#define UI_MERGEINTROPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_MergeIntroPage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *introText;

    void setupUi(QWizardPage *MergeIntroPage)
    {
        if (MergeIntroPage->objectName().isEmpty())
            MergeIntroPage->setObjectName(QStringLiteral("MergeIntroPage"));
        MergeIntroPage->resize(528, 349);
        verticalLayout = new QVBoxLayout(MergeIntroPage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        introText = new QLabel(MergeIntroPage);
        introText->setObjectName(QStringLiteral("introText"));
        introText->setTextFormat(Qt::PlainText);
        introText->setWordWrap(true);

        verticalLayout->addWidget(introText);


        retranslateUi(MergeIntroPage);

        QMetaObject::connectSlotsByName(MergeIntroPage);
    } // setupUi

    void retranslateUi(QWizardPage *MergeIntroPage)
    {
        MergeIntroPage->setWindowTitle(QApplication::translate("MergeIntroPage", "WizardPage", Q_NULLPTR));
        MergeIntroPage->setTitle(QApplication::translate("MergeIntroPage", "Introduction", Q_NULLPTR));
        MergeIntroPage->setSubTitle(QApplication::translate("MergeIntroPage", "Welcome to Merge Wizard", Q_NULLPTR));
        introText->setText(QApplication::translate("MergeIntroPage", "This wizard will take you through the process of merging two or more Segy Files into a single file.\n"
"Please note that, Segy files require similar properties to merge, and it may not be possible in all cases to merge files. The wizard will  guide you through it as well.", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MergeIntroPage: public Ui_MergeIntroPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERGEINTROPAGE_H
