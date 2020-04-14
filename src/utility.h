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

string vector_to_string(vector<string> &vect){

    string vector_string;

    if (!vect.empty()){

        for (int i = 0; i < vect.size(); i++){

            vector_string += vect[i];

            if (i < (vect.size() - 1)){
                vector_string += ", ";
            }
        }
    } else {
        vector_string = ".";
    }

    return vector_string;

}

#endif // __UTILITY_H_INCLUDED__