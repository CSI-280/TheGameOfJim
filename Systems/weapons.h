#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Item.h"

using namespace std;

class Weapons : public Item
{
public:
	//constructor and destructor
	Weapons() {
		int level = Player::getPlayerLevel();//This may need to be changed for it to properly scale
		if (level < 3) { level = 3; }
		int Rand = random(level, level - 2)
		setLevel(Rand);
		setAttack(Rand * 100);
		Item::setName("Rusty Sword");
		Item::setDescription("Sword covered in rust. \nIt's probably been sitting there for a long time.");
		Item::setType("Weapon");
	}

	Weapons(int level, int attack, string name, string description) {
		setLevel(level);
		setAttack(attack);
		Item::setName(name);
		Item::setDescription(description);
		Item::setType("Weapon");
	}

	~Weapons();

	//setters
	void setLevel(int level) { mLevel = level; }
	void setAttack(int attack) { mAttack = attack; }

	//getters
	int getLevel() { return mLevel; }
	int getAttack() { return mAttack; }
private:
	int mLevel, mAttack;
};