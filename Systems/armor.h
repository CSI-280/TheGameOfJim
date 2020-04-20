#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Item.h"
/*
using namespace std;

class Armor : public Item
{
public:
	//constructor and destructor
	Armor() {
		int level = Player::getPlayerLevel();
		int level = testPlayer.getPlayerLevel();
		if (level < 3) { level = 3; }
		int Rand = random(level, level - 2);
		setLevel(Rand);
		setDefense(Rand * 10);
		Item::setName("Shirt");
		Item::setDescription("Just an ordinary shirt.");
		Item::setType("Armor");
	}

	Armor(int level, int defense, string name, string description) {
		setLevel(level);
		setDefense(defense);
		Item::setName(name);
		setDescription(description);
		Item::setType("Armor");
	}

	~Armor();

	//setters
	void setLevel(int level) { mLevel = level; }
	void setDefense(int defense) { mDefense = defense; }

	//getters
	int getLevel() { return mLevel; }
	int getDefense() { return mDefense; }
private:
	int mLevel, mDefense;
};
*/