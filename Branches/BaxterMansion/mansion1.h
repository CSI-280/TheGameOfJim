#pragma once
#include "..\..\Systems\Rooms.h"
#include "..\..\Systems\Item.h"
#include "..\..\Systems\Inventory.h"
#include "..\Example Branch\ExampleBranch.h"

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

//Item* BlandKey = new Item();
//Item* HealthPotion = new Item();

void initMansion(unordered_map<string, Room*>* Rooms, unordered_map<string, Link*>* Links, unordered_map<string, Container*>* Containers, Inventory* Inventory)
{
	//Initalize Data
	Room* decrepitedHall = new Room("Decrepited Hallway");
	Container* dustyTable = new Container("Dusty Table", Inventory, false, true);
	Container* lockedChest = new Container("Locked Chest", Inventory, false, true);
	EmptyLinkToRoom* elToDecrepitedHall = new EmptyLinkToRoom("Empty Link to Decrepited Hallway", decrepitedHall);
	EmptyLinkToContainer* elToDustyTable = new EmptyLinkToContainer("Empty Link to Dusty Table", dustyTable);
	BasicKeyCheck* LinkToLockedChest = new BasicKeyCheck("Basic Key Check to Locked Chest", lockedChest, Inventory);


	//Store Data in Maps
	(*Rooms).insert(pair<string, Room*>((*decrepitedHall).getName(), decrepitedHall));
	(*Containers).insert(pair<string, Container*>((*dustyTable).getName(), dustyTable));
	(*Containers).insert(pair<string, Container*>((*lockedChest).getName(), lockedChest));
	(*Links).insert(pair<string, Link*>((*elToDecrepitedHall).getName(), elToDecrepitedHall));
	(*Links).insert(pair<string, Link*>((*elToDustyTable).getName(), elToDustyTable));
	(*Links).insert(pair<string, Link*>((*LinkToLockedChest).getName(), LinkToLockedChest));

	//Connect Rooms with Links
	(*(*Rooms)["Decrepited Hallway"]).addLink((*Links)["Empty Link to Dusty Table"]);
	(*(*Rooms)["Decrepited Hallway"]).addLink((*Links)["Basic Key Check to Locked Chest"]);
	(*(*Containers)["Dusty Table"]).addLink((*Links)["Empty Link to Decrepited Hallway"]);
	(*(*Containers)["Locked Chest"]).addLink((*Links)["Empty Link to Decrepited Hallway"]);

	//Detailing
	(*(*Containers)["Dusty Table"]).addItems(BlandKey);
	(*(*Containers)["Locked Chest"]).addItems(HealthPotion);
	vector<string> RoomDescription;
	RoomDescription.push_back("You walk into the old, decrepited Hallway.");
	RoomDescription.push_back("The Hallway is covered in cobwebs, dust, and large amount of stains unknown substances.");
	RoomDescription.push_back("At the end of the Hallway there is a door with a large iron padlock keeping it shut,");
	RoomDescription.push_back("and next to it to your right is a table covered in a thick layer of dust.");
	RoomDescription.push_back("Similarly to the left of the door is a large wooden chest, locked with an almost exact copy of the lock on the door.");
	(*(*Rooms)["Decrepited Hallway"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Inspect the Table");
	RoomDescription.push_back("Inspect the Chest");
	(*(*Rooms)["Decrepited Hallway"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You open up the drawer of the table.");
	(*(*Containers)["Dusty Table"]).addContainerDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("That's all there is inside the table.");
	(*(*Containers)["Dusty Table"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You open up the chest.");
	(*(*Containers)["Locked Chest"]).addContainerDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("That's all there is inside the chest, kinda anti climatic but atleast it's useful.");
	(*(*Containers)["Locked Chest"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
}