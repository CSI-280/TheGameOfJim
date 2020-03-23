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
using namespace std;

class Item;
class Container;

class Link 
{
	public:
		virtual void follow();
};

class ContainerLink : private Link
{
	private:
		Container* mContainer;
	public:
		ContainerLink(Container* cContainer);
		bool CheckConditions();
		void follow();
};

class RoomLink : private Link
{
private:
	Room* mRoom;
public:
	RoomLink(Room* cRoom);
	bool CheckConditions();
	void follow();
};


class Container
{
	private:
		vector<Item> mItems;
		bool storage;
		bool takeable;
		string mName;
		vector<string> mContainerDescription;
		vector<Link> mLinks;
		vector<string> mLinkDescription;
	public:

};

class Room
{
	private:
		string mName;
		vector<string> mRoomDescription;
		vector<Link> mLinks;
		vector<string> mLinkDescription;
	public:
		Room(string cName);
		string getName();
		void setName(string cName);
		void printAll();
		int selection();
};