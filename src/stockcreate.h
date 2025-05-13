#ifndef STOCKCREATE_H
#define STOCKCREATE_H

#include <QDialog>
#include <qkeysequence.h>

namespace Ui {
class stockcreate;
}

class stockcreate : public QDialog
{
    Q_OBJECT

public:
    explicit stockcreate(QWidget *parent = nullptr);
    ~stockcreate();
    void startTimer(int interval = 100);

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
    Ui::stockcreate *ui;
    QTimer *timer;
signals:
    void itemAdded();
    void windowClosed();
};

#endif // STOCKCREATE_H
