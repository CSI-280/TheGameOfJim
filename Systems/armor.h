#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Item.h"

using namespace std;

class Armor : public Item
{
public:
	//constructor and destructor
	Armor() {
		setLevel(1);
		setDefense(10);
		setName("Shirt");
		setDescription("Just an ordinary shirt.");
	}

	Armor(int level, int defense, string name, string description) {
		setLevel(level);
		setDefense(defense);
		setName(name);
		setDescription(description);
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