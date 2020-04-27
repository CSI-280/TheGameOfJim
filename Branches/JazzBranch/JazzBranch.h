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

Item* ramenNoodles = new Item();
Item* candyBar = new Item();
Item* magazine = new Item();
Item* healthPotion = new Item();

void initConvenienceStore(unordered_map<string, Room*>* Rooms, unordered_map<string, Link*>* Links, unordered_map<string, Container*>* Containers, Inventory* Inventory)
{
	//Initalize Data
	(*ramenNoodles).setName("Ramen Noodles");
	(*candyBar).setName("Candy Bar");
	(*magazine).setName("Magazine");

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
	(*Rooms).insert(pair<string, Room*>((*dustyShed).getName(), dustyShed));
	(*Rooms).insert(pair<string, Room*>((*townPlaza).getName(), townPlaza));
	(*Rooms).insert(pair<string, Room*>((*castleCourtyard).getName(), castleCourtyard));
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
	(*(*Rooms)["Dusty Shed"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Put back the ramen noodles.");
	(*(*Rooms)["Dusty Shed"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You pick up the candy bar.");
	RoomDescription.push_back("Suddenly you are viewing the hustle and bustle of a town plaza.");
	RoomDescription.push_back("The surroundings are very foreign to you, as if from another world.");
	(*(*Rooms)["Town Plaza"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Put back the candy bar.");
	(*(*Rooms)["Town Plaza"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You pick up the magazine.");
	RoomDescription.push_back("Suddenly you see a castle courtyard with multiple guards watching the main enterance.");
	RoomDescription.push_back("They seem friendly, but if you do anything suspicious their attitude will change fast.");
	(*(*Rooms)["Castle Courtyard"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Put back the magazine.");
	(*(*Rooms)["Castle Courtyard"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
}

void initDustyShed(unordered_map<string, Room*>* Rooms, unordered_map<string, Link*>* Links, unordered_map<string, Container*>* Containers, Inventory* Inventory)
{
	//Initalize Data
	(*healthPotion).setName("Health Potion");

	Room* convenienceStore = new Room("Convenience Store");
	Room* dustyShed = new Room("Dusty Shed");
	Room* forest = new Room("Forest");
	Container* smallBox = new Container("Small Box", Inventory, false, true);

	EmptyLinkToRoom* elToConvenienceStore = new EmptyLinkToRoom("Empty Link to Convenience Store", convenienceStore);
	EmptyLinkToRoom* elToDustyShed = new EmptyLinkToRoom("Empty Link to Dusty Shed", dustyShed);
	EmptyLinkToRoom* elToForest = new EmptyLinkToRoom("Empty Link to Forest", forest);
	EmptyLinkToContainer* linkToSmallBox = new EmptyLinkToContainer("Empty Link to Small Box", smallBox);

	//Store Data in Maps
	(*Rooms).insert(pair<string, Room*>((*convenienceStore).getName(), convenienceStore));
	(*Rooms).insert(pair<string, Room*>((*dustyShed).getName(), dustyShed));
	(*Rooms).insert(pair<string, Room*>((*forest).getName(), forest));
	(*Containers).insert(pair<string, Container*>((*smallBox).getName(), smallBox));

	(*Links).insert(pair<string, Link*>((*elToConvenienceStore).getName(), elToConvenienceStore));
	(*Links).insert(pair<string, Link*>((*elToDustyShed).getName(), elToDustyShed));
	(*Links).insert(pair<string, Link*>((*elToForest).getName(), elToForest));
	(*Links).insert(pair<string, Link*>((*linkToSmallBox).getName(), linkToSmallBox));

	//Connect Rooms with Links
	(*(*Rooms)["Convenience Store"]).addLink((*Links)["Empty Link to Dusty Shed"]);
	(*(*Rooms)["Dusty Shed"]).addLink((*Links)["Empty Link to Convenience Store"]);
	(*(*Rooms)["Dusty Shed"]).addLink((*Links)["Empty Link to Forest"]);
	(*(*Rooms)["Forest"]).addLink((*Links)["Empty Link to Dusty Shed"]);
	(*(*Containers)["Small Box"]).addLink((*Links)["Empty Link to Dusty Shed"]);

	//Detailing
	(*(*Containers)["Small Box"]).addItems(healthPotion);
	vector<string> RoomDescription;
	RoomDescription.push_back("You find yourself physically in the shed.");
	RoomDescription.push_back("You're confused, but don't think much of it at the moment.");
	RoomDescription.push_back("You see the small box on the work table");
	RoomDescription.push_back("as well as the door which leads outside.");
	(*(*Rooms)["Dusty Shed"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Inspect the Small Box");
	RoomDescription.push_back("Look outside");
	(*(*Rooms)["Dusty Shed"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You open up the Small Box.");
	(*(*Containers)["Small Box"]).addContainerDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Stop Looking at the Small Box.");
	(*(*Containers)["Small Box"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You look outside and find yourself looking at a heavily wooded forest.");
	RoomDescription.push_back("It's dark outside, and you do not know if it is safe to venture out.");
	(*(*Rooms)["Forest"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Go outside.");
	RoomDescription.push_back("Stop looking outside");
	(*(*Rooms)["Forest"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
}

void initTownPlaza(unordered_map<string, Room*>* Rooms, unordered_map<string, Link*>* Links, unordered_map<string, Container*>* Containers, Inventory* Inventory)
{
	//Initalize Data
	Room* convenienceStore = new Room("Convenience Store");
	Room* townPlaza = new Room("Town Plaza");
	Room* alleyWayScuffle = new Room("Alley Way Scuffle");

	EmptyLinkToRoom* elToConvenienceStore = new EmptyLinkToRoom("Empty Link to Convenience Store", convenienceStore);
	EmptyLinkToRoom* elToTownPlaza = new EmptyLinkToRoom("Empty Link to Town Plaza", townPlaza);
	EmptyLinkToRoom* elToAlleyWayScuffle = new EmptyLinkToRoom("Empty Link to Alley Way Scuffle", alleyWayScuffle);

	//Store Data in Maps
	(*Rooms).insert(pair<string, Room*>((*convenienceStore).getName(), convenienceStore));
	(*Rooms).insert(pair<string, Room*>((*townPlaza).getName(), townPlaza));
	(*Rooms).insert(pair<string, Room*>((*alleyWayScuffle).getName(), alleyWayScuffle));

	(*Links).insert(pair<string, Link*>((*elToConvenienceStore).getName(), elToConvenienceStore));
	(*Links).insert(pair<string, Link*>((*elToTownPlaza).getName(), elToTownPlaza));
	(*Links).insert(pair<string, Link*>((*elToAlleyWayScuffle).getName(), elToAlleyWayScuffle));

	//Connect Rooms with Links
	(*(*Rooms)["Convenience Store"]).addLink((*Links)["Empty Link to Dusty Shed"]);
	(*(*Rooms)["Town Plaza"]).addLink((*Links)["Empty Link to Convenience Store"]);
	(*(*Rooms)["Town Plaza"]).addLink((*Links)["Empty Link to Alley Way Scuffle"]);
	(*(*Rooms)["Alley Way Scuffle"]).addLink((*Links)["Empty Link to Town Plaza"]);

	//Detailing
	vector<string> RoomDescription;
	RoomDescription.push_back("You find yourself in the town plaza.");
	RoomDescription.push_back("You're confused, but don't think much of it at the moment.");
	RoomDescription.push_back("The streets are packed with people and there are multiple vendors selling various wares.");
	RoomDescription.push_back("Suddenly, you hear a fight coming from a nearby alleyway.");
	(*(*Rooms)["Town Plaza"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Check out the fight");
	RoomDescription.push_back("Stay in the plaza");
	(*(*Rooms)["Town Plaza"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You decide to stay in the town plaza.");
	RoomDescription.push_back("There is much to check out but you aren't sure where to begin.");
	RoomDescription.push_back("All of a sudden, you start to feel lightheaded.");
	RoomDescription.push_back("You fall to the ground and people start crowding around you.");
	RoomDescription.push_back("Then, everything turns dark.");
	(*(*Rooms)["Town Plaza"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You peek around to the alley way where there are two people fighting.");
	RoomDescription.push_back("They are both wielding knives, and both have small wounds where they nicked each other.");
	RoomDescription.push_back("They also seem to be arguing about a certain treasure that is hidden somewhere in a forest.");
	(*(*Rooms)["Alley Way Scuffle"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Go to the fight");
	RoomDescription.push_back("Go back to the plaza");
	(*(*Rooms)["Alley Way Scuffle"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
}

void initCastleCourtyard(unordered_map<string, Room*>* Rooms, unordered_map<string, Link*>* Links, unordered_map<string, Container*>* Containers, Inventory* Inventory)
{
	//Initalize Data
	Room* convenienceStore = new Room("Convenience Store");
	Room* castleCourtyard = new Room("Castle Courtyard");
	Room* castleOutskirts = new Room("Castle Outskirts");

	EmptyLinkToRoom* elToConvenienceStore = new EmptyLinkToRoom("Empty Link to Convenience Store", convenienceStore);
	EmptyLinkToRoom* elToCastleCourtyard = new EmptyLinkToRoom("Empty Link to Castle Courtyard", castleCourtyard);
	EmptyLinkToRoom* elToCastleOutskirts = new EmptyLinkToRoom("Empty Link to Castle Outskirts", castleOutskirts);

	//Store Data in Maps
	(*Rooms).insert(pair<string, Room*>((*convenienceStore).getName(), convenienceStore));
	(*Rooms).insert(pair<string, Room*>((*castleCourtyard).getName(), castleCourtyard));
	(*Rooms).insert(pair<string, Room*>((*castleOutskirts).getName(), castleOutskirts));

	(*Links).insert(pair<string, Link*>((*elToConvenienceStore).getName(), elToConvenienceStore));
	(*Links).insert(pair<string, Link*>((*elToCastleCourtyard).getName(), elToCastleCourtyard));
	(*Links).insert(pair<string, Link*>((*elToCastleOutskirts).getName(), elToCastleOutskirts));

	//Connect Rooms with Links
	(*(*Rooms)["Convenience Store"]).addLink((*Links)["Empty Link to Dusty Shed"]);
	(*(*Rooms)["Castle Courtyard"]).addLink((*Links)["Empty Link to Convenience Store"]);
	(*(*Rooms)["Castle Courtyard"]).addLink((*Links)["Empty Link to Castle Outskirts"]);
	(*(*Rooms)["Castle Outskirts"]).addLink((*Links)["Empty Link to Castle Courtyard"]);

	//Detailing
	vector<string> RoomDescription;
	RoomDescription.push_back("You find yourself in the castle courtyard.");
	RoomDescription.push_back("You're confused, but don't think much of it at the moment.");
	RoomDescription.push_back("There is a huge gate kept watch by two guards.");
	RoomDescription.push_back("Past the gate you can see the castle, which is beautiful yet intimidating.");
	RoomDescription.push_back("The two guards haven't noticed you yet.");
	RoomDescription.push_back("You think it unwise to engage with them at the current moment.");
	(*(*Rooms)["Castle Courtyard"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Go to the outskirts");
	RoomDescription.push_back("Stay for a little longer");
	(*(*Rooms)["Castle Courtyard"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You decide to stay in the castle outskirts.");
	RoomDescription.push_back("You don't really know what to do, so you just walk around the perimeter.");
	RoomDescription.push_back("At this point the guards notice you, and are keeping a close watch.");
	RoomDescription.push_back("They haven't said anything yet, but they seem close to wanting to question you.");
	RoomDescription.push_back("You should probably leave.");
	(*(*Rooms)["Castle Courtyard"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You decide to turn around and go away from the castle courtyard.");
	RoomDescription.push_back("Trees line a stone path which seems to go on forever.");
	RoomDescription.push_back("When you squint, you see something curious in the distance.");
	RoomDescription.push_back("You feel compelled to check it out.");
	(*(*Rooms)["Castle Outskirts"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Continue to the castle outskirts");
	(*(*Rooms)["Castle Outskirts"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
}