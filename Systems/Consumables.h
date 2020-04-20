#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Item.h"
#include "main.cpp"
using namespace std;
/*
class Consumables : public Item
{
public:
	//constructor and destructor
	Consumables() {
		int level = testPlayer.getPlayerLevel();
		if (level < 3) { level = 3; }
		int Rand = random(level, level - 2);
		setLevel(Rand);
		setHealing(Rand * 25);
		Item::setName("Half Eaten Cookie");
		Item::setDescription("Saved it for later!");
		Item::setType("Consumable");
	}

	Consumables(int level, int healing, string name, string description) {
		setLevel(level);
		setHealing(healing);
		Item::setName(name);
		Item::setDescription(description);
		Item::setType("Consumable");
	}

	~Consumables();

	//setters
	void setLevel(int level) { mLevel = level; }
	void setHealing(int healing) { mHealing = healing; }

	//getters
	int getLevel() { return mLevel; }
	int getHealing() { return mHealing; }
private:
	int mLevel, mHealing;
};
*/