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
class Item {

    public:
        
        Item(string, string);
        void display();

        string name;
        string type;
        
};

Item::Item (string _name, string _type){

    name = _name;
    type = _type;
    
}

void Item::display(){

    cout << "Item Sheet:\n" << endl;
    cout << "\tName: " << name << endl;
    cout << "\tType: " << type << endl;

}

#endif  // __ITEM_H_INCLUDED__