#ifndef BATTERY_H
#define BATTERY_H


class Battery
{
        public:
                Battery();
                ~Battery();
                void drainLevel(int, int);
                int getLevel();

        private:
                int level;
};
#endif // BATTERY_H
