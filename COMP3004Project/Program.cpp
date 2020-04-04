#include <iostream>
#include <string>

#include "Program.h"

Program::Program() {}

Program::~Program() {}

void Program::setProg(int x)
{
	prog = progs[x];
}

void Program::setPower(int PL)
{
	powerLevel = PL;
}

string Program::getProg()
{
	return prog;
}

int Program::getPower()
{
	return powerLevel;
}
	
