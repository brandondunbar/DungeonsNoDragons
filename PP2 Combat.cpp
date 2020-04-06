#include <iostream>
#include <string>
#include "armor.h"
#include "character.h"
#include "enemy.h"
#include "item.h"
#include "player.h"
#include "spell.h"
#include "utility.h"
#include "weapon.h"

using namespace std;

//For actions
bool attack = false;
bool magic = false;
bool item = false;
bool defend = false;
bool intimidate = false;

//To make sure people can't do intimidate multiple times
int intimidateCount = 0;

//For spells
bool fireBallConfirm = false;
bool thunderBoltConfirm = false;
bool iceSpikeConfirm = false;

//Spell Damage Stats
int fireBallDamage = 20;
int thunderBoltDamage = 15;
int iceSpikeDamage = 10;

//Status Effects
void fireBallDOT();
//FireBall timer
int fireBallBurnTime = 0;
void thunderBoltFlash();
//ThunderBolt Timer
int thunderBoltFlashTime = 0;
void iceSpikeArmorBreak();
//Ice spike timer
int iceSpikeArmorBreakTime = 0;

//Spell Mana Cost
int fireBallCost = 10;
int thunderBoltCost = 10;
int iceSpikeCost = 10;

//For items
int healthPotionHeal = 25;
int bombDamage = 50;

//Items held
int healthPotionHeld = 3;
int bombHeld = 3;

//For items
bool healthPotion = false;
bool bomb = false;

//Test Stats for player
int playerHealth = 100;
int playerDamage = 45;
int playerDamageBase = 30;
int playerArmor = 20;
int playerArmorBase = 20;
int playerWisdom = 20;
int playerIntimidation = 20;
int playerMana = 100 + playerWisdom;
int playerDamageDealt;

//Test Stats for enemy
int enemyHealth = 100;
int enemyDamage = 40;
int enemyArmor = 20;
int enemyArmorBase = 20;
int enemyLevel = 10;
int enemyDamageDealt;

//Combat sys
void battleSys();
void spellCastSys();
void gameContSys();
void itemUseSys();
void gameOverSys();
void enemyTurnSys();
void enemyDeath();

int main()
{
    battleSys();

    //Player Death
    if (playerHealth <= 0)
    {
        gameOverSys();
    }

    //Test to make sure the enemy death works
    cout << "\n\nGame finished!";
    gameContSys();
}

//Makes sure the text doesn't go too fast
void gameContSys()
{
    string playerConfirm;

    cout << "\nType N to continue\n";
    cin >> playerConfirm;

    if (playerConfirm == "N" or "n")
    {
        return;
    }
}

//Main battle system
void battleSys()
{
    int battleChoice;

    while (enemyHealth > 0 and playerHealth > 0)
    {
        cout << "\nCurrent stats:\n"
             << "Health: "
             << playerHealth
             << "\nMana: "
             << playerMana;

        cout << "\n\nWhat will you do?.\n"
             << "1. Attack\n"
             << "2. Magic\n"
             << "3. Defend\n"
             << "4. Item\n"
             << "5. Intimidate\n";

        cin >> battleChoice;

        switch (battleChoice)
        {
            //Attack
            case 1:
                cout << "\nYou swing at the enemy dealing ";

                playerDamageDealt = playerDamage - enemyArmor;

                if (playerDamageDealt < 0)
                {
                    playerDamageDealt = 0;
                }

                cout << playerDamageDealt
                     << " damage!";

                attack = true;
                magic = false;
                defend = false;
                item = false;
                intimidate = false;
                gameContSys();
                break;
            //Magic
            case 2:
                if (playerMana <= 0 )
                {
                    cout << "\nYou're out of mana!";
                    gameContSys();
                    attack = false;
                    magic = false;
                    item = false;
                    intimidate = false;

                    //Failing to do an action will automatically result in defending
                    defend = true;
                    break;
                }
                if (playerMana > 0)
                {
                    attack = false;
                    magic = true;
                    defend = false;
                    item = false;
                    intimidate = false;
                    spellCastSys();
                    break;
                }
            //Defending
            case 3:
                cout << "\nYou brace for the attack!\n"
                     << "Your defense increased to "
                     << playerArmor + float(playerArmor/2)
                     << "!";

                gameContSys();
                attack = false;
                magic = false;
                defend = true;
                item = false;
                intimidate = false;
                break;

            //Items
            case 4:
                cout << "\nYou reach into your pouch!\n";
                itemUseSys();
                attack = false;
                magic = false;
                defend = false;
                item = true;
                intimidate = false;
                break;

            //Intimidate
            case 5:
                cout << "\nYou attempt to intimidate the enemy!\n"
                     << "Current intimidation Level: "
                     << playerIntimidation;
                gameContSys();
                if (playerIntimidation <= enemyLevel or intimidateCount > 0)
                {
                    cout << "\n\nYou failed to intimidate the enemy!";
                    gameContSys();
                    attack = false;
                    magic = false;
                    defend = true;
                    item = false;
                    intimidate = false;
                    break;
                }
                if (playerIntimidation > enemyLevel and intimidateCount == 0)
                {
                    cout << "\n\nYou instill fear into the enemy!\n"
                         << "You lower the enemy's damage and armor by "
                         << enemyLevel + float(playerIntimidation/2);
                    gameContSys();
                    intimidateCount = intimidateCount + 1;
                    attack = false;
                    magic = false;
                    defend = false;
                    item = false;
                    intimidate = true;
                }
        }


        //Attack
        if (attack == true)
        {
            //Thunder Bolt Flash Buff
            if (thunderBoltFlashTime > 0)
            {
                playerDamageDealt = playerDamage + (thunderBoltDamage + float(playerWisdom/2));
            }

            if (thunderBoltFlashTime == 0)
            {
                playerDamageDealt = playerDamageBase;
            }

            //Ice Spike Armor Break
            if (iceSpikeArmorBreakTime > 0)
            {
                enemyArmor = 0;
                iceSpikeArmorBreak();
            }

            if (iceSpikeArmorBreakTime == 0)
            {
                enemyArmor = enemyArmorBase;
            }

            enemyHealth = enemyHealth - (playerDamageDealt - enemyArmor);
        }

        //Magic
        if (magic == true)
        {
            //FireBall
            if (fireBallConfirm == true)
            {
                enemyHealth = enemyHealth - fireBallDamage;
                fireBallBurnTime = 5;
            }

            //ThunderBolt
            if (thunderBoltConfirm == true)
            {
                enemyHealth = enemyHealth - thunderBoltDamage;
                thunderBoltFlashTime = 3;
            }

            //Ice Spike
            if (iceSpikeConfirm == true)
            {
                enemyHealth = enemyHealth - iceSpikeDamage;
                iceSpikeArmorBreakTime = 3;
            }
        }

        //Items
        if (item == true)
        {
            //Health Potion usage
            if (healthPotion == true)
            {
                playerHealth = playerHealth + healthPotionHeal;

                //Makes sure the player doesn't go over 100 HP
                if (playerHealth > 100)
                {
                    playerHealth = 100;
                }
            }

            //Bomb usage
            if (bomb == true)
            {
                enemyHealth = enemyHealth - bombDamage;
            }
        }

        //Defending
        if (defend == true)
        {

            playerArmor = playerArmor + float(playerArmor/2);
        }

        if (defend == false)
        {
            playerArmor = playerArmorBase;
        }

        //Intimidation
        if (intimidate == true)
        {
            enemyArmor = enemyArmor - (enemyLevel + float(playerIntimidation/2));
            //Makes sure that enemy's armor doesn't go negative
            if (enemyArmor < 0)
            {
                enemyArmor = 0;
            }
            enemyDamage = enemyDamage - (enemyLevel + float(playerIntimidation/2));
            //Makes sure the enemy doesn't do no damage
            if (enemyDamage < 5)
            {
                enemyDamage = 5;
            }
        }

        //FireBall DOT
        fireBallDOT();

        //Enemy Death
        if (enemyHealth <= 0)
        {
            enemyDeath();
            return;
        }

        //Enemy's turn
        enemyTurnSys();

    }


}

//Magic system
void spellCastSys()
{
    int spellChoice;

    cout << "\nWhat spell will you use?\n"
         << "1. FireBall\n"
         << "2. ThunderBolt\n"
         << "3. Ice Spike\n";

    cin >> spellChoice;

    switch (spellChoice)
    {
        //Fire Ball
        case 1:
            cout << "\nYou cast a FireBall spell, dealing "
                 << fireBallDamage + float(playerWisdom/2)
                 << " damage!\n";
            enemyHealth = enemyHealth - (fireBallDamage + float(playerWisdom/2));
            playerMana = (playerMana - fireBallCost);
            fireBallConfirm = true;
            thunderBoltConfirm = false;
            iceSpikeConfirm = false;
            gameContSys();
            break;
        //Thunder Bolt
        case 2:
            cout << "\nYou cast a ThunderBolt spell, dealing "
                 << thunderBoltDamage + float(playerWisdom/2)
                 << " damage!\n";
            enemyHealth = enemyHealth - (thunderBoltDamage + float(playerWisdom/2));
            playerMana = (playerMana - thunderBoltCost);
            fireBallConfirm = false;
            thunderBoltConfirm = true;
            iceSpikeConfirm = false;
            gameContSys();
            break;
        //Ice Spike
        case 3:
            cout << "\nYou cast a Ice Spike spell, dealing "
                 << iceSpikeDamage + float(playerWisdom/2)
                 << " damage!\n";
            enemyHealth = enemyHealth - (iceSpikeDamage + float(playerWisdom/2));
            playerMana = (playerMana - iceSpikeCost);
            fireBallConfirm = false;
            thunderBoltConfirm = false;
            iceSpikeConfirm = true;
            gameContSys();
            break;
    }
}

//Item use system
void itemUseSys()
{
    int itemChoice;

    cout << "\nHealth Potions Held: "
         << healthPotionHeld
         << "\nBombs Held: "
         << bombHeld
         << "\nWhat item will you use?\n"
         << "1. Health potion\n"
         << "2. Bomb\n";

    cin >> itemChoice;

    switch (itemChoice)
    {
        case 1:
            //If the player is at full health
            if (100 <= playerHealth)
            {
                cout << "\nYou're already at full health!";
                gameContSys();
                item = false;
                defend = true;
                break;
            }
            if (healthPotionHeld == 0)
            {
                cout << "\nYou have no more Health Potions!";
                gameContSys();
                item = false;
                defend = true;
                break;
            }
            if (healthPotionHeld > 0 and playerHealth < 100)
            {
                cout << "\nYou drink a Health Potion!\n"
                     << "You heal "
                     << healthPotionHeal
                     << " HP!";
                gameContSys();
                healthPotionHeld = healthPotionHeld - 1;
                healthPotion = true;
                bomb = false;
                break;
            }
        case 2:
            if (bombHeld == 0)
            {
                cout << "\nYou have no more Bombs!";
                gameContSys();
                item = false;
                defend = true;
                break;
            }
            if (bombHeld > 0)
            {
                cout << "\nYou toss a Bomb!\n"
                     << "You deal "
                     << bombDamage
                     << " damage!";
                gameContSys();
                bombHeld = bombHeld - 1;
                healthPotion = false;
                bomb = true;
            }
    }
}

//Fire DOT
void fireBallDOT()
{
    if (fireBallBurnTime > 0)
    {
        cout << "\n\nThe enemy takes burn damage!\n"
             << "They take "
             << fireBallDamage + float(playerWisdom/2)
             << " burn damage!";

        gameContSys();

        enemyHealth = enemyHealth - (fireBallDamage + float(playerWisdom/2));
        fireBallBurnTime = fireBallBurnTime - 1;
    }
}

//Thunder Bolt Status effect
void thunderBoltFlash()
{
    cout << "\n\nThe lightning is channeled into your blade!\n"
         << "Your damage is increased by "
         << thunderBoltDamage + float(playerWisdom/2)
         << "!";

    gameContSys();

    thunderBoltFlashTime = thunderBoltFlashTime - 1;
}

//Ice Spike Status effect
void iceSpikeArmorBreak()
{
    cout << "\n\nThe sheer cold has rendered the enemy armor rubbish!\n"
         << "Your physical attacks will ignore armor for 4 turns!";

    gameContSys();

    iceSpikeArmorBreakTime = iceSpikeArmorBreakTime - 1;
}

void gameOverSys()
{
    cout << "\n\nYou fall over, succumbing to your wounds.\n"
         << "Game Over!";

    gameContSys();
}

void enemyTurnSys()
{
    //Enemy response

    //Shows enemy's health
    cout << "\n\nEnemy's current HP: "
         << enemyHealth;

    if (enemyHealth > float(enemyHealth/2))
    {
        cout << "\n\nThe enemy strikes at you!\n"
             << "They deal ";

        enemyDamageDealt = enemyDamage - playerArmor;

        if (enemyDamageDealt < 0)
        {
            enemyDamageDealt = 0;
        }

        cout << enemyDamageDealt
             << " damage!";

        playerHealth = playerHealth - enemyDamageDealt;

        gameContSys();

    }

    if (enemyHealth <= float(enemyHealth/2))
    {
        cout << "\n\nDesperate, the enemy charges at you in a blind rage!\n"
             << "They deal ";

        enemyDamageDealt = (enemyDamage + float(enemyDamage/2)) - playerArmor;

        if (enemyDamageDealt < 0)
        {
            enemyDamageDealt = 0;
        }

        cout << enemyDamageDealt
             << " damage!";

        playerHealth = playerHealth - enemyDamageDealt;

        gameContSys();
    }
}

void enemyDeath()
{
    cout << "\n\nYour enemy dies before you!\n"
         << "You won!";
}

