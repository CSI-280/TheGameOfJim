#pragma once

using namespace std;

//NOT YET IMPLEMENTED
class Item 
{
private:
	//String that dictates the type of item
	//Example Types - "HeadArmor", "BodyArmor", "FeetArmor", "Sword", "Key"
	string itemType;
public:
	string name;

	string getType() { return itemType; };
};