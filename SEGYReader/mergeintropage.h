#ifndef MERGEINTROPAGE_H
#include <QWizardPage>
#define MERGEINTROPAGE_H



namespace Ui {
class MergeIntroPage;
}

class MergeIntroPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit MergeIntroPage(QWidget *parent = 0);
    ~MergeIntroPage();

private:
    Ui::MergeIntroPage *ui;
};

#endif // MERGEINTROPAGE_H
