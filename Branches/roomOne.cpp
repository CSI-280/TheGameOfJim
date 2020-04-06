#include "roomOne.h"
#include "rooms.h"
#include "Item.h"
#include "inventory.h"
#include "JacobRoom.h"

int main()
{
	Room Rooms("RoomOne");
	vector<string> RoomOne;
	RoomOne.push_back("You wake up!");
	RoomOne.push_back("You find yourself alone in a dark room. Scared you get up and look around.");
	RoomOne.push_back("It is so dark you can barely see 5 feet in front of you but you think from the breeze on your face you are outside.");
	RoomOne.push_back("How you got here and where you go next is what you must find out.");
	Rooms.addRoomDescription(RoomOne);
	Room* ptr = &Rooms;
	JLink JacobRoom(ptr);
	Rooms.addLink(&JacobRoom);
	vector<string> Description;
	Description.push_back("test");
	Rooms.addLinkDescription(Description);
	Rooms.executeRoom();
}
