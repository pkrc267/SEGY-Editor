/********************************************************************************
** Form generated from reading UI file 'mergetracesort.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MERGETRACESORT_H
#define UI_MERGETRACESORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_MergeTraceSort
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *time;
    QRadioButton *lineSequenceNumber;
    QRadioButton *none;

    void setupUi(QWizardPage *MergeTraceSort)
    {
        if (MergeTraceSort->objectName().isEmpty())
            MergeTraceSort->setObjectName(QStringLiteral("MergeTraceSort"));
        MergeTraceSort->resize(581, 434);
        MergeTraceSort->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(MergeTraceSort);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(MergeTraceSort);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        groupBox = new QGroupBox(MergeTraceSort);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        time = new QRadioButton(groupBox);
        time->setObjectName(QStringLiteral("time"));

        verticalLayout_2->addWidget(time);

        lineSequenceNumber = new QRadioButton(groupBox);
        lineSequenceNumber->setObjectName(QStringLiteral("lineSequenceNumber"));

        verticalLayout_2->addWidget(lineSequenceNumber);

        none = new QRadioButton(groupBox);
        none->setObjectName(QStringLiteral("none"));
        none->setChecked(true);

        verticalLayout_2->addWidget(none);


        verticalLayout->addWidget(groupBox);


        retranslateUi(MergeTraceSort);

        QMetaObject::connectSlotsByName(MergeTraceSort);
    } // setupUi

    void retranslateUi(QWizardPage *MergeTraceSort)
    {
        MergeTraceSort->setWindowTitle(QApplication::translate("MergeTraceSort", "WizardPage", Q_NULLPTR));
        MergeTraceSort->setTitle(QApplication::translate("MergeTraceSort", "Sorting the Traces", Q_NULLPTR));
        MergeTraceSort->setSubTitle(QApplication::translate("MergeTraceSort", "Please choose the way you want the traces to be sorted.", Q_NULLPTR));
        label->setText(QApplication::translate("MergeTraceSort", "The traces will be sorted based on the sequence chosen by you. The Traces will be disambiguated ased on the sequence in which you chose files.", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MergeTraceSort", "Order Traces By", Q_NULLPTR));
        time->setText(QApplication::translate("MergeTraceSort", "Time", Q_NULLPTR));
        lineSequenceNumber->setText(QApplication::translate("MergeTraceSort", "Line Sequence Number", Q_NULLPTR));
        none->setText(QApplication::translate("MergeTraceSort", "None", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MergeTraceSort: public Ui_MergeTraceSort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERGETRACESORT_H
