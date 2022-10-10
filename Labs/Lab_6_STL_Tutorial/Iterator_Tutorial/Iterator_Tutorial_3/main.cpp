/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: October 6, 2022, 8:20 PM
 * Purpose: Iterator tutorial 3. 
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
      
    // Declaring iterators to our vector.
    vector<int>::iterator ptr = ar.begin(); // Beginning of our vector.
    vector<int>::iterator ftr = ar.end();   // Ending of our vector.
     
     
    // Using next() to return a new iterator (Will point to 4).
    // From the start, we advance our iterator forward by 3.
    auto it1 = next(ptr, 3);
      
    // Using prev() to return a new iterator (Will point to 3).
    // From the end, we move our iterator backward by 3.
    auto it2 = prev(ftr, 3);
      
    // Displaying our iterator position.
    cout << "The position of our new iterator using next() is : ";
    cout << *it1 << " ";
    cout << endl;
      
    // Displaying our iterator position.
    cout << "The position of our new iterator using prev() is : ";
    cout << *it2 << " ";
    cout << endl;
    
    //Exit the Program - Cleanup.
    return 0;
}