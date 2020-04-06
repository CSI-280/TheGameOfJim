#pragma once
#include <string>

using namespace std;

class Player {
private:
	int mHealth, mAttack, mDefense, mSpeed;
	string mName, mGender, mPronoun1, mPronoun2, mPronoun3;
public:
	Player();
	Player(string, string, int, int, int, int);
	~Player();

	string getPlayerName();
	string getPlayerGender();
	string getPlayerPronoun1();
	string getPlayerPronoun2();
	string getPlayerPronoun3();
	int getPlayerHealth();
	int getPlayerAttack();
	int getPlayeDefense();
	int getPlayerSpeed();

	void setPlayerName(string);
	void setPlayerGender(string);
	void setPlayerPronouns(string);
	void setPlayerHealth(int);
	void setPlayerAttack(int);
	void setPlayerDefense(int);
	void setPlayerSpeed(int);
};