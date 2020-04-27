
//combat.h
//Dang Doan
//Dangdoan115@gmail.com
//Combat System for Dungeons no Dragons

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

bool battle_Sys(Player& mainPlayer, Enemy& anEnemy)
{

    //Dice
    Dice d;

    while (mainPlayer.health > 0 && anEnemy.health > 0)
    {
        int enemy_Health;
        int player_Choice;

        //Combat Menu
        cout
             << "\nPlayer Health: "
             << mainPlayer.health
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
            {
                mainPlayer.deal_damage(anEnemy);

                cout << "\n\nEnemy's current HP: "
                     << anEnemy.health;

                break;
            }
            //Magic DMG
        case 2:
            {
                if (mainPlayer.spellbook.empty())
                {
                    cout << "You have not learned any spells.\n";
                    break;
                }
                cout << "\n\nYou open your spellbook.";

                mainPlayer.display_spellbook();
                int choice;
                cout << "\n\nWhich spell do you want to use?\n";
                cin >> choice;
                mainPlayer.deal_damage(anEnemy, mainPlayer.spellbook[choice]);

                cout << "\n\nEnemy's current HP: "
                     << anEnemy.health;

                break;
            }

            //Defend
        case 3:
            {

                cout << "\n\nYou get into a defensive stance.";

                //Buffs player to
                Buff defending = Buff("Defending", "Armor", 5, 1);
                mainPlayer.add_buff(defending);

                break;
            }
            //Items
        case 4:
            {
                if (mainPlayer.inventory.empty())
                {
                    cout << "Your inventory is empty.\n";
                    break;
                }
                int choice;
                cout << "\n\nYou open your backpack.";
                mainPlayer.display_inventory();
                cout << "\nEnter which item to use: \n";
                cin >> choice;

                Item chosenItem = mainPlayer.inventory[choice];

                if (chosenItem.name == "Health Potion")
                {
                    mainPlayer.health += 25;
                }
                else if (chosenItem.name == "Mana Potion")
                {
                    mainPlayer.mana += 25;
                }
                else if (chosenItem.type == "Bomb")
                {
                    mainPlayer.deal_damage(anEnemy, chosenItem);
                }

                mainPlayer.inventory.erase(mainPlayer.inventory.begin() + choice);
                break;
            }
            //Intimidate
        case 5:
            {
                cout << "\n\nYou attempt to intimidate.";

                //Debuffs the enemy's STR and WIS
                Buff intimidate_STR = Buff("Intimidate STR", "str", -2, 3);
                Buff intimidare_WIS = Buff("Intimidate WIS", "wis", -2, 3);

                anEnemy.add_buff(intimidate_STR);
                anEnemy.add_buff(intimidare_WIS);

                break;
            }

        //Checking stats for debugging

        case 7:
            {
                anEnemy.display();
            }

        case 8:
            {
                mainPlayer.display();
            }

        }

        mainPlayer.trigger_buffs();

        if (anEnemy.health <= 0)
        {
            return true;
        }

        //Enemy attack
        if (d.roll() <= 10)
        {
            cout << "\n\nThe enemy used a physical attack.";
            anEnemy.deal_damage(mainPlayer);
        }
        else
        {
            cout << "\n\nThe enemy used a magic attack.";
            anEnemy.deal_damage(mainPlayer, Spells["Fireball"]);
        }

        anEnemy.trigger_buffs();
    }

    return false;
}

#endif // COMBAT_H_INCLUDED
