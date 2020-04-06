#include "Combat.h"

bool combat(Player thePlayer, Enemies theEnemy, Inventory playerInventory)
{
	//grab the player's values. this can be updated later to handle inventory changes.
	int health = thePlayer.getPlayerHealth();
	int attack = thePlayer.getPlayerAttack();
	int speed = thePlayer.getPlayerSpeed();
	int defense = thePlayer.getPlayeDefense();
	string name = thePlayer.getPlayerName();
	//grab enemy values
	int enemyHealth = theEnemy.getHealth();
	int enemyAttack = theEnemy.getAttack();
	int enemySpeed = theEnemy.getSpeed();
	int enemyDefense = theEnemy.getArmor();
	string enemyName = theEnemy.getName();



	// NOTE: This will probably need to be tweaked in the future, the current system of items doesn't seem to have a proper way to identify what is a weapon, armor piece, consumable, etc.
	// For now treat this as pseudocode

	//Apply the player's inventory items to their stats. 
	// Since indexes 0 - 3 are the weapons and armor, they will be the only ones that are applied.
	for (int i = 0; i < 4; i++)
	{
		if (i == 0) //The weapon slot (0)
		{
			Weapons theWeapon = playerInventory.getItem(i); //Grab the item in the weapon slot
			attack += theWeapon.getAttack(); //Add the weapon's attack stat to the player's base attack
		}
		else //The armor slots (1 - 3)
		{
			Armor theArmor = playerInventory.getItem(i); //Grab the item in the armor slots
			defense += theArmor.getDefense(); //Add the armor's defense stat to the player's base defense
		}
			
	}


	bool encounterActive = true;
	bool death = false;
	bool consumed = false;
	int choice;

	while (encounterActive == true)
	{
		cout << "[ " << name << " ]  " << "HP: " << health << "  ATK: " << attack << "  SPD: " << speed << "  DEF: " << defense << endl;
		cout << "[ " << enemyName << " ]  " << "HP: " << enemyHealth << "  ATK: " << enemyAttack << "  SPD: " << enemySpeed << "  DEF: " << enemyDefense << endl;

		cout << "You are faced by " + enemyName + ", what do you do?" << endl;
		cout << "1. Light Attack" << endl
			<< "2. Strong Attack" << endl
			<< "3. Defend" << endl
			<< "4. Use Item" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			//Light attack, normal speed. We can change these later if we want to use different menu options or balancing.
			encounterActive = damageCalc(health, defense, speed, attack, enemyHealth, enemyDefense, enemySpeed, enemyAttack, name, enemyName, encounterActive, death);
			system("pause");
			system("cls");
			break;
		case 2:
			//Strong attack, lower speed but higher attack. We can also rebalance this later.
			encounterActive = damageCalc(health, defense, speed - 2, attack + 3, enemyHealth, enemyDefense, enemySpeed, enemyAttack, name, enemyName, encounterActive, death);
			system("pause");
			system("cls");
			break;
		case 3:
			//Testing a "Defend" option that increases player defense but cuts speed and attack.
			encounterActive = damageCalc(health, defense + 10, speed - 10, attack - 3, enemyHealth, enemyDefense, enemySpeed, enemyAttack, name, enemyName, encounterActive, death);
			system("pause");
			system("cls");
			break;
		case 4:
			//For now this is only set up for healing consumables.
			useConsumable(thePlayer, health, playerInventory);
			system("pause");
			system("cls");
			break;
		default:
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Please choose one of the menu options." << endl;
		}
	}

	//Encounter is over. Return whether or not player died.
	if (death == false)
		thePlayer.setPlayerHealth(health);

	return death;

}

bool damageCalc(int& health, int defense, int speed, int attack, int& enemyHealth, int enemyDefense, int enemySpeed, int enemyAttack, string name, string enemyName, bool encounterActive, bool& death)
{
	bool miss = false;

	if (speed >= enemySpeed) // Player gets first attack
	{
		// 10% chance for crits and misses
		if (random(10) == 1)
			attack *= 2; //Crit!
		else if (random(10) == 2)
			miss = true; //Miss!

		if (miss == false) //If the player didn't miss
			//Basic defense calculation, remove defense as a percentage of health.
			enemyHealth -= attack - (attack * (enemyDefense * 0.01));

		if (miss == true)
			cout << "You missed!" << endl;
		else
			cout << "You deal " << attack - (attack * (enemyDefense * 0.01)) << " damage to " << enemyName << endl;
		if (enemyHealth <= 0)
		{
			cout << "You defeated " << enemyName << "!" << endl;
			encounterActive = false;
			return encounterActive;
		}
		miss = false; // Reset miss value

		// 10% chance for crits and misses
		if (random(10) == 1)
			enemyAttack *= 2; //Crit!
		else if (random(10) == 2)
			miss = true; //Miss!

		if (miss == false) //If the enemy didn't miss
			//Basic defense calculation, remove defense as a percentage of health.
			health -= enemyAttack - (enemyAttack * (defense * 0.01));

		if (miss == true)
			cout << enemyName << " missed!" << endl;
		else
			cout << enemyName << " deals " << enemyAttack - (enemyAttack * (defense * 0.01)) << " damage to you." << endl;
		if (health <= 0)
		{
			//Player has died, update death bool
			cout << "Out of HP, game over!" << endl;
			encounterActive = false;
			death = true;
			return encounterActive;
		}
		miss = false;
	}
	else // Enemy gets first attack
	{

		// 10% chance for crits and misses
		if (random(10) == 1)
			enemyAttack *= 2; //Crit!
		else if (random(10) == 2)
			miss = true; //Miss!

		if (miss == false) //If the enemy didn't miss
			//Basic defense calculation, remove defense as a percentage of health.
			health -= enemyAttack - (enemyAttack * (defense * 0.01));

		if (miss == true)
			cout << enemyName << " missed!" << endl;
		else
			cout << enemyName << " deals " << enemyAttack - (enemyAttack * (defense * 0.01)) << " damage to you." << endl;
		if (health <= 0)
		{
			//Player has died, update death bool
			cout << "Out of HP, game over!" << endl;
			encounterActive = false;
			death = true;
			return encounterActive;
		}

		// 10% chance for crits and misses
		if (random(10) == 1)
			attack *= 2; //Crit!
		else if (random(10) == 2)
			miss = true; //Miss!

		if (miss == false) //If the player didn't miss
			//Basic defense calculation, remove defense as a percentage of health.
			enemyHealth -= attack - (attack * (enemyDefense * 0.01));

		if (miss == true)
			cout << "You missed!" << endl;
		else
			cout << "You deal " << attack - (attack * (enemyDefense * 0.01)) << " damage to " << enemyName << endl;
		if (enemyHealth <= 0)
		{
			cout << "You defeated " << enemyName << "!" << endl;
			encounterActive = false;
			return encounterActive;
		}
	}

	return encounterActive;
}


// This will also need to be tweaked in the future since there seems to be no reliable way at the moment to tell what items are consumables
void useConsumable(Player thePlayer, int& health, Inventory playerInventory)
{
	int choice;
	bool choiceMade = false;
	Consumables theConsumable;

	cout << "What item would you like to use? " << endl;

	for (int i = 4; i <= 15; i++) //Print item choice menu, everything after the active inventory slots (weapons/armor). Could be tweaked later to just show consumables.
		cout << i - 3 << ". " << playerInventory.getItem(i);
	cout << "0. Cancel" << endl;

	while choiceMade = false;
	{
		cin >> choice;

		if (choice > 0 && choice <= 12) //Valid choice for now
		{
			//There needs to be some way to identify whether or not an item in the inventory is a consumable
			//Will probably have to be changed in the future.
			cout << "You used your " << playerInventory.getItem(choice + 3);
			theConsumable = playerInventory.getItem(choice + 3);
			health += theConsumable.getHealing();
			choiceMade = true;
		}
		else if (choice == 0)
		{
			cout << "Cancelling..." << endl;
			choiceMade = true;
		}
		else
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Please choose a valid option." << endl;
		}
	}
}