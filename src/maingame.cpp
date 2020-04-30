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

const int MAX_HEALTH = 100;
const int MAX_MANA = 100;

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
    mainPlayer.gold = 20;
    mainPlayer.health = MAX_HEALTH;
    mainPlayer.mana = MAX_MANA;
    //Intro sequence
    cout << "\n\nWelcome to Dungeons no Dragons!"
         << "\nDungeons no Dragons is a text adventure game with mechanics inspired by Dungeons and Dragons."
         << "\nYou've been searching for your sister for the last two years since she went missing."
         << "\nYour search eventually lead you to the southern city, Eretedon, a city plagued with rumors of the arrival of Gylbesdaym, Eater of All."
         << "\nYou arrive at a tavern on the city outskirts and sit at the counter."
         << "\nThe man next to you says,"
         << "\n\nHooded man: You must be insane to come to this city at such a time"
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
         << "\n6.Thief, an agile cutpurse\n";

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
            mainPlayer.learnSpell(Spells["Fireball"]);
            break;

        case 4:
            mainPlayer.character_class = "Summoner";
            //Add items
            mainPlayer.weapon = Weapons["Pine Magic Staff"];
            mainPlayer.learnSpell(Spells["Lightning Bolt"]);
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
    cout << "\n\nAfter leaving the tavern, the storywriter advises you to register at the guild and earn some gold before anything else.\n";

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
        cout << "9) View your stats\n";
        cout << "10) Inventory\n";
        cout << "11) Give up\n";
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
                    mainPlayer.health = MAX_HEALTH;
                    mainPlayer.mana = MAX_MANA;
                    mainPlayer.gold -= 10;
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
                    secondDungeon(mainPlayer);
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
                    thirdDungeon(mainPlayer);
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
                    fourthDungeon(mainPlayer);
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
                    fifthDungeon(mainPlayer);
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
                    sixthDungeon(mainPlayer);
                    break;
                }
            }
        case 9:
            {
                mainPlayer.display();
                break;
            }
        case 10:
            {
                //Work in progress, changes needed for the player to fully access their inventory
                cout << "You check your gear\n";
                mainPlayer.inventory();
                break;
            }
        case 11:
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
    cout << "9) Leave\n\n";
    cout << "Your gold - " << aPlayer.gold << endl;


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
                    aPlayer.invItems.push_back(Items["Health Potion"]);
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
                    aPlayer.invItems.push_back(Items["Mana Potion"]);
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
                    aPlayer.invItems.push_back(Items["Bomb"]);
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
                    aPlayer.invArmors.push_back(Armors["Iron Armor"]);
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
                    aPlayer.invArmors.push_back(Armors["Lightning Armor"]);
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
                    aPlayer.invWeapons.push_back(Weapons["Iron Sword"]);
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
                    aPlayer.invWeapons.push_back(Weapons["Long Bow"]);
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
                    aPlayer.invWeapons.push_back(Weapons["Staff"]);
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

//Dungeon 1
void firstDungeon(Player& aPlayer)
{
    Puzzle p = Puzzle(0);
    string inventoryAnswer;

    //Story
    cout << "\n\nThe guild decides to give you a exterminate mission to assess your skill and experience."
         << "\nThe location is the GreenHill Cave and the target is the slime king."
         << "\nYou push open the moss covered doors and head inside without hesitation."
         << "\nAfter a few steps you encounter a slime, and enter into combat.\n";

    //enemy generation
    Enemy slime = EnemyGenerator("slime", 1);

    //Combat
    if (battle_Sys(aPlayer, slime))
    {
        //Win
        cout << "\n\nThe slime splatters into a dozen driplets.";
    }
    else
    {
        //Lose
        cout << "\n\nYou get absorbed by the slime.";
        return;
    }


    //Inventory
    cout << "\nDo you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();

    //Puzzle
    cout << "\n\nYou spot a door sealed by magic.\n";
    cout << "There is a puzzle imprinted on the door. It reads: \n";
    if(p.solve())
    {
            //Rewards gold
        cout << "\n\nYou find a small pouch of coins nested next to a skeleton beyond the door. There is nothing else.\n";
        aPlayer.gold += 50;
    }

    cout << "You keep walking further into the dungeon when you come across another slime.\n";
    cout << "This slime looks a little stronger than the previous.\n";
    cout << "You enter into battle with the slime.\n";
    //enemy generation
    slime = EnemyGenerator("slime", 2);

    //Combat
    if (battle_Sys(aPlayer, slime))
    {
        //Win
        cout << "\n\nThe slime gets split down the middle.";
    }
    else
    {
        //Lose
        cout << "\n\nYou died from a slime.";
        return;
    }

    //Inventory
    cout << "\nDo you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();

    //Story
    cout << "\n\nYou find a huge, moss covered door at the end of the cave."
         << "\nIts quite heavy but you manage to push it open and enter."
         << "\nYou spot at the other end of the room a giant slime.";
    //boss generation
    Enemy slimeKing = EnemyGenerator("boss", 1);

    if (battle_Sys(aPlayer, slimeKing))
    {
        //Win
        cout << "\n\nThe slime king liquifies as you deliver the final blow.";
    }
    else
    {
        //Lose
        cout << "Your journey ends just as quickly as it began.";
        return;
    }

    p = Puzzle(0);

    //Puzzle
    cout << "\n\nA locked chest appears where the boss was once at.";
    if(p.solve())
    {
            //Rewards Unique Boss Item
            cout << "\n\nThe chest opens.\n";
            cout << "Inside, you find a slime armor and put it in your inventory.\n";
            aPlayer.store(Armor("Slime Armor", 10, 10, "Neutral"));
    }
    else
    {
        cout << "The chest disappears.\n";
    }
    

    //Story
    cout << "\n\nYou find a mysterious rune on the floor and promptly erase it."
         << "\nNext to the rune was an odd note, you take it with you."
         << "\nYou head back to Eretedon\n\n";
}

//Dungeon 2
void secondDungeon(Player& aPlayer)
{
    Puzzle p = Puzzle(0);
    string inventoryAnswer;

    //Story
    cout << "\n\nAfter reporting to the guild your feat and recieving your gate pass, you run into the storywriter you met at the bar."
         << "\nStorywriter: Oh hey "
         << aPlayer.name
         << ", nice meeting you here."
         << "\nStorywriter: I've heard rumors of undead rising recently in nearby villages, it sounds suspicious."
         << "\nStorywriter: I was going to file an official request but I hope you can check it out for me."
         << "\nYou give him a thumbs up and tell the storywriter you'll head there right away."
         << "\nStorywriter: Alright, I'll tell the guild that you've gone to the villages, good luck."
         << "\nBefore the storywriter left, you hand him the note and asked him to figure out what it means."
         << "\nStorywriter: I see, interesting. I'll see what I can find out about it."
         << "\n\n\nYou arrive at the closest village in the west to find no one around in the streets."
         << "\nYou decide to investigate."
         << "\nAll of the sudden, an undead creature jumps out at you and you battle it.\n";
    //enemy generation
    Enemy zombie = EnemyGenerator("undead", 1);

    //Battle
    if (battle_Sys(aPlayer, zombie))
    {
        //Win
        cout << "\n\nYou dispatched the undead swiftly";
    }
    else
    {
        //Lose
        cout << "\n\nYou're swarmed and killed";
        return;
    }


    //Inventory
    cout << "\nDo you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();

    //Puzzle
    //Puzzle Story
    cout << "\n\nYou found a odd magic chest";
    if(p.solve())
    {
        //Standard puzzle reward
        cout << "\n\nThe chest opens\n";
        cout << "Inside, you find some gold and a health pot.\n";
        aPlayer.gold += 25;
        aPlayer.store(Item("Health Potion", "Potion"));
    }
    else
    {
        cout << "The chest mysteriously disappears.\n";
    }
    
    cout << "When you look up you notice another zombie charging right at you, this one looks stronger\n";
    cout << "You engage in combat with it.\n";
    //enemy generation
    zombie = EnemyGenerator("undead", 2);

    //Battle
    if (battle_Sys(aPlayer, zombie))
    {
        //Win
        cout << "\n\nThe undead falls to the ground";
    }
    else
    {
        //Lose
        cout << "\n\nYour journey ends by the hands of the undead";
        return;
    }

    //Inventory
    cout << "\nDo you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();

    //Story
    cout << "\n\nYou find a lich in the center of the village."
         << "\nIt looks your way and begins to prepare it's spells.";

    //Boss
    Enemy undeadGiant = EnemyGenerator("boss", 2);
    if (battle_Sys(aPlayer, undeadGiant))
    {
        //Win
        cout << "\n\nThe lich dies, releasing it's magic which breaks the ground showing hidden underground structure.";
    }
    else
    {
        //Lose
        cout << "\n\nThe lich smites you with a lightning bolt.";
        return;
    }

    p = Puzzle(0);

    //Puzzle
    //Puzzle story
    cout << "\n\nA locked chest falls on top of the lich's corpse.";
    if(p.solve())
    {
        //Rewards Unique Boss Item
        cout << "\n\nThe chest opens.\n";
        cout << "Inside you find a lich bane sword.\n";
        aPlayer.store(Weapon("Lich Bane", 20, "Undead"));
    }
    else
    {
        cout << "\n\nThe chest mysteriously disappears.\n";
    }
    

    //Story
    cout << "\n\nYou explore the underground structure a bit to find a mysterious rune."
         << "\nYou spot a rune glowing in a corner near a table."
         << "\nYou approach it to find that it looks similar to the one in the cave."
         << "\nYou quicky sketch the mysterious rune onto some paper and destroy it"
         << "\nYou return to Eretedon.";
}

//Dungeons 3
void thirdDungeon(Player& aPlayer)
{
    Puzzle p = Puzzle(1);
    string inventoryAnswer;

    //Story
    cout << "\n\nYou waited for the storywriter at the guild to ask him about the rune."
         << "\nYou've waited for what feels like hours until he finally showed up with books in hand."
         << "\nStorywriter: Ah "
         << aPlayer.name
         << ", I was looking for you. I've found something interesting about the note you gave me."
         << "\nStorywriter: The language used for the note turns out to be ancient dwarven, an extinct language."
         << "\nThats not all, its also encoded. The person who wrote this seemed well versed in the language."
         << "\nI managed to translate a little bit of it."
         << "\nIt says, the Castle of Green Stones."
         << "\nI think it may be refering to the castle ruins northwest of the city, maybe you should check it out."
         << "\nYou hand him the sketching of the rune and ask him about it."
         << "\nStorywriter: I'm not to well-versed in magic but I know a mage who is, I'll ask him about it."
         << "\nYou thank him and head northwest towards the ruins."
         << "\nUpon arrival, you notice traces of goblins being in the area, you prepare for combat."
         << "\nThe first goblin runs up to you and begins to fight you.\n";

    //Enemy Generation
    Enemy miniGoblin = EnemyGenerator("greeny", 1);

    //Battle
    if (battle_Sys(aPlayer, miniGoblin))
    {
        //won battle
        cout << "\n\nYou killed the goblin.";
    }
    else
    {
        //died
        cout << "\n\nYou are killed by the goblin.";
        return;
    }


    //Inventory
    cout << "\nDo you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();
    //Puzzle
    //Puzzle Story
    cout << "\n\nYou find door covered in a magic field with a riddle on it.\n";

    if(p.solve())
    {
        //standard puzzle reward
        cout << "\n\nYou break open the door.\n";
        cout << "Just beyond the door you find some gold, a health pot, and a mana pot.\n";
        aPlayer.gold += 30;
        aPlayer.store(Item("Health Potion", "Potion"));
        aPlayer.store(Item("Mana Potion", "Potion"));
    }
    else
    {
        cout << "The door seals completely shut.\n";
    }
    

    cout << "\nA second, stronger goblin comes charging at you. You engage in combat.\n";
    //Enemy Generation
    Enemy goblinWarrior = EnemyGenerator("greeny", 2);
    //Battle
    if (battle_Sys(aPlayer, goblinWarrior))
    {
        //won battle
        cout << "\n\nYou slay the orc.";
    }
    else
    {
        //died
        cout << "\n\nThe orcs overwhelm you.";
        return;
    }

    //Inventory
    cout << "\nDo you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();

    //Story
    cout << "\n\nYou break down the massive doors and find the orc warlord sitting arrogantly on his throne."
         << "\nHe slowly stands up and you prepare for a fight.";

    //Boss
    Enemy goblinLord = EnemyGenerator("boss", 3);
    if (battle_Sys(aPlayer, goblinLord))
    {
        //won battle
        cout << "\n\nThe orc warlord gets knocked through a wall, revealing a path deeper underground.";
    }
    else
    {
        //died
        cout << "\n\nYou are sliced in half by his massive blade.";
        return;
    }

    //Puzzle
    //Puzzle Story
    cout << "\n\nYou spot a locked chest behind his throne.";
    p = Puzzle(1);

    if(p.solve())
    {
        //Rewards Unique Boss Item
        cout << "\n\nThe chest opens. Inside you find an orc hammer.\n";
        aPlayer.store(Weapon("Orc Hammer", 35, "Neutral"));
    }
    else
    {
        cout << "\n\nThe chest mysteriously disappears.\n";
    }
    

    //Story
    cout << "\n\nYou look at the path deeper downwards."
         << "\nUnsure if going down is a good idea, you return to Eretedon.";
}

//Dungeon 4
void fourthDungeon(Player& aPlayer)
{
    Puzzle p = Puzzle(2);
    string inventoryAnswer;

    //Story
    cout << "\n\nYou meet up with the storywriter at the plaza."
         << "\nStorywriter: Hey "
         << aPlayer.name
         << ", I got some good news and some bad news."
         << "\nThe good news is that the note mentions something about a woman and its dated back around two years ago, it might be your sister."
         << "\nThe bad news is that my mage friend informed me that this rune might be related to the appearence of Gylbesdaym."
         << "\nYou tell him about the hidden passage."
         << "\nStorywriter: I see, maybe we should go check that out."
         << "\nAs you two were about to head to the gate, you hear a massive explosion roar throughout the city."
         << "\nYou both turn around to find the upper half of the Eretedon royal palace gone and the city districts nearby engulfed in flames."
         << "\nA massive portal appears above the palace and countless demons appear out of it."
         << "\nStorywriter: You go and help the guards, I'll go find the mage to help us."
         << "\nYou head straight towards the palace through the main road while the storywriter goes to find the mage."
         << "\nYou engage in combat with the first demon that runs straight towards you.\n";

    //Enemy Generation
    Enemy lesserDemon = EnemyGenerator("demon", 1);

    //Battle
    if (battle_Sys(aPlayer, lesserDemon))
    {
        //Win
        cout << "\n\nYou turn the abyssal chicken into ash.";

    }
    else
    {
        //Lose
        cout << "\n\nYou're pierced through the chest.";
        return;

    }

    //Inventory
    cout << "\nDo you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();

    //Puzzle
    //Puzzle Story
    cout << "\n\nYou find a locked chest in some rubble.";
    if(p.solve())
    {
        //Rewards
        cout << "\n\nThe chest unlocks.";
        cout << " Inside you find some gold.\n";
        aPlayer.gold += 100;
    }
    else
    {
        cout << "\n\nThe chest mysteriously disappears.\n";
    }
    
    cout << "You look up and spot another demon charging right at you. This one looks stronger.\n\n";
    //Enemy Generation
    lesserDemon = EnemyGenerator("demon", 2);
    //Battle
    if (battle_Sys(aPlayer, lesserDemon))
    {
        //Win
        cout << "You destroy the demon.";

    }
    else
    {
        //Lose
        cout << "You are pelted by fireballs.";
        return;

    }

    //Inventory
    cout << "\nDo you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();

    //Story
    cout << "\n\nYou find the royal guards fleeing from the palace."
         << "\nYou enter through the palace remains and find a greater demon lord standing on top of what was once the throne room."
         << "\nHe lets out a roar and charges at you.";


    //Boss
    Enemy demonLord = EnemyGenerator("boss", 4);
    if (battle_Sys(aPlayer, demonLord))
    {
        //Win
        cout << "\n\nYou eliminate the demon lord's soul from this world.";
        
    }
    else
    {
        //Lose
        cout << "\n\nThe demon lord burns you to a crisp";
        return;

    }

    p = Puzzle(2);

    //Puzzle
    //Puzzle Story
    cout << "\n\nYou spot the demon lord's loot chest, its locked.";

    if(p.solve())
    {
        //Rewards Unique Boss Item
        cout << "The chest magically opens and you find demon enchanted armor.\n";
        aPlayer.store(Armor("Demon Armor", 30, 30, "Demonic"));
    }
    else
    {
        cout << "\n\nThe chest mysteriously disappears.\n";
    }
    

    //Story
    cout << "\n\nYou pick up the broken horn as a trophy and head back to the guild.";
}

//Dungeon 5
void fifthDungeon(Player& aPlayer)
{
    Puzzle p = Puzzle(2);
    string inventoryAnswer;

    //Story
    cout << "\n\nYou and the storywriter meet up at the guildhouse."
         << "\nStorywriter: glad to see that you're safe but I'm going to have to stay here and help with the aftermath."
         << "\nWe still don't know what lies in under the ruins but just don't do anything too crazy."
         << "\nYou gear up and head back towards the ruins in the northwest."
         << "\n\nYou arrive at the entrance to the depths."
         << "\nAs you head further down, the air feels damp and cold."
         << "\nYou eventually find an opening that leads to an ancient dwarven ruin. The markings nearby matches the words written on the note."
         << "\nThe doors open before you even touch them."
         << "\nYou enter inside the empty facility."
         << "\nYou engage into combat with magical animated armor.\n";

    //Enemy Generation
    Enemy dwarf = EnemyGenerator("construct", 1);

    //Battle
    if (battle_Sys(aPlayer, dwarf))
    {
        //won battle
        cout << "\n\nThe suit of armor falls to the ground.";
    }
    else
    {
        //died
        cout << "\n\nYou are slain by the suit of armor.";
        return;
    }


    //Inventory
    cout << "\nDo you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();
    //Puzzle
    //Puzzle Story
    cout << "\n\nYou find a complex dwarven mechanical door.";

    if(p.solve())
    {
        //standard puzzle reward
        cout << "\n\nThe door opens.";
        cout << " Just beyond the door you find some gold.\n";
        aPlayer.gold += 150;
    }
    else
    {
        cout << "\n\nThe door magically seals shut.\n";
    }
    

    cout << "Next you run into a clockwork golem.\n";
    //Enemy Generation
    dwarf = EnemyGenerator("construct", 2);
    //Battle
    if (battle_Sys(aPlayer, dwarf))
    {
        //won battle
        cout << "\n\nThe golem breaks apart.";
    }
    else
    {
        //died
        cout << "\n\nYou're crushed by it's greatsword";
    }

    //Inventory
    cout << "\nDo you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();

    //Story
    cout << "\n\nYou enter the a dark room at the end of the room."
         << "\nYou begin to hear clicks and hissing around you."
         << "\nYou look up to find a pair of blue glowing eyes staring at you."
         << "\nThe lights flicker on and you get a clear sight of the machine."
         << "\nIt has a long body of a serpent and legs of a centepede. It's face resembles that of a crocodile."
         << "\nIt craws around the walls quickly then lunges at you.";

    //Boss
    Enemy dwarfBoss = EnemyGenerator("boss", 5);
    if (battle_Sys(aPlayer, dwarfBoss))
    {
        //won battle
        cout << "\n\nYou break the machine into multiple pieces.";
    }
    else
    {
        //died
        cout << "\n\nIt vaporizes you with magic charged lasers.";
        return;
    }

    //Puzzle
    //Puzzle Story
    cout << "\n\nYou find an odd orb sealed by a mechanical lock.";
    p = Puzzle(2);

    if(p.solve())
    {
        //Rewards Unique Boss Item
        cout << "\n\nYou open the orb. Inside you find powerful mechanical armor.\n";
        aPlayer.store(Armor("Mechanical Armor", 60, 10, "Neutral"));
    }
    else
    {
        cout << "\n\nThe orb flies away.\n";
    }
    

    //Story
    cout << "\n\nYou also find a note near the machine."
         << "It only has numbers on it, perhaps a date?"
         << "You return to Eretedon";
}

//Dungeon 6
void sixthDungeon(Player& aPlayer)
{
    string inventoryAnswer;
    string playerAnswer;
    int finalChoice;

    //Story
    cout << "\n\nAs you head towards the guild hall, a tear in time and space rips the area in half."
         << "\nGylbesdaym, the Eater of All, lets out a massive roar that shatters all the windows nearby and sends trees flying."
         << "\nHe lets out a burst of pure magic that scorches half of the city into dust."
         << "\nIt begins to charge another beam straight at you.";

    //Boss
    Enemy gylbesdaym = EnemyGenerator("boss", 6);
    if (battle_Sys(aPlayer, gylbesdaym))
    {
        //Win
        cout << "\n\nGylbesdaym returns through the tear";
    }
    else
    {
        //Lose
        cout << "\n\nGylbesdaym hits you with it's extinction ray.";
        return;
    }

    //Boss Drop

    //Inventory
    cout << "\nDo you want to check your gear (y/n)?";
    cin >> inventoryAnswer;

    if (inventoryAnswer == "y" || inventoryAnswer == "Y")
        aPlayer.inventory();

    //Story
    cout << "\n\nYou follow Gylbesdaym through the portal to find yourself in a lavish throne room."
         << "\nYou hear a familiar voice across the room."
         << "\nFamiliar voice: You're a failure, and failures deserved to be erased."
         << "\nBefore you even know what happened, Gylbesdaym's guts splatter on the walls and windows around you."
         << "\nIn front of you was your sister."
         << "\nSister?: Its suprising that you made it this far, I expected you to have been killed along with the rest of the village 2 years ago."
         << "\nYou: Who are you?"
         << "\nSister?: Me? Oh you must mean this human shell that I took a few years ago."
         << "\nThe demon sheds it's human form to present a grotesque crimson winged demon."
         << "\n???: My name is Xanoroth, the Embodiment of Dispair."
         << "\nXanoroth: It seems that my pet has failed, I guess I'll have to destroy your plane of existence myself."
         << "\nYou: ";

    cin >> playerAnswer;

    cout << "\n\nXanoroth: Oh, I see that you aim to stop me. Your grave shall be where you stand."
         << "\nHe unsheathes his blade which ignites the throne room ablaze just from sheer power."
         << "\nXanoroth: Let us end this.";

    //Final Boss
    Enemy demonSister = EnemyGenerator("boss", 7);
    if (battle_Sys(aPlayer, demonSister))
    {
        //Win
        cout << "\n\nYou destroy his sword and destroy his soul.";
    }
    {
        //Lose
        cout << "\n\nYou're sliced in half and your soul is destroyed.";
        return;
    }

    //Story
    cout << "\n\nXanoroth: No, it can't be. I'm invincible."
         << "\nYou: ";

    cin >> playerAnswer;

    cout << "\n\nXanoroth: I will come for your soul, you'll never escape."
         << "\nWhat will you do?"
         << "\n1. Mercy"
         << "\n2. Execute\n";

    cin >> finalChoice;

    switch (finalChoice)
    {
        case 1:
        {
            cout << "\n\nYou walk away and out of the tear."
                 << "\nIn the distance, you hear..."
                 << "\nXanoroth: You fool!, You will regret sparing me."
                 << "\n\nIt is said that Eretedon was wiped from the face of the planet a mere 3 months later."
                 << "\nThe hero, "
                 << aPlayer.name
                 << ", was said to have been almost completely forgotten from history itself."
                 << "\nThe end.";
            
            return;
        }

        case 2:
        {
            cout << "\n\nYou remove the demon's head and take it with you as proof."
                 << "\nWith Xanoroth gone, the tear collapses on itself as you leave.\n"
                 << aPlayer.name
                 << " was known as the hero who saved the world after leaving the tear with head in hand."
                 << "\nNo one knows where the hero has gone since then, but rumors have it that they wander the land, hunting the other 5 great beasts of the world."
                 << "\nThe end.";

            return;
        }
    }
}

