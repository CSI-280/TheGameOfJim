#include <iostream>
#include <ctime>
#include "Rand-Num.h"
using namespace std;

/* Multi is optional for if we want to have any system that multiplies the RNG, 
like say by player/enemy level or the something else. it and its options can be dropped 
if we decide we don't want to do that that.*/

int random(int max, int min, int multi)
{
	//If no minimum is given default to 1 for range
	if (min == 1) {
		//If no multiplier is given then we don't use any
		if (multi == 0) {
			int number = (rand() % max) + min;
			return number;
		}
		else {
			int number = (rand() % max) + min;
			int actNum = number * multi;
			return actNum;
		}
	}
	//If minimum is given then we calculate the range and use
	else {
		//If no multiplier is given then we don't use any
		if (multi == 0) {
			int range = max - min + 1;
			int number = rand() % range + min;
			return number;
		}
		else {
			int range = max - min + 1;
			int number = rand() % range + min;
			return number * multi;
		}
	}
	
}


/*Test to see how each stage works

int main() {
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		cout << random(25) << "\n";
	}
	cout << "Next TEST" << "\n";
	for (int i = 0; i < 10; i++) {
		cout << random(25, 10) << "\n";;
	}
	cout << "final TEST" << "\n";
	for (int i = 0; i < 10; i++) {
		cout << random(25, 10, 2) << "\n";;
	}
}
*/