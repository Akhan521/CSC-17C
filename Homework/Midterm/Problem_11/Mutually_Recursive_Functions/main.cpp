/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: October 17, 2022, 10:20 PM
 * Purpose: Problem 11 - Mutually recursive functions.
 * 
 * Recursive definitions:
 *  Let C(2x) = 1/2 * C(x) * S(x).
 *  Let S(2x) = (C^2(x) * S^2(x)) / (C^2(x) - S^2(x)).
 *  Interval: |x| <= atan(1) AND Delta x = 0.1.
 *  
 * Base conditions: 
 *  |x| < tolerance AND tolerance < 10^-6.
 *  C(x) = 1/x + x/6 AND S(x) = 1 + x^2/2.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <cmath>     //Math Library.
#include <iomanip>   //Formatting.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
float recFunc1(float); //Our first recursive function.
float recFunc2(float); //Our second recursive function.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    
    //Declare Variables.
    cout<<"This program demonstrates mutually recursive functions.\n";
    cout<<"We've defined 2 functions: C(x) and S(x). Both of these\n";
    cout<<"functions are defined recursively and called within each other.\n";
    cout<<"\nLet C(2x) = 1/2 * C(x) * S(x).\n";
    cout<<"Let S(2x) = (C^2(x) * S^2(x)) / (C^2(x) - S^2(x)).\n";
    cout<<"Interval: |x| <= atan(1) AND Delta x = 0.1.\n";
    cout<<endl;
    
    //Initialize Variables.
    
    //Map Inputs to Outputs -> Process.
    
    //Display Inputs/Outputs.
    for(float x=-atan(1);x<atan(1)+0.1f;x+=0.1f){
        cout<<fixed;
        cout<<"C("<<setprecision(2)<<x<<") = "
                  <<setprecision(4)<<recFunc1(x)<<"\t";
        cout<<"S("<<setprecision(2)<<x<<") = "
                  <<setprecision(4)<<recFunc2(x)<<endl;
    }
    //Exit the Program - Cleanup.
    return 0;
}

//C(x):
float recFunc1(float x){
    //Base condition:
    float tol=1e-6; //Our tolerance.
    //If |x| < tolerance...
    if(abs(x)<tol)
        //We return 1/x + x/6.
        return 1.0f/x+x/6.0f;
    //Recursion: C(2x) = 1/2 * C(x) * S(x).
    return 1.0f/2*recFunc1(x/2)*recFunc2(x/2);
}

//S(x):
float recFunc2(float x){
    //Base condition:
    float tol=1e-6; //Our tolerance.
    //If |x| < tolerance...
    if(abs(x)<tol)
        //We return 1 + x^2/2.
        return 1+pow(x,2)/2.0f;
    //Recursion: S(2x) = (C^2(x) * S^2(x)) / (C^2(x) - S^2(x)).
    float cx=recFunc1(x/2); //Storing C(x).
    float sx=recFunc2(x/2); //Storing S(x).
    //Returning (C^2(x) * S^2(x)) / (C^2(x) - S^2(x)).
    return ((cx*cx)*(sx*sx))/((cx*cx)-(sx*sx));
}