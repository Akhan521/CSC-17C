/* 
 * File:     main.cpp
 * Author:   Dr. Mark E. Lehr
 * Purpose:  Simple vector program used to derive the Big O()
 *           of the inefficient push function for problem 3.
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
    cout<<"Simple Vector Object Initialization: "<<svp[svp.size()-1];
    
    //Push an Object and print out the last object.
    svp.push(b);
    cout<<"Simple Vector pushing the next object: "<<svp[svp.size()-1];
    
    //Fill the simple vector with 100 randomly-sized 2D Matrix Objects.
    for(int i=0;i<100;i++){
        int rSize=rand()%10;
        Object c(rSize);
        svp.push(c);
    }
    
    //Outputting the last one.
    cout<<"Size of the Simple Vector = "<<svp.size()<<endl;
    cout<<"The last object in the vector is: "<<endl;
    cout<<svp[svp.size()-1];
    
    //Create another simple vector using the copy constructor.
    SimpleVector<Object> csvp(svp);
    cout<<"Size of the Copied Simple Vector = "<<csvp.size()<<endl;
    cout<<"The last object in the vector is: "<<endl;
    cout<<csvp[csvp.size()-1];
    
    //Utilize a simple Simple Vector.
    int size=15;
    SimpleVector<Object> svi(size);
    cout<<"Size of this vector = "<<svi.size()<<endl;
    cout<<"Last 2 Objects of the Simple Vector: "<<endl;
    cout<<svi[svi.size()-2]
        <<svi[svi.size()-1];
    
    //Exit.
    return 0;
}