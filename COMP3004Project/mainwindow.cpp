#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    state = false;
    electrode = false;
    screen = 0;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbPower_clicked()
{
    Battery bTemp;  //new battery level stored in global variable
    bat = bTemp;
    if (state == false){
        if (bat.getLevel() > 30)
        {
            QString ms1 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4' "
                               " color='blue'><b>PROGRAMS</b></font><br><font size = '4'>FREQUENCY</font>").arg(bat.getLevel());
            ui->tbScreen->setStyleSheet("background-color: rgb(255, 255, 255)");
            ui->tbScreen->setText(ms1);
            ui->pbPower->setText("OFF");
            screen = 1;
            selection = 0;
            state = true;
            FL = 1;
            PL = 1;
            timededuct = 0;
        }
        else if (bat.getLevel() > 10 && bat.getLevel() < 40)
        {
            ui->tbScreen->setStyleSheet("background-color: rgb(255, 255, 255)");
            ui->tbScreen->setText("<p align= 'center'> PLEASE CHARGE DEVICE</p>");
            ui->pbPower->setText("OFF");
            screen = 8;
            state = true;
            FL = 1;
            PL = 1;
        }
    }
    else
    {
        ui->tbScreen->setStyleSheet("background-color: rgb(0, 0, 0)");
        ui->tbScreen->clear();
        ui->pbPower->setText("ON");
        screen = 0;
        state = false;
    }
}

void MainWindow::on_pbDown_clicked()
{
  if (state == true)
  {
    if(screen == 1) //main menu options
    {
        if (selection == 0)
        {
            QString ms2 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                  " PROGRAMS</font><br><font size = '4' color = 'blue'><b>FREQUENCY</b></font>").arg(bat.getLevel());
            ui->tbScreen->setText(ms2);
            selection = 1;
        }
    }
    if(screen == 2) //program menu options
    {
       if(selection == 0)
       {
            QString pr2 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                     " HAND</font><br><font color = 'blue' size = '4'><b>THROAT</b></font><font size = '4'><br>HEAD</font>").arg(bat.getLevel());
            ui->tbScreen->setText(pr2);
            selection = 1;
       }
       else if (selection == 1)
       {
           QString pr3 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                    " HAND</font><br><font size = '4'>THROAT</font><font color = 'blue' size = '4'><br><b>HEAD</b></font>").arg(bat.getLevel());
           ui->tbScreen->setText(pr3);
           selection = 2;
       }
    }
    if(screen == 3) //frequency menu options
    {
        if (selection == 0)
        {
            QString fs2 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                 "1.0-9.9 Hz</font><br><font color = 'blue' size = '4'><b>10 Hz </b></font><font size = '4'><br>20 Hz<br>60 Hz<br>77 Hz"
                                  " <br>125 Hz<br>140 Hz<br>200 Hz<br>7710 <br>7720 <br>77AM</font>").arg(bat.getLevel());
            ui->tbScreen->setText(fs2);
            selection = 1;
        }
        else if (selection == 1)
        {
            QString fs3 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                 "1.0-9.9 Hz</font><font size = '4'><br>10 Hz</font><font color = 'blue' size = '4'><br><b>20 Hz</b></font><br><font size = '4'>60 Hz<br>77 Hz"
                                  " <br>125 Hz<br>140 Hz<br>200 Hz<br>7710 <br>7720 <br>77AM</font>").arg(bat.getLevel());
            ui->tbScreen->setText(fs3);
            selection = 2;
        }
        else if (selection == 2)
        {
            QString fs4 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                 "1.0-9.9 Hz</font><font size = '4'><br>10 Hz</font><font size = '4'><br>20 Hz</font><br><font color = 'blue' size = '4'><b>60 Hz</b></font><br>"
                                  "<font size = '4'>77 Hz <br>125 Hz<br>140 Hz<br>200 Hz<br>7710 <br>7720 <br>77AM</font>").arg(bat.getLevel());
            ui->tbScreen->setText(fs4);
            selection = 3;
        }
        else if (selection == 3)
        {
            QString fs5 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                 "1.0-9.9 Hz</font><font size = '4'><br>10 Hz</font><font size = '4'><br>20 Hz</font><br><font size = '4'>60 Hz</font><br>"
                                  "<font color = 'blue' size = '4'><b>77 Hz </b></font><br><font size = '4'> 125 Hz<br>140 Hz<br>200 Hz<br>7710 <br>7720 <br>77AM</font>").arg(bat.getLevel());
            ui->tbScreen->setText(fs5);
            selection = 4;
        }
        else if (selection == 4)
        {
            QString fs6 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                 "1.0-9.9 Hz</font><font size = '4'><br>10 Hz</font><font size = '4'><br>20 Hz</font><br><font size = '4'>60 Hz</font><br>"
                                  "<font size = '4'>77 Hz</font><br><font color = 'blue' size = '4'><b> 125 Hz</b></font><br><font size = '4'>140 Hz<br>200 Hz<br>7710 "
                                  "<br>7720 <br>77AM</font>").arg(bat.getLevel());
            ui->tbScreen->setText(fs6);
            selection = 5;
        }
        else if (selection == 5)
        {
            QString fs7 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                 "1.0-9.9 Hz</font><font size = '4'><br>10 Hz</font><font size = '4'><br>20 Hz</font><br><font size = '4'>60 Hz</font><br>"
                                  "<font size = '4'>77 Hz</font><br><font size = '4'>125 Hz</font><br><font color = 'blue' size = '4'><b>140 Hz</b></font><br><font size = '4'>200 Hz<br>7710"
                                  " <br>7720 <br>77AM</font>").arg(bat.getLevel());
            ui->tbScreen->setText(fs7);
            selection = 6;
        }
        else if (selection == 6)
        {
            QString fs8 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                 "1.0-9.9 Hz</font><font size = '4'><br>10 Hz</font><font size = '4'><br>20 Hz</font><br><font size = '4'>60 Hz</font><br>"
                                  "<font size = '4'>77 Hz</font><br><font size = '4'>125 Hz</font><br><font size = '4'>140 Hz</font><br><font color = 'blue' size = '4'><b>200 Hz</b></font><br>"
                                  "<font size = '4'>7710 <br>7720 <br>77AM</font>").arg(bat.getLevel());
            ui->tbScreen->setText(fs8);
            selection = 7;
        }
        else if (selection == 7)
        {
            QString fs9 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                 "1.0-9.9 Hz</font><font size = '4'><br>10 Hz</font><font size = '4'><br>20 Hz</font><br><font size = '4'>60 Hz</font><br>"
                                  "<font size = '4'>77 Hz</font><br><font size = '4'>125 Hz</font><br><font size = '4'>140 Hz</font><br><font size = '4'>200 Hz</font><br>"
                                  "<font color = 'blue' size = '4'><b>7710 </b></font><font size = '4'><br>7720 <br>77AM</font>").arg(bat.getLevel());
            ui->tbScreen->setText(fs9);
            selection = 8;
        }
        else if (selection == 8)
        {
            QString fs10 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                 "1.0-9.9 Hz</font><font size = '4'><br>10 Hz</font><font size = '4'><br>20 Hz</font><br><font size = '4'>60 Hz</font><br>"
                                  "<font size = '4'>77 Hz</font><br><font size = '4'>125 Hz</font><br><font size = '4'>140 Hz</font><br><font size = '4'>200 Hz</font><br>"
                                  "<font size = '4'>7710</font><font color = 'blue' size = '4'><br><b>7720 </b></font><font size = '4'><br>77AM</font>").arg(bat.getLevel());
            ui->tbScreen->setText(fs10);
            selection = 9;
        }
        else if (selection == 9)
        {
            QString fs11 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                 "1.0-9.9 Hz</font><font size = '4'><br>10 Hz</font><font size = '4'><br>20 Hz</font><br><font size = '4'>60 Hz</font><br>"
                                  "<font size = '4'>77 Hz</font><br><font size = '4'>125 Hz</font><br><font size = '4'>140 Hz</font><br><font size = '4'>200 Hz</font><br>"
                                  "<font size = '4'>7710</font><font size = '4'><br>7720 </font><font color = 'blue' size = '4'><br><b>77AM</b></font>").arg(bat.getLevel());
            ui->tbScreen->setText(fs11);
            selection = 10;
        }
    }
  }
}

void MainWindow::on_pbUp_clicked()
{
    if (state == true)
    {
        if (screen == 1) //main menu options
        {
            if (selection == 1)
            {
                QString ms1 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4' "
                                     " color='blue'><b>PROGRAMS</b></font><br><font size = '4'>FREQUENCY</font>").arg(bat.getLevel());
                ui->tbScreen->setText(ms1);
                selection = 0;
            }
        }
        else if(screen == 2) //program menu options
        {
            if(selection == 1)
            {
                QString pr1 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4' "
                                     " color='blue'><b>HAND</b></font><br><font size = '4'>THROAT<br>HEAD</font>").arg(bat.getLevel());
                ui->tbScreen->setText(pr1);
                selection = 0;
            }
            else if(selection == 2)
            {
                QString pr2 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                         " HAND</font><br><font color = 'blue' size = '4'><b>THROAT</b></font><font size = '4'><br>HEAD</font>").arg(bat.getLevel());
                ui->tbScreen->setText(pr2);
                selection = 1;
            }
        }
        else if(screen == 3) //frequency menu options
        {
            if(selection == 1)
            {
                QString fs1 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4' "
                                     " color='blue'><b>1.0-9.9 Hz</b></font><br><font size = '4'>10 Hz <br>20 Hz<br>60 Hz<br>77 Hz"
                                      " <br>125 Hz<br>140 Hz<br>200 Hz<br>7710 <br>7720 <br>77AM</font>").arg(bat.getLevel());
                ui->tbScreen->setText(fs1);
                selection = 0;
            }
             else if(selection == 2)
            {
                QString fs2 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                     "1.0-9.9 Hz</font><br><font color = 'blue' size = '4'><b>10 Hz </b></font><font size = '4'><br>20 Hz<br>60 Hz<br>77 Hz"
                                      " <br>125 Hz<br>140 Hz<br>200 Hz<br>7710 <br>7720 <br>77AM</font>").arg(bat.getLevel());
                ui->tbScreen->setText(fs2);
                selection = 1;
            }
            else if (selection == 3)
            {
                QString fs3 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                     "1.0-9.9 Hz</font><font size = '4'><br>10 Hz</font><font color = 'blue' size = '4'><br><b>20 Hz</b></font><br><font size = '4'>60 Hz<br>77 Hz"
                                      " <br>125 Hz<br>140 Hz<br>200 Hz<br>7710 <br>7720 <br>77AM</font>").arg(bat.getLevel());
                ui->tbScreen->setText(fs3);
                selection = 2;
            }
            else if (selection == 4)
            {
                QString fs4 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                     "1.0-9.9 Hz</font><font size = '4'><br>10 Hz</font><font size = '4'><br>20 Hz</font><br><font color = 'blue' size = '4'><b>60 Hz</b></font><br>"
                                      "<font size = '4'>77 Hz <br>125 Hz<br>140 Hz<br>200 Hz<br>7710 <br>7720 <br>77AM</font>").arg(bat.getLevel());
                ui->tbScreen->setText(fs4);
                selection = 3;
            }
            else if (selection == 5)
            {
                QString fs5 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                     "1.0-9.9 Hz</font><font size = '4'><br>10 Hz</font><font size = '4'><br>20 Hz</font><br><font size = '4'>60 Hz</font><br>"
                                      "<font color = 'blue' size = '4'><b>77 Hz </b></font><br><font size = '4'> 125 Hz<br>140 Hz<br>200 Hz<br>7710 <br>7720 <br>77AM</font>").arg(bat.getLevel());
                ui->tbScreen->setText(fs5);
                selection = 4;
            }
            else if (selection == 6)
            {
                QString fs6 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                     "1.0-9.9 Hz</font><font size = '4'><br>10 Hz</font><font size = '4'><br>20 Hz</font><br><font size = '4'>60 Hz</font><br>"
                                      "<font size = '4'>77 Hz</font><br><font color = 'blue' size = '4'><b> 125 Hz</b></font><br><font size = '4'>140 Hz<br>200 Hz<br>7710 "
                                      "<br>7720 <br>77AM</font>").arg(bat.getLevel());
                ui->tbScreen->setText(fs6);
                selection = 5;
            }
            else if (selection == 7)
            {
                QString fs7 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                     "1.0-9.9 Hz</font><font size = '4'><br>10 Hz</font><font size = '4'><br>20 Hz</font><br><font size = '4'>60 Hz</font><br>"
                                      "<font size = '4'>77 Hz</font><br><font size = '4'>125 Hz</font><br><font color = 'blue' size = '4'><b>140 Hz</b></font><br><font size = '4'>200 Hz<br>7710"
                                      " <br>7720 <br>77AM</font>").arg(bat.getLevel());
                ui->tbScreen->setText(fs7);
                selection = 6;
            }
            else if (selection == 8)
            {
                QString fs8 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                     "1.0-9.9 Hz</font><font size = '4'><br>10 Hz</font><font size = '4'><br>20 Hz</font><br><font size = '4'>60 Hz</font><br>"
                                      "<font size = '4'>77 Hz</font><br><font size = '4'>125 Hz</font><br><font size = '4'>140 Hz</font><br><font color = 'blue' size = '4'><b>200 Hz</b></font><br>"
                                      "<font size = '4'>7710 <br>7720 <br>77AM</font>").arg(bat.getLevel());
                ui->tbScreen->setText(fs8);
                selection = 7;
            }
            else if (selection == 9)
            {
                QString fs9 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                     "1.0-9.9 Hz</font><font size = '4'><br>10 Hz</font><font size = '4'><br>20 Hz</font><br><font size = '4'>60 Hz</font><br>"
                                      "<font size = '4'>77 Hz</font><br><font size = '4'>125 Hz</font><br><font size = '4'>140 Hz</font><br><font size = '4'>200 Hz</font><br>"
                                      "<font color = 'blue' size = '4'><b>7710 </b></font><font size = '4'><br>7720 <br>77AM</font>").arg(bat.getLevel());
                ui->tbScreen->setText(fs9);
                selection = 8;
            }
            else if (selection == 10)
            {
                QString fs10 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4'> "
                                     "1.0-9.9 Hz</font><font size = '4'><br>10 Hz</font><font size = '4'><br>20 Hz</font><br><font size = '4'>60 Hz</font><br>"
                                      "<font size = '4'>77 Hz</font><br><font size = '4'>125 Hz</font><br><font size = '4'>140 Hz</font><br><font size = '4'>200 Hz</font><br>"
                                      "<font size = '4'>7710</font><font color = 'blue' size = '4'><br><b>7720 </b></font><font size = '4'><br>77AM</font>").arg(bat.getLevel());
                ui->tbScreen->setText(fs10);
                selection = 9;
            }
        }
    }
}

void MainWindow::on_pbOK_clicked()
{
    if (state == true)
    {
        if (screen == 1)
        {
            if (selection == 0)
            { //Programs screen
                screen = 2;
                selection = 0;
                QString pr1 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4' "
                                     " color='blue'><b>HAND</b></font><br><font size = '4'>THROAT<br>HEAD</font>").arg(bat.getLevel());
                ui->tbScreen->setText(pr1);
            }
            else
            { //Frequency screen
                screen = 3;
                selection = 0;
                QString fs1 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4' "
                                     " color='blue'><b>1.0-9.9 Hz</b></font><br><font size = '4'>10 Hz <br>20 Hz<br>60 Hz<br>77 Hz"
                                      " <br>125 Hz<br>140 Hz<br>200 Hz<br>7710 <br>7720 <br>77AM</font>").arg(bat.getLevel());
                ui->tbScreen->setText(fs1);
            }
        }
        else if(screen == 2)
        {//Program Power Level Screen
            prog.setProg(selection); //sets program
            screen = 4;
            QString pl = QString("<p align = 'right'><font size = '1'> %1% </font></p><p align = 'center'><font size = '4'>POWER LEVEL"
                                  "</font><br><font size = '6'> %2 </font></p>").arg(bat.getLevel()).arg(PL);
            ui->tbScreen->setText(pl);
        }
        else if(screen == 3)
        { //Frequency Power Level Screen
            freq.setFreq(selection); //sets selected frequency
            screen = 5;
            QString fl = QString("<p align = 'right'><font size = '1'> %1% </font></p><p align = 'center'><font size = '4'>POWER LEVEL"
                                  "</font><br><font size = '6'> %2 </font></p>").arg(bat.getLevel()).arg(FL);
            ui->tbScreen->setText(fl);
        }
        else if(screen == 4)
        {
            prog.setPower(PL); //sets power level of program
            screen = 6;
            selection = 0;
            QString time1 =QString("<p align = 'right'><font size = '1'> %1% </font></p><p align = 'center'><font size = '4'>TIME"
                            "</font><br><font size = '6'> 1:00 </font></p>").arg(bat.getLevel());
            ui->tbScreen->setText(time1);
        }
        else if(screen == 5)
        {
            freq.setPower(FL); //sets power level of frequency
            QString ms1 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4' "
                                 " color='blue'><b>PROGRAMS</b></font><br><font size = '4'>FREQUENCY</font>").arg(bat.getLevel());
            ui->tbScreen->setText(ms1);
            screen = 1;
            selection = 0;
        }
        else if(screen == 6)
        {
            if (electrode == false)
            {
                ui->tbScreen->setText("<p align = 'center'>Please attach electrode</p>");
            }
            else
            {
                screen = 7;
                duration = (selection + 1)*60; // in seconds
                counter = duration;
                time = new QTime(0, duration / 60, 0);
                timer = new QTimer(this);
                connect(timer, SIGNAL(timeout()), this, SLOT(TimeSlot()));
                timer->start(1000);
            }
        }
        else if(screen == 8)
        {
            QString ms1 = QString("<p align= 'right'><font size = '1'> %1% </font></p><font size = '4' "
                                 " color='blue'><b>PROGRAMS</b></font><br><font size = '4'>FREQUENCY</font>").arg(bat.getLevel());
            ui->tbScreen->setText(ms1);
            screen = 1;
            selection = 0;
        }
    }
}

void MainWindow::on_pbRight_clicked()
{
    if (state == true)
    {
        if (screen == 4)
        {
            if(PL < 10)
            {
                PL++;
                QString pl = QString("<p align = 'right'><font size = '1'> %1% </font></p><p align = 'center'><font size = '4'>POWER LEVEL"
                                      "</font><br><font size = '6'> %2 </font></p>").arg(bat.getLevel()).arg(PL);
                ui->tbScreen->setText(pl);
            }
        }
        if (screen == 5)
        {
            if(FL < 10)
            {
                FL++;
                QString fl = QString("<p align = 'right'><font size = '1'> %1% </font></p><p align = 'center'><font size = '4'>POWER LEVEL"
                                      "</font><br><font size = '6'> %2 </font></p>").arg(bat.getLevel()).arg(FL);
                ui->tbScreen->setText(fl);
            }
        }
        if (screen == 6)
        {
            if (selection == 0)
            {
                QString time2 = QString("<p align = 'right'><font size = '1'> %1% </font></p><p align = 'center'><font size = '4'>TIME"
                                "</font><br><font size = '6'> 2:00 </font></p>").arg(bat.getLevel());
                ui->tbScreen->setText(time2);
                selection = 1;
            }
            else if (selection == 1)
            {
                QString time3 = QString("<p align = 'right'><font size = '1'> %1% </font></p><p align = 'center'><font size = '4'>TIME"
                                "</font><br><font size = '6'> 3:00 </font></p>").arg(bat.getLevel());
                ui->tbScreen->setText(time3);
                selection = 2;
            }
            else if (selection == 2)
            {
                QString time4 = QString("<p align = 'right'><font size = '1'> %1% </font></p><p align = 'center'><font size = '4'>TIME"
                                "</font><br><font size = '6'> 4:00 </font></p>").arg(bat.getLevel());
                ui->tbScreen->setText(time4);
                selection = 3;
            }
            else if (selection == 3)
            {
                QString time5 = QString("<p align = 'right'><font size = '1'> %1% </font></p><p align = 'center'><font size = '4'>TIME"
                                "</font><br><font size = '6'> 5:00 </font></p>").arg(bat.getLevel());
                ui->tbScreen->setText(time5);
                selection = 4;
            }
        }
    }
}

void MainWindow::on_pbLeft_clicked()
{
    if (state == true)
    {
       if (screen == 4)
        {
            if(PL > 1)
            {
                PL--;
                QString pl = QString("<p align = 'right'><font size = '1'> %1% </font></p><p align = 'center'><font size = '4'>POWER LEVEL"
                                      "</font><br><font size = '6'> %2 </font></p>").arg(bat.getLevel()).arg(PL);
                ui->tbScreen->setText(pl);
            }
        }
        else if (screen == 5)
        {
            if(FL > 1)
            {
                FL--;
                QString fl = QString("<p align = 'right'><font size = '1'> %1% </font></p><p align = 'center'><font size = '4'>POWER LEVEL"
                                      "</font><br><font size = '6'> %2 </font></p>").arg(bat.getLevel()).arg(FL);
                ui->tbScreen->setText(fl);
            }
        }
       else if (screen == 6)
       {
           if (selection == 1)
           {
               QString time1 = QString("<p align = 'right'><font size = '1'> %1% </font></p><p align = 'center'><font size = '4'>TIME"
                               "</font><br><font size = '6'> 1:00 </font></p>").arg(bat.getLevel());
               ui->tbScreen->setText(time1);
               selection = 0;
           }
          else if (selection == 2)
           {
               QString time2 = QString("<p align = 'right'><font size = '1'> %1% </font></p><p align = 'center'><font size = '4'>TIME"
                               "</font><br><font size = '6'> 2:00 </font></p>").arg(bat.getLevel());
               ui->tbScreen->setText(time2);
               selection = 1;
           }
           else if (selection == 3)
           {
               QString time3 = QString("<p align = 'right'><font size = '1'> %1% </font></p><p align = 'center'><font size = '4'>TIME"
                               "</font><br><font size = '6'> 3:00 </font></p>").arg(bat.getLevel());
               ui->tbScreen->setText(time3);
               selection = 2;
           }
           else if (selection == 4)
           {
               QString time4 = QString("<p align = 'right'><font size = '1'> %1% </font></p><p align = 'center'><font size = '4'>TIME"
                               "</font><br><font size = '6'> 4:00 </font></p>").arg(bat.getLevel());
               ui->tbScreen->setText(time4);
               selection = 3;
           }
       }
    }
}

void MainWindow::TimeSlot() {
    QTime t;
    t = time->addSecs(timededuct); //deduct time from timer display
    if (t.toString("h:m:ss") == "23:59:59") {
        timer->stop();
        ui->tbScreen->setText("Treatment complete!");
        qDebug() << "Session complete";
    }
    else if(state == false || electrode == false) { //if device switches off or electrode is off stop timer
        timer->stop();
        if (electrode == false)
            qDebug() << "Session paused";
        if (state == false)
            qDebug() << "Device shut off. Session stopped.";
    }
    else
    {
        if ((counter != duration) && (counter % 60) == 0 ) //if counter is at minute mark excluding start time
        {
            bat.drainLevel(freq.getPower(), prog.getPower());
            if(bat.getLevel() == 0) //when battery = 0 it shuts off
            {
                ui->tbScreen->setStyleSheet("background-color: rgb(0, 0, 0)");
                ui->tbScreen->clear();
                ui->pbPower->setText("ON");
                screen = 0;
                state = false;
            }
        }
        qDebug() << counter;
        counter--;
        timededuct--;
        QString p = QString::fromStdString(prog.getProg());
        QString f = QString::fromStdString(freq.getFreq()); //must convert strings to QStrings
        QString sTime = QString("<p align = 'right'><font size = '1'> %1% </font></p><p align = 'left'><font size = '4'> %2 Power Level: %3 <br> %4 Power Level: %5 </font></p>"
                                "<p align = 'center'><font size = '6'> %6 </font></p>").arg(bat.getLevel()).arg(p).arg(prog.getPower()).arg(f).arg(freq.getPower()).arg(t.toString("m:ss"));
        ui->tbScreen->setText(sTime);
        qDebug() << t.toString("m:ss");
    }

}

void MainWindow::on_Electrode_clicked()
{
    if (electrode == false)
    {
        ui->Electrode->setText("Electrode Attached");
        electrode = true;
        if (screen == 7)
        {
            timer->start();
            qDebug() << "Session resuming";
        }
    }
    else
    {
        ui->Electrode->setText("Electrode Detached");
        electrode = false;
    }
}
