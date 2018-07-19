/********************************************************************************
** Form generated from reading UI file 'mergecompareproperties.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MERGECOMPAREPROPERTIES_H
#define UI_MERGECOMPAREPROPERTIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_MergeCompareProperties
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *binaryValuesTable;
    QLabel *errorLabel;

    void setupUi(QWizardPage *MergeCompareProperties)
    {
        if (MergeCompareProperties->objectName().isEmpty())
            MergeCompareProperties->setObjectName(QStringLiteral("MergeCompareProperties"));
        MergeCompareProperties->resize(541, 461);
        verticalLayout = new QVBoxLayout(MergeCompareProperties);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(MergeCompareProperties);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        binaryValuesTable = new QTableWidget(MergeCompareProperties);
        if (binaryValuesTable->columnCount() < 2)
            binaryValuesTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        binaryValuesTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        binaryValuesTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (binaryValuesTable->rowCount() < 30)
            binaryValuesTable->setRowCount(30);
        binaryValuesTable->setObjectName(QStringLiteral("binaryValuesTable"));
        binaryValuesTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        binaryValuesTable->setRowCount(30);
        binaryValuesTable->setColumnCount(2);

        verticalLayout->addWidget(binaryValuesTable);

        errorLabel = new QLabel(MergeCompareProperties);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setEnabled(true);
        errorLabel->setWordWrap(true);

        verticalLayout->addWidget(errorLabel);


        retranslateUi(MergeCompareProperties);

        QMetaObject::connectSlotsByName(MergeCompareProperties);
    } // setupUi

    void retranslateUi(QWizardPage *MergeCompareProperties)
    {
        MergeCompareProperties->setWindowTitle(QApplication::translate("MergeCompareProperties", "WizardPage", Q_NULLPTR));
        MergeCompareProperties->setTitle(QApplication::translate("MergeCompareProperties", "Global Comparision", Q_NULLPTR));
        MergeCompareProperties->setSubTitle(QApplication::translate("MergeCompareProperties", "Choose global Segy File or Binary Header Properties.", Q_NULLPTR));
        label->setText(QApplication::translate("MergeCompareProperties", "You may either use any of the values from the different Seg-Y files selected or input any new value.", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = binaryValuesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MergeCompareProperties", "Header", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = binaryValuesTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MergeCompareProperties", "New Value", Q_NULLPTR));
        errorLabel->setText(QApplication::translate("MergeCompareProperties", "<font color='RED'>Not Possible to Merge Files. Values that must be same are RED. Please exit the Wizard</font>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MergeCompareProperties: public Ui_MergeCompareProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERGECOMPAREPROPERTIES_H
