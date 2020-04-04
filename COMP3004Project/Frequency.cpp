#include <iostream>
#include <string>
#include "Frequency.h"

Frequency::Frequency()
{
	freq = freqs[0];
    powerLevel = 1;
}

Frequency::~Frequency() {}

void Frequency::setFreq(int x)
{
	freq = freqs[x];
}

void Frequency::setPower(int FL)
{
	powerLevel = FL;
}

string Frequency::getFreq()
{
	return freq;
}

int Frequency::getPower()
{
	return powerLevel;
}
