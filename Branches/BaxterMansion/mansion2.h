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

Item* HeartKey = new Item();
Item* DiamondKey = new Item();

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

class BasicDoorCheck : public Link
{
private:
	Inventory* mTrackedInventory;
public:
	BasicDoorCheck(string cName, Door* cDoor, Inventory* cInventory) : Link(cName, cRoom)
	{
		mTrackedInventory = cInventory;
	}

	bool checkConditions()
	{
		if ((*mTrackedInventory).checkPlayerInventoryForItem(*HeartKey))
		{
			if ((*mTrackedInventory).checkPlayerInventoryForItem(*DiamondKey)) {
				cout << "You Unlock the lock with the Keys!" << endl;
				return true;
			}
			else
			{
				cout << "You can't open the lock without both keys!" << endl;
				return false;
			}
		}
		else if ((*mTrackedInventory).checkPlayerInventoryForItem(*DiamondKey))
		{
			if ((*mTrackedInventory).checkPlayerInventoryForItem(*HeartKey)) {
				cout << "You Unlock the lock with the Keys!" << endl;
				return true;
			}
			else
			{
				cout << "You can't open the lock without both keys!" << endl;
				return false;
			}
		}
		else
		{
			cout << "You can't open the lock without the keys!" << endl;
			return false;
		}
	}
};

void initMansion2(unordered_map<string, Room*>* Rooms, unordered_map<string, Link*>* Links, unordered_map<string, Container*>* Containers, Inventory* Inventory)
{
	//Initalize Data
	Room* roomReturn = new Room("Room of Return");
	Room* heart = new Room("Heart Room");
	Room* diamond = new Room("Diamond Room");
	Room* roomforNextTime = new Room("Next Week");
	Container* bloodTable = new Container("Blood Stained Table", Inventory, false, true);
	Container* chemTable = new Container("Chemical Lab Table", Inventory, false, true);

	EmptyLinkToRoom* elToRoomReturn = new EmptyLinkToRoom("Empty Link to Room of Return", roomReturn);
	EmptyLinkToRoom* elToHeart = new EmptyLinkToRoom("Empty Link to Heart Room", heart);
	EmptyLinkToRoom* elToDiamond = new EmptyLinkToRoom("Empty Link to Diamond Room", diamond);
	EmptyLinkToContainer* elToBloodTable = new EmptyLinkToContainer("Empty Link to Bloody Table", bloodTable);
	EmptyLinkToContainer* elToChemTable = new EmptyLinkToContainer("Empty Link to Chemical Lab Table", chemTable);
	BasicDoorCheck* LinkToLockedDoor = new BasicDoorCheck("Basic Key check for unlocking Door", roomforNextTime, Inventory);

	//Store Data in Maps
	(*Rooms).insert(pair<string, Room*>((*roomReturn).getName(), roomReturn));
	(*Rooms).insert(pair<string, Room*>((*heart).getName(), heart));
	(*Rooms).insert(pair<string, Room*>((*diamond).getName(), diamond));
	(*Rooms).insert(pair<string, Room*>((*roomforNextTime).getName(), roomforNextTime));

	(*Containers).insert(pair<string, Container*>((*bloodTable).getName(), bloodTable));
	(*Containers).insert(pair<string, Container*>((*chemTable).getName(), chemTable));

	(*Links).insert(pair<string, Link*>((*elToRoomReturn).getName(), elToRoomReturn));
	(*Links).insert(pair<string, Link*>((*elToHeart).getName(), elToHeart));
	(*Links).insert(pair<string, Link*>((*elToDiamond).getName(), elToDiamond));
	(*Links).insert(pair<string, Link*>((*LinkToLockedDoor).getName(), LinkToLockedDoor));
	(*Links).insert(pair<string, Link*>((*elToBloodTable).getName(), elToBloodTable);
	(*Links).insert(pair<string, Link*>((*elToChemTable).getName(), elToChemTable);

	//Connect Rooms with Links
	(*(*Rooms)["Room of Return"]).addLink((*Links)["Empty Link to Heart Room"]);
	(*(*Rooms)["Room of Return"]).addLink((*Links)["Empty Link to Diamond Room"]);
	(*(*Rooms)["Room of Return"]).addLink((*Links)["Basic Key check for unlocking Door"]);
	(*(*Rooms)["Heart Room"]).addLink((*Links)["Empty Link to Room of Return"]);
	(*(*Rooms)["Diamond Room"]).addLink((*Links)["Empty Link to Room of Return"]);
	(*(*Rooms)["Basic Key check for unlocking Door"]).addLink((*Links)["Empty Link to Room of Return"]);
	(*(*Containers)["Blood Stained Table"]).addLink((*Links)["Empty Link to Heart Room"]);
	(*(*Containers)["Chemical Lab Table"]).addLink((*Links)["Empty Link to Diamond Room"]);

	//Detailing
	vector<string> RoomDescription;
	RoomDescription.push_back("The flash of light from the previous room illuminates the room you now find yourself in.");
	RoomDescription.push_back("The windows were caked in grime and for the most part boarded up, leaving only the slimmest of slithers for the rays to struggle though.");
	RoomDescription.push_back("As you entered what looks to be an old living room the light cast from the open doorway was lost from view cauing you to blunder into dusty cobwebs.");
	RoomDescription.push_back("As your eyes adjust to the darkness you see what is truly in this room.");
	RoomDescription.push_back("In front of you is another locked door, with two locks on it. One in the shape of a heart and the other diamond.");
	RoomDescription.push_back("To your left is an oddily bright red door, with the shape of a cartoon heart etched into the inner square of it.");
	RoomDescription.push_back("To your right is a much calmer blue door, with the shape of the diamond suit etched into the inner square of it.");
	(*(*Rooms)["Room of Return"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Inspect Heart");
	RoomDescription.push_back("Inspect Diamond");
	(*(*Rooms)["Room of Return"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("The Heart door is unlocked and able to be entered");
	RoomDescription.push_back("You feel and odd vibration coming from the other side of the door, and hear the disticnt sound of clashing metal.");
	(*(*Rooms)["Heart Room"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Go into the Heart Room.");
	RoomDescription.push_back("Stop looking at the Heart Door.");
	(*(*Rooms)["Heart Room"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Inside the heart room you find a ghstly sight. The machinery you heard was indeed present, much to your horror.");
	RoomDescription.push_back("The room seems to be like a meat processing plant, with many of the tools and equipment being heavily stained in the blood and juices of the meat.");
	RoomDescription.push_back("The problem arises when you see what type of meat seems to be processed here, as off to side you see a blood covered table with a disticly human looking scull and ribcage lying a top it.");
	(*(*Rooms)["Heart Room"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Inspect the table.");
	RoomDescription.push_back("Leave the Room.");
	(*(*Rooms)["Heart Room"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You find a heart shaped key hidden within the bloody viscera, much to your displeasure.");
	(*(*Containers)["Blood Stained Table"]).addContainerDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("The Diamond door is unlocked and able to be entered.");
	RoomDescription.push_back("You smell the distinct scent of Almonds coming from the other side of the door along with the sound of fans blowing within.");
	(*(*Rooms)["Diamond Room"]).addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Go into the Diamond Room.");
	RoomDescription.push_back("Stop looking at the Diamond Door.");
	(*(*Rooms)["Diamond Room"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Inside the diamond room you find a room filled with chemical equipment. The chemicals all make a distinct odor of almonds for some reason, though after sniffing the air you begin to cough and look elswhere.");
	RoomDescription.push_back("You see a table with animal cages along with small beakers containg similar chemicals connected to each cage.");
	(*(*Rooms)["Diamond Room"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Inspect the table.");
	RoomDescription.push_back("Leave the Room.");
	(*(*Rooms)["Diamond Room"]).addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You find that each cage has grotesque experiments held within, which some containing two headed rats, others some type of bug-like creatures, and in the last one a diamond shaped key thankfully.");
}