#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
using namespace std;

class Program
{
	public:
		Program();
		~Program();
		void setProg(int);
		void setPower(int);
		string getProg();
		int getPower();
	
	private:
		string progs[3] = {"HEAD", "THROAT", "HAND"};
		string prog;
		int powerLevel;
};

#endif
