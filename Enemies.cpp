#include  "main.cpp"
#include "enemies.h"

using namespace std;

class enemies {
Private :
	//armor MIGHT be a damage reduction based on level
	//speed can dictate who attacks first and if the speed is high enough, possibly the enemy can attack twice before the player


Public :
	getSpeed() { return speed; }
	setSpeed(newSpeed) { speed == newSpeed; }

	getArmor() { return armor; }
	setArmor(newArmor) { armor == newArmor; }

	getHealth() { return health; }
	setHealth(newHealth) { health == newHealth; }

	getName() { return name; }
	setName(newName) { name == newName; }

	attack(/*player class type*/) {

	}

	
};