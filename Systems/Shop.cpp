#include "Shop.h"
#include <iostream>
#include <string>

using namespace std;

// Basic shop constructor
Shop::Shop()
{
	mNumofItems = 0;
	mShopOfferings = new Item[mNumofItems];
	mShopPrices = new int[mNumofItems];

}

// Small shop constructor
Shop::Shop(Item item1, int price1, Item item2, int price2, Item item3, int price3, Item item4, int price4)
{
	mNumofItems = 4;
	mShopOfferings = new Item[mNumofItems];
	mShopOfferings[0] = item1;
	mShopOfferings[1] = item2;
	mShopOfferings[2] = item3;
	mShopOfferings[3] = item4;

	mShopPrices = new int[mNumofItems];
	mShopPrices[0] = price1;
	mShopPrices[1] = price2;
	mShopPrices[2] = price3;
	mShopPrices[3] = price4;
}

// Large shop constructor	--- Not sure how big we wanted shops, can definitely take out items if it's too much
Shop::Shop(Item item1, int price1, Item item2, int price2, Item item3, int price3, Item item4, int price4,
	Item item5, int price5, Item item6, int price6, Item item7, int price7, Item item8, int price8,
	Item item9, int price9, Item item10, int price10)
{
	mNumofItems = 10;
	mShopOfferings = new Item[mNumofItems];
	mShopOfferings[0] = item1;
	mShopOfferings[1] = item2;
	mShopOfferings[2] = item3;
	mShopOfferings[3] = item4;
	mShopOfferings[4] = item5;
	mShopOfferings[5] = item6;
	mShopOfferings[6] = item7;
	mShopOfferings[7] = item8;
	mShopOfferings[8] = item9;
	mShopOfferings[9] = item10;

	mShopPrices = new int[mNumofItems];
	mShopPrices[0] = price1;
	mShopPrices[1] = price2;
	mShopPrices[2] = price3;
	mShopPrices[3] = price4;
	mShopPrices[4] = price5;
	mShopPrices[5] = price6;
	mShopPrices[6] = price7;
	mShopPrices[7] = price8;
	mShopPrices[8] = price9;
	mShopPrices[9] = price10;
}

Shop::~Shop()
{
	delete[] mShopOfferings;
}


void Shop::shopDialogue(Inventory playerInventory)
{
	string shopInput = "";
	int choice = 0;

	cout << "Hello and welcome to my shop.  Would you like to see what we have for sale? (Y/N)" << endl;
	cin >> shopInput;


	// Get player's response
	while (shopInput != "Y" || shopInput != "y" || shopInput != "N" || shopInput != "n")
	{
		cout << "Please answer (Y)es or (N)o." << endl;
		cin >> shopInput;
	}

	if (shopInput == "Y" || shopInput == "y")
	{
		cout << "Excellent!  Here's what we have!" << endl << endl;
		choice = displayItems();
		purchaseItem(choice, playerInventory);
	}

	else if (shopInput == "N" || shopInput == "n")
	{
		cout << "Oh...  Okay.  Then goodbye I guess..." << endl;
	}
}


int Shop::displayItems()
{
	int choiceNum = 0;
	bool moveOn = false;

	// Show all items for sale
	for (int i = 0; i < mNumofItems; ++i)
	{
		cout << "Item " << i+1 << ": " << mShopOfferings[i].getName() << "/t Price: " << mShopPrices[i] << endl
			<< "Item description: " << mShopOfferings[i].getDescription() << endl;
	}

	cout << "Which item would you like to buy?  Enter the corresponding item number. "
		<< "If you don't want to buy anything, just enter 0.";

	cin >> choiceNum;

	while (moveOn == false)
	{
		if (isdigit(choiceNum) == false)
		{
			cout << "Please enter only the item's number, or 0 to not buy anything."
		}

		if (isdigit(choiceNum) == true)
		{
			moveOn = true;
		}
	}

	return choiceNum;
}


Item Shop::purchaseItem(int choice, Inventory playerInventory)
{
	// Check if player has enough money?

	playerInventory.addItemToPlayerInventory(mShopOfferings[choice - 1]);
}