/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: October 5, 2022, 9:45 PM
 * Purpose: Implementing the SimpleVector class
 *             using our linked list class.
 */

//System Libraries.

//User Libraries.
#include "SimpleVector.h"

//Global/Universal Constants -- No Global Variables.
//Science, Math, Conversions, Higher Dimensioned constants only.

//Function Prototypes.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Setting the random number seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //Creating and filling our first SimpleVector.
    cout<<"Implementing the SimpleVector class using a linked list."<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"Creating our first vector:"<<endl;
    int size=10;
    SimpleVector<int> vect(size);
    //Printing it.
    vect.print();
    
    //Inserting 2 nodes at the front.
    cout<<"Inserting 2 nodes at the front."<<endl;
    vect.push_front(rand()%90+10);
    vect.push_front(rand()%90+10);
    //Printing it.
    vect.print();
    
    //Inserting 2 nodes at the back.
    cout<<"Inserting 2 nodes at the back."<<endl;
    vect.push_back(rand()%90+10);
    vect.push_back(rand()%90+10);
    //Printing it.
    vect.print();
    
    //Demonstrating the copy constructor.
    cout<<"Demonstrating the copy constructor."<<endl;
    SimpleVector<int> copy(vect);
    cout<<"Copy of our 1st vector:"<<endl;
    copy.print();
    
    //Popping 2 nodes from the front.
    cout<<"Popping 2 nodes from the front."<<endl;
    vect.pop_front();
    vect.pop_front();
    //Printing it.
    vect.print();
    
    //Popping 2 nodes from the back.
    cout<<"Popping 2 nodes from the back."<<endl;
    vect.pop_back();
    vect.pop_back();
    //Printing it.
    vect.print();
    
    //Exit stage right.
    return 0;
}