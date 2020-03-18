#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    state = false;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbPower_clicked()
{
    if (state == false){
        ui->tbScreen->setStyleSheet("background-color: rgb(255, 255, 255)");
        ui->tbScreen->setText("PROGRAMS \nFREQUENCY");
        ui->pbPower->setText("OFF");
        state = true;
    }
    else
    {
        ui->tbScreen->setStyleSheet("background-color: rgb(0, 0, 0)");
        ui->pbPower->setText("ON");
        state = false;
    }
}
