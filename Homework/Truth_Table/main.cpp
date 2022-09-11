/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: 8-30-2022
 * Purpose: Truth Table
 */

//System Libraries Here.
#include <iostream>
using namespace std;

//User Libraries Here.

//Global Constants Only, No Global Variables.
//Like PI, e, Gravity, or conversions.

//Function Prototypes Here.

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all variables here.
    bool x,y;
    //Display the heading.
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y "
        <<"!(X&&Y) !X||!Y  !(X||Y) !X&&!Y"<<endl;
    //Start our table outputs.
    while(cin>>x>>y){
        //Output our values given our inputs.
        cout<<(x?'T':'F')<<" "
            <<(y?'T':'F')<<"  "
            <<(!x?'T':'F')<<"  "
            <<(!y?'T':'F')<<"   "
            <<(x&&y?'T':'F')<<"    "
            <<(x||y?'T':'F')<<"   "
            <<(x^y?'T':'F')<<"    "
            <<((x^y)^x?'T':'F')<<"     "
            <<((x^y)^y?'T':'F')<<"       "
            <<(!(x&&y)?'T':'F')<<"      "
            <<(!x||!y?'T':'F')<<"        "
            <<(!(x||y)?'T':'F')<<"      "
            <<(!x&&!y?'T':'F')
            <<endl;
    }
    //Outputting a newline.
    cout<<endl;
    //Exit stage right.
    return 0;
}