#include "Inventory.h"
#include "Item.h"
#include <iostream>

using namespace std;

Inventory::Inventory() //Empty For Now - In Future player could have starting items.
{

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
	for (int i = 0; i < PlayerInventory.size(); i++)
	{
		if (PlayerInventory[i] = item)
		{
			return true;
		}
	}

	return false;
}

//Gets the index of an Item
int getIndexOfItem(Item item)
{
	for (int i = 0; i < PlayerInventory.size(); i++)
	{
		if (PlayerInventory[i] = item)
		{
			return i;
		}
	}
	return null;
}

string Inventory::getItemDesc(Item item)
{
	errorstring = "No such item is in your inventory"
	for (int i = 0; i < PlayerInventory.size(); i++)
	{
		if (PlayerInventory[i] = item)
		{
			descrption = PlayerInventory[i].getDescription()
			return description;
		}
	}
	return errorstring;
}

void Inventory::getPlayerInventory()
{
	string inventory = ""
	for (int i = 0; i < PlayerInventory.size(); i++)
	{
		//if end of inventory simply add last item
		if (i == (PlayerInventory.size() - 1) {
			inventory += PlayerInventory[i].getName()
		}
		//if not end of inventory add item name and comma for next item
		else {
			inventory += PlayerInventory[i].getName() + ", "
		}
	}
	//print out string containing full inventory item names
	cout << "Current Inventory: " << inventory << "."
}

//This is going on the assumption that these items are in fact in the inventory
//but their indexes are unkown
void Inventory::swapInventorySpaces(Item item1, Item item2) {
	//temporary holder for item when switching
	Item temp;
	int index1;
	int index2;
	//for loop for finding item's index numbers 
	for (int i = 0; i < PlayerInventory.size(); i++)
	{
		if (PlayerInventory[i] = item1)
		{
			index1 = i;
		}
		else if (PlayerInventory[i] = item2)
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
	for (int i = 0; i < PlayerInventory.size(); i++)
	{
		if (PlayerInventory[i] = item)
		{
			PlayerInventory[i] = NULL;
		}
	}
}

//Adds the item to the inventory
void Inventory::addItemToPlayerInventory(Item item)
{
	for (int i = 0; i < PlayerInventory.size(); i++)
	{
		if (PlayerInventory[i] = NULL)
		{
			PlayerInventory[i] = item;
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

int Inventory::getPlayerInventorySize() { return PlayerInventory.size(); }

int Inventory::getActiveInventorySize() { return ActiveInventory.size(); }
