#pragma once

#include "Rooms.h"

Link::Link(Container* cContainer)
{
	mType = true;
	mContainer = cContainer;
	mRoom = nullptr;
}

Link::Link(Room* cRoom)
{
	mType = false;
	mContainer = nullptr;
	mRoom = cRoom;
}

void Link::follow()
{
	if (mType)
	{
		(*mContainer).executeContainer();
	}
	else
	{
		(*mRoom).executeRoom();
	}
}

Container::Container(string cName, Inventory* cTrackedInventory, bool cStorage, bool cTakeable)
{
	mName = cName;
	mTrackedInventory = cTrackedInventory;
	storage = cStorage;
	takeable = cTakeable;
}

void Container::addLink(Link* cLink)
{
	mLinks.push_back(cLink);
}

void Container::addContainerDescription(vector<string> cDescription)
{
	mContainerDescription = cDescription;
}

void Container::addLinkDescription(vector<string> cDescription)
{
	mLinkDescription = cDescription;
}

Inventory* Container::getTrackedInventory()
{
	return mTrackedInventory;
}

void Container::setTrackedInventory(Inventory* cTrackedInventory)
{
	mTrackedInventory = cTrackedInventory;
}

void Container::printAll(bool printName)
{
	int i;
	if (printName)
	{
		cout << mName << endl;
		cout << endl;
	}
	for (i = 0; i < mContainerDescription.size(); i++)
	{
		cout << mContainerDescription[i] << endl;
	}
	cout << endl;
	for (i = 0; i < mLinkDescription.size(); i++)
	{
		cout << i << ") " << mLinkDescription[i] << endl;
	}
	if (takeable && mItems.size != 0)
	{
		cout << i << ") Take Items" << endl;
		i++;
	}
	if (storage)
	{
		cout << i << ") Store Items" << endl;
	}

}

int Container::executeContainer()
{
	int choice, choice2;
	int i;
	bool input = true;
	printAll();
	cout << "What will you do? (Please input a number.)" << endl;
	cin >> choice;
	cout << endl;
	do
	{
		if (choice < mLinks.size())
		{
			input = true;
			if ((*mLinks[choice]).checkConditions())
			{
				(*mLinks[choice]).follow();
			}
			else
			{
				cout << "You can't do that!" << endl;
				input = false;
			}
		}
		else if (choice == mLinks.size() && takeable && mItems.size != 0)
		{
			input = false;
			cout << "0) Take Nothing." << endl;
			for (i = 1; i <= mItems.size(); i++)
			{
				cout << i << ") " << mItems[i - 1].name << endl;
			}
			cout << "Which will you take? (Please input a number.)" << endl;
			cin >> choice2;
			cout << endl;
			if (choice2 > 0 && choice2 <= mItems.size())
			{
				(*mTrackedInventory).addItemToPlayerInventory(mItems[choice2 - 1]);
				mItems.erase(mItems.begin + (choice2 - 1));
			}
		}
		else if ((choice == mLinks.size() + 1 && takeable && mItems.size != 0 && storage) || (choice == mLinks.size() && (!takeable || !mItems.size != 0) && storage))
		{
			input = false;
			cout << "0) Store Nothing." << endl;
			for (i = 1; i <= (*mTrackedInventory).getPlayerInventorySize(); i++)
			{
				cout << i << ") " << (*mTrackedInventory).getItem(i - 1).name << endl;
			}
			cout << "Which will you Store? (Please input a number.)" << endl;
			cin >> choice2;
			cout << endl;
			if (choice2 > 0 && choice2 <= (*mTrackedInventory).getPlayerInventorySize())
			{
				Item subject = (*mTrackedInventory).getItem(i - 1);
				mItems.push_back(subject);
				(*mTrackedInventory).removeItemFromPlayerInventory(subject);
			}
		}
		else
		{
			input = false;
		}
	} while (!input);

}

Room::Room(string cName)
{
	mName = cName;
}

void Room::addLink(Link* cLink)
{
	mLinks.push_back(cLink);
}

void Room::addRoomDescription(vector<string> cDescription)
{
	mRoomDescription = cDescription;
}

void Room::addLinkDescription(vector<string> cDescription)
{
	mLinkDescription = cDescription;
}

void Room::printAll(bool printName)
{
	int i;
	if (printName)
	{
		cout << mName << endl;
		cout << endl;
	}
	for (i = 0; i < mRoomDescription.size(); i++)
	{
		cout << mRoomDescription[i] << endl;
	}
	cout << endl;
	for (i = 0; i < mLinkDescription.size(); i++)
	{
		cout << i << ") " << mLinkDescription[i] << endl;
	}
}

int Room::executeRoom()
{
	int choice, choice2;
	int i;
	bool input = true;
	printAll();
	do
	{
		cout << "What will you do? (Please input a number.)" << endl;
		cin >> choice;
		cout << endl;

		if (choice < mLinks.size())
		{
			input = true;
			if ((*mLinks[choice]).checkConditions())
			{
				(*mLinks[choice]).follow();
			}
			else
			{
				cout << "You can't do that!" << endl;
				input = false;
			}
		}
		else
		{
			input = false;
		}
	} while (!input);
}