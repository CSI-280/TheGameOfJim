#include "Player.h"
#include "enemies.h"
#include "Inventory.h"
#include "Item.h"
#include "weapons.h"
#include "armor.h"
#include "Consumables.h"
#include "Rand-Num.h"

using namespace std;

bool combat(Player thePlayer, Enemies theEnemy, Inventory playerInventory);
bool damageCalc(int& health, int defense, int speed, int attack, int& enemyHealth, int enemyDefense, int enemySpeed, int enemyAttack, string name, string enemyName, bool encounterActive, bool& death);
// void useConsumable(Player, int&, Inventory);