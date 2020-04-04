#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QtCore>
#include "Battery.h"
#include "Frequency.h"
#include "Program.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pbPower_clicked();


    void on_pbDown_clicked();

    void on_pbUp_clicked();

    void on_pbOK_clicked();

    void on_pbRight_clicked();

    void on_pbLeft_clicked();

    void TimeSlot();

    void on_Electrode_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTime *time;
    Battery bat;
    Program prog;
    Frequency freq;
    bool state;
    bool electrode;
    int screen; //0 - off, 1 - Main Menu, 2 - Programs, 3 - Frequency 4  - Program Power Level 5 - Frequency Power Level 6- Time 7 - Session
    int selection; //0 - first option, 1 - second option etc.
    int FL, PL;
    int duration;
    int counter;
    int timededuct;
};

#endif // MAINWINDOW_H
