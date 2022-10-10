/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: October 6, 2022, 11:10 AM
 * Purpose: Demonstrating set functions.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <iterator>  //Iterators.
#include <set>       //Sets.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:

//Execution Begins Here:
int main(int argc, char** argv) {
    // Empty set container. (Stores values in descending order).
    // By typing greater<type>, we can specify descending order.
    set<int, greater<int> > s1;
 
    // Insert elements in random order.
    s1.insert(40);
    s1.insert(30);
    s1.insert(60);
    s1.insert(20);
    s1.insert(50);
    s1.insert(10);
    
    // Only one 50 will be added to the set.
    s1.insert(50);
 
    // Printing set s1:
    // Creating an iterator for set s1.
    set<int, greater<int> >::iterator itr;
    cout << "\nThe set s1 is : \n";
    // Outputting our values using an iterator.
    for (itr = s1.begin(); itr != s1.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
 
    // Assigning the elements from s1 to s2.
    // Values are stored in ascending order.
    set<int> s2(s1.begin(), s1.end());
 
    // Print all elements of the set s2.
    cout << "\nThe set s2, after being assigned from s1, is : \n";
    // Outputting our values using an iterator.
    for (itr = s2.begin(); itr != s2.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
 
    // Remove all elements up to 30 in s2.
    cout << "\ns2 after the removal of elements less than 30 "
            ":\n";
    //Using erase() to remove elements in our set.
    s2.erase(s2.begin(), s2.find(30));
    // Outputting our values using an iterator.
    for (itr = s2.begin(); itr != s2.end(); itr++) {
        cout << *itr << " ";
    }
 
    // Remove the element with a value of 50 in s2
    int num;
    num = s2.erase(50);
    cout << "\ns2.erase(50) : ";
    cout << num << " removed\n";
    // Outputting our values using an iterator.
    for (itr = s2.begin(); itr != s2.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
 
    // lower_bound(val): Returns an iterator to the first element that is 
    // equivalent to val or that won't go before the element val in the set.
    // upper_bound(val): Returns an iterator to the first element that will 
    // go after the element val in the set.
    
    // Lower bound and upper bound for set s1 w/ respect to 40.
    cout << "\ns1.lower_bound(40) : \n"
         << *s1.lower_bound(40) << endl;
    cout << "s1.upper_bound(40) : \n"
         << *s1.upper_bound(40) << endl;
 
    // Lower bound and upper bound for set s2 w/ respect to 40.
    cout << "s2.lower_bound(40) :\n"
         << *s2.lower_bound(40) << endl;
    cout << "s2.upper_bound(40) : \n"
         << *s2.upper_bound(40) << endl;
    
    //Exit the Program - Cleanup.
    return 0;
}