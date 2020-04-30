/*dictionary of various items, armor, spells, weapons, and enemies*/

#pragma once
#include <iostream>
#include <map>
#include <string>
#include "player.h"
#include "enemy.h"

/*std::map<std::string, Enemy> Enemies = {
    {"Orc Fighter", Enemy("Basic Orc Fighter", "fighter", "orc")},
    {"Magical Training Dummy", Enemy("Magical Training Dummy", "Dummy", "Dummy")}
};*/
std::map<std::string, Item> Items = {
    {"Health Potion", Item("Health Potion", "Potion")},
    {"Mana Potion", Item("Mana Potion", "Potion")},
    {"Bomb", Item("Bomb", "Bomb")}
};
std::map<std::string, Armor> Armors = {
    {"Iron Armor", Armor("Iron Armor", 5, 1, "Neutral")},
    {"Lightning Armor", Armor("Lightning Armor", 10, 10, "Lightning")}
};
std::map<std::string, Spell> Spells = {
    {"Fireball", Spell("Fireball", "Fire", "Burn", 10, 10)},
    {"Lightning bolt", Spell("Lightning bolt", "Lightning", "Shock", 15, 15)},
    {"Ice Spike", Spell("Ice Spike", "Ice", "Freeze", 20, 10)}
};
std::map<std::string, Weapon> Weapons = {
    {"Iron Sword", Weapon("Iron Sword", 10, "neutral")},
    {"Longbow", Weapon("Longbow", 10, "Neutral")},
    {"Staff", Weapon("Staff", 20, "Neutral")},
    {"Dull Magic Sword", Weapon("Dull Magic Sword", 3, "Neutral")},
    {"Rusty Great Sword", Weapon("Rusty Great Sword", 10, "Neutral")},
    {"Dusty Magic Tome", Weapon("Dusty Magic Tome", 4, "Magic")},
    {"Pine Magic Staff", Weapon("Pine Magic Staff", 4, "Magic")},
    {"Short Bow", Weapon("Short Bow", 7, "Neutral")},
    {"Chipped Dual Daggers", Weapon("Chipped Dual Daggers", 4, "Neutral")},
};
