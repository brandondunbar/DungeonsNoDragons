/*
* main.cpp
* The main file used for testing and demonstration
* Brandon Dunbar
* dunbar.b965960@stu.sanjac.edu         brandon.dunbar97@gmail.com
*/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

#include "player.h"
#include "enemy.h"

int main(){

    // Player Test:

    cout << "\n\nTesting: Character Creation------------------------------------------\n\n" << endl;

    cout << "What is your name?\n>>> ";
    string name;
    cin >> name;

    cout << "What class are you? (Wizard, Rogue, Fighter)\n>>> ";
    string character_class;
    cin >> character_class;

    cout << "What race are you? (Elf, Human, Dwarf)\n>>> ";
    string race;
    cin >> race;
    
    Player player_character = Player(name, character_class, race, 1);
    player_character.health = 20;

    // Weapon Test:

    cout << "\n\nTesting: Weapons------------------------------------------\n\n" << endl;

    Weapon iron_sword = Weapon("Iron Sword", 10, "neutral");
    cout << "Picked up iron sword!" << endl;
    player_character.equip(iron_sword);
    cout << "Equipped weapon: " << player_character.weapon.name << endl;

    Weapon longbow = Weapon("Longbow", 10, "neutral");
    cout << "Picked up longbow!" << endl;
    player_character.equip(longbow);
    cout << "Equipped weapon: " << player_character.weapon.name << endl;
    cout << player_character.get_inventory();

    // Armor Test:

    cout << "\n\nTesting: Armor Test------------------------------------------\n\n" << endl;

    Armor leather_armor = Armor("Chain Mail", 5, 1, "neutral");
    cout << "Picked up chain mail!" << endl;
    player_character.equip(leather_armor);
    cout << "Equipped armor: " << player_character.armor.name << endl;

    Armor iron_armor = Armor("Plate Armor", 7, 1, "neutral");
    cout << "Picked up plate armor!" << endl;
    player_character.equip(iron_armor);
    cout << "Equipped armor: " << player_character.armor.name << endl;
    cout << player_character.get_inventory();

    // Random Item Test:

    cout << "\n\nTesting: Items------------------------------------------\n\n" << endl;

    Item health_potion = Item("Health Potion", "Potion");
    cout << "Picked up health potion!" << endl;
    player_character.store(health_potion);
    cout << player_character.get_inventory();

    // Enemy Creation Test:

    cout << "\n\nTesting: Enemy Creation------------------------------------------\n\n" << endl;

    Enemy orc = Enemy("Ruk");
    orc.race = "Orc";
    cout << orc.name << " the " << orc.race << " " << orc.character_class << " has been created!" << endl;

    // Player physical attack Enemy Test:

    cout << "\n\nTesting: Player Physical Attack------------------------------------------\n\n" << endl;

    cout << orc.health << " health!" << endl;

    cout << "You attack with your " << player_character.weapon.name << "!" << endl;

    bool killed = player_character.deal_damage(orc);

    if ( killed ) {
        cout << "You killed " << orc.name << "!" << endl;
    } else {
        cout << orc.name << " is at " << orc.health << "!" << endl;
    }

    // Enemy weakness test:

    cout << "\n\nTesting: Player Attack Enemy Weakness------------------------------------------\n\n" << endl;

    Weapon elemental_sword = Weapon("Flame Sword", 11, "Fire");
    cout << "You find a " << elemental_sword.name << "!" << endl;
    
    player_character.equip(elemental_sword);
    cout << elemental_sword.name << " equipped!" << endl;

    orc.health = 10;
    cout << orc.name << " has returned to full health!" << endl;

    orc.weaknesses.push_back(elemental_sword.element);
    cout << orc.name << " gained a weakness to " << elemental_sword.element << "!" << endl;

    killed = player_character.deal_damage(orc);

    if ( killed ) {
        cout << "You killed " << orc.name << "!" << endl;
    } else {
        cout << orc.name << " is at " << orc.health << "!" << endl;
    }

    // Player Strength Test:

    cout << "\n\nTesting: Player Attack Player Strength------------------------------------------\n\n" << endl;

    orc.health = 10;
    cout << orc.name << " has returned to full health!" << endl;

    player_character.strengths.push_back(elemental_sword.element);
    cout << player_character.name << " gained a strength with " << elemental_sword.element << "!" << endl;

    killed = player_character.deal_damage(orc);

    if ( killed ) {
        cout << "You killed " << orc.name << "!" << endl;
    } else {
        cout << orc.name << " is at " << orc.health << "!" << endl;
    }

    // Player Spell Test:

    cout << "\n\nTesting: Player Spell Attack------------------------------------------\n\n" << endl;

    orc.health = 10;
    cout << orc.name << " has returned to full health!" << endl;

    Spell Fireball = Spell("Fireball", "Fire", "Burn");

    player_character.spellbook.push_back(Fireball);
    cout << player_character.name << " learned " << Fireball.name << "!" << endl;

    killed = player_character.deal_damage(orc, Fireball);

    if ( killed ) {
        cout << "You killed " << orc.name << "!" << endl;
    } else {
        cout << orc.name << " is at " << orc.health << "!" << endl;
    }

    return 0;

}
