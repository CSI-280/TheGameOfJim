#pragma once
#include "Item.h"
#include "Inventory.h"

class Shop {
public:
	// Constructors
	Shop();
	Shop(Item item1, int price1, Item item2, int price2, Item item3, int price3, Item item4, int price4);
	Shop(Item item1, int price1, Item item2, int price2, Item item3, int price3, Item item4, int price4,
		Item item5, int price5, Item item6, int price6, Item item7, int price7, Item item8, int price8,
		Item item9, int price9, Item item10, int price10);

	void shopDialogue(Inventory playerInventory);
	int displayItems();
	Item purchaseItem(int choice, Inventory playerInventory);
	
	// Deconstructor
	~Shop();

private:
	int mNumofItems;

	// Array for the items the shop sells
	Item* mShopOfferings;

	// Array for the prices of the items
	int* mShopPrices;
};