/*dice object
sebastian roe
roe.s996299@stu.sanjac.edu*/

#ifndef DICE_H_INCLUDED
#define DICE_H_INCLUDED
#include <iostream>
#include <random>
#include <ctime>

class Dice
{
public:
    Dice(int sides = 20);
    
    int roll();
private:
    std::mt19937 mt;
    std::uniform_int_distribution<int> dist;
};

Dice::Dice(int sides):
    dist(1,sides),
    mt(time(NULL))
{}

int Dice::roll()
{
    return dist(mt);
}



#endif // DICE_H_INCLUDED
