/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: October 6, 2022, 12:10 PM
 * Purpose: Map tutorial.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <iterator>  //Iterators.
#include <map>       //Maps.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:

//Execution Begins Here:
int main(int argc, char** argv) {
    //Empty map container.
    map<int, int> gquiz1;
  
    //Insert elements in random order.
    //Demonstrating how pairs can be inserted.
    gquiz1.insert(pair<int, int>(1, 40));
    gquiz1.insert(pair<int, int>(2, 30));
    gquiz1.insert(pair<int, int>(3, 60));
    gquiz1.insert(pair<int, int>(4, 20));
    gquiz1.insert(pair<int, int>(5, 50));
    gquiz1.insert(pair<int, int>(6, 50));
    
    //Demonstrating another way to insert a value.
    gquiz1[7]=10;
     
    //Printing map gquiz1 using an iterator.
    map<int, int>::iterator itr;
    cout << "\nThe map gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    //Displaying each key-value pair.
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        //Accessing each key and value.
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;
  
    //Assigning the elements from gquiz1 to gquiz2.
    map<int, int> gquiz2(gquiz1.begin(), gquiz1.end());
  
    //Print all elements of the map gquiz2.
    cout << "\nThe map gquiz2, after being"
         << " assigned from gquiz1, is : \n";
    cout << "\tKEY\tELEMENT\n";
    //Displaying each key-value pair.
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        //Accessing each key and value.
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;
  
    //Remove all elements up to the element with key = 3 in gquiz2.
    cout << "\ngquiz2 after the removal of"
            " elements less than key = 3 : \n";
    cout << "\tKEY\tELEMENT\n";
    //Erasing the specified elements.
    gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
    //Displaying each key-value pair.
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        //Accessing each key and value.
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
  
    //Remove the element with key = 4.
    int num;
    num = gquiz2.erase(4);
    cout << "\ngquiz2.erase(4) : ";
    cout << num << " removed \n";
    cout << "\tKEY\tELEMENT\n";
    //Displaying each key-value pair.
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        //Accessing each key and value.
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;
  
    //Lower bound and upper bound for map gquiz1 w/ respect to key = 5.
    cout << "gquiz1.lower_bound(5) : "
         << "\tKEY = ";
    //Accessing the returned iterator's key.
    cout << gquiz1.lower_bound(5)->first << '\t';
    //Accessing the returned iterator's value.
    cout << "\tELEMENT = " << gquiz1.lower_bound(5)->second
         << endl;
    cout << "gquiz1.upper_bound(5) : "
         << "\tKEY = ";
    //Accessing the returned iterator's key.
    cout << gquiz1.upper_bound(5)->first << '\t';
    //Accessing the returned iterator's value.
    cout << "\tELEMENT = " << gquiz1.upper_bound(5)->second
         << endl;
    
    //Exit the Program - Cleanup.
    return 0;
}