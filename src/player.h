/*
*   player.h
*   Holds the player class, inherits the character class in character.h
*   Brandon Dunbar
*   dunbar.b965960@stu.sanjac.edu       brandon.dunbar97@gmail.com
*/

//=================================
// Include Guard
#ifndef __PLAYER_H_INCLUDED__   // if player.h hasn't been included yet...
#define __PLAYER_H_INCLUDED__   //   #define this so the compiler knows it has been included

//=================================
// Included Dependencies
#include <vector>
#include <string>
#include "character.h"
#include "item.h"

//=================================
class Player : public Character {

    public:

        Player(std::string _name, std::string _class, std::string _race, int _level);

        bool store(Item _item);
        bool store(Weapon _weapon);
        bool store(Armor _armor);

        bool equip(Weapon _weapon);
        bool equip(Armor _armor);

        std::string get_inventory();

        std::vector<Item> inventory;
        int gold = 0;

};

Player::Player(std::string _name, std::string _class, std::string _race, int _level) : Character(
    _name, _class, _race, _level) {

}

// Store method(s)

bool Player::store(Item _item){

    inventory.push_back(_item);
    return true;

}

bool Player::store(Weapon _weapon){

    inventory.push_back(_weapon);
    return true;

}

bool Player::store(Armor _armor){

    inventory.push_back(_armor);
    return true;

}

// Equip methods

bool Player::equip(Weapon _weapon){

    if (weapon.name != "Fists"){
        store(weapon);
    }

    weapon = _weapon;

    return true;

}

bool Player::equip(Armor _armor){

    
    store(armor);
    armor = _armor;
    return true;

}

// Display Inventory

std::string Player::get_inventory(){

    int items_in_inventory = inventory.size();

    // Create string for display
    std::string inventory_display = "\nInventory:\n";

    // Loop through items in inventory vector
    for (int i = 0; i < items_in_inventory; i++){
        inventory_display += "\t- " + inventory[i].name + "\n";
    }

    return inventory_display;
}

#endif  // __PLAYER_H_INCLUDED__