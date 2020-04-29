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


int main()
{
    Player mainPlayer = Player("name", "class", "race");
    //Intro sequence
    cout << "\n\nWelcome to Dungeons no Dragons!"
         << "\nDungeons no Dragons is a text adventure game with mechanics inspired by Dungeons and Dragons."
         << "\nYou recieved a clue on your sister who went missing a few years ago."
         << "\nYou begin your search in the southern city Eretedon, a city plagued with rumors of the arrival of Gylbesdaym, Eater of All."
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
            mainPlayer.weapon = Weapons["Dull Magic Sword"];
            break;

        case 2:
            mainPlayer.character_class = "Mercenary";
            //Add items
            mainPlayer.weapon = Weapons["Rusty Great Sword"];
            break;

        case 3:
            mainPlayer.character_class = "Scholar";
            //Add items
            mainPlayer.weapon = Weapons["Dusty Magic Tome"];
            break;

        case 4:
            mainPlayer.character_class = "Summoner";
            //Add items
            mainPlayer.weapon = Weapons["Pine Magic Staff"];
            break;

        case 5:
            mainPlayer.character_class = "Marksman";
            //Add items
            mainPlayer.weapon = Weapons["Short Bow"];
            break;

        case 6:
            mainPlayer.character_class = "Thief";
            //Add items
            mainPlayer.weapon = Weapons["Chipped Dual Daggers"];
            break;
    }

    cout << "\nI was a "
         << mainPlayer.character_class;

    //End of character creation

    //Transition to city (story)
    cout << "After leaving the tavern, the storywriter advises you to register at the guild and earn some gold before anything else.";

    while (!gameOver && mainPlayer.health > 0)
    {
        int choice;
        cout << "Welcome to Eretedon! What would you like to do here?\n";
        cout << "1) Rest at the inn (10 gold)\n";
        cout << "2) Visit the store\n";
        cout << "3) Enter the first dungeon\n";
        cout << "4) Enter the second dungeon\n";
        cout << "5) Enter the third dungeon\n";
        cout << "6) Enter the fourth dungeon\n";
        cout << "7) Enter the fifth dungeon\n";
        cout << "8) Enter the sixth dungeon\n";
        cout << "9) Inventory\n";
        cout << "10) Give up\n";
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
                    // firstDungeon(mainPlayer);
                    hasDoneFirstDungeon = true;
                    break;
                }
            }
        case 4:
            {
                if (hasDoneSecondDungeon)
                {
                    cout << "You enter the dungeon, but the monsters are already slain. You head back to Eretedon.\n";
                    break;
                }
                else if (!hasDoneFirstDungeon)
                {
                    cout << "The dungeon is sealed with powerful magic. You head back to Eretedon.\n";
                    break;
                }
                else
                {
                    // secondDungeon(mainPlayer);
                    hasDoneSecondDungeon = true;
                    break;
                }
            }
        case 5:
            {
                if (hasDoneThirdDungeon)
                {
                    cout << "You enter the dungeon, but the monsters are already slain. You head back to Eretedon.\n";
                    break;
                }
                else if (!hasDoneSecondDungeon)
                {
                    cout << "The dungeon is sealed with powerful magic. You head back to Eretedon.\n";
                    break;
                }
                else
                {
                    // thirdDungeon(mainPlayer);
                    hasDoneThirdDungeon = true;
                    break;
                }
            }
        case 6:
            {
                if (hasDoneFourthDungeon)
                {
                    cout << "You enter the dungeon, but the monsters are already slain. You head back to Eretedon.\n";
                    break;
                }
                else if (!hasDoneThirdDungeon)
                {
                    cout << "The dungeon is sealed with powerful magic. You head back to Eretedon.\n";
                    break;
                }
                else
                {
                    // fourthDungeon(mainPlayer);
                    hasDoneFourthDungeon = true;
                    break;
                }
            }
        case 7:
            {
                if (hasDoneFifthDungeon)
                {
                    cout << "You enter the dungeon, but the monsters are already slain. You head back to Eretedon.\n";
                    break;
                }
                else if (!hasDoneFourthDungeon)
                {
                    cout << "The dungeon is sealed with powerful magic. You head back to Eretedon.\n";
                    break;
                }
                else
                {
                    // fifthDungeon(mainPlayer);
                    hasDoneFifthDungeon = true;
                    break;
                }
            }
        case 8:
            {
                if (!hasDoneFifthDungeon)
                {
                    cout << "The dungeon is sealed with powerful magic. You head back to Eretedon.\n";
                    break;
                }
                else
                {
                    // sixthDungeon(mainPlayer);
                    break;
                }
            }
        case 9:
            {
                //Work in progress, changes needed for the player to fully access their inventory
                cout << "You check your gear\n";
                mainPlayer.inventory();
            }
        case 10:
            {
                cout << "You leave the city with no clues to where your sister could be\n";
                cout << "End of game.\n";
                gameOver = true;
                break;
            }
        default:
            {
                cout << "Your character wanders around for a bit, gets lost, then finds his way back to the guild.\n";
                break;
            }
        }
    }
    return 0;
}

//Store
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

//Dungeon 1 (needs story and enemy generation)
void firstDungeon(Player& aPlayer)
{
    Puzzle p = Puzzle(0);
    string inventoryAnswer;

    //Story
    cout << "\n\nThe guild decides to give you a exterminate mission to assess your skill and experience."
         << "\nThe location is the GreenHill Cave and the target is the slime king."
         << "\nYou push open the moss covered doors and head inside without hesitation.";

    //Enemy Generation

    //Combat
    if (battle_Sys(aPlayer, slime))
    {
        //Win
    }
    else
    {
        //Lose
    }
    

    //Inventory
    cout << "Do you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();

    //Puzzle
    cout << "\n\nYou spot a door sealed by magic.";
    if(p.solve())
    {
        //Rewards gold
        cout << "\n\nYou find a small pouch of coins nested next to a skeleton.";
        aPlayer.gold += 50;
    }

    //Enemy Generation

    //Combat
    if (battle_Sys(aPlayer, slime))
    {
        //Win
    }
    else
    {
        //Lose
    }

    //Inventory
    cout << "Do you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();

    //Story

    //Boss
    if (battle_Sys(aPlayer, slimeKing))
    {
        //Win
    }
    else
    {
        //Lose
    }
    
    Puzzle p = Puzzle(0);

    //Puzzle
    cout << "\n\nA locked chest appears where the boss was once at.";
    if (p.solve())
    {
            //Rewards Unique Boss Item
    }
}

//Dungeon 2 (needs story and enemy generation)
void secondDungeon(Player& aPlayer)
{
    Puzzle p = Puzzle(0);
    string inventoryAnswer;

    //Story

    //Enemy Generation

    //Battle
    if (battle_Sys(aPlayer, zombie))
    {
        //Win
    }
    else
    {
        //Lose
    }
    

    //Inventory
    cout << "Do you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();
    //Puzzle
    //Puzzle Story
    if(p.solve())
    {
            //Standard puzzle reward
    }
    
    //Enemy Generation

    //Battle
    if (battle_Sys(aPlayer, zombie))
    {
        //Win
    }
    else
    {
        //Lose
    }
    
    //Inventory
    cout << "Do you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();
    //Story

    //Boss
    if (battle_Sys(aPlayer, undeadGiant))
    {
        //Win
    }
    else
    {
        //Lose
    }

    Puzzle p = Puzzle(0);

    //Puzzle
    //Puzzle story
    if(p.solve())
    {
        //Rewards Unique Boss Item
    }
}

void thirdDungeon(Player& aPlayer)
{
    Puzzle p = Puzzle(1);
    string inventoryAnswer;

    //Story

    //Enemy Generation

    //Battle
    if (battle_Sys(aPlayer, miniGoblin))
    {
        //won battle
    }
    else
    {
        //died
    }
    

    //Inventory
    cout << "Do you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();
    //Puzzle
    //Puzzle Story

    if(p.solve());
    {
        //standard puzzle reward
    }
    

    //Enemy Generation

    //Battle
    if (battle_Sys(aPlayer, goblinWarrior))
    {
        //won battle
    }
    else
    {
        //died
    }

    //Inventory
    cout << "Do you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();
    //Boss
    if (battle_Sys(aPlayer, goblinLord))
    {
        //won battle
    }
    else
    {
        //died
    }

    //Puzzle
    //Puzzle Story
    Puzzle p = Puzzle(1);

    if(p.solve());
    {
        //Rewards Unique Boss Item
    }
}

//Dungeon 4 (needs story and enemy generation)
void fourthDungeon(Player& aPlayer)
{
    Puzzle p = Puzzle(2);
    string inventoryAnswer;

    //Story

    //Enemy Generation

    //Battle
    if (battle_Sys(aPlayer, lesserDemon))
    {
        //Win
    }
    else
    {
        //Lose
    }
    
    //Inventory
    cout << "Do you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();
    //Puzzle
    //Puzzle Story
    if(p.solve())
    {
        //Rewards
    }

    //Enemy Generation

    //Battle
    if (battle_Sys(aPlayer, lesserDemon))
    {
        //Win
    }
    else
    {
        //Lose
    }
    
    //Inventory
    cout << "Do you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();
    //Boss
    if (battle_Sys(aPlayer, demonLord))
    {
        //Win
    }
    else
    {
        //Lose
    }
    
    Puzzle p = Puzzle(2);

    //Puzzle
    //Puzzle Story

    if(p.solve())
    {
        //Rewards Unique Boss Item
    }
}

void fifthDungeon(Player& aPlayer)
{
    Puzzle p = Puzzle(2);
    string inventoryAnswer;

    //Story

    //Enemy Generation

    //Battle
    if (battle_Sys(aPlayer, dwarf))
    {
        //won battle
    }
    else
    {
        //died
    }
    

    //Inventory
    cout << "Do you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();
    //Puzzle
    //Puzzle Story

    if(p.solve());
    {
        //standard puzzle reward
    }
    

    //Enemy Generation

    //Battle
    if (battle_Sys(aPlayer, dwarf))
    {
        //won battle
    }
    else
    {
        //died
    }

    //Inventory
    cout << "Do you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();
    //Boss
    if (battle_Sys(aPlayer, dwarfBoss))
    {
        //won battle
    }
    else
    {
        //died
    }

    //Puzzle
    //Puzzle Story
    Puzzle p = Puzzle(2);

    if(p.solve());
    {
        //Rewards Unique Boss Item
    }
}

//Dungeon 6 (needs story and enemy generation)
void sixthDungeon(Player& aPlayer)
{
    string inventoryAnswer;

    //Story

    //Boss
    if (battle_Sys(aPlayer, gylbesdaym))
    {
        //Win
    }
    else
    {
        //Lose
    }

    //Inventory
    cout << "Do you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();

    //Final Boss
    if (battle_Sys(aPlayer, demonSister))
    {
        //Win
    }
    else
    {
        //Lose
    }

    //Story
}



