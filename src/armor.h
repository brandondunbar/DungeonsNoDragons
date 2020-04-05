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
#include <vector>
#include <string>
#include "item.h"

//=================================
class Armor : public Item {

    public:

        Armor(std::string _name, int _physical_defense, int _magical_defense, std::string _element);
        int physical_defense;
        int magical_defense;
        std::string element;

};

Armor::Armor(std::string _name, int _physical_defense, int _magical_defense, std::string _element) : Item(_name, "Armor") {
    physical_defense = _physical_defense;
    magical_defense = _magical_defense;
    element = _element;
}

#endif  // __ARMOR_H_INCLUDED__