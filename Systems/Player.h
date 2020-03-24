#pragma once

using namespace std;

class Player {
private:
	int mHealth, mAttack, mDefense, mSpeed;
	string mName;
public:
	Player();
	Player(string, int, int, int, int);
	~Player();

	string getPlayerName();
	int getPlayerHealth();
	int getPlayerAttack();
	int getPlayeDefense();
	int getPlayerSpeed();

	void setPlayerName(string);
	void setPlayerHealth(int);
	void setPlayerAttack(int);
	void setPlayerDefense(int);
	void setPlayerSpeed(int);
};