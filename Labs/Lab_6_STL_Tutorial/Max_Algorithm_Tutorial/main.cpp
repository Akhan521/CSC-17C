/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: October 6, 2022, 6:30 PM
 * Purpose: Max algorithm tutorial.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <algorithm> //Algorithms.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
bool comp(int,int); //To compare 2 ints.

//Execution Begins Here:
int main(int argc, char** argv) {
    // Comparing the ASCII values of a and b.
    cout << max('a','b') << "\n";
  
    // Returns the first element if both numbers are the same.
    cout << max(7,7) << "\n";
    
    //Declaring 2 integers.
    int a = 7; 
    int b = 28; 
    
    // Comparing 2 ints using a pre-defined binary function.
    // We can pass our binary function into max to use it.
    cout << max(a,b,comp) << "\n"; 
    
    // Returns the first element if both numbers are the same.
    cout << max(7,7,comp) << "\n"; 
    
    // Finding the largest of all our numbers.
    cout << max({1, 2, 3, 4, 5, 10, -1, 7},comp) << "\n";
 
    //Exit the Program - Cleanup.
    return 0;
}

//To compare 2 ints.
bool comp(int a, int b){ 
    return (a < b); 
} 