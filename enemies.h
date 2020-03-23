#pragma once
#include  "main.cpp"

using namespace std;

class enemies {
Private:
	//armor MIGHT be a damage reduction based on level
	//speed can dictate who attacks first and if the speed is high enough, possibly the enemy can attack twice before the player
	int health, armor, speed;
	string name;

Public:
	int getSpeed();
	setSpeed(int);

	int getArmor();
	setArmor(int);

	int getHealth();
	setHealth(int);

	string getName();
	setName(string);

	attack(/*player class type*/);

};