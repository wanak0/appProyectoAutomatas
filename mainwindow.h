#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "sintactico.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Sintactico sintac;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionOpen_triggered();

    void on_actionClose_triggered();

    void on_actionAnalize_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
