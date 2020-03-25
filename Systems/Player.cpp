#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() //basic stats minus name
{
	mHealth = 100;
	mAttack = 5;
	mDefense = 5;
	mSpeed = 5;
}

Player::Player(string name, int health, int attack, int defense, int speed) //allows for creation of a character with any stats
{
	mName = name;
	mHealth = health;
	mAttack = attack;
	mDefense = defense;
	mSpeed = speed;
}

Player::~Player() {}

string Player::getPlayerName() { return mName; } //getters and setters (boring stuff)

int Player::getPlayerHealth() { return mHealth; }

int Player::getPlayerAttack() { return mAttack; }

int Player::getPlayeDefense() { return mDefense; }

int Player::getPlayerSpeed() { return mSpeed; }

void Player::setPlayerName(string name) { mName = name; }

void Player::setPlayerHealth(int health) { mHealth = health; }

void Player::setPlayerAttack(int attack) { mAttack = attack; }

void Player::setPlayerDefense(int defense) { mDefense = defense; }

void Player::setPlayerSpeed(int speed) { mSpeed = speed; }
