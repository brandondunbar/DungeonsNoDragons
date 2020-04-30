
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

    while (mainPlayer.current_health > 0 && anEnemy.current_health > 0)
    {
        int enemy_Health;
        int player_Choice;

        //Combat Menu
        cout
             << "\nPlayer Health: "
             << mainPlayer.current_health
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
                     << anEnemy.current_health;

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
                
                if (mainPlayer.current_mana < mainPlayer.spellbook[choice].cost)
                {
                    cout << "\n\nYou don't have enough mana";
                }
                else
                {
                    mainPlayer.deal_damage(anEnemy, mainPlayer.spellbook[choice]);
                }
                

                if (mainPlayer.spellbook[choice].name == "Slime Bomb")
                {
                    Buff slimeBomb = Buff("Slime Bomb", "dot", 10, 5);
                    anEnemy.add_buff(slimeBomb);
                }

                if (mainPlayer.spellbook[choice].name == "Shout")
                {
                    Buff shout = Buff("Shout", "str", 5, 5);
                    mainPlayer.add_buff(shout);
                }

                if (mainPlayer.spellbook[choice].name == "Shadow Banish")
                {
                    Buff banish = Buff("Shadow Banish", "str", -5, 3);
                    anEnemy.add_buff(banish);
                }

                cout << "\n\nEnemy's current HP: "
                     << anEnemy.current_health;

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
                if (mainPlayer.invItems.empty())
                {
                    cout << "Your inventory is empty.\n";
                    break;
                }
                int choice;
                cout << "\n\nYou open your backpack.";
                mainPlayer.display_items();
                cout << "\nEnter which item to use: \n";
                cin >> choice;

                Item chosenItem = mainPlayer.invItems[choice];

                if (chosenItem.name == "Health Potion")
                {
                    if (mainPlayer.current_health + 25 > 100)
                        mainPlayer.current_health = 100;
                    else
                        mainPlayer.current_health += 25;
                }
                else if (chosenItem.name == "Mana Potion")
                {
                    if (mainPlayer.current_mana + 25 > 100)
                        mainPlayer.current_mana = 100;
                    else
                        mainPlayer.current_mana += 25;
                }
                else if (chosenItem.type == "Bomb")
                {
                    mainPlayer.deal_damage(anEnemy, chosenItem);
                }

                mainPlayer.invItems.erase(mainPlayer.invItems.begin() + choice);
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

        if (anEnemy.current_health <= 0)
        {
            cout << "The enemy dropped " << anEnemy.loot[0].name << endl;
            mainPlayer.store(anEnemy.loot[0]);
            return true;
        }

        //Enemy attack
        if (d.roll() <= 10 && anEnemy.spellbook.size() > 0)
        {
            Dice spellDice = Dice(anEnemy.spellbook.size());
            int spellChoice = spellDice.roll();
            Spell spell = anEnemy.spellbook[spellChoice-1];
            cout << "\n\nThe enemy used " << spell.name << endl;
            anEnemy.deal_damage(mainPlayer, spell);
            
        }
        else
        {
            cout << "\n\nThe enemy used a physical attack.";
            anEnemy.deal_damage(mainPlayer);
        }

        anEnemy.trigger_buffs();
    }

    return false;
}

#endif // COMBAT_H_INCLUDED
