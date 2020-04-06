/*
*   utility.h
*   Holds various methods created for convenience
*   Brandon Dunbar
*   dunbar.b965960@stu.sanjac.edu       brandon.dunbar97@gmail.com
*/

//=================================
// Include Guard
#ifndef __UTILITY_H_INCLUDED__   // if utility.h hasn't been included yet...
#define __UTILITY_H_INCLUDED__   //   #define this so the compiler knows it has been included

//=================================
bool vector_contains_value(vector<string> &vect, string value){

    for (int i = 0; i < vect.size(); i++){
        if (vect[i] == value){
            return true;
        }
    }

    return false;

}


#endif // __UTILITY_H_INCLUDED__