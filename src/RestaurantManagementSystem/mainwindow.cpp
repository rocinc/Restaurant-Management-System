#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "deskwindow.h"
#include "orderwindow.h"
#include "stockwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_stockbutton_clicked()
{
    stockwindow *w=new stockwindow();
    w->show();
    this->close();
}


void MainWindow::on_pushButton_3_clicked()
{
    orderwindow *w=new orderwindow();
    w->show();
    this->close();
}


void MainWindow::on_pushButton_7_clicked()
{
    deskwindow *w=new deskwindow();
    w->show();
    this->close();
}

void MainWindow::on_pushButton_4_clicked()
{

}
