#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <vector>
#include <list>
#include <unordered_map>
#include "Systems\Player.h"
#include "Systems\enemies.h"
#include "Systems\Combat.h"
#include "Systems\Rooms.h"
#include "Branches/intro.h"
#include "Branches/Example Branch/ExampleBranch.h"
#include "Branches/Rapture Branch/RaptureBranch.h"
#include "Branches/BaxterMansion/mansion1.h"
#include "Branches/BaxterMansion/mansion2.h"
#include "Branches/roomOne.cpp"
#include "Branches/Jacob/jacob_room.h"
#include "Branches/MikeSpaceAdventure/SpaceAdventure.h"
using namespace std;

int main()
{
	//cout << "InitialCode" << endl;

	unordered_map<string, Room*> RoomTable;
	unordered_map<string, Link*> LinkTable;
	unordered_map<string, Container*> ContainerTable;
	Enemies testEnemy;
	Player testPlayer;
	Inventory playerInventory;

	initBoringBranch(&RoomTable, &LinkTable, &ContainerTable, &playerInventory);
	initRaptureBranch(&RoomTable, &LinkTable, &ContainerTable, &playerInventory, &testPlayer);
	initMansion(&RoomTable, &LinkTable, &ContainerTable, &playerInventory);
	initMansion2(&RoomTable, &LinkTable, &ContainerTable, &playerInventory);
	initSpaceAdventure(&RoomTable, &LinkTable);
	//initFirstRoom(&RoomTable);
	//initKitchen(&RoomTable, &LinkTable, &ContainerTable, &playerInventory);
	//initLivingRoom(&RoomTable, &LinkTable, &ContainerTable, &playerInventory);
	//goingOutside(&RoomTable, &LinkTable, &ContainerTable, &playerInventory);

	//intro(testPlayer);
	//playGame(LinkTable["Empty Link to Boring Shed"]);
	//playGame(LinkTable["Link to LakeFront"]);
	//playGame(LinkTable["Empty Link to Decrepited Hallway"]);
	//playGame(LinkTable["Empty Link to Room of Return"]);
	//playGame(LinkTable["Empty Link to Space Ship"]);

	// combat(testPlayer, testEnemy);

	/*
		Create Rooms/Containers in maps.
		Create Link in map, give pointer to room/container.
		Give Rooms/Containers any links they are supposed to have.
		run playGame() with a pointer to the first room.
	*/

	deleteall(&RoomTable, &LinkTable, &ContainerTable);
	string noQuit;
	cin >> noQuit;
	return 0;
}