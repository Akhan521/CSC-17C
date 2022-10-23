/* 
 * File:     main.cpp
 * Author:   Dr. Mark E. Lehr
 * Purpose:  Simple vector program used to derive the Big O()
 *           of the efficient push function for problem 3.
 *           Note:  This simple vector only works with objects.
 */

//System Libraries:
#include <iostream>
using namespace std;

//User Libraries:
#include "Object.h"       //2D Matrix Objects.
#include "SimpleVector.h" //Simple Vector class.

//Global Constants.

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //Test objects.
    Object a(3),b(4);
    cout<<"One of the Objects: "<<a;
    
    //Test an object by populating the simple vector with it.
    SimpleVector<Object> svp(a);
    cout<<"Simple Vector Size = "<<svp.mxSize()
        <<svp[svp.size()-1];
    
    //Push an object and print out the last object.
    svp.push(b);
    cout<<"Simple Vector Size (After Pushing) = "<<svp.mxSize()
        <<svp[svp.size()-1];
    
    //Fill the simple vector with 100 randomly-sized 2D Matrix Objects.
    for(int i=0;i<100;i++){
        int rSize=rand()%10;
        Object c(rSize);
        svp.push(c);
    }
    
    //Printing the sizes and the last object.
    cout<<"Max Size and Size of the Simple Vector = "
        <<svp.mxSize()<<" "<<svp.size()<<endl;
    cout<<"The last object in the vector is: "<<endl;
    cout<<svp[svp.size()-1];
    
    //Create another simple vector using our copy constructor.
    SimpleVector<Object> csvp(svp);
    cout<<"Max Size and Size of the Copied Simple Vector = "
        <<csvp.mxSize()<<" "<<csvp.size()<<endl;
    cout<<"The last object in the vector is: "<<endl;
    cout<<csvp[csvp.size()-1];
 
    //Utilize a simple Simple Vector.
    int size=50;
    SimpleVector<Object> svi(size);
    cout<<"Last 2 values of the Simple Vector:"<<endl;
    cout<<"The Max Size and Size = "
        <<svi.mxSize()<<" "<<svi.size()<<endl
        <<svi[svi.size()-2]<<svi[svi.size()-1];
    
    //Exit.
    return 0;
}