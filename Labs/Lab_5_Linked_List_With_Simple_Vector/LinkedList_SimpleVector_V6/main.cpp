/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: October 5, 2022, 9:05 PM
 * Purpose: Templating our linked list.
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
    //srand(static_cast<unsigned int>(time(0)));
    
    //Creating and filling our list.
    LinkedList<int> list(5);
    
    //Printing the list.
    list.prntLst();
    
    //Inserting 2 new links at the front.
    cout<<"Pushing 2 links to the front."<<endl;
    list.push_front(list.create(6));
    list.push_front(list.create(7));
    //Printing our modified list.
    list.prntLst();
    
    //Inserting 2 new links at the back.
    cout<<"Pushing 2 links to the back."<<endl;
    list.push_back(list.create(8));
    list.push_back(list.create(9));
    //Printing our modified list.
    list.prntLst();
    
    //Popping 2 elements from the front.
    cout<<"Popping 2 links from the front."<<endl;
    int popped1=list.pop_front();
    int popped2=list.pop_front();
    if(popped1!=-1)
        cout<<"The 1st popped element is: "<<popped1<<endl;
    if(popped2!=-1)
        cout<<"The 2nd popped element is: "<<popped2<<endl;
    //Printing our modified list.
    list.prntLst();
    
    //Popping 2 elements from the back.
    cout<<"Popping 2 links from the back."<<endl;
    int popped3=list.pop_back();
    int popped4=list.pop_back();
    if(popped3!=-1)
        cout<<"The 1st popped element is: "<<popped3<<endl;
    if(popped4!=-1)
        cout<<"The 2nd popped element is: "<<popped4<<endl;
    //Printing our modified list.
    list.prntLst();
    
    //Exit stage right.
    return 0;
}