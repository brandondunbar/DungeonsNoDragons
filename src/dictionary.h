#pragma once
#include <iostream>
#include <map>
#include <string>
#include "player.h"
#include "enemy.h"

std::map<std::string, Enemy> Enemies = {
    {"Orc Fighter", Enemy("Basic Orc Fighter", "fighter", "orc", 1)},
    {"Magical Training Dummy", Enemy("Magical Training Dummy", "Dummy", "Dummy", 1)}
};
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
    {"Thunderbolt", Spell("Thunderbolt", "Lightning", "Shock", 15, 15)},
    {"Ice Spike", Spell("Ice Spike", "Ice", "Freeze", 20, 10)}
};
std::map<std::string, Weapon> Weapons = {
    {"Iron Sword", Weapon("Iron Sword", 10, "neutral")},
    {"Longbow", Weapon("Longbow", 10, "Neutral")},
    {"Staff", Weapon("Staff", 20, "Neutral")}
};
