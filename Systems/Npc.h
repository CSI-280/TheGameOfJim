#pragma once
#include <string>
#include "Item.h"

using namespace std;

class Npc {
private:
	string mName;
	Item mItem;
	// very basic dialogue for now
	string mDialogue;
public:
	Npc();
	Npc(string, Item, string);
	~Npc();

	// getters
	string getNpcName();
	Item getNpcItem();
	string getNpcDialogue();

	// setters
	void setNpcName(string);
	void setNpcItem(Item);
	void setNpcDialogue(string);

	void givePlayerItem(Inventory);

	void talk();
};