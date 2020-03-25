#pragma once
#include "Item.h"

using namespace std;

class Inventory {
private:

	//Note the Item Class has not been created yet.
	Item PlayerInventory[15]; //Default Inventory Size of 15
	Item ActiveInventory[4]; // An array of the items the player has equipped [1 Weapon, 2 Head Armor, 3 Chest Armor, 4 Leg Armor]

public:
	Inventory();
	~Inventory();

	bool checkPlayerInventoryForItem(Item item);
	
	void removeItemFromPlayerInventory(Item item);
	bool addItemToPlayerInventory(Item item);

	int getPlayerInventorySize();
	int getActiveInventorySize();
};