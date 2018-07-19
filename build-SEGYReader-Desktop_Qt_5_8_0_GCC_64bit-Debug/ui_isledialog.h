/********************************************************************************
** Form generated from reading UI file 'isledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ISLEDIALOG_H
#define UI_ISLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_IsLEDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioBE;
    QRadioButton *radioLE;

    void setupUi(QDialog *IsLEDialog)
    {
        if (IsLEDialog->objectName().isEmpty())
            IsLEDialog->setObjectName(QStringLiteral("IsLEDialog"));
        IsLEDialog->resize(589, 482);
        verticalLayout_2 = new QVBoxLayout(IsLEDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableWidget = new QTableWidget(IsLEDialog);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 40)
            tableWidget->setRowCount(40);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(16, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(17, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(18, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(19, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(20, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(21, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(22, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(23, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(24, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(25, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(26, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(27, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(28, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(29, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(30, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(31, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(32, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(33, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(34, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(35, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(36, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(37, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(38, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(39, __qtablewidgetitem40);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        label = new QLabel(IsLEDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        buttonBox = new QDialogButtonBox(IsLEDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Open);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);

        groupBox = new QGroupBox(IsLEDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioBE = new QRadioButton(groupBox);
        radioBE->setObjectName(QStringLiteral("radioBE"));
        radioBE->setEnabled(true);
        radioBE->setChecked(true);

        verticalLayout->addWidget(radioBE);

        radioLE = new QRadioButton(groupBox);
        radioLE->setObjectName(QStringLiteral("radioLE"));

        verticalLayout->addWidget(radioLE);


        gridLayout->addWidget(groupBox, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        retranslateUi(IsLEDialog);

        QMetaObject::connectSlotsByName(IsLEDialog);
    } // setupUi

    void retranslateUi(QDialog *IsLEDialog)
    {
        IsLEDialog->setWindowTitle(QApplication::translate("IsLEDialog", "Dialog", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("IsLEDialog", "Text", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("IsLEDialog", "C 1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("IsLEDialog", "C 2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("IsLEDialog", "C 3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("IsLEDialog", "C 4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QApplication::translate("IsLEDialog", "C 5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QApplication::translate("IsLEDialog", "C 6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QApplication::translate("IsLEDialog", "C 7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem8->setText(QApplication::translate("IsLEDialog", "C 8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem9->setText(QApplication::translate("IsLEDialog", "C 9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem10->setText(QApplication::translate("IsLEDialog", "C10", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem11->setText(QApplication::translate("IsLEDialog", "C11", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem12->setText(QApplication::translate("IsLEDialog", "C12", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem13->setText(QApplication::translate("IsLEDialog", "C13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem14->setText(QApplication::translate("IsLEDialog", "C14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem15->setText(QApplication::translate("IsLEDialog", "C15", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem16->setText(QApplication::translate("IsLEDialog", "C16", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem17->setText(QApplication::translate("IsLEDialog", "C17", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(17);
        ___qtablewidgetitem18->setText(QApplication::translate("IsLEDialog", "C18", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(18);
        ___qtablewidgetitem19->setText(QApplication::translate("IsLEDialog", "C19", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(19);
        ___qtablewidgetitem20->setText(QApplication::translate("IsLEDialog", "C20", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(20);
        ___qtablewidgetitem21->setText(QApplication::translate("IsLEDialog", "C21", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(21);
        ___qtablewidgetitem22->setText(QApplication::translate("IsLEDialog", "C22", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->verticalHeaderItem(22);
        ___qtablewidgetitem23->setText(QApplication::translate("IsLEDialog", "C23", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->verticalHeaderItem(23);
        ___qtablewidgetitem24->setText(QApplication::translate("IsLEDialog", "C24", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->verticalHeaderItem(24);
        ___qtablewidgetitem25->setText(QApplication::translate("IsLEDialog", "C25", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->verticalHeaderItem(25);
        ___qtablewidgetitem26->setText(QApplication::translate("IsLEDialog", "C26", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->verticalHeaderItem(26);
        ___qtablewidgetitem27->setText(QApplication::translate("IsLEDialog", "C27", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->verticalHeaderItem(27);
        ___qtablewidgetitem28->setText(QApplication::translate("IsLEDialog", "C28", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->verticalHeaderItem(28);
        ___qtablewidgetitem29->setText(QApplication::translate("IsLEDialog", "C29", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->verticalHeaderItem(29);
        ___qtablewidgetitem30->setText(QApplication::translate("IsLEDialog", "C30", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->verticalHeaderItem(30);
        ___qtablewidgetitem31->setText(QApplication::translate("IsLEDialog", "C31", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->verticalHeaderItem(31);
        ___qtablewidgetitem32->setText(QApplication::translate("IsLEDialog", "C32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->verticalHeaderItem(32);
        ___qtablewidgetitem33->setText(QApplication::translate("IsLEDialog", "C33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->verticalHeaderItem(33);
        ___qtablewidgetitem34->setText(QApplication::translate("IsLEDialog", "C34", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->verticalHeaderItem(34);
        ___qtablewidgetitem35->setText(QApplication::translate("IsLEDialog", "C35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->verticalHeaderItem(35);
        ___qtablewidgetitem36->setText(QApplication::translate("IsLEDialog", "C36", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->verticalHeaderItem(36);
        ___qtablewidgetitem37->setText(QApplication::translate("IsLEDialog", "C37", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->verticalHeaderItem(37);
        ___qtablewidgetitem38->setText(QApplication::translate("IsLEDialog", "C38", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->verticalHeaderItem(38);
        ___qtablewidgetitem39->setText(QApplication::translate("IsLEDialog", "C39", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->verticalHeaderItem(39);
        ___qtablewidgetitem40->setText(QApplication::translate("IsLEDialog", "C40", Q_NULLPTR));
        label->setText(QApplication::translate("IsLEDialog", "Please choose whether this file is Big Endian or Little Endian.\n"
"In case you do not understand what this means, just click okay.", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("IsLEDialog", "Data Format Storage Type", Q_NULLPTR));
        radioBE->setText(QApplication::translate("IsLEDialog", "Big Endian", Q_NULLPTR));
        radioLE->setText(QApplication::translate("IsLEDialog", "Little Endian", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class IsLEDialog: public Ui_IsLEDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ISLEDIALOG_H
