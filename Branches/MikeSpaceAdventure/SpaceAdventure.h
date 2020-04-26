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

void initSpaceShip(unordered_map<string, Room*>* Rooms, unordered_map<string, Link*>* Links, unordered_map<string, Container*>* Containers, Inventory* Inventory)
{
	//Initalize Data
	Room* spaceShip = new Room("Space Ship");
	Room* kathor1 = new Room("Kathor1");
	Room* tovic1 = new Room("Tovic1");
	Room* kathor2 = new Room("Kathor2");
	Room* tovic2 = new Room("Tovic2");

	EmptyLinkToRoom* elToSpaceShip = new EmptyLinkToRoom("Empty Link to Space Ship", spaceShip);
	EmptyLinkToRoom* elToKathor1 = new EmptyLinkToRoom("Empty Link to Kathor1", kathor);
	EmptyLinkToRoom* elToTovic1 = new EmptyLinkToRoom("Empty Link to Tovic1", tovic);

	//Store Data in Maps
	(*Rooms).insert(pair<string, Room*>((*spaceShip).getName(), spaceShip));
	(*Rooms).insert(pair<string, Room*>((*kathor1).getName(), kathor1));
	(*Rooms).insert(pair<string, Room*>((*tovic1).getName(), tovic1));
	(*Rooms).insert(pair<string, Room*>((*kathor2).getName(), kathor2));
	(*Rooms).insert(pair<string, Room*>((*tovic2).getName(), tovic2));

	(*Links).insert(pair<string, Link*>((*elToSpaceShip).getName(), elToSpaceShip));
	(*Links).insert(pair<string, Link*>((*elToKathor1).getName(), elToKathor1));
	(*Links).insert(pair<string, Link*>((*elToTovic1).getName(), elToTovic1));
	(*Links).insert(pair<string, Link*>((*elToKathor2).getName(), elToKathor2));
	(*Links).insert(pair<string, Link*>((*elToTovic2).getName(), elToTovic2));

	//Connect Rooms with Links
	(*(*Rooms)["Space Ship"]).addLink((*Links)["Empty Link to Kathor1"]);
	(*(*Rooms)["Space Ship"]).addLink((*Links)["Empty Link to Tovic1"]);
	(*(*Rooms)["Kathor1"]).addLink((*Links)["Empty Link to Space Ship"]);
	(*(*Rooms)["Kathor1"]).addLink((*Links)["Empty Link to Kathor2"]);
	(*(*Rooms)["Tovic1"]).addLink((*Links)["Empty Link to Space Ship"]);
	(*(*Rooms)["Tovic1"]).addLink((*Links)["Empty Link to Tovic2"]);
	(*(*Rooms)["Kathor2"]).addLink((*Links)["Empty Link to Kathor1"]);
	(*(*Rooms)["Tovic2"]).addLink((*Links)["Empty Link to Tovic1"]);


	//Detailing
	vector<string> RoomDescription;

	// space ship
	RoomDescription.push_back("You stand in your recently purchased space ship.");
	RoomDescription.push_back("You look dazingly back at your home plantet of Pluto.");
	RoomDescription.push_back("Your gaze turns to the stars, while wondering where you will start your adventure.");
	RoomDescription.push_back("You look at your console and three holograms of planets appear.");
	(*(*Rooms)["Space Ship"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();

	RoomDescription.push_back("Inspect Kathor");
	RoomDescription.push_back("Inspect Tovic");
	(*(*Rooms)["SpaceShip"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();

	// kathor 1
	RoomDescription.push_back("Kathor is a place of majestic mountains and rivervalleys.");
	RoomDescription.push_back("It is home to the Kathins, a peaceful race who care more about their crops than outsiders.");
	(*(*Rooms)["Kathor1"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();

	RoomDescription.push_back("Go to Kathor.");
	RoomDescription.push_back("Stop looking at Kathor.");
	(*(*Rooms)["Kathor1"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();

	// kathor 2
	vector<string> RoomDescription;
	RoomDescription.push_back("You get off your space ship and land in Kathor.");
	RoomDescription.push_back("You look off into the distance and see a grand mountain surrounded by valleys.")
	RoomDescription.push_back("A river is right next to your space ship.")
	RoomDescription.push_back("Across from the river you see smoke, probably coming from a village.")
	(*(*Rooms)["Kathor2"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();

	RoomDescription.push_back("Inspect Smoke")
	RoomDescription.push_back("Stop Looking at smoke")
	(*(*Rooms)["Kathor2"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	
	// tovic1
	RoomDescription.push_back("Tovic is split in half one side only ocean the other is a enormous desert.");
	RoomDescription.push_back("It is home to many clans of desert bandits who descended from the Tovir");
	(*(*Rooms)["Tovic1"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();

	RoomDescription.push_back("Go to Tovic.");
	RoomDescription.push_back("Stop looking at Tovic.");
	(*(*Rooms)["Tovic1"]).addLinkDescription(RoomDescription);

	// tovic2
	RoomDescription.push_back("You get off your space ship and land in Tovic.");
	RoomDescription.push_back("You see sand only sand...")
	RoomDescription.push_back("A loud bang comes from the distance, gun shots.")
	(*(*Rooms)["Tovic2"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();

	RoomDescription.push_back("Inspect gun shots")
	RoomDescription.push_back("Stop Looking at gun shots")
	(*(*Rooms)["Tovic2"]).addLinkDescription(RoomDescription);


}
