/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: October 10, 2022, 1:40 PM
 * Purpose: Prioritized Doubly Linked List.
 * 
 * We'll search through our linked list for values. If these values are found,
 * we'll bring the links with those values to the front. If these values are
 * not found, the order of the list remains the same. Elements that are found
 * are given higher priority, so these will be at the front of our list.
 */

//System Libraries.

//User Libraries.
#include "LinkedList.h"

//Global/Universal Constants -- No Global Variables.
//Science, Math, Conversions, Higher Dimensioned constants only.

//Function Prototypes.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Setting the random number seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //Creating and filling our list w/ random 2 digit numbers.
    LinkedList<int> list(100);
    
    //Printing the list.
    list.prntLst();
    
    //Searching for 20 random 2 digit numbers.
    //Values that are found are placed at the front.
    for(int i=1;i<=20;i++){
        list.find(rand()%90+10);
    }
    
    //Printing the list.
    list.prntLst();
    
    //Exit stage right.
    return 0;
}