#ifndef MAINWINDOW_H
#include <QMainWindow>
#include <segyfileRevised.h>
#include <mergewizard.h>
#define MAINWINDOW_H


namespace Ui {
class MainWindow;
}
using namespace std;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int numOfWindowsOpen;
    MergeWizard *wiz;

private slots:
    void open();
    void close();
    void save();
    void saveAs();
    void merge();
    void closeWithTitleBar();
    void mergeDone();
};

#endif // MAINWINDOW_H
