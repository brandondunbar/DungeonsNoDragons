#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

#include "armor.h"
#include "weapon.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "buff.h"
#include "dice.h"
#include "item.h"
#include "spell.h"
#include "utility.h"
#include "combat.h"

int main()
{
    //Test player
    Player player_character = Player("Bill", "Warrior", "Human", 5);
    player_character.health = 100;
    player_character.mana = 100;
    player_character.intelligence = 10;
    player_character.wisdom = 10;

    player_character.learnSpell(Spells["Fireball"]);

    //Enemy generation
    Enemy phantom = Enemy("Phantom", "Assassin", "Ghost", 7);
    phantom.health = 100;

    battle_Sys(player_character, phantom);
}
