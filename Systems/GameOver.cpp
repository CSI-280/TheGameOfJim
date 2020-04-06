#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

void gameOver() {

	string userInputContinue = ""

	// Tell the player that they died.
	cout << "\n Game Over, You Died.\n\n"

	// loop to contiue game
	while ( userInputContinue != "yes" or userInputContinue != "no" )
	{
		// Ask the player if they want to continue playing.
		cout << "Do you want to continue playing? yes or no\n"
		cin >> userInputContinue

		if ( userInputContinue == "yes" )
		{
			// Load old save state here.
		} 
		else if ( userInputContinue == "no" )
		{
			// Thank the player for playing.
			cout << "\n Thank you, for playing.\n"
		}
		else
		{
			// Handle input error.
			cout << "\n Wrong Input, Please type yes or no "
		}
	}
}


