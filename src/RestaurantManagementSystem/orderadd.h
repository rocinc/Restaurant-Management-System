#ifndef ORDERADD_H
#define ORDERADD_H

#include <QDialog>

namespace Ui {
class orderadd;
}

class orderadd : public QDialog
{
    Q_OBJECT

public:
    explicit orderadd(QWidget *parent = nullptr);
    ~orderadd();
    void startTimer(int interval = 100);


private slots:
    void updateTimer();

    void on_buttonBox_rejected();
    void handleCloseWindow();

    void on_buttonBox_accepted();
    void on_floorTextBox_currentIndexChanged(int index);
    void on_areaTextBox_currentIndexChanged(int index);
    int* readAreasWithDesks(const char* fileName, int floor, int* outCount);
    int* readDesksWithArea(const char* fileName, int floor, int area, int* outCount);
    void on_deskTextBox_currentIndexChanged(int index);

    void on_addButton_clicked();
    void freshdishes();
    void newdish();

    void on_deleteButton_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::orderadd *ui;
    QTimer *timer;
    void addRow(char *name, char *taste, int count);
signals:
    void itemAdded();
    void windowClosed();
};

#endif // ORDERADD_H
