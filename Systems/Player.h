#pragma once
#include <string>

using namespace std;

class Player {
private:
	int mHealth, mAttack, mDefense, mSpeed, mExp, mExpNeeded, mLevel;
	string mName;
public:
	Player();
	Player(string, int, int, int, int, int, int);
	~Player();

	string getPlayerName();
	int getPlayerHealth();
	int getPlayerAttack();
	int getPlayeDefense();
	int getPlayerSpeed();
	int getPlayerExp();
	int getPlayerExpNeeded();

	void setPlayerName(string);
	void setPlayerHealth(int);
	void setPlayerAttack(int);
	void setPlayerDefense(int);
	void setPlayerSpeed(int);
	void setPlayerExp();
	void setPlayerExpNeeded();

	void LevelUp();
};