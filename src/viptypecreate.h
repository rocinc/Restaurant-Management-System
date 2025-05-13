#ifndef VIPTYPECREATE_H
#define VIPTYPECREATE_H

#include <QDialog>

namespace Ui {
class viptypecreate;
}

class viptypecreate : public QDialog
{
    Q_OBJECT

public:
    explicit viptypecreate(QWidget *parent = nullptr);
    ~viptypecreate();
    void startTimer(int interval = 100);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void updateTimer();
    void handleCloseWindow();

    void on_buttonBox_accepted();

private:
    Ui::viptypecreate *ui;
    QTimer *timer;
signals:
    void windowClosed();
};

#endif // VIPTYPECREATE_H
