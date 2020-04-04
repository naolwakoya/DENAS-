#ifndef FREQUENCY_H
#define FREQUENCY_H

#include <string>
using namespace std;

class Frequency
{
	public:
		Frequency();
		~Frequency();
		void setFreq(int);
		void setPower(int);
        string getFreq();
		int getPower();

	private:
        string freqs[11] = {"1.0-9.9 Hz", "10 Hz", "20 Hz", "60 Hz", "77 Hz", "125 Hz",
                            "140 Hz", "200 Hz", "7710", "7720", "77AM"};
        string freq;
		int powerLevel;
};

#endif
