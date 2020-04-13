
//=================================
// Include Guard
#ifndef __ENEMY_H_INCLUDED__   // if enemy.h hasn't been included yet...
#define __ENEMY_H_INCLUDED__   //   #define this so the compiler knows it has been included

//=================================
// Included Dependencies
#include <vector>
#include <string>
#include "character.h"
#include "item.h"

//=================================
class Enemy : public Character {

    public:

        Enemy(std::string _name, std::string _class="fighter", std::string _race="goblin", int _level=1);
        Enemy() = default;

        std::string element = "neutral";
        std::vector<Item> loot;

};

// Constructor
Enemy::Enemy(std::string _name, std::string _class, std::string _race, int _level) : Character(
    _name, _class, _race, _level) {

    Weapon iron_sword = Weapon("Iron Sword", 10, "neutral");
    weapon = iron_sword;

    Armor leather_armor = Armor("Leather Armor", 5, 1, "neutral");
    armor = leather_armor;

    health = 10;

}


#endif  // __ENEMY_H_INCLUDED__
