#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Weapons.h"
#include "Consumables.h"
#include "Armor.h"
#include "questItem.h"
#include "Rand-Num.cpp"
#include "Player.h"
#include "main.cpp"
using namespace std;


class Item 
{
private:
	//String that dictates the type of item
	//Example Types - "HeadArmor", "BodyArmor", "LegArmor", "Weapon", "Key"
	string mName, mDescription, mItemType;
public:
	void setName(string name) { mName = name; }
	void setDescription(string description) { mDescription = description; }
	void setType(string type) { mItemType = type; }

	string getDescription() { return mDescription; }
	string getName() { return mName; }
	string getType() { return mItemType; };

	Item() {
		//Random Item from any category
		int Rand = random(3);
		if (Rand == 3) {
			Armor();
		}
		else if (Rand == 2) {
			Weapons();
		}
		else {
			Consumables();
		}


	}

	Item(string name, string description) {
		setName(name);
		setDescription(description);
	}
};