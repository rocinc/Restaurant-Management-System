#ifndef ORDERSTATUSEDIT_H
#define ORDERSTATUSEDIT_H

#include "orderdata.h"
#include <QDialog>

namespace Ui {
class orderstatusedit;
}

class orderstatusedit : public QDialog
{
    Q_OBJECT

public:
    explicit orderstatusedit(QWidget *parent = nullptr);
    ~orderstatusedit();
    void sendOrderNode(orderNode* n);
    void startTimer(int interval = 100);

private slots:
    void on_buttonBox_accepted();
    void updateTimer();
    void handleCloseWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::orderstatusedit *ui;
    QTimer *timer;
signals:
    void windowClosed();
};

#endif // ORDERSTATUSEDIT_H
