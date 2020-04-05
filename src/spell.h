/*
*   spell.h
*   Holds the spell class, which represents magical spells usable by a character (player or enemy)
*   This is a placeholder.
*   Brandon Dunbar
*   dunbar.b965960@stu.sanjac.edu       brandon.dunbar97@gmail.com
*/

//=================================
// Include Guard
#ifndef __SPELL_H_INCLUDED__   // if spell.h hasn't been included yet...
#define __SPELL_H_INCLUDED__   //   #define this so the compiler knows it has been included

//=================================
// Included Dependencies
#include <vector>
#include <string>

//=================================
class Spell {

    public:
        
        Spell(std::string, std::string, std::string);  

        std::string name;
        std::string element;
        std::string status_effect;
        int damage;
        int cost;

};

Spell::Spell (std::string _name, std::string _element, std::string _status_effect) {

    name = _name;
    element = _element;
    status_effect = _status_effect; 
    
}


#endif // __SPELL_H_INCLUDED__