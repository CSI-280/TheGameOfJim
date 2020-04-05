#pragma once
#include <string>
#include "Item.h"

using namespace std;

class Npc {
private:
	string mName;
	Item mItem;
public:
	Npc();
	Npc(string, Item);
	~Npc();

	// getters
	string getNpcName();
	Item getNpcItem();

	// setters
	void setNpcName(string);
	void setNpcItem(Item);
};