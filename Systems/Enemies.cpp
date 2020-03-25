#include "enemies.h"


//default constructor	
Enemies::Enemies()
{
	mHealth = 100;
	mArmor = 100;
	mSpeed = 100;
	mName = "Billy the Bin";
}

//Overloaded constructor
Enemies::Enemies(int health, int armor, int speed, string name) 
{
	mHealth = health;
	mArmor = armor;
	mSpeed = speed;
	mName = name;

}



	
