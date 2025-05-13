#ifndef VIPCREATE_H
#define VIPCREATE_H

#include <QDialog>

namespace Ui {
class vipcreate;
}

class vipcreate : public QDialog
{
    Q_OBJECT

public:
    explicit vipcreate(QWidget *parent = nullptr);
    ~vipcreate();
    void startTimer(int interval = 100);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void updateTimer();
    void handleCloseWindow();

    void on_buttonBox_accepted();

private:
    Ui::vipcreate *ui;
    QTimer *timer;
signals:
    void windowClosed();
};

#endif // VIPCREATE_H
