#ifndef ISLEDIALOG_H
#define ISLEDIALOG_H

#include <QDialog>
#include <string>

namespace Ui {
class IsLEDialog;
}
using namespace std;

class IsLEDialog : public QDialog
{
    Q_OBJECT

public:
    bool BE;
    explicit IsLEDialog( string _filename,QWidget *parent = 0);
    ~IsLEDialog();
public slots:
    void radiotoggled(bool);
//    void accept();
//    void reject();


private:
    string filename;
    Ui::IsLEDialog *ui;
};

#endif // ISLEDIALOG_H
