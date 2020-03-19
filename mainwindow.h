#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_tbScreen_highlighted(const QString &arg1);

private:
    Ui::MainWindow *ui;
    bool state;
};

#endif // MAINWINDOW_H
