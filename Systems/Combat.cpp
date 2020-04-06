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

	//status effects
	bool isBurned = false;
	bool isPoisoned = false;
	bool isAsleep = false;
	bool isParalyzed = false;

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

//not sure how to implement turn durations? for example, burn and poison could last 3 turns and then it would go away. 
void statusBurn(int& health, string name) //takes 10% off of player's current health
{
	int burnDamage = health * 0.1;
	health -= burnDamage;

	cout << name " is burned!\n" << burnDamage << " damage is taken.\n" << health << " HP remains.\n";
}

bool statusParalysis(int& speed, string name)
{
	bool canMove = true;
	int speedDeduct = speed - 2;
	if (random(10) == 5) //random chance to be completely paralyzed for a turn
	{
		canMove = false;
		cout << name << " is paralyzed and unable to move!\n";
		
		return canMove;
	}

	cout << name << " is paralyzed! Speed has been reduced.\n";

	return canMove;
}

bool statusSleep(string name)
{
	bool awake = false;
	if (random(10) == 3 || random(10) == 5) //random chance to wake up again, won't wake up otherwise
	{
		bool awake = true;
		cout << name << " is no longer alseep!\n";
	}
	cout << name << " is fast alseep!\n";
}

void statusPoison(int& health, string name)
{
	int poisonDamage = health * 0.2;
	health -= poisonDamage;

	cout << name << " is poisoned!\n" << poisonDamage << " damage is taken.\n" << health << " HP remains.\n";

	if (random(10) == 9)
	{
		poisonDamage = health * 0.3; //crit poison
		health -= poisonDamage

		cout << name << " has been severely poisoned!\n" << poisonDamage << " damage is taken.\n" << health << " HP remains.\n";
	}
}