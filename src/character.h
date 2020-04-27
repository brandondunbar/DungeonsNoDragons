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
#include "map"
#include "vector"
#include "utility.h"
#include "weapon.h"
#include "armor.h"
#include "spell.h"
#include "buff.h"

const int ELEMENT_STRENGTH_BONUS = 3;
const int ELEMENT_WEAKNESS_PENALTY = 1;

//=================================
class Character {

    public:

        Character(string, string, string);
        Character() = default;
        void set_health_and_mana();

        int calculate_modifier(int stat);

        int calculate_damage_to_deal();
        int calculate_damage_to_deal(Spell spell_attack);

        bool deal_damage(Character &target);
        bool deal_damage(Character &target, Spell spell_attack);
        bool deal_damage(Character &target, Item bomb);

        bool take_damage(int damage);

        int calculate_damage_to_receive(int damage, string element, string damage_type);
        void display_attributes();

        void display_buffs();
        void add_buff(Buff buff);
        void mod_stat(string stat, int amount);
        void trigger_buffs();
        void buff_effect(Buff &buff, const int index_pos);

        // Basic Info
        string name;
        string character_class;
        string race;
        int health;
        int mana = 0;

        // Base Stats
        int strength = 10, constitution = 10, dexterity = 10, intelligence = 10, wisdom = 10, charisma = 10;
        // Current Stats
        int current_strength, current_constitution, current_dexterity, current_intelligence, current_wisdom, current_charisma;

        // Elemental type strengths and weaknesses
        vector<string> strengths, weaknesses;

        // Buffs/Debuffs
        vector<Buff> buffs;

        // Things
        vector<Spell> spellbook;
        Weapon weapon;
        Armor armor;

        void learnSpell(Spell& aSpell);

};

Character::Character (string _name, string _class, string _race) : weapon("Fists", 5, "neutral"), armor("Leather Armor", 5, 1, "neutral") {

    name = _name;
    character_class = _class;
    race = _race;

    // Set Temp stats
    current_strength = strength;
    current_constitution = constitution;
    current_dexterity = dexterity;
    current_intelligence = intelligence;
    current_wisdom = wisdom;
    current_charisma = charisma;

}

void Character::set_health_and_mana(){
    health = constitution*5;
    mana = intelligence*5;
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
    // Get player strength modifier
    damage += calculate_modifier(strength);

    // If the weapon's element is a player strength,
    if ( vector_contains_value(strengths, weapon.element) ) {

        // Apply element strength bonus
        damage += ELEMENT_STRENGTH_BONUS;

    }
    cout << "Damage calc'd: " << damage << endl;
    return damage;

}

int Character::calculate_damage_to_deal(Spell spell_attack){
    /* Calculates damage output of a spell */

    // Get weapon damage
    int damage = spell_attack.damage;
    // Get player wisdom modifier
    damage += calculate_modifier(wisdom);

    // Add spell focus modifier
    if ( weapon.element == "Magic" ) {
        damage += weapon.damage;
    }

    // If the weapon's element is a player strength,
    if ( vector_contains_value(strengths, spell_attack.element) ) {

        // Apply element strength bonus
        damage += ELEMENT_STRENGTH_BONUS;

    }

    mana -= spell_attack.cost;

    return damage;
}


// Calculate damage received method

int Character::calculate_damage_to_receive(int damage, string element, string damage_type){
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

    if (damage < 0)
    {
        return 0;
    }

    return damage;
}

// Deal damage methods

bool Character::deal_damage(Character &target){
    /* Deals damage to target character, returns bool reflecting if target is killed */

    int damage = calculate_damage_to_deal();

    damage = target.calculate_damage_to_receive(damage, weapon.element, "physical");
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

bool Character::deal_damage(Character &target, Item bomb){

    int damage = bomb.damage;
    damage = target.calculate_damage_to_receive(damage, "explosive", "physical");
    bool killed = target.take_damage(damage);

    return killed;

}

// Take damage methods

bool Character::take_damage(int damage){

    health -= damage;

    if ( health <= 0 ){
        return true;
    } else {
        return false;
    }
}

void Character::display_attributes(){
    cout << "\tName: " << name << endl;
    cout << "\tClass: " << character_class << endl;
    cout << "\tRace: " << race << endl;
    cout << "\tHealth: " << health << endl;
    cout << "\tMana: " << mana << endl;
    cout << "\tBuffs: ";
    display_buffs();

    cout << "\n\nStats:" << endl;
    cout << "\tStrength: (" << current_strength << "/" << strength << ")" << endl;
    cout << "\tConstitution: (" << current_constitution << "/" << constitution << ")" << endl;
    cout << "\tDexterity: (" << current_dexterity << "/" << dexterity << ")" << endl;
    cout << "\tIntelligence: (" << current_intelligence << "/" << intelligence << ")" << endl;
    cout << "\tWisdom: (" << current_wisdom << "/" << wisdom << ")" << endl;
    cout << "\tCharisma: (" << current_charisma << "/" << charisma << ")" << endl;

}

void Character::display_buffs(){

    for ( int i = 0; i < buffs.size(); i++ ){

        cout << buffs[i].name;

        if ( i < buffs.size() - 1 ){

            cout << ", ";

        }
    }
}

void Character::add_buff(Buff buff){

    bool already_added = false;

    for ( int i = 0; i < buffs.size(); i++ ){
        if ( buffs[i].name == buff.name){

            buffs[i].round_timer = buff.round_timer;
            already_added = true;
            break;
        }
    }

    if ( !already_added ){

        buffs.push_back(buff);

    }
}

void Character::trigger_buffs(){

    for ( int i = 0; i < buffs.size(); i++ ) {
        buff_effect(buffs[i], i);
    }

}

void Character::mod_stat(string stat, int amount){

    if ( stat == "str" ) {

        current_strength += amount;

    } else if ( stat == "con" ) {

        current_constitution += amount;

    } else if ( stat == "dex" ) {

        current_dexterity += amount;

    }  else if ( stat == "int" ) {

        current_intelligence += amount;

    } else if ( stat == "wis" ) {

        current_wisdom += amount;

    }  else if ( stat == "cha" ) {

        current_charisma += amount;

    } else if ( stat == "armor" ) {

        armor.physical_defense += amount;
        armor.magical_defense += amount;

    } else if ( stat == "dot" ) {

        health -= amount;

    }

}

void Character::buff_effect(Buff &buff, const int index_pos){

    if ( buff.activated == false ) {

        mod_stat(buff.target_stat, buff.mod);

        // To make sure the buff isn't continuously added
        if ( buff.target_stat != "dot" ) {  // Damage over time should be continuously added
            buff.activated = true;
        }

    }

    if ( buff.round_timer == 0 ){

        buffs.erase(buffs.begin() + index_pos);
        mod_stat(buff.target_stat, -buff.mod);

    }

    buff.round_timer--;

}

void Character::learnSpell(Spell& aSpell)
{
    spellbook.push_back(aSpell);
}

#endif // __CHARACTER_H_INCLUDED__
