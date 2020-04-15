
//=================================
// Include Guard
#ifndef __ENEMY_H_INCLUDED__   // if enemy.h hasn't been included yet...
#define __ENEMY_H_INCLUDED__   //   #define this so the compiler knows it has been included

//=================================
// Included Dependencies
#include "character.h"
#include "item.h"

//=================================
class Enemy : public Character {

    public:

        Enemy(string _name, string _class="fighter", string _race="goblin", int _level=1);
        Enemy() = default;
        void display();

        string element = "neutral";
        vector<Item> loot;

};

// Constructor
Enemy::Enemy(string _name, string _class, string _race, int _level) : Character(
    _name, _class, _race, _level) {

    Weapon iron_sword = Weapon("Iron Sword", 10, "neutral");
    weapon = iron_sword;

    Armor leather_armor = Armor("Leather Armor", 5, 1, "neutral");
    armor = leather_armor;

    health = 10;

}

void Enemy::display(){

    cout << "Enemy Sheet:\n" << endl;
    display_attributes();

    cout << "\n\tLoot:\n\t\t";

    for (int i; i<loot.size(); i++){
        cout << loot[i].name;
        if (i < (loot.size() - 1)){
            cout << ", ";
        }
    }
    cout << endl;

    cout << "\tElement: " << element << endl;
    cout << "\tWeapon: " << weapon.name << endl;
    cout << "\tArmor: " << armor.name << endl;

}


#endif  // __ENEMY_H_INCLUDED__
