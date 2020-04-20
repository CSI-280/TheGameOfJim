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
	Room* kathor = new Room("Kathor");
	Room* fentol = new Room("Fentol");
	Room* tovic = new Room("tovic");

	EmptyLinkToRoom* elToSpaceShip = new EmptyLinkToRoom("Empty Link to Space Ship", spaceShip);
	EmptyLinkToRoom* elToKathor = new EmptyLinkToRoom("Empty Link to Kathor", kathor);
	EmptyLinkToRoom* elToFentol = new EmptyLinkToRoom("Empty Link to Fentol", fentol);
	EmptyLinkToRoom* elToTovic = new EmptyLinkToRoom("Empty Link to Tovic", tovic);

	//Store Data in Maps
	(*Rooms).insert(pair<string, Room*>((*spaceShip).getName(), spaceShip));
	(*Rooms).insert(pair<string, Room*>((*kathor).getName(), kathor));
	(*Rooms).insert(pair<string, Room*>((*fentol).getName(), fentol));
	(*Rooms).insert(pair<string, Room*>((*tovic).getName(), tovic));

	(*Links).insert(pair<string, Link*>((*elToSpaceShip).getName(), elToSpaceShip));
	(*Links).insert(pair<string, Link*>((*elToKathor).getName(), elToKathor));
	(*Links).insert(pair<string, Link*>((*elToFentol).getName(), elToFentol));
	(*Links).insert(pair<string, Link*>((*elToTovic).getName(), elToTovic));

	//Connect Rooms with Links
	(*(*Rooms)["Space Ship"]).addLink((*Links)["Empty Link to Kathor"]);
	(*(*Rooms)["Space Ship"]).addLink((*Links)["Empty Link to Fentol"]);
	(*(*Rooms)["Space Ship"]).addLink((*Links)["Empty Link to Tovic"]);
	(*(*Rooms)["Kathor"]).addLink((*Links)["Empty Link to Space Ship"]);
	(*(*Rooms)["Fentol"]).addLink((*Links)["Empty Link to Space Ship"]);
	(*(*Rooms)["Tovic"]).addLink((*Links)["Empty Link to Space Ship"]);


	//Detailing
	vector<string> RoomDescription;
	RoomDescription.push_back("You stand in your recently purchased space ship.");
	RoomDescription.push_back("You look dazingly back at your home plantet of Pluto.");
	RoomDescription.push_back("Your gaze turns to the stars, while wondering where you will start your adventure.");
	RoomDescription.push_back("You look at your console and three holograms of planets appear.");
	(*(*Rooms)["Space Ship"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Inspect Kathor");
	RoomDescription.push_back("Inspect Fentol");
	RoomDescription.push_back("Inspect Tovic");
	(*(*Rooms)["SpaceShip"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Kathor is a place of majestic mountains and rivervalleys.");
	RoomDescription.push_back("It is home to the Kathins, a peaceful race who care more about their crops than outsiders.");
	(*(*Rooms)["Kathor"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Go to Kathor.");
	RoomDescription.push_back("Stop looking at Kathor.");
	(*(*Rooms)["Kathor"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Fentol is a place of a vast jungle consuming the whole planet.");
	RoomDescription.push_back("It is home to the Fents, a religious race who worship their god, Zutzin.");
	(*(*Rooms)["Fentol"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Go to Fentol.");
	RoomDescription.push_back("Stop looking at Fentol.");
	(*(*Rooms)["Fentol"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Tovic is split in half one side only ocean the other is a enormous desert.");
	RoomDescription.push_back("It is home to many clans of desert bandits who descended from the Tovir");
	(*(*Rooms)["Tovic"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Go to Tovic.");
	RoomDescription.push_back("Stop looking at Tovic.");
	(*(*Rooms)["Tovic"]).addLinkDescription(RoomDescription);
}

void initKathor(unordered_map<string, Room*>* Rooms, unordered_map<string, Link*>* Links, unordered_map<string, Container*>* Containers, Inventory* Inventory)
{
	//Initalize Data
	Room* spaceShip = new Room("Space Ship");
	Room* kathor = new Room("Kathor");
	Room* kathorVillage = new Room("Kathor Village")

	EmptyLinkToRoom* elToSpaceShip = new EmptyLinkToRoom("Empty Link to Space Ship", spaceShip);
	EmptyLinkToRoom* elToKathor = new EmptyLinkToRoom("Empty Link to Kathor", kathor);
	EmptyLinkToRoom* elToKathorVillage = new EmptyLinkToRoom("Empty Link to Kathor Village", kathorVillage);

	//Store Data in Maps
	(*Rooms).insert(pair<string, Room*>((*spaceShip).getName(), spaceShip));
	(*Rooms).insert(pair<string, Room*>((*kathor).getName(), kathor));
	(*Rooms).insert(pair<string, Room*>((*kathorVillage).getName(), kathorVillage));

	(*Links).insert(pair<string, Link*>((*elToSpaceShip).getName(), elToSpaceShip));
	(*Links).insert(pair<string, Link*>((*elToKathor).getName(), elToKathor));
	(*Links).insert(pair<string, Link*>((*elToKathorVillage).getName(), elToKathorVillage));


	//Connect Rooms with Links
	(*(*Rooms)["Space Ship"]).addLink((*Links)["Empty Link to Kathor"]);
	(*(*Rooms)["Kathor"]).addLink((*Links)["Empty Link to Space Ship"]);
	(*(*Rooms)["Kathor"]).addLink((*Links)["Empty Link to Kathor Village"]);
	(*(*Rooms)["Kathor Village"]).addLink((*Links)["Empty Link to Kathor"]);


	//Detailing
	vector<string> RoomDescription;
	RoomDescription.push_back("You get off your space ship and land in Kathor.");
	RoomDescription.push_back("You look off into the distance and see a grand mountain surrounded by valleys.")
	RoomDescription.push_back("A river is right next to your space ship.")
	RoomDescription.push_back("Across from the river you see smoke, probably coming from a village.")
	(*(*Rooms)["Kathor"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Inspect Space Ship")
	RoomDescription.push_back("Inspect Smoke")
	(*(*Rooms)["Kathor"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Your space ship is gleaming in the sun.")
	(*(*Rooms)["Space Ship"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Stop looking at space ship.")
	(*(*Rooms)["Space Ship"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Towards the smoke, you see a way to cross the river.")
	(*(*Rooms)["Kathor Village"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Go towards the smoke.")
	RoomDescription.push_back("Stop looking at the smoke.")
	(*(*Rooms)["Kathor Village"]).addLinkDescription(RoomDescription);

	void initTovic(unordered_map<string, Room*>* Rooms, unordered_map<string, Link*>* Links, unordered_map<string, Container*>* Containers, Inventory* Inventory)
	{
		//Initalize Data
		Room* spaceShip = new Room("Space Ship");
		Room* tovic = new Room("Tovic");
		Room* tovicGunFight = new Room("Tovic Gun Fight")

		EmptyLinkToRoom* elToSpaceShip = new EmptyLinkToRoom("Empty Link to Space Ship", spaceShip);
		EmptyLinkToRoom* elToTovic = new EmptyLinkToRoom("Empty Link to Tovic", tovic);
		EmptyLinkToRoom* elToTovicGunFight = new EmptyLinkToRoom("Empty Link to Tovic Gun Fight", tovicGunFight);

		//Store Data in Maps
		(*Rooms).insert(pair<string, Room*>((*spaceShip).getName(), spaceShip));
		(*Rooms).insert(pair<string, Room*>((*tovic).getName(), tovic));
		(*Rooms).insert(pair<string, Room*>((*tovicGunFight).getName(), tovicGunFight));

		(*Links).insert(pair<string, Link*>((*elToSpaceShip).getName(), elToSpaceShip));
		(*Links).insert(pair<string, Link*>((*elToTovic).getName(), elToTovic));
		(*Links).insert(pair<string, Link*>((*elToTovicGunFight).getName(), elToTovicGunFight));


		//Connect Rooms with Links
		(*(*Rooms)["Space Ship"]).addLink((*Links)["Empty Link to Tovic"]);
		(*(*Rooms)["Tovic"]).addLink((*Links)["Empty Link to Space Ship"]);
		(*(*Rooms)["Tovic"]).addLink((*Links)["Empty Link to Toviv Gun Fight"]);
		(*(*Rooms)["Tovic Gun Fight"]).addLink((*Links)["Empty Link to Tovic"]);


		//Detailing
		vector<string> RoomDescription;
		RoomDescription.push_back("You get off your space ship and land in Tovic.");
		RoomDescription.push_back("You see sand only sand...")
		RoomDescription.push_back("A loud bang comes from the distance, gun shots.")
		(*(*Rooms)["Tovic"]).addRoomDescription(RoomDescription);
		RoomDescription.clear();
		RoomDescription.push_back("Inspect Space Ship")
		RoomDescription.push_back("Inspect gun shots")
		(*(*Rooms)["Tovic"]).addLinkDescription(RoomDescription);
		RoomDescription.clear();
		RoomDescription.push_back("Your space ship is covered in the sand.")
		(*(*Rooms)["Space Ship"]).addRoomDescription(RoomDescription);
		RoomDescription.clear();
		RoomDescription.push_back("Stop looking at space ship.")
		(*(*Rooms)["Space Ship"]).addLinkDescription(RoomDescription);
		RoomDescription.clear();
		RoomDescription.push_back("Looking closing in the direction of the shots you see two groups fighting.")
		(*(*Rooms)["Tovic Gun Fight"]).addRoomDescription(RoomDescription);
		RoomDescription.clear();
		RoomDescription.push_back("Go towards the gun shots.")
		RoomDescription.push_back("Stop looking at the gun shots.")
		(*(*Rooms)["Tovic Gun Fight"]).addLinkDescription(RoomDescription);
