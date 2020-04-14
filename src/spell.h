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
class Spell {

    public:
        
        Spell(string _name, string _element, string _status_effect, int _damage, int _manacost);  

        string name;
        string element;
        string status_effect;
        int damage;
        int cost;

};

Spell::Spell (string _name, string _element, string _status_effect, int _damage, int _manacost) :
name(_name), element(_element), status_effect(_status_effect), damage(_damage), cost(_manacost) {}


#endif // __SPELL_H_INCLUDED__