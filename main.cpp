#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <vector>
#include <list>
#include "Systems\enemies.h"
#include "Systems\Combat.h"
#include "Branches/intro.h"
using namespace std;

int main()
{
	
	cout << "InitialCode" << endl;

	Enemies testEnemy;
	Player testPlayer;
	intro(testPlayer);

	// combat(testPlayer, testEnemy);

	string noQuit;
	cin >> noQuit;
	return 0;
}