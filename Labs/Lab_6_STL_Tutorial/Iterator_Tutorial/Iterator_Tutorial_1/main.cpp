/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: October 6, 2022, 7:50 PM
 * Purpose: Iterator tutorial 1.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include<iterator>   //Iterators.
#include<vector>     //Vectors.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:

//Execution Begins Here:
int main(int argc, char** argv) {
    
    // Declaring a vector and initializing it.
    vector<int> ar = { 1, 2, 3, 4, 5 };
      
    // Declaring an iterator to a vector.
    vector<int>::iterator ptr;
      
    // Displaying vector elements using begin() and end().
    cout << "The vector elements are : ";
    for (ptr = ar.begin(); ptr < ar.end(); ptr++)
        cout << *ptr << " ";
    
    //Exit the Program - Cleanup.
    return 0;
}