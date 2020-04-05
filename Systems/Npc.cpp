#include "Npc.h"
#include <iostream>
#include <string>

Npc::Npc()
{
	mName = "Name";
	mItem = Item();
}

Npc::Npc(string name, Item item)
{
	mName = name;
	mItem = item;
}

Npc::~Npc() {}

// getters
string Npc::getNpcName() { return mName; }

Item Npc::getNpcItem() { return mItem; }

// setters
void Npc::setNpcName(string name)
{
	mName = name;
}

void Npc::setNpcItem(Item item)
{
	mItem = item;
}

