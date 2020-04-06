#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Item.h"

using namespace std;

class Consumables : public Item
{
	//constructor and destructor
	Consumables() {
		setLevel(1);
		setHealing(10);
		setName("Half Eaten Cookie");
		setDescription("Saved it for later!");
	}

	Consumables(int level, int healing, string name, string description) {
		setLevel(level);
		setHealing(healing);
		setName(name);
		setDescription(description);
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