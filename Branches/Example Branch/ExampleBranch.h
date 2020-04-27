#pragma once
#include "..\..\Systems\Rooms.h"

/*
void loadBranchExample(unordered_map<string, Room*> Rooms, unordered_map<string, Link*> Links, unordered_map<string, Container*> Containers)
{
	Room dummyRoom("DummyRoom");
	Rooms.insert(pair<string,Room>(dummyRoom.getName(), dummyRoom));
	//Link dummyLink("DummyLink", Rooms["DummyRoom"])
	//Links.insert(pair<string, Link>(dummyLink.getName(), dummyLink));
	//Rooms["DummyRoom"].addLink(Links["DummyLink"])
}
*/

Item* BlandKey = new Item();
Item* HealthPotion = new Item();

class EmptyLinkToRoom : public Link
{
public:
	EmptyLinkToRoom(string cName, Room* cRoom) : Link(cName, cRoom)
	{

	}

	bool checkConditions()
	{
		return true;
	}
};

class EmptyLinkToContainer : public Link
{
public:
	EmptyLinkToContainer(string cName, Container* cContainer) : Link(cName, cContainer)
	{

	}

	bool checkConditions()
	{
		return true;
	}
};

class BasicKeyCheck : public Link
{
private:
	Inventory* mTrackedInventory;
public:
	BasicKeyCheck(string cName, Container* cContainer, Inventory* cInventory) : Link(cName, cContainer)
	{
		mTrackedInventory = cInventory;
	}

	bool checkConditions()
	{
		if ((*mTrackedInventory).checkPlayerInventoryForItem(*BlandKey))
		{
			cout << "You Unlock the chest with the Key!" << endl;
			return true;
		}
		else
		{
			cout << "You can't open the chest without the key!" << endl;
			return false;
		}
	}
};

void initBoringBranch(unordered_map<string, Room*>* Rooms, unordered_map<string, Link*>* Links, unordered_map<string, Container*>* Containers, Inventory* Inventory)
{
	//Initalize Data
	(*BlandKey).setName("Bland Key");
	(*HealthPotion).setName("Health Potion");
	Room* boringShed = new Room("Boring Shed");
	Container* boringCrate = new Container("Boring Crate", Inventory, false, true);
	Container* boringChest = new Container("Boring Chest", Inventory, false, true);
	EmptyLinkToRoom* elToBoringShed = new EmptyLinkToRoom("Empty Link to Boring Shed", boringShed);
	EmptyLinkToContainer* elToBoringCrate = new EmptyLinkToContainer("Empty Link to Boring Crate", boringCrate);
	BasicKeyCheck* LinkToBoringChest = new BasicKeyCheck("Basic Key Check to Boring Chest", boringChest, Inventory);

	//Store Data in Maps
	(*Rooms).insert(pair<string, Room*>((*boringShed).getName(), boringShed));
	(*Containers).insert(pair<string, Container*>((*boringCrate).getName(), boringCrate));
	(*Containers).insert(pair<string, Container*>((*boringChest).getName(), boringChest));
	(*Links).insert(pair<string, Link*>((*elToBoringShed).getName(), elToBoringShed));
	(*Links).insert(pair<string, Link*>((*elToBoringCrate).getName(), elToBoringCrate));
	(*Links).insert(pair<string, Link*>((*LinkToBoringChest).getName(), LinkToBoringChest));

	//Connect Rooms with Links
	(*(*Rooms)["Boring Shed"]).addLink((*Links)["Empty Link to Boring Crate"]);
	(*(*Rooms)["Boring Shed"]).addLink((*Links)["Basic Key Check to Boring Chest"]);
	(*(*Containers)["Boring Crate"]).addLink((*Links)["Empty Link to Boring Shed"]);
	(*(*Containers)["Boring Chest"]).addLink((*Links)["Empty Link to Boring Shed"]);

	//Detailing
	(*(*Containers)["Boring Crate"]).addItems(BlandKey);
	(*(*Containers)["Boring Chest"]).addItems(BlandKey);
	vector<string> RoomDescription;

	RoomDescription.push_back("You walk into the shed.");
	RoomDescription.push_back("The shed is completely barren except for a single table.");
	RoomDescription.push_back("On the Table is a simple looking wooden crate");
	RoomDescription.push_back("and a bland wooden chest, locked with a sturdy iron padlock.");
	(*(*Rooms)["Boring Shed"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();

	RoomDescription.push_back("Inspect the Crate");
	RoomDescription.push_back("Inspect the Chest");
	(*(*Rooms)["Boring Shed"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();

	RoomDescription.push_back("You open up the crate.");
	(*(*Containers)["Boring Crate"]).addContainerDescription(RoomDescription);
	RoomDescription.clear();

	RoomDescription.push_back("Stop Looking at the Crate.");
	(*(*Containers)["Boring Crate"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();

	RoomDescription.push_back("You open up the chest.");
	(*(*Containers)["Boring Chest"]).addContainerDescription(RoomDescription);
	RoomDescription.clear();

	RoomDescription.push_back("Stop Looking at the Chest.");
	(*(*Containers)["Boring Chest"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
}