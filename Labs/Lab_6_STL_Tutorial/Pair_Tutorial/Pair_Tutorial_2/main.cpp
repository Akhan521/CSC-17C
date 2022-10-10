/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: October 6, 2022, 10:30 AM
 * Purpose: Pair Tutorial 2.
 */

//System Libraries:
#include <bits/stdc++.h> //To demonstrate tie() with pairs.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    
    //Defining a pair.
    pair<int, int> pair1 = { 1, 2 };
    int a, b;
    //The tie method is used to unpack pair values
    //into separate variables.
    tie(a, b) = pair1;
    //Displaying the unpacked values.
    cout << a << " " << b << "\n";
    
    //Defining another pair.
    pair<int, int> pair2 = { 3, 4 };
    //The ignore keyword indicates that the element isn't 
    //going to be unpacked. It is ignored.
    tie(a, ignore) = pair2;
  
    //Prints old value of b.
    cout << a << " " << b << "\n";
  
    //Illustrating a pair of pairs.
    pair<int, pair<int, char> > pair3 = { 3, { 4, 'a' } };
    //To store our pair values.
    int x, y;
    char z;
  
    // tie(x,y,z) = pair3; Gives a compilation error.
    // tie(x, tie(y,z)) = pair3; Gives a compilation error.
    // Each pair needs to be explicitly handled.
    x = pair3.first;
    tie(y, z) = pair3.second;
    //Displaying the unpacked values.
    cout << x << " " << y << " " << z << "\n";
    
    //Exit the Program - Cleanup.
    return 0;
}