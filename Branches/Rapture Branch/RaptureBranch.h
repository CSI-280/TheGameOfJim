#pragma once
#include "..\..\Systems\Rooms.h"
#include "..\..\Systems\Item.h"
#include "..\..\Systems\Inventory.h"
#include "..\..\Systems\Player.h"
#include "..\..\Systems\Enemies.h"
#include "..\..\Systems\Combat.h"
#include "..\Example Branch\ExampleBranch.h"

class SplicerFight : public Link
{
public:
	SplicerFight(string cName, Room* cRoom, Player* cPlayer, Inventory* cInventory) : Link(cName, cRoom)
	{
		mFightWon = false;
		trackedPlayer = cPlayer;
		mInventory = cInventory;
	}

	bool checkConditions()
	{
		if (!mFightWon)
		{
			Enemies splicer(55, 7, 7, 7, "Thuggish Splicer");
			cout << "You encounter a man in the hall, an he charges you!" << endl;
			if (!(combat((*trackedPlayer), splicer, (*mInventory))))
			{
				mFightWon = true;
				return mFightWon;
			} else {
				return mFightWon;
			}
		}
		else
		{
			return true;
		}
	}
private:
	bool mFightWon;
	Player* trackedPlayer;
	Inventory* mInventory;
};

void initRaptureBranch(unordered_map<string, Room*>* Rooms, unordered_map<string, Link*>* Links, unordered_map<string, Container*>* Containers, Inventory* Inventory, Player* Player)
{
	//Initialize Data
	Room* LakeFront = new Room("Rapture Lakefront");
	Room* OpenOcean = new Room("Rapture Ocean");
	Room* LightHouse = new Room("Rapture Lighthouse");
	Room* RaptureLobby = new Room("Rapture Lobby");
	Room* FirstTunnel = new Room("Rapture First Tunnel");
	EmptyLinkToRoom* LinkToLakeFront = new EmptyLinkToRoom("Link to LakeFront", LakeFront);
	EmptyLinkToRoom* LinkToOcean = new EmptyLinkToRoom("Link to Ocean", OpenOcean);
	EmptyLinkToRoom* LinkToLightHouse = new EmptyLinkToRoom("Link to LightHouse", LightHouse);
	SplicerFight* LinkToLobby = new SplicerFight("Splicer Fight in Lobby", RaptureLobby, Player, Inventory);
	EmptyLinkToRoom* LinkToFirstTunnel = new EmptyLinkToRoom("Link to FirstTunnel", FirstTunnel);
	

	//Insert Data into Maps.
	(*Rooms).insert(pair<string, Room*>(LakeFront->getName(), LakeFront));
	(*Rooms).insert(pair<string, Room*>(OpenOcean->getName(), OpenOcean));
	(*Rooms).insert(pair<string, Room*>(LightHouse->getName(), LightHouse));
	(*Rooms).insert(pair<string, Room*>(RaptureLobby->getName(), RaptureLobby));
	(*Rooms).insert(pair<string, Room*>(FirstTunnel->getName(), FirstTunnel));
	(*Links).insert(pair<string, Link*>(LinkToLakeFront->getName(), LinkToLakeFront));
	(*Links).insert(pair<string, Link*>(LinkToOcean->getName(), LinkToOcean));
	(*Links).insert(pair<string, Link*>(LinkToLightHouse->getName(), LinkToLightHouse));
	(*Links).insert(pair<string, Link*>(LinkToLobby->getName(), LinkToLobby));
	(*Links).insert(pair<string, Link*>(LinkToFirstTunnel->getName(), LinkToFirstTunnel));

	//Add Links
	LakeFront->addLink(LinkToOcean);
	OpenOcean->addLink(LinkToLakeFront);
	OpenOcean->addLink(LinkToLightHouse);
	LightHouse->addLink(LinkToOcean);
	LightHouse->addLink(LinkToLobby);
	RaptureLobby->addLink(LinkToLightHouse);
	RaptureLobby->addLink(LinkToFirstTunnel);
	FirstTunnel->addLink(LinkToLobby);

	//Detailing
	vector<string> RoomDescription;
	RoomDescription.push_back("You walk toward the beach.");
	RoomDescription.push_back("You see a boat, seeming to in good working order.");
	LakeFront->addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Take the boat onto the water.");
	LakeFront->addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You sail out into the waves, knowing you could always return.");
	RoomDescription.push_back("You see a lighthouse in the distance.");
	OpenOcean->addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Return to Shore.");
	RoomDescription.push_back("Sail onto the lighthouse.");
	OpenOcean->addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You run up to the lighthouse, and inside you see an elevator.");
	RoomDescription.push_back("You could return to the boat, if you wanted.");
	LightHouse->addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Return to the boat.");
	RoomDescription.push_back("Take the Elevator Down.");
	LightHouse->addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You walk into the lobby, dingy and grey.");
	RoomDescription.push_back("The Elevator still seems to work.");
	RaptureLobby->addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Take the elevator.");
	RoomDescription.push_back("Walk further in.");
	RaptureLobby->addLinkDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("You have reached the room the DM has not made yet.");
	FirstTunnel->addRoomDescription(RoomDescription);
	RoomDescription.clear();
	RoomDescription.push_back("Shoot Go Back.");
	FirstTunnel->addLinkDescription(RoomDescription);
	RoomDescription.clear();
}

