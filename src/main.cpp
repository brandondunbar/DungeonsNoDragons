/*
* main.cpp
* The main file used for testing and demonstration
* Brandon Dunbar
* dunbar.b965960@stu.sanjac.edu         brandon.dunbar97@gmail.com
*/

#include <iostream> 
#include <vector> 

using namespace std;

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
    player_character.display_inventory();

    // Armor Test:

    cout << "\n\nTesting: Armor Test------------------------------------------\n\n" << endl;

    Armor chain_mail = Armor("Chain Mail", 5, 1, "neutral");
    cout << "Picked up chain mail!" << endl;
    player_character.equip(chain_mail);
    cout << "Equipped armor: " << player_character.armor.name << endl;

    Armor iron_armor = Armor("Iron Armor", 7, 1, "neutral");
    cout << "Picked up iron armor!" << endl;
    player_character.equip(iron_armor);
    cout << "Equipped armor: " << player_character.armor.name << endl;
    player_character.display_inventory();

    // Random Item Test:

    cout << "\n\nTesting: Items------------------------------------------\n\n" << endl;

    Item health_potion = Item("Health Potion", "Potion");
    cout << "Picked up health potion!" << endl;
    player_character.store(health_potion);
    player_character.display_inventory();

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

    Spell fireball = Spell("Fireball", "Fire", "Burn", 10, 5);
    Spell lightning_bolt = Spell("Lightning Bolt", "Electricity", "Shock", 10, 5);

    player_character.spellbook.push_back(fireball);
    cout << player_character.name << " learned " << fireball.name << "!" << endl;

    player_character.spellbook.push_back(lightning_bolt);
    cout << player_character.name << " learned " << lightning_bolt.name << "!" << endl;

    killed = player_character.deal_damage(orc, fireball);

    if ( killed ) {
        cout << "You killed " << orc.name << "!" << endl;
    } else {
        cout << orc.name << " is at " << orc.health << "!" << endl;
    }

    // Player Sheet Test:

    cout << "\n\nTesting: Player Sheet------------------------------------------\n\n" << endl;

    player_character.display();

    // Enemy Sheet Test:

    cout << "\n\nTesting: Enemy Sheet------------------------------------------\n\n" << endl;

    orc.display();

    // Item Sheet Test:

    cout << "\n\nTesting: Item Sheet------------------------------------------\n\n" << endl;

    health_potion.display();

    // Weapon Sheet Test:

    cout << "\n\nTesting: Weapon Sheet------------------------------------------\n\n" << endl;

    iron_sword.display();

    // Armor Sheet Test:

    cout << "\n\nTesting: Armor Sheet------------------------------------------\n\n" << endl;

    chain_mail.display();

    // Spell Sheet Test:

    cout << "\n\nTesting: Spell Sheet------------------------------------------\n\n" << endl;

    fireball.display();

    // Buff Test:

    cout << "\n\nTesting: Buff------------------------------------------\n\n" << endl;

    Buff str_debuff = Buff("Strength Debuff", "str", -5, 2);
    player_character.add_buff(str_debuff);

    cout << "Strength debuff received!\n" << endl;

    player_character.display();

    player_character.trigger_buffs();
    cout << "\nBuffs triggered!\n" << endl;

    player_character.display();

    player_character.trigger_buffs();
    cout << "\nBuffs triggered!" << endl;

    player_character.trigger_buffs();
    cout << "Buffs triggered!\n" << endl;

    player_character.display();

    // Bomb Test:

    cout << "\n\nTesting: Bombs------------------------------------------\n\n" << endl;

    Item bomb = Item("Basic Bomb", "bomb");
    bomb.damage = 10;
    cout << "Bomb Created" << endl;

    orc.health = 10;

    killed = player_character.deal_damage(orc, bomb);
    cout << "You throw your bomb!" << endl;

    if ( killed ) {
        cout << "You killed " << orc.name << "!" << endl;
    } else {
        cout << orc.name << " is at " << orc.health << "!" << endl;
    }

    return 0;

}
