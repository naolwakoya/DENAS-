#ifndef SESSION_H
#define SESSION_H

#include <string>
#include <QtCore>

class Session : public QObject
{
    Q_OBJECT

    public:
        Session(int, std::string, int);
        ~Session();

        QTimer *timer;

        int getDuration() const;
        int getPower() const;
        std::string getName() const;

        void beginTimer(); // begin timer with duration
        void pauseTimer(); // pause timer
        void endTimer(); // end timer

    public slots:
        void MySlot();

    private:
        int duration;
        int power;
        std::string name;
        int counter;
};

#endif // SESSION_H
