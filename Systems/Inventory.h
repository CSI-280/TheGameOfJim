#pragma once
#include "Item.h"

using namespace std;

class Inventory {
private:

	//Note the Item Class has not been created yet.
	Item PlayerInventory[15]; //Default Inventory Size of 15
	Item ActiveInventory[4]; // An array of the items the player has equipped [Weapon, HeadArmor, BodyArmor, LegArmor]

public:
	Inventory();
	~Inventory();

	bool checkPlayerInventoryForItem(Item item);
	int getIndexOfItem(Item item);
	Item getItem(int index);
	string getItemDesc(Item item)

	void getPlayerInventory();
	void swapInventorySpaces(Item item1, Item item2)

	void removeItemFromPlayerInventory(Item item);
	void addItemToPlayerInventory(Item item);

	int getPlayerInventorySize();
	int getActiveInventorySize();
};