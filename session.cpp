#include <sstream>
#include <iomanip>
#include <QtCore>

#include "session.h"

Session::Session(int duration, std::string name, int power) {
    this -> duration = duration;
    this -> name = name;
    this -> power = power;
    counter = duration;
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

void Session::beginTimer() {
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(MySlot()));

    timer->start(duration * 100);
}

void Session::pauseTimer() {
    // some logic to drain battery
}

void Session::endTimer() {
    // some logic to drain battery
}

void Session::MySlot() {
    if (counter < 0) {
        delete this;
    } else {
        qDebug() << counter;
    }
    counter--;
}
