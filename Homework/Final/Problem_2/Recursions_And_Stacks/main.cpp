/* 
 * File:    main.cpp
 * Author:  Dr. Mark E. Lehr.
 * Purpose: Problem 2 - Hyperbolic functions + Stacks.
 *          This is the program that was provided to us
 *          for problem 2 of our 17C final.
 */

//System libraries.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>
using namespace std;

//Function prototypes.
float h(float); //Hyperbolic sine.
float g(float); //Hyperbolic cosine.

//Our stacks that will be used to keep count of function calls.
//We will look at the sizes to determine how many times each is called.
stack<float> sinhStk; //To keep count of how many times hyp. sine is called.
stack<float> coshStk; //To keep count of how many times hyp. cosine is called.

int main(int argc, char** argv) {
    //Testing out our recursive trig. functions over [-1,1] w/ Delta X = 0.1.
    for(float angRad=-1;angRad<1.1;angRad+=0.1f){
        //Comparing our hyperbolic sine w/ the original.
        cout<<"Angle = "<<setprecision(1)<<angRad<<" sinh = "<<sinh(angRad)<<
              " Our sinh = "<<h(angRad)<<endl;
        //Comparing our hyperbolic cosine w/ the original.
        cout<<"Angle = "<<setprecision(1)<<angRad<<" cosh = "<<cosh(angRad)<<
              " Our cosh = "<<g(angRad)<<endl;
        //Outputting how many times each hyp. function was called.
        cout<<"\nOur sinh was called "<<sinhStk.size()<<" times.";
        cout<<"\nOur cosh was called "<<coshStk.size()<<" times.\n";
        cout<<endl;
        //Clearing our stacks to prepare for the next iteration.
        while(!sinhStk.empty()) sinhStk.pop();
        while(!coshStk.empty()) coshStk.pop();
    }
    //Exit stage right.
    return 0;
}
//Recursive hyperbolic sine.
float h(float angR){
    //We add a call into our sinh stack.
    sinhStk.push(angR);
    //Base condition:
    float tol=1e-6;
    if(angR>-tol&&angR<tol) return angR+angR*angR*angR/6;
    //Recursion.
    return 2*h(angR/2)*g(angR/2);
}
//Recursive hyperbolic cosine.
float g(float angR){
    //We add a call into our cosh stack.
    coshStk.push(angR);
    //Base condition:
    float tol=1e-6;
    if(angR>-tol&&angR<tol) return 1+angR*angR/2;
    //Recursion:
    float b=h(angR/2);
    return 1+2*b*b;
}
