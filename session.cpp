#include <sstream>
#include <iomanip>
#include <sstream>
#include <iomanip>
#include <QtCore>

#include "session.h"

Session::Session(int duration, std::string name, int power) {
    this -> duration = duration;
    this -> name = name;
    this -> power = power;
    counter = duration;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(MySlot()));

    timer->start(duration * 100);
}

Session::~Session() {
    qDebug() << "Session ended";
}

int Session::getDuration() const {
    return this -> duration;
}

int Session::getPower() const {
    return this -> power;
}

std::string Session::getName() const {
    return this -> name;
}

void Session::pauseOrResumeTimer() {
    if (timer->isActive()) {
        qDebug() << "Session active but going to pause";
        timer->stop();
    } else {
        qDebug() << "Session not active but will start again";
        timer->start();
    }
}

void Session::MySlot() {
    if (counter < 0) {
        delete this;
    } else {
        qDebug() << counter;
    }
    counter--;
}
