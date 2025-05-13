#ifndef VIPWINDOW_H
#define VIPWINDOW_H

#include "vipdata.h"
#include <QDialog>
#include <qtablewidget.h>

void createNewVipType(viptype newtype);

namespace Ui {
class vipwindow;
}

typedef struct viplistmodel
{
    QList<QTableWidgetItem *>* row;
    vipNode* currentnode;
}viplistmodel;

class vipwindow : public QDialog
{
    Q_OBJECT

public:
    explicit vipwindow(QWidget *parent = nullptr);
    ~vipwindow();
    //vipNode* getVipList(int *hashlen);
    //viptype** getVipTypeList(int *arraylen);


private slots:
    void on_addButton_clicked();

    void on_saveAndExitButton_clicked();

    void on_deleteButton_clicked();

    void on_addVipButton_clicked();

    void on_editVipButton_clicked();

    void on_deleteVipButton_clicked();
    void SearchSuggestionClicking(const QString &text);

private:
    Ui::vipwindow *ui;
    void freshlist();
    void freshTypeListWithArray();
    void createNewVipType();
    void fresh();
};

#endif // VIPWINDOW_H
