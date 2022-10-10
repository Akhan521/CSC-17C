/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: October 6, 2022, 11:00 AM
 * Purpose: Intro to sets.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <set>       //Sets.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:

//Execution Begins Here:
int main(int argc, char** argv) {
    //Defining a set of chars.
    set<char> a;
    //Inserting characters.
    a.insert('G');
    a.insert('F');
    a.insert('G');
    //Displaying set values.
    for(auto& str: a)
    {
      std::cout << str << ' ';
    }
    cout << '\n';
    
    //Exit the Program - Cleanup.
    return 0;
}