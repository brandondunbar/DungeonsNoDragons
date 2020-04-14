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
#include "character.h"
#include "item.h"

//=================================
class Player : public Character {

    public:

        Player(string _name, string _class, string _race, int _level);

        bool store(Item _item);
        bool store(Weapon _weapon);
        bool store(Armor _armor);

        void equip(Weapon _weapon);
        void equip(Armor _armor);

        void display_inventory();
        void display();
        void display_spellbook();

        vector<Item> inventory;
        int gold = 0;

};

Player::Player(string _name, string _class, string _race, int _level) : Character(
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

void Player::equip(Weapon _weapon){

    if (weapon.name != "Fists"){
        store(weapon);
    }

    weapon = _weapon;
}

void Player::equip(Armor _armor){
    
    store(armor);
    armor = _armor;
}

// Display Inventory

void Player::display_inventory(){

    int items_in_inventory = inventory.size();

    // Create string for display
    cout << "\nInventory:" << endl;

    // Loop through items in inventory vector
    for ( int i = 0; i < items_in_inventory; i++ ){
        cout << "\t- " << inventory[i].name << endl;
    }
}

// Display Player Sheet

void Player::display(){
    cout << "Player Sheet:\n" << endl;
    display_attributes();
    cout << "\n\tGold: " << gold << endl;
    cout << "\tWeapon: " << weapon.name << endl;
    cout << "\tArmor: " << armor.name << endl;
    cout << "\tSpells";
    display_spellbook();
}

// Display Spellbook

void Player::display_spellbook(){

    cout << "(" << spellbook.size() << "):\n\t\t";

    if (spellbook.size() == 0) {

        cout << "None" << endl;

    } else {

        for ( int i = 0; i < spellbook.size(); i++ ){

            cout << spellbook[i].name;

            if ( i < spellbook.size() -1 ){
                cout << ", ";
            }
        }
    }
}

#endif  // __PLAYER_H_INCLUDED__