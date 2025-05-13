#ifndef VIPEDIT_H
#define VIPEDIT_H

#include "vipdata.h"
#include <QDialog>

namespace Ui {
class vipedit;
}

class vipedit : public QDialog
{
    Q_OBJECT

public:
    explicit vipedit(QWidget *parent = nullptr);
    ~vipedit();
    void startTimer(int interval = 100);
    void sendnode(vipNode *node);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void updateTimer();
    void handleCloseWindow();

    void on_buttonBox_accepted();

private:
    Ui::vipedit *ui;
    QTimer *timer;
signals:
    void windowClosed();
};

#endif // VIPEDIT_H
