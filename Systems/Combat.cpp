#include "Combat.h"

void combat(Player thePlayer, Enemies theEnemy/*, Inventory playerInventory (if necessary later)*/)
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
	int choice;

	while (encounterActive == true)
	{
		cout << "[ " << name << " ]  " << "HP: " << health << "  ATK: " << attack << "  SPD: " << speed << "  DEF: " << defense << endl;
		cout << "[ " << enemyName << " ]  " << "HP: " << enemyHealth << "  ATK: " << enemyAttack << "  SPD: " << enemySpeed << "  DEF: " << enemyDefense << endl;

		cout << "You are faced by " + enemyName + ", what do you do?" << endl;
		cout << "1. Light Attack" << endl
			<< "2. Strong Attack" << endl
			<< "3. Use Item" << endl
			<< "4. Run" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			//Light attack, normal speed. We can change these later if we want to use different menu options or balancing.
			encounterActive = damageCalc(health, defense, speed, attack, enemyHealth, enemyDefense, enemySpeed, enemyAttack, name, enemyName, encounterActive);
			system("pause");
			system("cls");
			break;
		case 2:
			//Strong attack, lower speed but higher attack. We can also rebalance this later.
			encounterActive = damageCalc(health, defense, speed - 2, attack + 3, enemyHealth, enemyDefense, enemySpeed, enemyAttack, name, enemyName, encounterActive);
			system("pause");
			system("cls");
			break;
		case 3:
			//To be added once inventory is all set up. Could also be replaced with a different option like "Defend" or something.
			system("pause");
			system("cls");
			break;
		case 4:
			//To be added once the random number generator is set up. 
			//Planning to make it so if player speed is higher than enemy, they can always run, but if lower it could be decided by giving it a (player speed / enemy speed) chance.
			system("pause");
			system("cls");
			break;
		default:
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Please choose one of the menu options." << endl;
		}
	}

	//Encounter is over. For now this just handles setting the player's health to their new amount. If we don't want this it can be changed later.

	thePlayer.setPlayerHealth(health);

	//This is where we'll handle drops and returning to the room once those are set up.

}

bool damageCalc(int& health, int defense, int speed, int attack, int& enemyHealth, int enemyDefense, int enemySpeed, int enemyAttack, string name, string enemyName, bool encounterActive)
{
	if (speed >= enemySpeed) // Player gets first attack
	{
		//I'm going to leave out defense calculations for now until we decide how we want them set up. We can also work on miss/crit RNG later.
		enemyHealth -= attack;
		cout << "You deal " << attack << " damage to " << enemyName << endl;
		if (enemyHealth <= 0)
		{
			cout << "You defeated " << enemyName << "!" << endl;
			encounterActive = false;
			return encounterActive;
		}
		health -= enemyAttack;
		cout << enemyName << " deals " << enemyAttack << " damage to you." << endl;
		if (health <= 0)
		{
			//We'll have to decide what happens on death.
			cout << "Out of HP, game over!" << endl;
			encounterActive = false;
			return encounterActive;
		}
	}
	else // Enemy gets first attack
	{
		health -= enemyAttack;
		cout << enemyName << " deals " << enemyAttack << " damage to you." << endl;
		if (health <= 0)
		{
			cout << "Out of HP, game over!" << endl;
			encounterActive = false;
			return encounterActive;
		}
		enemyHealth -= attack;
		cout << "You deal " << attack << " damage to " << enemyName << endl;
		if (enemyHealth <= 0)
		{
			cout << "You defeated " << enemyName << "!" << endl;
			encounterActive = false;
			return encounterActive;
		}
	}

	return encounterActive;
}


