/* 
*   item.h
*   The header file containing the item class, inherited by weapons, armor, and other items.
*   Brandon Dunbar
*   dunbar.b965960@stu.sanjac.edu       brandon.dunbar97@gmail.com
*/

//=================================
// Include Guard
#ifndef __ITEM_H_INCLUDED__   // if item.h hasn't been included yet...
#define __ITEM_H_INCLUDED__   //   #define this so the compiler knows it has been included

//=================================
// Included Dependencies
#include <vector>
#include <string>

//=================================
class Item {

    public:
        
        Item(std::string, std::string);

        std::string name;
        std::string type;
        
};

Item::Item (std::string _name, std::string _type){

    name = _name;
    type = _type;
    
}

#endif  // __ITEM_H_INCLUDED__