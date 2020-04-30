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
    {"Bomb", Item("Bomb", "Bomb")},
    {"Gold Pouch", Item("Gold Pouch", "Gold Pouch")}
};
std::map<std::string, Armor> Armors = {
    {"None", Armor("None", 0, 0, "Neutral")},
    {"Iron Armor", Armor("Iron Armor", 10, 5, "Neutral")},
    {"Lightning Armor", Armor("Lightning Armor", 25, 25, "Neutral")},
    {"Cursed Armor", Armor("Cursed Armor", 20, 15, "dark")},
    {"Damascus Armor", Armor("Damascus Armor", 40, 40, "Neutral")},
    {"Gear Armor", Armor("Gear Armor", 50, 50, "Neutral")},
    {"Void Armor", Armor("Void Armor", 60, 60, "dark")},
    {"Armor of a thousand souls", Armor("Armor of a thousand souls", 70, 70, "Neutral")}
};
std::map<std::string, Spell> Spells = {
    {"Fireball", Spell("Fireball", "Fire", "Burn", 10, 10)},
    {"Lightning bolt", Spell("Lightning bolt", "Lightning", "Shock", 15, 15)},
    {"Ice Spike", Spell("Ice Spike", "Ice", "Freeze", 20, 10)},
    {"Holy Beam", Spell("Holy Beam", "Holy", "None", 10, 5)}
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
    {"Steel Sword", Weapon("Steel Sword", 20, "Neutral")},
    {"Damascus Sword", Weapon("Damascus Sword", 30, "Neutral")},
    {"Gear Sword", Weapon("Gear Sword", 40, "Neutral")},
    {"Void Sword", Weapon("Void Sword", 50, "Dark")},
    {"Sword of a thousand souls", Weapon("Sword of a thousand souls", 70, "Neutral")}
};
