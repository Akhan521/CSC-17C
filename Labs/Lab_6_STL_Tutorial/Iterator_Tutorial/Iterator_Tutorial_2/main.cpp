/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: October 6, 2022, 7:50 PM
 * Purpose: Iterator tutorial 2. 
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
    // Setting it to the front of our vector.
    vector<int>::iterator ptr = ar.begin();
      
    // Displaying what ptr is currently pointing to.
    cout << "Before advancing : " << *ptr << endl;
    
    // Using advance() to increment our iterator position (Will point to 4).
    advance(ptr, 3);
      
    // Displaying what ptr is now pointing to.
    cout << "After advancing  : " << *ptr << endl;
    
    //Exit the Program - Cleanup.
    return 0;
}