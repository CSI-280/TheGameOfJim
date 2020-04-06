#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() //basic stats minus name
{
	mHealth = 100;
	mAttack = 5;
	mDefense = 5;
	mSpeed = 5;
	mExp = 0;
	mLevel = 1;
}

Player::Player(string name, string gender, int health, int attack, int defense, int speed, int exp, int level) //allows for creation of a character with any stats

{
	mName = name;
	mGender = gender;
	mHealth = health;
	mAttack = attack;
	mDefense = defense;
	mSpeed = speed;
	mExp = exp;
	mLevel = level;
}

Player::~Player() {}

string Player::getPlayerName() { return mName; } //getters and setters (boring stuff)

string Player::getPlayerGender() { return mGender; }

string Player::getPlayerPronoun1() { return mPronoun1; }

string Player::getPlayerPronoun2() { return mPronoun2; }

string Player::getPlayerPronoun3() { return mPronoun3; }

int Player::getPlayerHealth() { return mHealth; }

int Player::getPlayerAttack() { return mAttack; }

int Player::getPlayeDefense() { return mDefense; }

int Player::getPlayerSpeed() { return mSpeed; }

int Player::getPlayerExp() { return mExp; }

int Player::getPlayerExpNeeded() { return mExpNeeded;}


void Player::setPlayerName(string name) { mName = name; }

void Player::setPlayerGender(string gender) { mGender = gender; }

void Player::setPlayerPronouns(string gender)
{
	if (gender == "Male") {
		mPronoun1 = "He";
		mPronoun2 = "Him";
		mPronoun3 = "His";
	}
	else if (gender == "Female") {
		mPronoun1 = "She";
		mPronoun2 = "Her";
		mPronoun3 = "Her";
	}
	else {
		mPronoun1 = "They";
		mPronoun2 = "Them";
		mPronoun3 = "Their";
	}
}

void Player::setPlayerHealth(int health) { mHealth = health; }

void Player::setPlayerAttack(int attack) { mAttack = attack; }

void Player::setPlayerDefense(int defense) { mDefense = defense; }

void Player::setPlayerSpeed(int speed) { mSpeed = speed; }

void Player::setPlayerExp(int exp) { mExp = exp; }

void Player::setPlayerExpNeeded(int expNeeded) {mExpNeeded = expNeeded}


void calcPlayerExp(int expAwarded)
{
	mExp += expAwarded;
	mExpNeeded -= expAwarded;
	if (mExp >= mExpNeeded)
	{
		levelUp();
	}

	else
	{
		cout << mExpNeeded << " experience needed to reach next level.\n";
	}
}

void Player::levelUp()
{
		mLevel += 1;
		mHealth += 5;
		mAttack += 2;
		mDefense += 2;
		mSpeed += 2;
		cout << "Congrats, you're now level " << mLevel << "!" << endl;
}
