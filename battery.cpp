#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Battery.h"

Battery::Battery() //constructor
{
        srand( (unsigned)time(NULL) );
        level = ((rand() % 10) + 1)*10; //battery is set at multiple of 10 from 1 - 10
}

Battery::~Battery() {}

void Battery::drainLevel(int FL, int PL)
{
        level -= (FL + PL) / 2; //battery is drained by sum of power levels divided by 2
}

int Battery::getLevel()
{
        return level;
}
