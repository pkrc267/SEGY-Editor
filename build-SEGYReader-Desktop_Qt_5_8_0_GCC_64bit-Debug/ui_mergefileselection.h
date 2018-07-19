/********************************************************************************
** Form generated from reading UI file 'mergefileselection.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MERGEFILESELECTION_H
#define UI_MERGEFILESELECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_MergeFileSelection
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addFilesTextFile;
    QPushButton *addFileManual;
    QCheckBox *showLocationCheck;
    QTableWidget *filesTable;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveFileButton;
    QLineEdit *saveFileEdit;

    void setupUi(QWizardPage *MergeFileSelection)
    {
        if (MergeFileSelection->objectName().isEmpty())
            MergeFileSelection->setObjectName(QStringLiteral("MergeFileSelection"));
        MergeFileSelection->resize(542, 407);
        verticalLayout = new QVBoxLayout(MergeFileSelection);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        addFilesTextFile = new QPushButton(MergeFileSelection);
        addFilesTextFile->setObjectName(QStringLiteral("addFilesTextFile"));

        horizontalLayout_2->addWidget(addFilesTextFile, 0, Qt::AlignLeft);

        addFileManual = new QPushButton(MergeFileSelection);
        addFileManual->setObjectName(QStringLiteral("addFileManual"));

        horizontalLayout_2->addWidget(addFileManual, 0, Qt::AlignLeft);

        showLocationCheck = new QCheckBox(MergeFileSelection);
        showLocationCheck->setObjectName(QStringLiteral("showLocationCheck"));

        horizontalLayout_2->addWidget(showLocationCheck, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout_2);

        filesTable = new QTableWidget(MergeFileSelection);
        if (filesTable->columnCount() < 5)
            filesTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        filesTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        filesTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        filesTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        filesTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        filesTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        filesTable->setObjectName(QStringLiteral("filesTable"));
        filesTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        filesTable->setShowGrid(true);
        filesTable->horizontalHeader()->setVisible(true);
        filesTable->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(filesTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        saveFileButton = new QPushButton(MergeFileSelection);
        saveFileButton->setObjectName(QStringLiteral("saveFileButton"));

        horizontalLayout->addWidget(saveFileButton);

        saveFileEdit = new QLineEdit(MergeFileSelection);
        saveFileEdit->setObjectName(QStringLiteral("saveFileEdit"));

        horizontalLayout->addWidget(saveFileEdit);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MergeFileSelection);

        QMetaObject::connectSlotsByName(MergeFileSelection);
    } // setupUi

    void retranslateUi(QWizardPage *MergeFileSelection)
    {
        MergeFileSelection->setWindowTitle(QApplication::translate("MergeFileSelection", "WizardPage", Q_NULLPTR));
        MergeFileSelection->setTitle(QApplication::translate("MergeFileSelection", "Select Files", Q_NULLPTR));
        MergeFileSelection->setSubTitle(QApplication::translate("MergeFileSelection", "Choose the files to be merged. If you do not know what Big Endian means, let the column be in its default state.", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        addFilesTextFile->setToolTip(QApplication::translate("MergeFileSelection", "from a text file that contains file locations in separate lines.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        addFilesTextFile->setText(QApplication::translate("MergeFileSelection", "Add from Text File", "from a text file that contains file locations in separate lines."));
        addFileManual->setText(QApplication::translate("MergeFileSelection", "Add Files", Q_NULLPTR));
        showLocationCheck->setText(QApplication::translate("MergeFileSelection", "Show Locations", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = filesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MergeFileSelection", "File", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = filesTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MergeFileSelection", "Location", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = filesTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MergeFileSelection", "Big-Endian", Q_NULLPTR));
        saveFileButton->setText(QApplication::translate("MergeFileSelection", "Save File as", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MergeFileSelection: public Ui_MergeFileSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERGEFILESELECTION_H
