#include "Inventory.h"
#include "Item.h"
#include <iostream>

using namespace std;

Inventory::Inventory() //Empty For Now - In Future player could have starting items.
{
	Item defaultItem;

	for (int i = 0; i <= 14; i++)
		PlayerInventory[i] = defaultItem; // This sets all slots to be empty, all having a name of default
										  // This is required for the current addItemToPlayerInventory code
}

Inventory::~Inventory() 
{

}

Item Inventory::getItem(int index)
{
	return PlayerInventory[index];
}

bool Inventory::checkPlayerInventoryForItem(Item item)
{
	//Loop over the inventory and return true if you find the item.
	for (int i = 0; i < getPlayerInventorySize(); i++)
	{
		if (PlayerInventory[i].getName() == item.getName())
		{
			return true;
		}
	}

	return false;
}

//Gets the index of an Item
int Inventory::getIndexOfItem(Item item)
{
	for (int i = 0; i < getPlayerInventorySize(); i++)
	{
		if (PlayerInventory[i].getName() == item.getName())
		{
			return i;
		}
	}
	return NULL;
}

string Inventory::getItemDesc(Item item)
{
	string errorstring = "No such item is in your inventory";
	for (int i = 0; i < getPlayerInventorySize(); i++)
	{
		if (PlayerInventory[i].getName() == item.getName())
		{
			string description = PlayerInventory[i].getDescription();
			return description;
		}
	}
	return errorstring;
}

void Inventory::getPlayerInventory()
{
	string inventory = "";
	for(int i = 0; i < getPlayerInventorySize(); i++)
	{
		//if end of inventory simply add last item
		if (i == (getPlayerInventorySize() - 1))
		{
			inventory += PlayerInventory[i].getName();
		}
		//if not end of inventory add item name and comma for next item
		else 
		{
			inventory += PlayerInventory[i].getName() + ", ";
		}
	}
	//print out string containing full inventory item names
	cout << "Current Inventory: " << inventory << ".";
}

//This is going on the assumption that these items are in fact in the inventory
//but their indexes are unkown
void Inventory::swapInventorySpaces(Item item1, Item item2) {
	//temporary holder for item when switching
	Item temp;
	int index1;
	int index2;
	//for loop for finding item's index numbers 
	for (int i = 0; i < getPlayerInventorySize(); i++)
	{
		if (PlayerInventory[i].getName() == item1.getName())
		{
			index1 = i;
		}
		else if (PlayerInventory[i].getName() == item2.getName())
		{
			index2 = i;
		}
	}
	temp = PlayerInventory[index1];
	PlayerInventory[index1] = PlayerInventory[index2];
	PlayerInventory[index2] = temp;
}

//Searches for the item that is attempting to be removed. If it is not there it does nothing
//Otherwise the item is replaced with null
void Inventory::removeItemFromPlayerInventory(Item item)
{
	for (int i = 0; i < getPlayerInventorySize(); i++)
	{
		if (PlayerInventory[i].getName() == item.getName())
		{
			Item newItem = new Item();
			PlayerInventory[i] = newItem;
		}
	}
}

//Adds the item to the inventory
void Inventory::addItemToPlayerInventory(Item item)
{
	for (int i = 0; i < getPlayerInventorySize(); i++)
	{
		if (PlayerInventory[i].getName() == "Default")
		{
			PlayerInventory[i] = item;
			break;
		}
	}
}

void Inventory::swapIntoActiveInventory(int activeIndex, int playerIndex)
{
	//Items you are swapping
	Item activeItem = ActiveInventory[activeIndex];
	Item playerItem = PlayerInventory[playerIndex];
	
	//This is the type of slot that you are attempting to swap into.
	string reqType;
	if (activeIndex == 0)
	{
		reqType = "Weapon";
	}
	if (activeIndex == 1)
	{
		reqType = "HeadArmor";
	}
	if (activeIndex == 2)
	{
		reqType = "BodyArmor";
	}
	if (activeIndex == 3)
	{
		reqType = "LegArmor";
	}

	//If the type of the slot you are swaping into to is the same
	//the item you are swaping in, then swap. Otherwise dont do anything.
	if (activeItem.getType() == reqType)
	{
		ActiveInventory[activeIndex] = playerItem;
		PlayerInventory[playerIndex] = activeItem;
	}
}

int Inventory::getPlayerInventorySize() { return PlayerInventorySize; }

int Inventory::getActiveInventorySize() { return ActiveInventorySize; }
