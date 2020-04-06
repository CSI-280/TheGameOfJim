#include "Npc.h"
#include <iostream>
#include <string>
#include "Inventory.h"

Npc::Npc()
{
	mName = "Name";
	mItem = Item();
	mDialogue = "Dialogue"
}

Npc::Npc(string name, Item item, string dialogue)
{
	mName = name;
	mItem = item;
	mDialogue = dialogue
}

Npc::~Npc() {}

// getters
string Npc::getNpcName() { return mName; }

Item Npc::getNpcItem() { return mItem; }

string Npc::getNpcDialogue() { return mDialogue; }

// setters
void Npc::setNpcName(string name)
{
	mName = name;
}

void Npc::setNpcItem(Item item)
{
	mItem = item;
}

void Npc::setNpcDialogue(string dialogue)
{
	mDialogue = dialogue
}

// add npc's item to the player inventory
void Npc::givePlayerItem(Inventory PlayerInventory)
{
	cout << nName << " gives the player " << mItem << endl;
	PlayerInventory.addItemToPlayerInventory(mItem)
}

void Npc::talk()
{
	cout << mDialogue << endl;
}

