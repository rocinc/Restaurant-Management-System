#ifndef STOCKWINDOW_H
#define STOCKWINDOW_H

#include "stockcreate.h"
#include "stockdata.h"
#include <QCloseEvent>
#include <QWidget>
#include <qmessagebox.h>
#include <qstandarditemmodel.h>
#include <qtablewidget.h>
#include <qtimer.h>

namespace Ui {
class stockwindow;
}

typedef struct listmodel
{
    QList<QTableWidgetItem *>* row;
    Node* currentnode;
}listmodel;

class stockwindow : public QWidget
{
    Q_OBJECT

public:
    explicit stockwindow(QWidget *parent = nullptr);
    ~stockwindow();

    void freshlist();

    Ui::stockwindow *ui;

private slots:

    void on_stockwindow_destroyed(QObject *arg1);

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void testf();
    void openStockCreateWindow();

    void on_pushButton_4_clicked();

    void on_setSequenceCombobox_currentIndexChanged(int index);

    void on_radioButton_clicked();

    void on_radioButton_3_clicked();

    int sortonce(listmodel *list, int left, int right, int upordown, int what);
    void sort(listmodel* list,int left,int right,int upordown,int what);

    void on_radioButton_4_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_5_clicked();

    void on_pushButton_5_clicked();
    void clicking(const QString &text);

protected:
    //关闭窗口时执行函数
    void closeEvent(QCloseEvent *event) override {
        event->accept();
    }
};



#endif // STOCKWINDOW_H
