/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionClose;
    QAction *actionAnalize;
    QWidget *centralwidget;
    QTableWidget *tableDisplay;
    QPlainTextEdit *textEditor;
    QLabel *labelFileName;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1049, 601);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName("actionSave_As");
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName("actionClose");
        actionAnalize = new QAction(MainWindow);
        actionAnalize->setObjectName("actionAnalize");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableDisplay = new QTableWidget(centralwidget);
        if (tableDisplay->columnCount() < 3)
            tableDisplay->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableDisplay->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableDisplay->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableDisplay->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableDisplay->setObjectName("tableDisplay");
        tableDisplay->setGeometry(QRect(10, 30, 581, 511));
        tableDisplay->horizontalHeader()->setCascadingSectionResizes(false);
        tableDisplay->horizontalHeader()->setMinimumSectionSize(22);
        tableDisplay->horizontalHeader()->setDefaultSectionSize(193);
        tableDisplay->horizontalHeader()->setHighlightSections(true);
        tableDisplay->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableDisplay->horizontalHeader()->setStretchLastSection(false);
        tableDisplay->verticalHeader()->setVisible(true);
        tableDisplay->verticalHeader()->setHighlightSections(true);
        textEditor = new QPlainTextEdit(centralwidget);
        textEditor->setObjectName("textEditor");
        textEditor->setGeometry(QRect(600, 30, 441, 511));
        labelFileName = new QLabel(centralwidget);
        labelFileName->setObjectName("labelFileName");
        labelFileName->setGeometry(QRect(600, 0, 431, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1049, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName("menuOptions");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuOptions->addAction(actionAnalize);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Analizador Sintactico", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save As...", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_As->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        actionAnalize->setText(QCoreApplication::translate("MainWindow", "Analize", nullptr));
#if QT_CONFIG(shortcut)
        actionAnalize->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        QTableWidgetItem *___qtablewidgetitem = tableDisplay->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Stack", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableDisplay->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Input", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableDisplay->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Production", nullptr));
        labelFileName->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
