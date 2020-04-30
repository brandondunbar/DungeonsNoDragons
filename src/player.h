/*
*   player.h
*   Holds the player class, inherits the character class in character.h
*   Brandon Dunbar
*   dunbar.b965960@stu.sanjac.edu       brandon.dunbar97@gmail.com
*/

//=================================
// Include Guard
#ifndef __PLAYER_H_INCLUDED__   // if player.h hasn't been included yet...
#define __PLAYER_H_INCLUDED__   //   #define this so the compiler knows it has been included

//=================================
// Included Dependencies
#include "character.h"
#include "item.h"
#include "dice.h"

//=================================
class Player : public Character {

    public:

        Player(string _name, string _class, string _race);

        bool store(const Item& _item);
        bool store(const Weapon& _weapon);
        bool store(const Armor& _armor);

        void equip(Weapon _weapon);
        void equip(Armor _armor);

        void display_items();
        void display_armors();
        void display_weapons();
        void display_inventory();
        void inventory();
        void display();
        void display_spellbook();

        vector<Item> invItems;
        vector<Weapon> invWeapons;
        vector<Armor> invArmors;
        int gold = 0;

};

Player::Player(string _name, string _class, string _race) : Character(
    _name, _class, _race) {

}

// Store method(s)

bool Player::store(const Item& _item){

    invItems.push_back(_item);
    return true;

}

bool Player::store(const Weapon& _weapon){

    invWeapons.push_back(_weapon);
    return true;

}

bool Player::store(const Armor& _armor){

    invArmors.push_back(_armor);
    return true;

}

// Equip methods

void Player::equip(Weapon _weapon){

    if (weapon.name != "Fists"){
        store(weapon);
    }

    weapon = _weapon;
}

void Player::equip(Armor _armor){

    store(armor);
    armor = _armor;
}

// Display Inventory

void Player::display_items(){

    int items_in_inventory = invItems.size();

    if (items_in_inventory == 0)
    {
        cout << "\nYou have no items in your inventory.\n";
        return;
    }

    // Create string for display
    cout << "\nInventory:\n" << endl;

    // Loop through items in inventory vector
    for ( int i = 0; i < items_in_inventory; i++ ){
        cout << "\t" << i << " " << invItems[i].name << endl;
    }
}

void Player::display_weapons()
{
    int numWeapons = invWeapons.size();

    if (numWeapons == 0)
    {
        cout << "You have no weapons in your inventory.\n";
        return;
    }

    cout << "\nWeapons:\n" << endl;

    for (int i = 0; i < numWeapons; i++)
    {
        cout << "\t" << i << " " << invWeapons[i].name << " " << "Damage: " << invWeapons[i].damage << endl;
    }
}

void Player::display_armors()
{
    int numArmors = invArmors.size();

    if (numArmors == 0)
    {
        cout << "You have no armors in your inventory.\n";
        return;
    }

    cout << "\nArmors:\n" << endl;

    for (int i = 0; i < numArmors; i++)
    {
        cout << "\t" << i << " " << invArmors[i].name << " " << "Phys Def: " << invArmors[i].physical_defense
        << " " << "Magic Def: " << invArmors[i].magical_defense << endl;
    }
}

void Player::display_inventory()
{
    display_items();
    display_weapons();
    display_armors();
    cout << endl;
}

void Player::inventory()
{
    // Get the operating system...
    string os_name = getOS();

    cout << "Welcome to the inventory manager.\n";
    int choice;
    while (true)
    {
        cout << "What would you like to do?\n\n";
        cout << "1) View your entire inventory\n";
        cout << "2) Use an item\n";
        cout << "3) Switch weapon\n";
        cout << "4) Switch armor\n";
        cout << "5) Exit inventory manager\n\n>>> ";
        cin >> choice;
        if (choice == 1)
        {
            display_inventory();
        }
        else if (choice == 2)
        {
            if (invItems.empty())
            {
                cout << "You have no items.\n";
            }
            else
            {
                int itemChoice;
                cout << "Which item do you want to use?\n\n>>> ";
                display_items();
                cin >> itemChoice;
                if (invItems[itemChoice].name == "Health Potion")
                {
                    cout << "Restored health by 25.\n";
                    if (current_health + 25 > base_health)
                        current_health = base_health;
                    else
                        current_health += 25;
                    invItems.erase(invItems.begin() + itemChoice);
                    pressAnyKey(os_name);
                }
                else if (invItems[itemChoice].name == "Mana Potion")
                {
                    cout << "Restored mana by 25.\n";
                    if (current_mana + 25 > base_mana)
                        current_mana = base_mana;
                    else
                        current_mana += 25;
                    invItems.erase(invItems.begin() + itemChoice);
                    pressAnyKey(os_name);
                }
                else if (invItems[itemChoice].name == "Bomb")
                {
                    cout << "You cannot use that item outside of combat.\n";
                    pressAnyKey(os_name);
                }
                else if (invItems[itemChoice].name == "Gold Pouch")
                {
                    Dice d(100);
                    int goldToGive = d.roll();
                    cout << "You open the gold pouch and find " << goldToGive << " gold.\n";
                    gold += goldToGive;
                    invItems.erase(invItems.begin() + itemChoice);
                    pressAnyKey(os_name);
                }
            }
        }
        else if (choice == 3)
        {
            if (invWeapons.size() == 0)
                cout << "You have no other weapons.\n";
            else
            {
                cout << "You are currently equipped with: \n";
                cout << weapon.name << " " << "Damage: " << weapon.damage;
                cout << "Your other weapons are: \n\n";
                display_weapons();
                cout << "Which weapon do you want to equip?\n>>> ";
                int weaponChoice;
                cin >> weaponChoice;
                Weapon oldWeapon = weapon;
                weapon = invWeapons[weaponChoice];
                invWeapons.erase(invWeapons.begin() + weaponChoice);
                invWeapons.push_back(oldWeapon);
                cout << weapon.name << " equipped." << endl;
                pressAnyKey(os_name);
            }
        }
        else if (choice == 4)
        {
            if (invArmors.size() == 0){
                cout << "You have no other armors.\n";
                pressAnyKey(os_name);
            } else
            {
                cout << "You are currently equipped with: \n";
                cout << armor.name << " " << "Phys Def: " << armor.physical_defense << " " << "Magic Def: " << armor.magical_defense << endl;
                display_armors();
                cout << "Which armor do you want to equip?\n>>> ";
                int armorChoice;
                cin >> armorChoice;
                Armor oldArmor = armor;
                armor = invArmors[armorChoice];
                invArmors.erase(invArmors.begin() + armorChoice);
                invArmors.push_back(oldArmor);
                cout << armor.name << " equipped." << endl;
                pressAnyKey(os_name);
            }
        }
        else if (choice == 5)
            break;
    }
}

// Display Player Sheet

void Player::display(){
    cout << "Player Sheet:\n" << endl;
    display_attributes();
    cout << "\n\tGold: " << gold << endl;
    cout << "\tWeapon: " << weapon.name << endl;
    cout << "\t\tDamage: " << weapon.damage << endl;
    cout << "\tArmor: " << armor.name << endl;
    cout << "\t\tPhysical Defense: " << armor.physical_defense << endl;
    cout << "\t\tMagical Defense: " << armor.magical_defense << endl;
    cout << "\tSpells";
    display_spellbook();
    cout << endl;
}

// Display Spellbook

void Player::display_spellbook(){

    cout << "(" << spellbook.size() << "):\n\t";

    if (spellbook.size() == 0) {

        cout << "None" << endl;

    } else {

        for ( int i = 0; i < spellbook.size(); i++ ){

            cout << i << " - " << spellbook[i].name;

            if ( i < spellbook.size() -1 ){
                cout << ", ";
            }
        }
    }
}

#endif  // __PLAYER_H_INCLUDED__
