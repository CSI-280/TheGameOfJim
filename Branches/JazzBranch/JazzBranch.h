#pragma once
#include "..\..\Systems\Rooms.h"
#include "..\..\Systems\Item.h"
#include "..\..\Systems\Inventory.h"

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

Item* ramenNoodles = new Item();
Item* candyBar = new Item();
Item* magazine = new Item();

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

void initJazzBranch(unordered_map<string, Room*>* Rooms, unordered_map<string, Link*>* Links, unordered_map<string, Container*>* Containers, Inventory* Inventory)
{
	//Initalize Data
	(*ramenNoodles).name = "Ramen Noodles";
	(*candyBar).name = "Candy Bar";
	(*magazine).name = "Magazine";

	Room* convenienceStore = new Room("Convenience Store");
	Room* dustyShed = new Room("Dusty Shed");
	Room* townPlaza = new Room("Town Plaza");
	Room* castleCourtyard = new Room("Castle Courtyard");

	EmptyLinkToRoom* elToConvenienceStore = new EmptyLinkToRoom("Empty Link to Convenience Store", convenienceStore);
	EmptyLinkToRoom* elToDustyShed = new EmptyLinkToRoom("Empty Link to Dusty Shed", dustyShed);
	EmptyLinkToRoom* elToTownPlaza = new EmptyLinkToRoom("Empty Link to Town Plaza", townPlaza);
	EmptyLinkToRoom* elToCastleCourtyard = new EmptyLinkToRoom("Empty Link to Castle Courtyard", castleCourtyard);

	//Store Data in Maps
	(*Rooms).insert(pair<string, Room*>((*convenienceStore).getName(), convenienceStore));
	(*Rooms).insert(pair<string, Container*>((*dustyShed).getName(), dustyShed));
	(*Rooms).insert(pair<string, Container*>((*townPlaza).getName(), townPlaza));
	(*Rooms).insert(pair<string, Link*>((*castleCourtyard).getName(), castleCourtyard));

	(*Links).insert(pair<string, Link*>((*elToConvenienceStore).getName(), elToConvenienceStore));
	(*Links).insert(pair<string, Link*>((*elToDustyShed).getName(), elToDustyShed));
	(*Links).insert(pair<string, Link*>((*elToTownPlaza).getName(), elToTownPlaza));
	(*Links).insert(pair<string, Link*>((*elToCastleCourtyard).getName(), elToCastleCourtyard));

	//Connect Rooms with Links
	(*(*Rooms)["Convenience Store"]).addLink((*Links)["Empty Link to Dusty Shed"]);
	(*(*Rooms)["Convenience Store"]).addLink((*Links)["Empty Link to Town Plaza"]);
	(*(*Rooms)["Convenience Store"]).addLink((*Links)["Empty Link to Castle Courtyard"]);
	(*(*Rooms)["Dusty Shed"]).addLink((*Links)["Empty Link to Convenience Store"]);
	(*(*Rooms)["Town Plaza"]).addLink((*Links)["Empty Link to Convenience Store"]);
	(*(*Rooms)["Castle Courtyard"]).addLink((*Links)["Empty Link to Convenience Store"]);

	//Detailing
	vector<string> RoomDescription;
	RoomDescription.push_back("You walk into the convenience store.");
	RoomDescription.push_back("It's very clean and the shelves are well stocked.");
	RoomDescription.push_back("You inspect the isles and find three items worth checking out:");
	RoomDescription.push_back("some ramen noodles, a candy bar, and a magazine.");
	(*(*Rooms)["Convenience Store"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Pick up Ramen Noodles");
	RoomDescription.push_back("Pick up Candy Bar");
	RoomDescription.push_back("Pick up Magazine");
	(*(*Rooms)["Convenience Store"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You pick up the ramen noodles.");
	RoomDescription.push_back("Suddenly you see a dusty old shed with not much inside of it.");
	RoomDescription.push_back("The only thing of note is a small box on a work table and the door that leads outside.");
	(*(*Rooms)["Dusty Shed"]).addContainerDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Put back the ramen noodles.");
	(*(*Rooms)["Dusty Shed"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You pick up the candy bar.");
	RoomDescription.push_back("Suddenly you are viewing the hustle and bustle of a town plaza.");
	RoomDescription.push_back("The surroundings are very foreign to you, as if from another world.");
	(*(*Rooms)["Town Plaza"]).addContainerDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Put back the candy bar.");
	(*(*Containers)["Town Plaza"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You pick up the magazine.");
	RoomDescription.push_back("Suddenly you see a castle courtyard with multiple guards watching the main enterance.");
	RoomDescription.push_back("They seem friendly, but if you do anything suspicious their attitude will change fast.");
	(*(*Rooms)["Castle Courtyard"]).addContainerDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Put back the magazine.");
	(*(*Containers)["Castle Courtyard"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
}