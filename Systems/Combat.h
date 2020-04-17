#include "Player.h"
#include "enemies.h"
#include "Inventory.h"
#include "Item.h"
#include "weapons.h"
#include "armor.h"
#include "Consumables.h"
#include "Rand-Num.h"

using namespace std;

bool combat(Player, Enemies, Inventory);
bool damageCalc(int&, int, int, int, int&, int, int, int, string, string, bool, bool&);
// void useConsumable(Player, int&, Inventory);