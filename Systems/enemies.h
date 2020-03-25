#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

class Enemies {

private:
	//armor MIGHT be a damage reduction based on level
	//mSpeed can dictate who attacks first and if the mSpeed is high enough, possibly the enemy can attack twice before the player
	int mHealth, mArmor, mSpeed, mAttack;
	string mName;


public:
	//constructors
	Enemies();
	Enemies(int, int, int, int, string);

	//destructor
	~Enemies();

	//getters
	int getSpeed() { return mSpeed; };
	int getArmor() { return mArmor; };
	int getHealth() { return mHealth; };
	int getAttack() { return mAttack; };
	string getName() { return mName; };

	//setters
	void setSpeed(int speed) { mSpeed = speed; };
	void setArmor(int armor) { mArmor = armor; };
	void setHealth(int health) { mHealth = health; };
	void setAttack(int attack) { mAttack = attack; };
	void setName(string name) { mName = name; };




};