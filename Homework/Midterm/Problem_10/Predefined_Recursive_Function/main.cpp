/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: October 17, 2022, 7:05 PM
 * Purpose: Problem 10 - Predefined Recursion.
 * 
 *  Let g(2x) = (2 * g(x)) / (1 + g^2(x)).
 *  Base conditions: 
 *  |x| < tolerance, tolerance < 10^-6, g(x) = x - x^3/6.
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
float recFunc(float); //Our predefined recursive function.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    
    //Declare Variables.
    cout<<"This program demonstrates a predefined recursive function:\n"<<endl;
    cout<<"Recursive definition: g(2x) = (2 * g(x)) / (1 + g^2(x)).\n"<<endl;
    cout<<"Base conditions: |x| < tolerance, tolerance < 10^-6, g(x) = x - x^3/6.\n";
    cout<<"Interval: [-1,1] & Delta x = 0.1.\n"<<endl;
    
    //Initialize Variables.
    
    //Map Inputs to Outputs -> Process.
    
    //Display Inputs/Outputs.
    for(float x=-1.0f;x<1.1f;x+=0.1f){
        cout<<fixed;
        //Outputting our results.
        cout<<"g("<<setprecision(1)<<x<<") = "
                  <<setprecision(4)<<recFunc(x)<<endl;
    }
    
    //Exit the Program - Cleanup.
    return 0;
}

//Our predefined recursive function:
float recFunc(float x){
    //Base conditions:
    float tol=1e-6; //Our tolerance.
    //If |x| < tolerance...
    if(abs(x)<tol)
        //We return x - x^3/6.
        return x-pow(x,3)/6.0f; 
    //Recursion: g(2x) = (2 * g(x)) / (1 + g^2(x)).
    float gx=recFunc(x/2.0f); //Storing g(x).
    //Returning g(2x) = (2 * g(x)) / (1 + g^2(x)).
    return (2*gx)/(1+gx*gx);
}