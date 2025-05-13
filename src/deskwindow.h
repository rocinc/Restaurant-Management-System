#ifndef DESKWINDOW_H
#define DESKWINDOW_H

#include <QDialog>
#include <qtreewidget.h>

namespace Ui {
class deskwindow;
}

class deskwindow : public QDialog
{
    Q_OBJECT

public:
    explicit deskwindow(QWidget *parent = nullptr);
    ~deskwindow();

private slots:
    void on_pushButton_clicked();

    void on_addbutton_clicked();
    int getItemLevel(QTreeWidgetItem* item);

    void on_addParallelbutton_clicked();
    void updateItemNumbers(QTreeWidgetItem *parent);

    void on_deletebutton_clicked();

    void on_saveButton_clicked();
    void freshlist();
    void expandAllItems(QTreeWidget *treeWidget);
    void expandAllChildItems(QTreeWidgetItem *item);


    void on_seeDetailsButton_clicked();

private:
    Ui::deskwindow *ui;
};

#endif // DESKWINDOW_H
