#ifndef ORDERWINDOW_H
#define ORDERWINDOW_H

#include "orderdata.h"
#include <QDialog>
#include <qlayoutitem.h>
#include <qtablewidget.h>

namespace Ui {
class orderwindow;
}

typedef struct orderlistmodel
{
    QList<QTableWidgetItem *>* row;
    orderNode* currentnode;
}orderlistmodel;

class orderwindow : public QDialog
{
    Q_OBJECT

public:
    void freshlist();
    explicit orderwindow(QWidget *parent = nullptr);
    ~orderwindow();

private slots:
    void on_saveAndClose_clicked();

    void on_statusButton_clicked();

    void on_payButton_clicked();

    void on_displayAll_clicked();

    void on_displayWaiting_clicked();

    void on_displayEating_clicked();

    void on_floorBox_currentIndexChanged(int index);

    void on_areaBox_currentIndexChanged(int index);

    void on_deskBox_currentIndexChanged(int index);

    bool isCorrectWithDeskCombobox(orderNode *node);

    void on_vipPayButton_clicked();

private:
    Ui::orderwindow *ui;
    void openOrderCreateWindow();
    void fresh();
};

#endif // ORDERWINDOW_H
