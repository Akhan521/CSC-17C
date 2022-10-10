/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: October 9, 2022, 6:10 PM
 * Purpose: Doubly Linked List.
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
    
    //Our list size:
    int n=10;
    
    //Creating and filling our list.
    LinkedList list(n);
    
    //Printing the list.
    list.prntLst();
    
    //Printing in reverse.
    list.prntRev();
    
    //Inserting 5 elements in sorted order.
    for(int i=1;i<=n/2;i++){
        //A random 2 digit number.
        list.push(rand()%90+10);
    }
    
    //Printing the list.
    list.prntLst();
    
    //Printing in reverse.
    list.prntRev();
    
    //Exit stage right.
    return 0;
}