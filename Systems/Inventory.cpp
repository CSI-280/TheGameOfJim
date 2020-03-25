#include "Inventory.h"
#include "Item.h"
#include <iostream>

using namespace std;

Inventory:Inventory() //Empty For Now - In Future player could have starting items.
{

}


Inventory::~Inventory() 
{

}

bool Inventory::checkPlayerInventoryForItem(Item item)
{
	//Loop over the inventory and return true if you find the item.
	for (int i = 0; i < PlayerInventory.size(); i++)
	{
		if (PlayerInventory[i] = item)
		{
			return true;
		}
	}

	return false;
}

//Searches for the item that is attempting to be removed. If it is not there it does nothing
//Otherwise the item is replaced with null
void Inventory::removeItemFromPlayerInventory(Item item)
{
	for (int i = 0; i < PlayerInventory.size(); i++)
	{
		if (PlayerInventory[i] = item)
		{
			PlayerInventory[i] = NULL;
		}
	}
}


//Adds the item to the inventory, returns true if successfull.
void Inventory::addItemToPlayerInventory(Item item)
{
	for (int i = 0; i < PlayerInventory.size(); i++)
	{
		if (PlayerInventory[i] = NULL)
		{
			PlayerInventory[i] = item;
			return true;
		}
	}

	return false;
}


int Inventory::getPlayerInventorySize() { return PlayerInventory.size(); }

int Inventory::getActiveInventorySize() { return ActiveInventory.size(); }
