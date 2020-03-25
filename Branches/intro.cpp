#include "intro.h"
#include "../Systems/Player.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

string playerName;
string returnPlayerName;
Player testPlay;

void intro(Player thePlayer)
{
	// Pause for dramatic effect
	sleep_for(seconds(1));

	// Friendly introduction
	cout << "\nWelcome to the life simulation. \n \n";

	sleep_for(seconds(2));

	// Explain the game
	cout << "You are going to be in control of a subject and pave how their life plays out. \n";
	sleep_for(seconds(3));
	cout << "Throughout their journey, you'll be given a list of choices, "
		<< "and choose what the subject does. \n \n";
		
	sleep_for(seconds(3));

	// Get player information
	cout << "But first, we need to name the subject you'll be in control of. \n";
	sleep_for(seconds(2));
	cout << "So what name do you want to give the subject? \n \n"
		;

	// Get name input from user and put into Player object
	cin >> playerName;
	thePlayer.setPlayerName(playerName);
	playerName = thePlayer.getPlayerName();
	
	// Judge the player's choice of name
	cout << "\n" << playerName << "? ";
	sleep_for(seconds(1));
	cout << "Really? ";
	sleep_for(seconds(2));
	cout << "That's an adequate choice for a name... ";
	sleep_for(seconds(2));
	cout << "I suppose. \n \n";
	sleep_for(seconds(3));
	cout << "Anyway, ";
	sleep_for(seconds(2));
	cout << "time for you to take control of " << playerName << "'s life, so let's transition to the simulation now. \n \n";
	sleep_for(seconds(3));

	// Transition to the story
	cout << "SIMULATION INITIATING IN \n \n";
	sleep_for(seconds(1));
	cout << "3 \n \n";
	sleep_for(seconds(1));
	cout << "2 \n \n";
	sleep_for(seconds(1));
	cout << "1 \n \n";
}


