#include <iostream>
#include <map>
#include "player.h"
#include "enemy.h"

using namespace std;


int main()
{

    map<string, Enemy> Enemies;
    map<string, Item> Items;
    map<string, Armor> Armors;
    map<string, Spell> Spells;
    map<string, Weapon> Weapons;

    Enemies.insert(pair<string, Enemy>("Orc Fighter", Enemy("Basic Orc Fighter", "fighter", "orc", 1)));
    Enemies.insert(pair<string, Enemy>("Magical training dummy", Enemy("Magical Training Dummy", "Dummy", "Dummy", 1)));
    Weapons.insert(pair<string, Weapon>("Iron Sword", Weapon("Iron Sword", 10, "neutral")));
    Weapons.insert(pair<string, Weapon>("Longbow", Weapon("Longbow", 10, "Neutral")));
    Weapons.insert(pair<string, Weapon>("Staff", Weapon("Staff", 20, "Neutral")));
    Armors.insert(pair<string, Armor>("Iron Armor", Armor("Iron Armor", 5, 1, "Neutral")));
    Armors.insert(pair<string, Armor>("Lightning Armor", Armor("Lightning Armor", 10, 10, "Lightning")));
    Spells.insert(pair<string, Spell>("Fireball", Spell("Fireball", "Fire", "Burn", 10, 10)));
    Spells.insert(pair<string, Spell>("Thunderbolt", Spell("Thunderbolt", "Lightning", "Shock", 15, 15)));
    Spells.insert(pair<string, Spell>("Ice Spike", Spell("Ice Spike", "Ice", "Freeze", 20, 10)));
    Items.insert(pair<string, Item>("Health Potion", Item("Health Potion", "Potion")));
    Items.insert(pair<string, Item>("Mana Potion", Item("Mana Potion", "Potion")));
    Items.insert(pair<string, Item>("Bomb", Item("Bomb", "Bomb")));


    //use
    Enemy orcfighter = Enemies["Orc Fighter"];
    Item healthpot = Items["Health Potion"];

    cout << orcfighter.level;


    return 0;
}
