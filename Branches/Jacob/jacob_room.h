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

Item* Note = new Item();
Item* moldyBread = new Item();
Item* healthPotion = new Item();

void initKitchen(unordered_map<string, Room*>* Rooms, unordered_map<string, Link*>* Links, unordered_map<string, Container*>* Containers, Inventory* Inventory)
{
    
    //Initalize Data
    //(*BlandKey).setName("Bland Key");
    //(*HealthPotion).setName("Health Potion");
    Room* abandonedKitchen = new Room("Abandoned Kitchen"); //boring shed
    Container* dilapidatedCabinets = new Container("Dilapidated Cabinets", Inventory, false, false); //boring crate
    Container* Fridge = new Container("Fridge", Inventory, false, false); //boring chest
    EmptyLinkToRoom* elToKitchen = new EmptyLinkToRoom("Empty Link to the kitchen", abandonedKitchen);
    EmptyLinkToContainer* elToCabinets = new EmptyLinkToContainer("Empty Link to the cabinets", dilapidatedCabinets);
	EmptyLinkToContainer* elToFridge = new EmptyLinkToContainer("Empty Link to Fridge", Fridge);



    //Store Data in Maps
    (*Rooms).insert(pair<string, Room*>((*abandonedKitchen).getName(), abandonedKitchen));
    (*Containers).insert(pair<string, Container*>((*dilapidatedCabinets).getName(), dilapidatedCabinets));
    (*Containers).insert(pair<string, Container*>((*Fridge).getName(), Fridge));
    (*Links).insert(pair<string, Link*>((*elToKitchen).getName(), elToKitchen));
    (*Links).insert(pair<string, Link*>((*elToCabinets).getName(), elToCabinets));
    (*Links).insert(pair<string, Link*>((*elToFridge).getName(), elToFridge));

    //Connect Rooms with Links
    (*(*Rooms)["Abandoned Kitchen"]).addLink((*Links)["Empty Link to the cabinets"]);
    (*(*Rooms)["Abandoned Kitchen"]).addLink((*Links)["Empty Link to Fridge"]);
    (*(*Containers)["Dilapidated Cabinets"]).addLink((*Links)["Empty Link to the kitchen"]);
    (*(*Containers)["Fridge"]).addLink((*Links)["Empty Link to the kitchen"]);

    //Detailing
    (*(*Containers)["Dilapidated Cabinets"]).addItems(Note);//add in something like a Note for plot development
    (*(*Containers)["Fridge"]).addItems(moldyBread);//add in trash like moldyBread
    vector<string> RoomDescription;
    RoomDescription.push_back("You enter into the kitchen, it looks like it has been ransacked ");
    RoomDescription.push_back("Out of the corner of your eye you see some dilapidated cabinets ");
    RoomDescription.push_back("You notice a broken, flickering , fridge with something in it");
    (*(*Rooms)["Abandoned Kitchen"]).addRoomDescription(RoomDescription);
    RoomDescription.clear();
    RoomDescription.push_back("Inspect the Cabinets");
    RoomDescription.push_back("Inspect the Fridge");
    (*(*Rooms)["Abandoned Kitchen"]).addLinkDescription(RoomDescription);
    RoomDescription.clear();
    RoomDescription.push_back("You open up the cabinets.");
    (*(*Containers)["Dilapidated Cabinets"]).addContainerDescription(RoomDescription);
    RoomDescription.clear();
    RoomDescription.push_back("Stop Looking at the cabinets.");
    (*(*Containers)["Dilapidated Cabinets"]).addLinkDescription(RoomDescription);
    RoomDescription.clear();
    RoomDescription.push_back("You open up the Fridge.");
    (*(*Containers)["Fridge"]).addContainerDescription(RoomDescription);
    RoomDescription.clear();
    RoomDescription.push_back("Stop Looking at the Fridge.");
    (*(*Containers)["Fridge"]).addLinkDescription(RoomDescription);
    RoomDescription.clear();
}

void initLivingRoom(unordered_map<string, Room*>* Rooms, unordered_map<string, Link*>* Links, unordered_map<string, Container*>* Containers, Inventory* Inventory)
{
    //Initalize Datafewfgw
    //(*BlandKey).setName("Bland Key");
    //(*HealthPotion).setName("Health Potion");
    Room* ravagedLivingRoom = new Room("Ravaged Living Room"); //boring shed
    EmptyLinkToRoom* elToRavagedLivingRoom = new EmptyLinkToRoom("Empty Link to the living room", ravagedLivingRoom);
    //Store Data in Maps
    (*Rooms).insert(pair<string, Room*>((*ravagedLivingRoom).getName(), ravagedLivingRoom));

    //Connect Rooms with Links
    (*(*Rooms)["Ravaged Living Room"]).addLink((*Links)["Empty Link to Dilapidated Cabinets"]);
    //(*(*Rooms)["Abandoned ravagedLivingRoom"]).addLink((*Links)["Basic Key Check to Fridge"]);
    (*(*Containers)["Dilapidated Cabinets"]).addLink((*Links)["Empty Link to the living room"]);
    (*(*Containers)["Fridge"]).addLink((*Links)["Empty Link to the living room"]);

    //Detailing
    vector<string> RoomDescription;
    RoomDescription.push_back("As you look at this living room, you realize there has been an attack!");
    RoomDescription.push_back("There appear to be burn marks in small circles everywhere, like tiny lightning strikes");
    RoomDescription.push_back("The broken tv has what appears to be bullet holes in it.");
    RoomDescription.push_back("in the middle of room, you see a completely clean and unaffected circle, perhaps something special happened here.");
    (*(*Rooms)["Ravaged Living Room"]).addRoomDescription(RoomDescription);
    RoomDescription.clear();

}

void goingOutside(unordered_map<string, Room*>* Rooms, unordered_map<string, Link*>* Links, unordered_map<string, Container*>* Containers, Inventory* Inventory)
{
    //Initalize Data
    //(*BlandKey).setName("Bland Key");
    //(*HealthPotion).setName("Health Potion");
    Room* rightOutside = new Room("Outside the broken house"); //boring shed
    Container* halfCar = new Container("Car split cleanly in half", Inventory, false, true); //boring crate
    Container* mailbox = new Container("mailbox", Inventory, false, true); //boring chest
    EmptyLinkToRoom* elToOutside = new EmptyLinkToRoom("Empty Link to Outside the broken house", rightOutside);
    EmptyLinkToContainer* elTohalfCar = new EmptyLinkToContainer("Empty Link to the halfCar", halfCar);
	EmptyLinkToContainer* eltomailbox = new EmptyLinkToContainer("Empty Link to the Mailbox", mailbox);
    (*healthPotion).setName("Health Potion");

    //Store Data in Maps
    (*Rooms).insert(pair<string, Room*>((*rightOutside).getName(), rightOutside));
    (*Containers).insert(pair<string, Container*>((*halfCar).getName(), halfCar));
    (*Containers).insert(pair<string, Container*>((*mailbox).getName(), mailbox));
    (*Links).insert(pair<string, Link*>((*elToOutside).getName(), elToOutside));
    (*Links).insert(pair<string, Link*>((*elTohalfCar).getName(), elTohalfCar));
    (*Links).insert(pair<string, Link*>((*eltomailbox).getName(), eltomailbox));

    //Connect Rooms with Links
    (*(*Rooms)["Outside the broken house"]).addLink((*Links)["Empty Link to the halfCar"]);
    (*(*Rooms)["Outside the broken house"]).addLink((*Links)["Empty Link to the Mailbox"]);
    (*(*Containers)["Car split cleanly in half"]).addLink((*Links)["Empty Link to Outside the broken house"]);
    (*(*Containers)["mailbox"]).addLink((*Links)["Empty Link to Outside the broken house"]);

    //Detailing
    (*(*Containers)["Car split cleanly in half"]).addItems(healthPotion);
    vector<string> RoomDescription;
    RoomDescription.push_back("As you walk outside, you see burn marks similar to those inside the living room. ");
    RoomDescription.push_back("Tiny burn marks and bullet holes paint the walls of every nearby building. ");
    RoomDescription.push_back("You notice a car which is cleanly split in two, and on one side is a clean circle.");
    RoomDescription.push_back("Once again reminding you of the living room.");
    (*(*Rooms)["Outside the broken house"]).addRoomDescription(RoomDescription);
    RoomDescription.clear();
    RoomDescription.push_back("Inspect the halfCar");
    RoomDescription.push_back("Inspect the mailbox");
    (*(*Rooms)["Outside the broken house"]).addLinkDescription(RoomDescription);
    RoomDescription.clear();
    RoomDescription.push_back("You open up the cabinets.");
    (*(*Containers)["Car split cleanly in half"]).addContainerDescription(RoomDescription);
    RoomDescription.clear();
    RoomDescription.push_back("Stop Looking at the cabinets.");
    (*(*Containers)["Car split cleanly in half"]).addLinkDescription(RoomDescription);
    RoomDescription.clear();
    RoomDescription.push_back("You open up the mailbox.");
    (*(*Containers)["mailbox"]).addContainerDescription(RoomDescription);
    RoomDescription.clear();
    RoomDescription.push_back("Stop Looking at the mailbox.");
    (*(*Containers)["mailbox"]).addLinkDescription(RoomDescription);
    RoomDescription.clear();
}
