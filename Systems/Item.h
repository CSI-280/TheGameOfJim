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
#include "Player.h"
#include "Rand-Num.h"
using namespace std;


class Item 
{
private:
	//String that dictates the type of item
	//Example Types - "HeadArmor", "BodyArmor", "LegArmor", "Weapon", "Key"
	string mName, mDescription, mItemType;
	int mAttack, mDefense, mHealing, mLevel;
public:

	void setName(string name) { mName = name; }
	void setDescription(string description) { mDescription = description; }
	void setType(string type) { mItemType = type; }
	void setAttack(int attack) { mAttack = attack; }
	void setDefense(int defense) { mDefense = defense; }
	void setHealing(int healing) { mHealing = healing; }
	void setLevel(int level) { mLevel = level;  }

	void generateRandomItem(int playerLevel) 
	{
		//Random Item from any category
		int Rand = random(3);
		if (Rand == 3) {
			if (playerLevel < 3) { playerLevel = 3; }
			int Rand2 = random(playerLevel, playerLevel - 2);
			setLevel(Rand2);
			setDefense(Rand2 * 10);
			setName("Shirt");
			setDescription("Just an ordinary shirt.");
			setType("BodyArmor");
		}
		else if (Rand == 2) {
			//This may need to be changed for it to properly scale
			if (playerLevel < 3) { playerLevel = 3; }
			int Rand2 = random(playerLevel, playerLevel - 2);
			setLevel(Rand2);
			setAttack(Rand2 * 100);
			setName("Rusty Sword");
			setDescription("Sword covered in rust. \nIt's probably been sitting there for a long time.");
			setType("Weapon");
		}
		else {
			if (playerLevel < 3) { playerLevel = 3; }
			int Rand2 = random(playerLevel, playerLevel - 2);
			setLevel(Rand2);
			setHealing(Rand2 * 25);
			setName("Half Eaten Cookie");
			setDescription("Saved it for later!");
			setType("Consumable");
		}
	}

	string getDescription() { return mDescription; };
	string getName() { return mName; };
	string getType() { return mItemType; };
	int getAttack() { return mAttack; }
	int getDefense() { return mDefense; }
	int getHealing() { return mHealing; }
	int getLevel() { return mLevel; }

	Item() {
		//Default to be overwritten, or potentially as placeholders in inventory
		setName("Default");
		setDescription("Empty Slot");
		setType("Default");
		setAttack(0);
		setDefense(0);
		setHealing(0);
		setLevel(0);
	}

	Item(string name, string description, string type, int attack, int defense, int healing, int level) {
		//This should let people create custom items
		setName(name);
		setDescription(description);
		setType(type);
		setAttack(attack);
		setDefense(defense);
		setHealing(healing);
		setLevel(level);
	}


};