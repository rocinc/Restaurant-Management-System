#ifndef ORDERADDTASTE_H
#define ORDERADDTASTE_H

#include <QDialog>

namespace Ui {
class orderaddtaste;
}

class orderaddtaste : public QDialog
{
    Q_OBJECT

public:
    explicit orderaddtaste(QWidget *parent = nullptr);
    ~orderaddtaste();
    void startTimer(int interval = 100);

private slots:
    void on_buttonBox_accepted();
    void onFoodSearchTextChanged();

    void updateTimer();

    void handleCloseWindow();

private:
    Ui::orderaddtaste *ui;
    QTimer *timer;
signals:
    void itemAdded();
    void AddWindowClosed();
};

#endif // ORDERADDTASTE_H
