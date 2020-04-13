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
#include "Item.h"
#include "Inventory.h"

class Container;
class Room;

void deleteall(unordered_map<string, Room*>* Rooms, unordered_map<string, Link*>* Links, unordered_map<string, Container*>* Containers);

class Link
{
	/*
	Link is a base class. It is virtual, meaning the classes defined as children of it must
	define the function CheckConditions itself. Once the conditions have been programmed, the
	Link may be used to access containers or rooms, simply by pushing them to the previous room/container.
	Children should ONLY define the checkConditions function.
	*/
	private:
		Container* mContainer;
		Room *mRoom;
		bool mType;
		string mName;
	public:
		Link(string cName, Container* cContainer);
		Link(string cName, Room* cRoom);
		Link() {};
		string getName();
		virtual bool checkConditions() = 0;
		Link* follow();
};

void playGame(Link* cLink);
//void loadBranchExample(unordered_map<string,Room*> Rooms, unordered_map<string, Link*> Links, unordered_map<string, Container*> Containers);

class Container
{
	/*
	Containers may contain items. They work similarly to rooms, allowing links in and out of them.
	You can specify if the player may add items to the container (storage) and if the player may 
	remove items from the container to take them (takeable). Both default to true.
	Containers are assumed to be unlocked. To lock a container, use a Link!
	Containers need a pointer to the inventory to modify it. (Likely the player's.)
	*/
	private:
		vector<Item*> mItems;
		Inventory* mTrackedInventory;
		bool storage;
		bool takeable;
		string mName;
		vector<string> mContainerDescription;
		vector<Link*> mLinks;
		vector<string> mLinkDescription;
	public:
		Container(string cName, Inventory* cTrackedInventory, bool cStorage = true, bool cTakeable = true);
		string getName();
		void addItems(Item* cItem);
		void addLink(Link* cLink);
		void addContainerDescription(vector<string> cDescription);
		void addLinkDescription(vector<string> cDescription);
		Inventory* getTrackedInventory();
		void setTrackedInventory(Inventory* cTrackedInventory);
		void printAll(bool printName = false);
		Link* executeContainer();
};

class Room
{
	/*
	Rooms are simple containers. They work similarly to containers, allowing links in and out of them.
	They cannot contain items. If the room is expected to contain items, consider linking a container to 
	the room, or simply making the "Room" a container.
	Rooms are assumed to be unlocked. To lock a room, use a Link!
	*/
	private:
		string mName;
		vector<string> mRoomDescription;
		vector<Link*> mLinks;
		vector<string> mLinkDescription;
	public:
		Room(string cName);
		string getName();
		void addLink(Link* cLink);
		void addRoomDescription(vector<string> cDescription);
		void addLinkDescription(vector<string> cDescription);
		void printAll(bool printName = false);
		Link* executeRoom();
};