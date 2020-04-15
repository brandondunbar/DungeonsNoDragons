/*
*   buff.h
*   Holds the buff class, which modifies character classes temporary stats
*   Brandon Dunbar
*   dunbar.b965960@stu.sanjac.edu       brandon.dunbar97@gmail.com
*/

//=================================
// Include Guard
#ifndef __BUFF_H_INCLUDED__   // if buff.h hasn't been included yet...
#define __BUFF_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <iostream>
using namespace std;

//=================================
class Buff {

    public:
        
        Buff(string name, string target_stat, int mod, int round_timer);

        string name, target_stat;
        int mod, round_timer;
        bool activated = false;
        

};

Buff::Buff (string _name, string _target_stat, int _mod, int _round_timer) : 
name(_name), target_stat(_target_stat), mod(_mod), round_timer(_round_timer) {

}

#endif // __BUFF_H_INCLUDED__