#include "Combat.h"

bool combat(Player thePlayer, Enemies theEnemy/*, Inventory playerInventory (if necessary later)*/)
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

	bool encounterActive = true;
	bool death = false;
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
			//Originally meant to be run, figured that might make progression screwy. For now this will be use item once we have consumables.
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