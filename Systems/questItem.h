#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Item.h"

using namespace std;

class questItems : public Item
{
public:
	//we can make the default the first key to the first door, for now its just this
	questItems() {
		setName("Broken Key");
		setDescription("I doesn't seem to work on anything");
		setUse("N/A");
	}
	questItems(string use, string description, string name) {
		setName(name);
		setDescription(description);
		setUse(use);
	}

	//setters
	void setUse(string use) { mUse = use; }
	
	//getters
	string getUse() { return mUse; }
private:
	// Im not sure exactly how the quest items planned to be implemented, in the future we can thing about implementing a password based system,
	//each item we implement can have a password that makes it unique to a specific door.
	string mUse;
};