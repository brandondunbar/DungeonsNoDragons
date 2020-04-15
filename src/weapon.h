/*
*   weapon.h
*   Holds the weapon class, inherits from the item class in item.h
*   Brandon Dunbar
*   dunbar.b965960@stu.sanjac.edu       brandon.dunbar97@gmail.com
*/

//=================================
// Include Guard
#ifndef __WEAPON_H_INCLUDED__   // if x.h hasn't been included yet...
#define __WEAPON_H_INCLUDED__   //   #define this so the compiler knows it has been included

//=================================
// Included Dependencies
#include "item.h"

//=================================
class Weapon : public Item {

    public:

        Weapon(std::string _name, int _damage, std::string _element);
        Weapon() = default;
        void display();
        int damage;
        std::string element;

};

Weapon::Weapon(std::string _name, int _damage, std::string _element) : Item(_name, "Weapon"){
    damage = _damage;
    element = _element;
}

void Weapon::display(){

    cout << "\nWeapon Sheet:" <<endl;
    cout << "\t" << type << ": " << name << endl;
    cout << "\tDamage: " << damage << endl;
    cout << "\tElement: " << element << endl;
    cout << "\n" << endl;

}

#endif  // __WEAPON_H_INCLUDED__
