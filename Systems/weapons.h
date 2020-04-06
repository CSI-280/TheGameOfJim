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
		setLevel(1);
		setAttack(100);
		setName("Rusty Sword");
		setDescription("Sword covered in rust. \nIt's probably been sitting there for a long time.");
	}

	Weapons(int level, int attack, string name, string description) {
		setLevel(level);
		setAttack(attack);
		setName(name);
		setDescription(description);
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