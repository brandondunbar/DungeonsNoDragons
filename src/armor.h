/*
*   armor.h
*   Holds the armor class, inherits the item class from item.h
*   Brandon Dunbar
*   dunbar.b965960@stu.sanjac.edu       brandon.dunbar97@gmail.com
*/

//=================================
// Include Guard
#ifndef __ARMOR_H_INCLUDED__   // if armor.h hasn't been included yet...
#define __ARMOR_H_INCLUDED__   //   #define this so the compiler knows it has been included

//=================================
// Included Dependencies
#include "item.h"

//=================================
class Armor : public Item {

    public:

        Armor(string _name, int _physical_defense, int _magical_defense, string _element);
        Armor() = default;
        void display();

        int physical_defense;
        int magical_defense;
        string element;

};

Armor::Armor(string _name, int _physical_defense, int _magical_defense, string _element) : Item(_name, "Armor") {
    physical_defense = _physical_defense;
    magical_defense = _magical_defense;
    element = _element;
}

void Armor::display(){

    cout << "Armor Sheet:" << endl;
    cout << "\t" << type << ": " << name << endl;
    cout << "\tPhysical Defense: " << physical_defense << endl;
    cout << "\tMagical Defense: " << magical_defense << endl;
    cout << "\tElement: " << element;

}

#endif  // __ARMOR_H_INCLUDED__
