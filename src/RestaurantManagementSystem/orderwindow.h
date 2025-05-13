#ifndef ORDERWINDOW_H
#define ORDERWINDOW_H

#include "orderdata.h"
#include <QDialog>
#include <qstandarditemmodel.h>

namespace Ui {
class orderwindow;
}

typedef struct orderlistmodel
{
    QList<QStandardItem *>* row;
    orderNode* currentnode;
}orderlistmodel;

class orderwindow : public QDialog
{
    Q_OBJECT

public:
    void freshlist();
    explicit orderwindow(QWidget *parent = nullptr);
    ~orderwindow();
    QStandardItemModel *model;

private slots:
    void on_saveAndClose_clicked();

private:
    Ui::orderwindow *ui;
    void openOrderCreateWindow();
    void fresh();
};

#endif // ORDERWINDOW_H
