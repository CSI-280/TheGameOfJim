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

using namespace std;

//NOT YET IMPLEMENTED
class Item 
{
private:
	//String that dictates the type of item
	//Example Types - "HeadArmor", "BodyArmor", "LegArmor", "Weapon", "Key"
	string mName, mDescription, itemType;
public:
	void setName(string name) { mName = name; }
	void setDescription(string description) { mDescription = description; }

	string getDescription() { return mDescription; }
	string getName() { return mName; }
	string getType() { return itemType; };

	Item() {
		setName("Common Key");
		setDescription("This may be able to open a box.")
	}

	Item(string name, string description) {
		setName(name);
		setDescription(description);
	}
};