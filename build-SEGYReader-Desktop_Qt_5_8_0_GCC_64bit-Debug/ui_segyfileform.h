/********************************************************************************
** Form generated from reading UI file 'segyfileform.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEGYFILEFORM_H
#define UI_SEGYFILEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SegyFileForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *convertButton;
    QPushButton *pushButton;
    QFrame *line;
    QLabel *openFileLabel;
    QHBoxLayout *horizontalLayout;
    QTabWidget *globalHeaderTabWidget;
    QWidget *textHeaderTab;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *textHeaderTable;
    QWidget *binaryHeaderTab;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *binaryHeaderTable;
    QWidget *extendedHeaderTab;
    QVBoxLayout *verticalLayout_3;
    QLabel *traceNumberLabel;
    QListWidget *traceList;
    QVBoxLayout *verticalLayout_2;
    QLabel *traceLabel;
    QTabWidget *traceTabWidget;
    QWidget *binaryHeaders;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *traceBinaryHeaderTable;
    QWidget *traceData;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *traceDataTable;

    void setupUi(QWidget *SegyFileForm)
    {
        if (SegyFileForm->objectName().isEmpty())
            SegyFileForm->setObjectName(QStringLiteral("SegyFileForm"));
        SegyFileForm->resize(800, 640);
        verticalLayout = new QVBoxLayout(SegyFileForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        convertButton = new QPushButton(SegyFileForm);
        convertButton->setObjectName(QStringLiteral("convertButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(convertButton->sizePolicy().hasHeightForWidth());
        convertButton->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(convertButton);

        pushButton = new QPushButton(SegyFileForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_4);

        line = new QFrame(SegyFileForm);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(3);
        line->setFrameShape(QFrame::HLine);

        verticalLayout->addWidget(line);

        openFileLabel = new QLabel(SegyFileForm);
        openFileLabel->setObjectName(QStringLiteral("openFileLabel"));

        verticalLayout->addWidget(openFileLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        globalHeaderTabWidget = new QTabWidget(SegyFileForm);
        globalHeaderTabWidget->setObjectName(QStringLiteral("globalHeaderTabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(globalHeaderTabWidget->sizePolicy().hasHeightForWidth());
        globalHeaderTabWidget->setSizePolicy(sizePolicy1);
        textHeaderTab = new QWidget();
        textHeaderTab->setObjectName(QStringLiteral("textHeaderTab"));
        verticalLayout_4 = new QVBoxLayout(textHeaderTab);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        scrollArea = new QScrollArea(textHeaderTab);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 309, 500));
        horizontalLayout_3 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        textHeaderTable = new QTableWidget(scrollAreaWidgetContents);
        if (textHeaderTable->columnCount() < 1)
            textHeaderTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        textHeaderTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (textHeaderTable->rowCount() < 40)
            textHeaderTable->setRowCount(40);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(9, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(10, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(11, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(12, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(13, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(14, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(15, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(16, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(17, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(18, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(19, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(20, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(21, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(22, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(23, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(24, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(25, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(26, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(27, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(28, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(29, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(30, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(31, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(32, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(33, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(34, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(35, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(36, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(37, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(38, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        textHeaderTable->setVerticalHeaderItem(39, __qtablewidgetitem40);
        textHeaderTable->setObjectName(QStringLiteral("textHeaderTable"));
        textHeaderTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textHeaderTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        textHeaderTable->horizontalHeader()->setVisible(false);

        horizontalLayout_3->addWidget(textHeaderTable);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);

        globalHeaderTabWidget->addTab(textHeaderTab, QString());
        binaryHeaderTab = new QWidget();
        binaryHeaderTab->setObjectName(QStringLiteral("binaryHeaderTab"));
        verticalLayout_5 = new QVBoxLayout(binaryHeaderTab);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        binaryHeaderTable = new QTableWidget(binaryHeaderTab);
        if (binaryHeaderTable->columnCount() < 3)
            binaryHeaderTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        binaryHeaderTable->setHorizontalHeaderItem(0, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        binaryHeaderTable->setHorizontalHeaderItem(1, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        binaryHeaderTable->setHorizontalHeaderItem(2, __qtablewidgetitem43);
        binaryHeaderTable->setObjectName(QStringLiteral("binaryHeaderTable"));

        verticalLayout_5->addWidget(binaryHeaderTable);

        globalHeaderTabWidget->addTab(binaryHeaderTab, QString());
        extendedHeaderTab = new QWidget();
        extendedHeaderTab->setObjectName(QStringLiteral("extendedHeaderTab"));
        globalHeaderTabWidget->addTab(extendedHeaderTab, QString());

        horizontalLayout->addWidget(globalHeaderTabWidget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        traceNumberLabel = new QLabel(SegyFileForm);
        traceNumberLabel->setObjectName(QStringLiteral("traceNumberLabel"));

        verticalLayout_3->addWidget(traceNumberLabel);

        traceList = new QListWidget(SegyFileForm);
        traceList->setObjectName(QStringLiteral("traceList"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(traceList->sizePolicy().hasHeightForWidth());
        traceList->setSizePolicy(sizePolicy2);
        traceList->setMaximumSize(QSize(100, 16777215));

        verticalLayout_3->addWidget(traceList);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        traceLabel = new QLabel(SegyFileForm);
        traceLabel->setObjectName(QStringLiteral("traceLabel"));
        traceLabel->setFrameShape(QFrame::Panel);
        traceLabel->setFrameShadow(QFrame::Sunken);
        traceLabel->setLineWidth(7);
        traceLabel->setMidLineWidth(0);

        verticalLayout_2->addWidget(traceLabel);

        traceTabWidget = new QTabWidget(SegyFileForm);
        traceTabWidget->setObjectName(QStringLiteral("traceTabWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(traceTabWidget->sizePolicy().hasHeightForWidth());
        traceTabWidget->setSizePolicy(sizePolicy3);
        binaryHeaders = new QWidget();
        binaryHeaders->setObjectName(QStringLiteral("binaryHeaders"));
        verticalLayout_6 = new QVBoxLayout(binaryHeaders);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        traceBinaryHeaderTable = new QTableWidget(binaryHeaders);
        if (traceBinaryHeaderTable->columnCount() < 3)
            traceBinaryHeaderTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        traceBinaryHeaderTable->setHorizontalHeaderItem(0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        traceBinaryHeaderTable->setHorizontalHeaderItem(1, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        traceBinaryHeaderTable->setHorizontalHeaderItem(2, __qtablewidgetitem46);
        traceBinaryHeaderTable->setObjectName(QStringLiteral("traceBinaryHeaderTable"));

        verticalLayout_6->addWidget(traceBinaryHeaderTable);

        traceTabWidget->addTab(binaryHeaders, QString());
        traceData = new QWidget();
        traceData->setObjectName(QStringLiteral("traceData"));
        horizontalLayout_2 = new QHBoxLayout(traceData);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        traceDataTable = new QTableWidget(traceData);
        if (traceDataTable->columnCount() < 2)
            traceDataTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        traceDataTable->setHorizontalHeaderItem(0, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        traceDataTable->setHorizontalHeaderItem(1, __qtablewidgetitem48);
        traceDataTable->setObjectName(QStringLiteral("traceDataTable"));

        horizontalLayout_2->addWidget(traceDataTable);

        traceTabWidget->addTab(traceData, QString());

        verticalLayout_2->addWidget(traceTabWidget);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SegyFileForm);

        globalHeaderTabWidget->setCurrentIndex(0);
        traceTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SegyFileForm);
    } // setupUi

    void retranslateUi(QWidget *SegyFileForm)
    {
        SegyFileForm->setWindowTitle(QApplication::translate("SegyFileForm", "Form", Q_NULLPTR));
        convertButton->setText(QApplication::translate("SegyFileForm", "Convert To Big Endian", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SegyFileForm", "undo", Q_NULLPTR));
        openFileLabel->setText(QApplication::translate("SegyFileForm", "Open File: ", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = textHeaderTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SegyFileForm", "Text", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = textHeaderTable->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("SegyFileForm", "C 1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = textHeaderTable->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("SegyFileForm", "C 2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = textHeaderTable->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("SegyFileForm", "C 3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = textHeaderTable->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("SegyFileForm", "C 4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = textHeaderTable->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QApplication::translate("SegyFileForm", "C 5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = textHeaderTable->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QApplication::translate("SegyFileForm", "C 6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = textHeaderTable->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QApplication::translate("SegyFileForm", "C 7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = textHeaderTable->verticalHeaderItem(7);
        ___qtablewidgetitem8->setText(QApplication::translate("SegyFileForm", "C 8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = textHeaderTable->verticalHeaderItem(8);
        ___qtablewidgetitem9->setText(QApplication::translate("SegyFileForm", "C 9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = textHeaderTable->verticalHeaderItem(9);
        ___qtablewidgetitem10->setText(QApplication::translate("SegyFileForm", "C10", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = textHeaderTable->verticalHeaderItem(10);
        ___qtablewidgetitem11->setText(QApplication::translate("SegyFileForm", "C11", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = textHeaderTable->verticalHeaderItem(11);
        ___qtablewidgetitem12->setText(QApplication::translate("SegyFileForm", "C12", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = textHeaderTable->verticalHeaderItem(12);
        ___qtablewidgetitem13->setText(QApplication::translate("SegyFileForm", "C13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = textHeaderTable->verticalHeaderItem(13);
        ___qtablewidgetitem14->setText(QApplication::translate("SegyFileForm", "C14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = textHeaderTable->verticalHeaderItem(14);
        ___qtablewidgetitem15->setText(QApplication::translate("SegyFileForm", "C15", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = textHeaderTable->verticalHeaderItem(15);
        ___qtablewidgetitem16->setText(QApplication::translate("SegyFileForm", "C16", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = textHeaderTable->verticalHeaderItem(16);
        ___qtablewidgetitem17->setText(QApplication::translate("SegyFileForm", "C17", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = textHeaderTable->verticalHeaderItem(17);
        ___qtablewidgetitem18->setText(QApplication::translate("SegyFileForm", "C18", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = textHeaderTable->verticalHeaderItem(18);
        ___qtablewidgetitem19->setText(QApplication::translate("SegyFileForm", "C19", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = textHeaderTable->verticalHeaderItem(19);
        ___qtablewidgetitem20->setText(QApplication::translate("SegyFileForm", "C20", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = textHeaderTable->verticalHeaderItem(20);
        ___qtablewidgetitem21->setText(QApplication::translate("SegyFileForm", "C21", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = textHeaderTable->verticalHeaderItem(21);
        ___qtablewidgetitem22->setText(QApplication::translate("SegyFileForm", "C22", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = textHeaderTable->verticalHeaderItem(22);
        ___qtablewidgetitem23->setText(QApplication::translate("SegyFileForm", "C23", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = textHeaderTable->verticalHeaderItem(23);
        ___qtablewidgetitem24->setText(QApplication::translate("SegyFileForm", "C24", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = textHeaderTable->verticalHeaderItem(24);
        ___qtablewidgetitem25->setText(QApplication::translate("SegyFileForm", "C25", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = textHeaderTable->verticalHeaderItem(25);
        ___qtablewidgetitem26->setText(QApplication::translate("SegyFileForm", "C26", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = textHeaderTable->verticalHeaderItem(26);
        ___qtablewidgetitem27->setText(QApplication::translate("SegyFileForm", "C27", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = textHeaderTable->verticalHeaderItem(27);
        ___qtablewidgetitem28->setText(QApplication::translate("SegyFileForm", "C28", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = textHeaderTable->verticalHeaderItem(28);
        ___qtablewidgetitem29->setText(QApplication::translate("SegyFileForm", "C29", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = textHeaderTable->verticalHeaderItem(29);
        ___qtablewidgetitem30->setText(QApplication::translate("SegyFileForm", "C30", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem31 = textHeaderTable->verticalHeaderItem(30);
        ___qtablewidgetitem31->setText(QApplication::translate("SegyFileForm", "C31", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem32 = textHeaderTable->verticalHeaderItem(31);
        ___qtablewidgetitem32->setText(QApplication::translate("SegyFileForm", "C32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem33 = textHeaderTable->verticalHeaderItem(32);
        ___qtablewidgetitem33->setText(QApplication::translate("SegyFileForm", "C33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem34 = textHeaderTable->verticalHeaderItem(33);
        ___qtablewidgetitem34->setText(QApplication::translate("SegyFileForm", "C34", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem35 = textHeaderTable->verticalHeaderItem(34);
        ___qtablewidgetitem35->setText(QApplication::translate("SegyFileForm", "C35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem36 = textHeaderTable->verticalHeaderItem(35);
        ___qtablewidgetitem36->setText(QApplication::translate("SegyFileForm", "C36", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem37 = textHeaderTable->verticalHeaderItem(36);
        ___qtablewidgetitem37->setText(QApplication::translate("SegyFileForm", "C37", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem38 = textHeaderTable->verticalHeaderItem(37);
        ___qtablewidgetitem38->setText(QApplication::translate("SegyFileForm", "C38", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem39 = textHeaderTable->verticalHeaderItem(38);
        ___qtablewidgetitem39->setText(QApplication::translate("SegyFileForm", "C39", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem40 = textHeaderTable->verticalHeaderItem(39);
        ___qtablewidgetitem40->setText(QApplication::translate("SegyFileForm", "C40", Q_NULLPTR));
        globalHeaderTabWidget->setTabText(globalHeaderTabWidget->indexOf(textHeaderTab), QApplication::translate("SegyFileForm", "Text Header", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem41 = binaryHeaderTable->horizontalHeaderItem(0);
        ___qtablewidgetitem41->setText(QApplication::translate("SegyFileForm", "Bytes", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem42 = binaryHeaderTable->horizontalHeaderItem(1);
        ___qtablewidgetitem42->setText(QApplication::translate("SegyFileForm", "Header", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem43 = binaryHeaderTable->horizontalHeaderItem(2);
        ___qtablewidgetitem43->setText(QApplication::translate("SegyFileForm", "Value", Q_NULLPTR));
        globalHeaderTabWidget->setTabText(globalHeaderTabWidget->indexOf(binaryHeaderTab), QApplication::translate("SegyFileForm", "Binary Headers", Q_NULLPTR));
        globalHeaderTabWidget->setTabText(globalHeaderTabWidget->indexOf(extendedHeaderTab), QApplication::translate("SegyFileForm", "Extended Headers", Q_NULLPTR));
        traceNumberLabel->setText(QApplication::translate("SegyFileForm", "Select Trace #", Q_NULLPTR));
        traceLabel->setText(QApplication::translate("SegyFileForm", "Trace # : ", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem44 = traceBinaryHeaderTable->horizontalHeaderItem(0);
        ___qtablewidgetitem44->setText(QApplication::translate("SegyFileForm", "Bytes", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem45 = traceBinaryHeaderTable->horizontalHeaderItem(1);
        ___qtablewidgetitem45->setText(QApplication::translate("SegyFileForm", "Header", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem46 = traceBinaryHeaderTable->horizontalHeaderItem(2);
        ___qtablewidgetitem46->setText(QApplication::translate("SegyFileForm", "Value", Q_NULLPTR));
        traceTabWidget->setTabText(traceTabWidget->indexOf(binaryHeaders), QApplication::translate("SegyFileForm", "Trace Header", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem47 = traceDataTable->horizontalHeaderItem(0);
        ___qtablewidgetitem47->setText(QApplication::translate("SegyFileForm", "Interval", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem48 = traceDataTable->horizontalHeaderItem(1);
        ___qtablewidgetitem48->setText(QApplication::translate("SegyFileForm", "Value", Q_NULLPTR));
        traceTabWidget->setTabText(traceTabWidget->indexOf(traceData), QApplication::translate("SegyFileForm", "Trace Data", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SegyFileForm: public Ui_SegyFileForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEGYFILEFORM_H
