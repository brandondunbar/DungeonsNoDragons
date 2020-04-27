#include <iostream>
#include <vector>

using namespace std;

#include "player.h"
#include "enemy.h"
#include "dice.h"
#include "puzzle.h"
#include "combat.h"

void visitStore(Player& aPlayer);
void firstDungeon(Player& aPlayer);
void secondDungeon(Player& aPlayer);
void thirdDungeon(Player& aPlayer);
void fourthDungeon(Player& aPlayer);
void fifthDungeon(Player& aPlayer);
void sixthDungeon(Player& aPlayer);

Enemy generateEnemy(int dungeon, int difficulty);

//Dungeon Checks
bool gameOver = false;
bool hasDoneFirstDungeon = false;
bool hasDoneSecondDungeon = false;
bool hasDoneThirdDungeon = false;
bool hasDoneFourthDungeon = false;
bool hasDoneFifthDungeon = false;

//Player Template
Player mainPlayer = Player("name", "class", "race");

int main()
{
    //Intro sequence
    cout << "\n\nWelcome to Dungeons no Dragons!"
         << "\nDungeons no Dragons is a text adventure game with mechanics inspired by Dungeons and Dragons."
         << "\nIn this game, you're on a quest to save your sister from Gylbesdaym, Eater of All."
         << "\nYou heard rumors of Gylbesdaym terrorizing a city in the south called Eretedon."
         << "\nYou arrive at a tavern on the city outskirts and sit at the counter."
         << "\nThe man next to you says,"
         << "\n\nHooded man: You must be insane to come to this acursed city at such a time"
         << "\nHooded man: There are rumors of a massive wave of monsters moving closer to the city because of Gylbesdaym's arrival recently."
         << "\nHooded man: You though, don't look like an average traveler, tell me, what is your name.";
    
    //Character creation
    cout << "\n\nMy name is: ";
    string name;
    cin >> name;

    mainPlayer.name = name;

    cout << "\nRaces: "
         << "\n1.Human, adaptable, average in all things"
         << "\n2.Elf, swift nomads that usually roam the forests in the west"
         << "\n3.Dwarf, their sturdiness makes up for thier lack of height"
         << "\n4.Tiefling, silver-tounged creatures born from darkness"
         << "\n5.Gnome, small, cunning tinkerers that boast high intelligence"
         << "\nSelect race: ";

    int raceChoice;
    cin >> raceChoice;
    switch (raceChoice)
    {
        case 1:
            mainPlayer.race = "Human";
            mainPlayer.strength += 1;
            mainPlayer.constitution += 1;
            mainPlayer.dexterity += 1;
            mainPlayer.intelligence += 1;
            mainPlayer.wisdom += 1;
            mainPlayer.charisma += 1;
            break;

        case 2:
            mainPlayer.race = "Elf";
            mainPlayer.dexterity += 2;
            break;

        case 3:
            mainPlayer.race = "Dwarf";
            mainPlayer.constitution += 2;
            break;

        case 4:
            mainPlayer.race = "Tiefling";
            mainPlayer.charisma += 2;
            break;

        case 5:
            mainPlayer.race = "Gnome";
            mainPlayer.intelligence += 2;
            break;
    }

    cout << "\nI am a "
         << mainPlayer.race;

    cout << "\n\nHooded man: Oh I see, I'm a novice storywriter and I've run into a writers' block recently."
         << "\nI came hoping to find new inspiration."
         << "\nWhat did you do before coming here?";

    cout << "\n\nClasses: "
         << "\n1.Paladin, a holy knight proficient in both holy magic and melee combat"
         << "\n2.Mercenary, a wandering sellsword skilled with a blade"
         << "\n3.Scholar, a student of the arcane arts knowledgeable in ancient magecraft"
         << "\n4.Summoner, commands spirits to weaken foes"
         << "\n5.Marksman, a former hunter with unrivaled precision"
         << "\n6.Thief, an agile cutpurse";
    
    int playerClass;
    cin >> playerClass;
    switch (playerClass)
    {
        case 1:
            mainPlayer.character_class = "Paladin";
            //Add items
            break;

        case 2:
            mainPlayer.character_class = "Mercenary";
            //Add items
            break;

        case 3:
            mainPlayer.character_class = "Scholar";
            //Add items
            break;

        case 4:
            mainPlayer.character_class = "Summoner";
            //Add items
            break;

        case 5:
            mainPlayer.character_class = "Marksman";
            //Add items
            break;

        case 6:
            mainPlayer.character_class = "Thief";
            //Add items
            break;
    }

    cout << "\nI was a "
         << mainPlayer.character_class;

    while (!gameOver && mainPlayer.health > 0)
    {
        int choice;
        cout << "Welcome to town! What would you like to do here?\n";
        cout << "1) Rest at the inn (10 gold)\n";
        cout << "2) Visit the store\n";
        cout << "3) Enter the first dungeon\n";
        cout << "4) Enter the second dungeon\n";
        cout << "5) Enter the third dungeon\n";
        cout << "6) Enter the fourth dungeon\n";
        cout << "7) Enter the fifth dungeon\n";
        cout << "8) Enter the sixth dungeon\n";
        cout << "9) Give up\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            {
                if (mainPlayer.gold < 10)
                {
                    cout << "You do not have enough gold to visit the inn.\n";
                    break;
                }
                else
                {
                    cout << "You visit the inn and rest for the night, restoring your health and mana.\n";
                    break;
                }
            }
        case 2:
            {
                visitStore(mainPlayer);
                break;
            }
        case 3:
            {
                if (hasDoneFirstDungeon)
                {
                    cout << "You enter the dungeon, but the monsters are already slain.\n";
                    break;
                }
                else
                {
                    firstDungeon(mainPlayer);
                    hasDoneFirstDungeon = true;
                    break;
                }
            }
        case 4:
            {
                if (hasDoneSecondDungeon)
                {
                    cout << "You enter the dungeon, but the monsters are already slain. You head back to town.\n";
                    break;
                }
                else if (!hasDoneFirstDungeon)
                {
                    cout << "The dungeon is sealed with powerful magic. You head back to town.\n";
                    break;
                }
                else
                {
                    secondDungeon(mainPlayer);
                    hasDoneSecondDungeon = true;
                    break;
                }
            }
        case 5:
            {
                if (hasDoneThirdDungeon)
                {
                    cout << "You enter the dungeon, but the monsters are already slain. You head back to town.\n";
                    break;
                }
                else if (!hasDoneSecondDungeon)
                {
                    cout << "The dungeon is sealed with powerful magic. You head back to town.\n";
                    break;
                }
                else
                {
                    thirdDungeon(mainPlayer);
                    hasDoneThirdDungeon = true;
                    break;
                }
            }
        case 6:
            {
                if (hasDoneFourthDungeon)
                {
                    cout << "You enter the dungeon, but the monsters are already slain. You head back to town.\n";
                    break;
                }
                else if (!hasDoneThirdDungeon)
                {
                    cout << "The dungeon is sealed with powerful magic. You head back to town.\n";
                    break;
                }
                else
                {
                    fourthDungeon(mainPlayer);
                    hasDoneFourthDungeon = true;
                    break;
                }
            }
        case 7:
            {
                if (hasDoneFifthDungeon)
                {
                    cout << "You enter the dungeon, but the monsters are already slain. You head back to town.\n";
                    break;
                }
                else if (!hasDoneFourthDungeon)
                {
                    cout << "The dungeon is sealed with powerful magic. You head back to town.\n";
                    break;
                }
                else
                {
                    fifthDungeon(mainPlayer);
                    hasDoneFifthDungeon = true;
                    break;
                }
            }
        case 8:
            {
                if (!hasDoneFifthDungeon)
                {
                    cout << "The dungeon is sealed with powerful magic. You head back to town.\n";
                    break;
                }
                else
                {
                    sixthDungeon(mainPlayer);
                    break;
                }
            }
        case 9:
            {
                cout << "You lay down your weapons and give up on saving your sister.\n";
                cout << "End of game.\n";
                gameOver = true;
                break;
            }
        default:
            {
                cout << "Your character wanders around for a bit, gets lost, then finds his way back to town.\n";
                break;
            }
        }
    }
    return 0;
}


void visitStore(Player& aPlayer)
{
    cout << "Welcome to the Jorildyn's store! What would you like to do?\n\n";
    cout << "1) Health Potion (restores 25 health) - 5 gold\n";
    cout << "2) Mana Potion (restores 25 mana) - 5 gold\n";
    cout << "3) Bomb (does 10 damage) - 5 gold\n";
    cout << "4) Iron Armor (5 physical defense, 1 magical defense, neutral) - 20 gold\n";
    cout << "5) Lightning Armor (10 physical defense, 10 magical defense, neutral) - 50 gold\n";
    cout << "6) Iron Sword (10 damage, neutral) - 15 gold\n";
    cout << "7) Long Bow (10 damage, neutral) - 15 gold\n";
    cout << "8) Staff (20 damage, neutral) - 30 gold\n";
    cout << "9) Leave\n";
    int choice;
    cin >> choice;
    while (true){
        switch (choice)
        {
            case 1:
            {
                if (aPlayer.gold < 5)
                {
                    cout << "You do not have enough gold to purchase this item.\n";
                    break;
                }
                else
                {
                    aPlayer.gold -= 5;
                    aPlayer.inventory.push_back(Items["Health Potion"]);
                    cout << "Thank you for your purchase!\n";
                    break;
                }
            }
            case 2:
            {
                if (aPlayer.gold < 5)
                {
                    cout << "You do not have enough gold to purchase this item.\n";
                    break;
                }
                else
                {
                    aPlayer.gold -= 5;
                    aPlayer.inventory.push_back(Items["Mana Potion"]);
                    cout << "Thank you for your purchase!\n";
                    break;
                }
            }
            case 3:
            {
                if (aPlayer.gold < 5)
                {
                    cout << "You do not have enough gold to purchase this item.\n";
                    break;
                }
                else
                {
                    aPlayer.gold -= 5;
                    aPlayer.inventory.push_back(Items["Bomb"]);
                    cout << "Thank you for your purchase!\n";
                    break;
                }
            }
            case 4:
            {
                if (aPlayer.gold < 20)
                {
                    cout << "You do not have enough gold to purchase this item.\n";
                    break;
                }
                else
                {
                    aPlayer.gold -= 20;
                    aPlayer.inventory.push_back(Armors["Iron Armor"]);
                    cout << "Thank you for your purchase!\n";
                    break;
                }
            }
            case 5:
            {
                if (aPlayer.gold < 50)
                {
                    cout << "You do not have enough gold to purchase this item.\n";
                    break;
                }
                else
                {
                    aPlayer.gold -= 50;
                    aPlayer.inventory.push_back(Armors["Lightning Armor"]);
                    cout << "Thank you for your purchase!\n";
                    break;
                }
            }
            case 6:
            {
                if (aPlayer.gold < 15)
                {
                    cout << "You do not have enough gold to purchase this item.\n";
                    break;
                }
                else
                {
                    aPlayer.gold -= 15;
                    aPlayer.inventory.push_back(Weapons["Iron Sword"]);
                    cout << "Thank you for your purchase!\n";
                    break;
                }
            }
            case 7:
            {
                if (aPlayer.gold < 15)
                {
                    cout << "You do not have enough gold to purchase this item.\n";
                    break;
                }
                else
                {
                    aPlayer.gold -= 15;
                    aPlayer.inventory.push_back(Weapons["Long Bow"]);
                    cout << "Thank you for your purchase!\n";
                    break;
                }
            }
            case 8:
            {
                if (aPlayer.gold < 30)
                {
                    cout << "You do not have enough gold to purchase this item.\n";
                    break;
                }
                else
                {
                    aPlayer.gold -= 30;
                    aPlayer.inventory.push_back(Weapons["Staff"]);
                    cout << "Thank you for your purchase!\n";
                    break;
                }
            }
            case 9:
            {
                cout << "Thank you for shopping here!\n";
                return;
            }
        }
        cout << "What else do you want to purchase?\n";
        cin >> choice;
    }
}
