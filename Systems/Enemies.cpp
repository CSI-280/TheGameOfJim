#include "enemies.h"


//default constructor	
Enemies::Enemies()
{
	mHealth = 100;
	mArmor = 5;
	mSpeed = 5;
	mAttack = 5;
	mName = "Billy the Bin";
}

//Overloaded constructor
Enemies::Enemies(int health, int armor, int speed, int attack, string name)
{
	mHealth = health;
	mArmor = armor;
	mSpeed = speed;
	mAttack = attack;
	mName = name;

}

//Destructor
Enemies::~Enemies() {}




