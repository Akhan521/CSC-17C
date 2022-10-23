/* 
 * File:    main.cpp
 * Author:  Dr. Mark E. Lehr
 * Purpose: Simple vector program used to derive the Big O()
 *          for the linked list push function in problem 3.
 */

//System Libraries:
#include <iostream>
using namespace std;

//User Libraries:
#include "Object.h"       //2D Matrix Objects.
#include "SimpleVector.h" //Simple Vector (Implemented w/ a Linked List.)

//Global Constants.

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //Test objects.
    Object a(3),b(4);
    
    //Output the objects.
    cout<<"Object to be placed at the front = ";
    cout<<a;
    cout<<"Object to placed at the end = ";
    cout<<b;

    //Create a Simple Vector using a Linked List.
    SimpleVector<Object> svp(a);
    
    //Fill the Simple Vector with 10 randomly-sized 2D Matrix Objects.
    for(int i=0;i<10;i++){
        int rSize=rand()%10;
        Object c(rSize);
        svp.push(c);
    }
    
    //Place object b at the end of our simple vector.
    svp.push(b);
    cout<<"Simple Vector size  = "<<svp.size()<<endl;
    cout<<"Front Object =  "<<svp[0];
    cout<<"End Object   =  "<<svp[svp.size()-1];
    
    //Exit.
    return 0;
}