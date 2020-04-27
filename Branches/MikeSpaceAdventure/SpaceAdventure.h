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
	Room* kathor2 = new Room("Kathor2");
	Room* kathor3 = new Room("Kathor3");
	Room* kathor4 = new Room("Kathor4");
	Room* kathor5a = new Room("Kathor5a");
	Room* kathor5b = new Room("Kathor5b");
	Room* kathor6 = new Room("Kathor6");
	Room* spaceShip2 = new Room("Space Ship 2");

	EmptyLinkToRoom* elToSpaceShip = new EmptyLinkToRoom("Empty Link to Space Ship", spaceShip);
	EmptyLinkToRoom* elToKathor1 = new EmptyLinkToRoom("Empty Link to Kathor1", kathor1);
	EmptyLinkToRoom* elToKathor2 = new EmptyLinkToRoom("Empty Link to Kathor2", kathor2);
	EmptyLinkToRoom* elToKathor3 = new EmptyLinkToRoom("Empty Link to Kathor3", kathor3);
	EmptyLinkToRoom* elToKathor4 = new EmptyLinkToRoom("Empty Link to Kathor4", kathor4);
	EmptyLinkToRoom* elToKathor4 = new EmptyLinkToRoom("Empty Link to Kathor5a", kathor5a);
	EmptyLinkToRoom* elToKathor4 = new EmptyLinkToRoom("Empty Link to Kathor5b", kathor5b);
	EmptyLinkToRoom* elToKathor4 = new EmptyLinkToRoom("Empty Link to Kathor6", kathor6);
	EmptyLinkToRoom* elToSpaceShip = new EmptyLinkToRoom("Empty Link to Space Ship 2", spaceShip2);


	//Store Data in Maps
	(*Rooms).insert(pair<string, Room*>((*spaceShip).getName(), spaceShip));
	(*Rooms).insert(pair<string, Room*>((*kathor1).getName(), kathor1));
	(*Rooms).insert(pair<string, Room*>((*kathor2).getName(), kathor2));
	(*Links).insert(pair<string, Link*>((*elToSpaceShip).getName(), elToSpaceShip));
	(*Links).insert(pair<string, Link*>((*elToKathor1).getName(), elToKathor1));
	(*Links).insert(pair<string, Link*>((*elToKathor2).getName(), elToKathor2));
	(*Links).insert(pair<string, Link*>((*elToKathor3).getName(), elToKathor3));
	(*Links).insert(pair<string, Link*>((*elToKathor4).getName(), elToKathor4));
	(*Links).insert(pair<string, Link*>((*elToKathor5a).getName(), elToKathor5a));
	(*Links).insert(pair<string, Link*>((*elToKathor5b).getName(), elToKathor5b));
	(*Links).insert(pair<string, Link*>((*elToKathor6).getName(), elToKathor6));
	(*Rooms).insert(pair<string, Room*>((*spaceShip2).getName(), spaceShip2));


	//Connect Rooms with Links
	(*(*Rooms)["Space Ship"]).addLink((*Links)["Empty Link to Kathor1"]);
	(*(*Rooms)["Kathor1"]).addLink((*Links)["Empty Link to Kathor2"]);
	(*(*Rooms)["Kathor2"]).addLink((*Links)["Empty Link to Kathor3"]);
	(*(*Rooms)["Kathor3"]).addLink((*Links)["Empty Link to Kathor4"]);
	(*(*Rooms)["Kathor4"]).addLink((*Links)["Empty Link to Kathor5a"]);
	(*(*Rooms)["Kathor4"]).addLink((*Links)["Empty Link to Kathor5b"]);
	(*(*Rooms)["Kathor5a"]).addLink((*Links)["Empty Link to Kathor6"]);
	(*(*Rooms)["Kathor5b"]).addLink((*Links)["Empty Link to Space Ship 2."]);




	//Detailing
	vector<string> RoomDescription;

	// space ship
	RoomDescription.push_back("You stand in your recently purchased space ship.");
	RoomDescription.push_back("You look dazingly back at your home plantet of Pluto.");
	RoomDescription.push_back("Your gaze turns to the stars, while wondering where you will start your adventure.");
	RoomDescription.push_back("You look at your console and a hologram of a planet appears.");
	(*(*Rooms)["Space Ship"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();

	RoomDescription.push_back("Inspect Kathor");
	(*(*Rooms)["SpaceShip"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();

	// kathor 1
	RoomDescription.push_back("Kathor is a place of majestic mountains and rivervalleys.");
	RoomDescription.push_back("It is home to the Kathins, a peaceful race who care more about their crops than outsiders.");
	(*(*Rooms)["Kathor1"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();

	RoomDescription.push_back("Go to Kathor.");
	(*(*Rooms)["Kathor1"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();

	// kathor 2
	RoomDescription.push_back("You get off your space ship and land in Kathor.");
	RoomDescription.push_back("You look off into the distance and see a grand mountain surrounded by valleys.")
	RoomDescription.push_back("A river is right next to your space ship.")
	RoomDescription.push_back("Across from the river you see smoke, probably coming from a village.")
	(*(*Rooms)["Kathor2"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();

	RoomDescription.push_back("Go towards the smoke.")
	(*(*Rooms)["Kathor2"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();

	// kathor 3
	RoomDescription.push_back("As you get near the smoke, you start to see the village.");
	RoomDescription.push_back("You climb on top of a hill, to get a better view of the village.");
	RoomDescription.push_back("As you look from up top of the hill, you see multiple Kathins, trying to put out the fire which is burning the biggest house in the village.");
	(*(*Rooms)["Kathor3"]).addRoomDescription(RoomDescription);
	RoomDescription.clear()

	RoomDescription.push_back("Go into village.");
	(*(*Rooms)["Kathor3"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();

	// kathor 4
	RoomDescription.push_back("You enter the village and see a family crying.");
	RoomDescription.push_back("You walk towards the family and ask is this your home that is burning?");
	RoomDescription.push_back("Family: Yes, our dog is still in the house.");
	(*(*Rooms)["Kathor4"]).addRoomDescription(RoomDescription);
	RoomDescription.clear()

	RoomDescription.push_back("Get the dog.");
	RoomDescription.push_back("Don't get the dog.");
	(*(*Rooms)["Kathor4"]).addLinkDescription(RoomDescription);
	RoomDescription.clear()

	// kathor 5a
	RoomDescription.push_back("You ready yourself, then rush straight in to the burning house.");
	RoomDescription.push_back("You hear barking coming from upstairs.");
	(*(*Rooms)["Kathor5a"]).addRoomDescription(RoomDescription);
	RoomDescription.clear()

	RoomDescription.push_back("Go upstairs.");
	(*(*Rooms)["Kathor5a"]).addLinkDescription(RoomDescription);
	RoomDescription.clear()

	// kathor 6
	RoomDescription.push_back("On the next floor you see the dog.");
	RoomDescription.push_back("He is trapped by fallen roof.");
	RoomDescription.push_back("You lift the fallen debris out of the way.");
	RoomDescription.push_back("You tell the dog to come, he does while wagging his tail.");
	(*(*Rooms)["Kathor6"]).addRoomDescription(RoomDescription);
	RoomDescription.clear()

	RoomDescription.push_back("Leave house with dog.");
	(*(*Rooms)["Kathor6"]).addLinkDescription(RoomDescription);
	RoomDescription.clear()


	// kathor 5b
	RoomDescription.push_back("The house stopped burning in the early hours of the morning.");
	RoomDescription.push_back("The family never fell asleep that night.");
	RoomDescription.push_back("In the morning the villagers start to question who you are and kicked you out of the village.");
	(*(*Rooms)["Kathor5b"]).addRoomDescription(RoomDescription);
	RoomDescription.clear()

	RoomDescription.push_back("Go back to spaces ship.");
	(*(*Rooms)["Kathor5b"]).addLinkDescription(RoomDescription);
	RoomDescription.clear()

	// space ship 2
	RoomDescription.push_back("You get back on your space ship.");
	RoomDescription.push_back("You start the engines of your space ship.");
	RoomDescription.push_back("You start to regret not saving that dog.");
	RoomDescription.push_back("The rest of your days are spent depressed that you didn't save the dog.");
	RoomDescription.push_back("THE END.");
	(*(*Rooms)["Space Ship 2"]).addRoomDescription(RoomDescription);
	RoomDescription.clear()



}
