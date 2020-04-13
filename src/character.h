/*
*   character.h
*   Holds the character class, inherited by player and enemy classes
*   Brandon Dunbar
*   dunbar.b965960@stu.sanjac.edu       brandon.dunbar97@gmail.com
*/

//=================================
// Include Guard
#ifndef __CHARACTER_H_INCLUDED__   // if character.h hasn't been included yet...
#define __CHARACTER_H_INCLUDED__   //   #define this so the compiler knows it has been included

//=================================
// Included Dependencies
#include <vector>
#include <string>
#include "utility.h"
#include "weapon.h"
#include "armor.h"
#include "spell.h"

const int ELEMENT_STRENGTH_BONUS = 3;
const int ELEMENT_WEAKNESS_PENALTY = 1;

//=================================
class Character {

    public:

        Character(std::string, std::string, std::string, int);
        Character() = default;

        int calculate_modifier(int stat);

        int calculate_damage_to_deal();
        int calculate_damage_to_deal(Spell spell_attack);

        bool deal_damage(Character &target);
        bool deal_damage(Character &target, Spell spell_attack);

        bool take_damage(int damage);

        int calculate_damage_to_receive(int damage, std::string element, std::string damage_type);

        // Basic Info
        std::string name;
        std::string character_class;
        std::string race;
        int level;
        int health;
        int mana;

        // Stats
        int strength, constitution, dexterity, intelligence, wisdom, charisma;

        // Type strengths and weaknesses
        std::vector<std::string> strengths, weaknesses;

        // Things
        std::vector<Spell> spellbook;
        Weapon weapon;
        Armor armor;

};

Character::Character (std::string _name, std::string _class, std::string _race, int _level) : weapon("Fists", 5, "neutral"), armor("Leather Armor", 5, 1, "neutral") {

    name = _name;
    character_class = _class;
    race = _race;
    level = _level;

}

int Character::calculate_modifier(int stat){
    /* Calculates modifier from base stat using d&d 5e formula */

    int modifier = (stat - 10) % 2;
    return modifier;

}

// Calculate damage to deal methods

int Character::calculate_damage_to_deal(){
    /* Calculates damage output of melee attack based on different factors */

    // Get weapon damage
    int damage = weapon.damage;
    // Get player strength
    damage += calculate_modifier(strength);

    // If the weapon's element is a player strength,
    if ( vector_contains_value(strengths, weapon.element) ) {

        // Apply element strength bonus
        damage += ELEMENT_STRENGTH_BONUS;

    }
    std::cout << "Damage calc'd: " << damage << std::endl;
    return damage;

}

int Character::calculate_damage_to_deal(Spell spell_attack){
    /* Calculates damage output of a spell */

    // Get weapon damage
    int damage = spell_attack.damage;
    // Get player strength
    damage += calculate_modifier(wisdom);

    // If the weapon's element is a player strength,
    if ( vector_contains_value(strengths, spell_attack.element) ) {

        // Apply element strength bonus
        damage += ELEMENT_STRENGTH_BONUS;

    }

    mana -= spell_attack.cost;

    return damage;
}

// Calculate damage received method

int Character::calculate_damage_to_receive(int damage, std::string element, std::string damage_type){
    /*
    Calculates damage to receive based on different factors
    damage: base damage to be dealt
    element: the magical element associated with the damage (most commonly neutral)
    damage_type: physical or magical
    */

    int damage_dampen = 0;

    // Physical or magical?
    if (damage_type == "physical"){
        damage_dampen += armor.physical_defense;
    } else if (damage_type == "magical") {
        damage_dampen += armor.magical_defense;
    }

    // Is character weak to element?
    if ( vector_contains_value(weaknesses, element) ){
        damage_dampen -= ELEMENT_WEAKNESS_PENALTY;
    }

    if ( armor.element == element ) {
        damage_dampen++;
    }

    damage -= damage_dampen;
    return damage;
}

// Deal damage methods

bool Character::deal_damage(Character &target){
    /* Deals damage to target character, returns bool reflecting if target is killed */

    int damage = calculate_damage_to_deal();

    damage = target.calculate_damage_to_receive(damage, weapon.element, "physical");
    std::cout << "Deal Damage method's damage value: " << damage << std::endl;
    bool killed = target.take_damage(damage);

    return killed;
}

bool Character::deal_damage(Character &target, Spell spell_attack){
    /* Deals damage to target character, returns bool reflecting if target is killed */

    int damage = calculate_damage_to_deal();
    damage = target.calculate_damage_to_receive(damage, spell_attack.element, "magical");
    bool killed = target.take_damage(damage);

    return killed;
}

// Take damage methods

bool Character::take_damage(int damage){

    std::cout << "Character " << name << " will receive " << damage << " damage to his health: " << health << " health" << std::endl;
    std::cout << "Pre-damage health: " << health << std::endl;
    health -= damage;
    std::cout << "Post-damage health: " << health << std::endl;

    if ( health <= 0 ){
        return true;
    } else {
        return false;
    }
}

#endif // __CHARACTER_H_INCLUDED__
