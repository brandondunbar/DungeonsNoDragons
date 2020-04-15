
//New Combat Sys

#ifndef COMBAT_H_INCLUDED
#define COMBAT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

#include "armor.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "item.h"
#include "weapon.h"
#include "dictionary.h"
#include "spell.h"
#include "utility.h"
#include "dice.h"
#include "buff.h"

void battle_Sys(Player& player_character, Enemy& anEnemy)
{

    //Dice
    Dice d;

    while (player_character.health > 0 && anEnemy.health > 0)
    {
        int enemy_Health;
        int player_Choice;

        //Combat Menu
        cout
             << "\nPlayer Health: "
             << player_character.health
             << "\n\nMake your move"
             << "\n1. Attack\n"
             << "2. Magic\n"
             << "3. Defend\n"
             << "4. Check Items/Use Items\n"
             << "5. Intimidate\n";

        cin >> player_Choice;

        switch (player_Choice)
        {
            //Physical DMG
        case 1:
            player_character.deal_damage(anEnemy);

            cout << "\n\nEnemy's current HP: "
                 << anEnemy.health;

            break;

            //Magic DMG
        case 2:

            cout << "\n\nYou open your spellbook.";

            player_character.display_spellbook();
            int choice;
            cout << "\n\nWhich spell do you want to use?\n";
            cin >> choice;
            player_character.deal_damage(anEnemy, player_character.spellbook[choice]);

            cout << "\n\nEnemy's current HP: "
                 << anEnemy.health;

            break;

            //Defend
        case 3:

            cout << "\n\nYou get into a defensive stance.";

            //Make a debuff for enemy STR and WIS based on dice roll

            break;

            //Items
        case 4:

            cout << "\n\nYou open your backpack.";
            player_character.display_inventory();

            break;

            //Intimidate
        case 5:

            cout << "\n\nYou attempt to intimidate.";

            //Buff the player by a dice roll

            break;

        }


        //Enemy attack
        if (d.roll() <= 10)
        {
            anEnemy.deal_damage(player_character);
        }
        else
        {
            anEnemy.deal_damage(player_character, Spells["Fireball"]);
        }
    }
}

#endif // COMBAT_H_INCLUDED
