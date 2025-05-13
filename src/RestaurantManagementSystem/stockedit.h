#ifndef STOCKEDIT_H
#define STOCKEDIT_H

#include "stockdata.h"
#include <QDialog>
#include <qstandarditemmodel.h>

namespace Ui {
class stockedit;
}

class stockedit : public QDialog
{
    Q_OBJECT

public:
    explicit stockedit(QWidget *parent = nullptr);
    ~stockedit();
    void startTimer(int interval = 100);
    void sendNode(Node* n);

private slots:
    void on_buttonBox_accepted();

    void on_stockcreate_destroyed();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void updateTimer();

    void on_buttonBox_rejected();
    void handleCloseWindow();

    void on_pushButton_3_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::stockedit *ui;
    QTimer *timer;
signals:
    void itemAdded();
    void windowClosed();
};

#endif // STOCKEDIT_H
