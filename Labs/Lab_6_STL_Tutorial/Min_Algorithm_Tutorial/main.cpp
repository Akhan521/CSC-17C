/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: October 6, 2022, 7:20 PM
 * Purpose: Min algorithm tutorial.
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
    
    // Declaring 2 integers.
    int a=5;
    int b=7;
    
    // Comparing the 2 integers.
    cout << min(a,b) << "\n";
  
    // Returns the first element if both numbers are the same.
    cout << min(7,7) << "\n";
    
    // Comparing the 2 using a pre-defined binary function.
    // We can pass in our own binary function into min, and
    // min() will use it to perform the comparison.
    cout << min(a,b,comp) << "\n";
  
    // Returns the first element if both numbers are the same.
    cout << min(7,7,comp) << "\n";
    
    // Finding the smallest of all our numbers.
    cout << min({ 1, 2, 3, 4, 5, 0, -1, 7 }, comp) << "\n";
 
    //Exit the Program - Cleanup.
    return 0;
}

//To compare 2 ints.
bool comp(int a, int b){ 
    return (a < b); 
} 