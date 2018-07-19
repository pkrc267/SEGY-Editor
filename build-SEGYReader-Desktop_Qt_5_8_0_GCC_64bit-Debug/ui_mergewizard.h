/********************************************************************************
** Form generated from reading UI file 'mergewizard.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MERGEWIZARD_H
#define UI_MERGEWIZARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWizard>

QT_BEGIN_NAMESPACE

class Ui_MergeWizard
{
public:

    void setupUi(QWizard *MergeWizard)
    {
        if (MergeWizard->objectName().isEmpty())
            MergeWizard->setObjectName(QStringLiteral("MergeWizard"));
        MergeWizard->resize(660, 429);

        retranslateUi(MergeWizard);

        QMetaObject::connectSlotsByName(MergeWizard);
    } // setupUi

    void retranslateUi(QWizard *MergeWizard)
    {
        MergeWizard->setWindowTitle(QApplication::translate("MergeWizard", "Wizard", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MergeWizard: public Ui_MergeWizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERGEWIZARD_H
