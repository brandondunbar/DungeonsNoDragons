//defines an enemy class derived from the character class
//=================================
// Include Guard
#ifndef __ENEMY_H_INCLUDED__   // if enemy.h hasn't been included yet...
#define __ENEMY_H_INCLUDED__   //   #define this so the compiler knows it has been included

//=================================
// Included Dependencies
#include "character.h"
#include "item.h"
#include "dice.h"
#include "dictionary.h"


//=================================
class Enemy : public Character {

    public:

        Enemy(string _name, string _class="fighter", string _race="goblin");
        Enemy() = default;
        void display();

        string element = "neutral";
        vector<Item> loot;

};


// Constructor
Enemy::Enemy(string _name, string _class, string _race) : Character(
    _name, _class, _race) {}


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
    cout << "\t\tDamage: " << weapon.damage << endl;
    cout << "\tArmor: " << armor.name << endl;
    cout << "\t\tPhysical Defense: " << armor.physical_defense << endl;
    cout << "\t\tMagical Defense: " << armor.magical_defense << endl;

}


int generateStat(int elementIndex, int tier){

    Dice d( tier * 5 );

    int stat_points = 0;
    for ( int i = 0; i <= elementIndex; i++ ){
        stat_points += d.roll();
    }
    return stat_points;
}


Item generateLoot(int elementIndex, int tier){

    Dice d;

    Item loot;

    int itemRoll = d.roll();

    if ( itemRoll <= 5 ) {

        // Health pot
        loot = Items["Health Potion"];

    } else if ( 6 <= itemRoll && itemRoll <= 10 ) {

        // Mana pot
        loot = Items["Mana Potion"];
        
    } else if ( 11 <= itemRoll && itemRoll <= 15 ) {

        // Bomb
        loot = Items["Bomb"];

    } else {

        // Gold
        loot = Items["Gold Pouch"];

    }

    return loot;

}


Enemy EnemyGenerator(string type, int tier){
    /* Generates enemy based on type and tier

    params:
        type - Type of enemy to generate i.e. slime, orc, demon
        tier - 1, 2, or 3; 3 is strongest
    */

    Dice d;

    Enemy generatedEnemy;

    if (type == "slime") {

        switch (tier) {

            case 1:
                {
                generatedEnemy = Enemy("Slime", "fighter", "slime");
                generatedEnemy.weapon = Weapon("Ooze Slash", 7, "Neutral");
                generatedEnemy.learnSpell( Spell("Slime Ball", "Neutral", "None", 7, 10) );
                generatedEnemy.armor = Armors["None"];
                break;
                }
            case 2:
                {
                string element;

                generatedEnemy = Enemy("Chuchu", "mage", "slime");

                int diceRoll = d.roll();

                if (diceRoll <= 5) {

                    element = "Fire";
                    generatedEnemy.weaknesses.push_back( "Water" );

                } else if (6 <= diceRoll && diceRoll <= 10) {

                    element = "Water";
                    generatedEnemy.weaknesses.push_back( "Electricity" );

                } else if (11 <= diceRoll && diceRoll <= 15) {

                    element = "Electricity";
                    generatedEnemy.weaknesses.push_back( "Earth" );

                } else if (16 <= diceRoll && diceRoll <= 20) {

                    element = "Earth";

                }

                string enemy_name = element + " Chuchu";
                generatedEnemy = Enemy(enemy_name, "mage", "slime");
                generatedEnemy.weapon = Weapon("Ooze Slash", 7, enemy_name);
                string spell_name = element + " Slime Ball";
                generatedEnemy.learnSpell( Spell(spell_name, "Neutral", element, 10, 5) );
                generatedEnemy.armor = Armors["None"];

                break;
                }
        }
    } else if (type == "undead") {

        switch (tier) {

            case 1:
                {
                generatedEnemy = Enemy("Zombie", "fighter", "undead");
                generatedEnemy.weapon = Weapon("Rotten Scratch", 20, "Neutral");
                generatedEnemy.learnSpell( Spell("Acrid Vomit", "Poison", "Toxic", 25, 10) );
                generatedEnemy.armor = Armors["Iron Armor"];
                break;
                }
            case 2:
                {
                int diceRoll = d.roll();

                if (diceRoll > 10) {

                    generatedEnemy = Enemy("Ghoul", "fighter", "spirit");
                    generatedEnemy.weapon = Weapon("Phantasmal Scratch", 27, "Spirit");
                    generatedEnemy.learnSpell( Spell("Spirit Ball", "None", "Spirit", 34, 10) );
                    generatedEnemy.armor = Armors["None"];

                } else {

                    generatedEnemy = Enemy("Wraith", "mage", "spirit");
                    generatedEnemy.weapon = Weapon("Phantasmal Scratch", 35, "Spirit");
                    generatedEnemy.learnSpell( Spell("Screech", "None", "Neutral", 37, 5));
                    generatedEnemy.armor = Armors["None"];

                }

                break;
                }
        }
    } else if (type == "greeny") {

        switch (tier) {

            case 1:
                {
                int diceRoll = d.roll();

                if (diceRoll > 10) {

                    generatedEnemy = Enemy("Goblin Warrior", "fighter", "goblin");
                    generatedEnemy.weapon = Weapons["Iron Sword"];
                    generatedEnemy.armor = Armors["Iron Armor"];

                } else {

                    generatedEnemy = Enemy("Goblin Archer", "archer", "goblin");
                    generatedEnemy.weapon = Weapons["Longbow"];
                    generatedEnemy.armor = Armors["Iron Armor"];

                }

                break;
                }
            case 2:
                {
                int diceRoll = d.roll();

                if (diceRoll > 10) {

                    generatedEnemy = Enemy("Orc Warrior", "fighter", "orc");
                    generatedEnemy.weapon = Weapons["Damascus Sword"];
                    generatedEnemy.armor = Armors["Damascus Armor"];

                } else {

                    generatedEnemy = Enemy("Orc Shaman", "mage", "orc");
                    generatedEnemy.weapon = Weapons["Dusty Magic Tome"];
                    generatedEnemy.learnSpell( Spells["Fireball"] );
                    generatedEnemy.learnSpell( Spells["Thunderbolt"] );
                    generatedEnemy.learnSpell( Spells["Ice Spike"] );
                    generatedEnemy.armor = Armors["Damascus Armor"];

                }

                break;
                }

            case 3:
                {
                int diceRoll = d.roll();

                if (diceRoll > 10) {

                    generatedEnemy = Enemy("Gith Archer", "archer", "gith");
                    generatedEnemy.weapon = Weapons["Longbow"];
                    generatedEnemy.armor = Armors["Gear Armor"];

                } else {

                    generatedEnemy = Enemy("Gith Shaman", "mage", "gith");
                    generatedEnemy.weapon = Weapons["Dusty Magic Tome"];
                    generatedEnemy.learnSpell( Spells["Fireball"] );
                    generatedEnemy.learnSpell( Spells["Thunderbolt"] );
                    generatedEnemy.learnSpell( Spells["Ice Spike"] );
                    generatedEnemy.armor = Armors["Gear Armor"];
                }

                break;
                }
        }
    } else if (type == "demon") {

        switch (tier) {

            case 1:
                {
                generatedEnemy = Enemy("Abyssal Chicken", "fighter", "demon");
                generatedEnemy.weapon = Weapon("Cursed Talons", 40, "dark");
                generatedEnemy.armor = Armors["Damascus Armor"];
                break;
                }

            case 2:
                {
                int diceRoll = d.roll();

                if (diceRoll > 6) {

                    generatedEnemy = Enemy("Demon Archer", "archer", "demon");
                    generatedEnemy.weapon = Weapons["Void Sword"];
                    generatedEnemy.armor = Armors["Damascus Armor"];

                } else if ( 6 < diceRoll < 12 ) {

                    generatedEnemy = Enemy("Demon Mage", "mage", "demon");
                    generatedEnemy.weapon = Weapons["Magic Tome"];
                    generatedEnemy.learnSpell( Spells["Fireball"] );
                    generatedEnemy.learnSpell( Spells["Lightning bolt"] );
                    generatedEnemy.learnSpell( Spells["Ice Spike"] );
                    generatedEnemy.armor = Armors["Damascus Armor"];

                } else {

                    generatedEnemy = Enemy("Demon Warrior", "warrior", "demon");
                    generatedEnemy.weapon = Weapons["Great Sword"];
                    generatedEnemy.armor = Armors["Damascus Armor"];

                }

                break;
                }

            case 3:
                {
                generatedEnemy = Enemy("Maurezhi", "fighter", "demon");
                generatedEnemy.weapon = Weapon("Blasphemous Hook", 50, "dark");
                generatedEnemy.armor = Armors["Damascus Armor"];

                break;
                }
        }
    } else if (type == "construct") {

        switch (tier) {

            case 1:
                {
                generatedEnemy = Enemy("Animated Armor", "fighter", "mech");
                generatedEnemy.weapon = Weapons["Great Sword"];
                generatedEnemy.armor = Armors["Gear Armor"];

                break;
                }

            case 2:
                {
                generatedEnemy = Enemy("Clockwork Golem", "fighter", "mech");
                generatedEnemy.weapon = Weapons["Great Sword"];
                generatedEnemy.armor = Armors["Gear Armor"];

                break;
                }

            case 3:
                {
                generatedEnemy = Enemy("Warforge", "fighter", "mech");
                generatedEnemy.weapon = Weapon("Mechanized Glaive", 25, "Neutral");
                generatedEnemy.armor = Armors["Gear Armor"];

                break;
                }
        }
    } else if (type == "boss") {

        switch (tier) {

            case 1:
                {
                generatedEnemy = Enemy("King Slime", "boss", "slime");
                generatedEnemy.weapon = Weapon("Slime Sword", 15, "Neutral");
                generatedEnemy.armor = Armors["None"];

                break;
                }

            case 2:
                {
                generatedEnemy = Enemy("Lich", "boss", "undead");
                generatedEnemy.weapon = Weapon("Ancient Great Sword", 20, "Neutral");
                generatedEnemy.armor = Armors["Iron Armor"];

                // Lightning magic
                break;
                }
            case 3:
                {
                generatedEnemy = Enemy("Orc Warlord", "boss", "orc");
                generatedEnemy.weapon = Weapon("Bone Great Sword", 25, "Neutral");
                generatedEnemy.armor = Armors["Cursed Armor"];

                break;
                }

            case 4:
                {
                generatedEnemy = Enemy("Orcus", "boss", "demon");
                generatedEnemy.weapon = Weapon("Soul Scythe", 30, "Dark");
                generatedEnemy.armor = Armors["Damascus Armor"];

                break;
                }

            case 5:
                {
                generatedEnemy = Enemy("Clockwork Behir", "boss", "construct");
                generatedEnemy.weapon = Weapon("Sharpened Gear", 35, "Neutral");
                generatedEnemy.armor = Armors["Gear Armor"];

                // Lightning Breath
                // Magic Charged Lasers
                break;
                }

            case 6:
                {
                generatedEnemy = Enemy("Leviathan", "boss", "elemental");
                generatedEnemy.weapon = Weapon("Petrified Bite", 40, "Neutral");
                generatedEnemy.armor = Armors["Void Armor"];

                break;
                }

            case 7:
                {
                generatedEnemy = Enemy("Demon Boss", "boss", "demon");
                generatedEnemy.weapon = Weapon("Cursed Warhammer of Damnation", 50, "Dark");
                generatedEnemy.armor = Armors["Armor of a thousand souls"];

                break;
                }
        }

    }    

    string types[] = {
        "slime", "undead", "greeny", "demon", "construct", "boss"
    };

    int elementIndex = 0;
    for ( int i = 0; i < 5; i++ ) {

        if ( types[i] == type ) {
            elementIndex = i;
            break;
        }
    }

    // Generate enemy stats
    generatedEnemy.strength = generateStat(elementIndex, tier);
    generatedEnemy.constitution = generateStat(elementIndex, tier);
    generatedEnemy.dexterity = generateStat(elementIndex, tier);
    generatedEnemy.intelligence = generateStat(elementIndex, tier);
    generatedEnemy.wisdom = generateStat(elementIndex, tier);
    generatedEnemy.charisma = generateStat(elementIndex, tier);
    generatedEnemy.loot.push_back(generateLoot(elementIndex, tier));

    // Initialize health, mana, and current stats
    generatedEnemy.initialize_stats();
    int healthModifier = elementIndex * tier;
    generatedEnemy.base_health *= (healthModifier/10);
    generatedEnemy.initialize_stats();

    return generatedEnemy;

}

#endif  // __ENEMY_H_INCLUDED__
