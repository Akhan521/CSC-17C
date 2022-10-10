/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: October 6, 2022, 10:10 AM
 * Purpose: Pair Tutorial 1.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <utility>   //Pairs.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    
    //Defining a pair.
    pair<int, char> PAIR1;
    //Defining another pair using initialization.
    pair<string, double> PAIR2("GeeksForGeeks", 1.23);
    //Defining 2 pairs to demonstrate default initialization.
    pair<int, double> PAIR3;
    pair<string, char> PAIR4;
    //Defining another pair to demonstrate make_pair().
    pair<string, double> PAIR5;
    //Defining 2 pairs to demonstrate swap().
    pair<char, int> pair1 = make_pair('A', 1);
    pair<char, int> pair2 = make_pair('B', 2);
  
    //First part of the pair.
    PAIR1.first = 100;
    //Second part of the pair.
    PAIR1.second = 'G';
    
    //Demonstrating make_pair().
    PAIR5 = make_pair("GeeksForGeeks is the Best", 4.56);
    
    //1st pair.
    cout << PAIR1.first << " ";
    cout << PAIR1.second << endl;
    
    //2nd pair.
    cout << PAIR2.first << " ";
    cout << PAIR2.second << endl;
    
    //It is initialized to 0.
    cout << PAIR3.first; 
    //It is initialized to 0.
    cout << PAIR3.second << endl; 
  
    //It prints nothing i.e NULL.
    cout << PAIR4.first; 
    //It prints nothing i.e NULL.
    cout << PAIR4.second << endl;
    
    //5th pair.
    cout << PAIR5.first << " ";
    cout << PAIR5.second << endl;
    
    //Demonstrating swap().
    cout << "\nBefore swapping:\n ";
    cout << "Contents of pair1 = " << pair1.first << " "
         << pair1.second << " ";
    cout << "Contents of pair2 = " << pair2.first << " "
         << pair2.second;
    pair1.swap(pair2);
  
    cout << "\nAfter swapping:\n ";
    cout << "Contents of pair1 = " << pair1.first << " "
         << pair1.second << " ";
    cout << "Contents of pair2 = " << pair2.first << " "
         << pair2.second;
    
    //Exit the Program - Cleanup.
    return 0;
}