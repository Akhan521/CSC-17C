/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: October 6, 2022, 12:00 PM
 * Purpose: List tutorial.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <iterator>  //Iterators.
#include <list>      //Lists.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
void showlist(list<int>); //Print the elements in a list.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Declaring 2 lists.
    list<int> gqlist1, gqlist2;
    
    //Filling our lists.
    for (int i = 0; i < 10; ++i) {
        gqlist1.push_back(i * 2);
        gqlist2.push_front(i * 3);
    }
    
    //Printing list 1.
    cout << "\nList 1 (gqlist1) is : ";
    showlist(gqlist1);
    
    //Printing list 2.
    cout << "\nList 2 (gqlist2) is : ";
    showlist(gqlist2);
    
    //Displaying the front and back of list 1.
    cout << "\ngqlist1.front() : " << gqlist1.front();
    cout << "\ngqlist1.back()  : " << gqlist1.back();
    cout<<endl;
    
    //Popping an element from the front.
    cout << "\ngqlist1.pop_front() : ";
    gqlist1.pop_front();
    //Printing list 1.
    showlist(gqlist1);
    
    //Popping an element from the back.
    cout << "\ngqlist2.pop_back() : ";
    gqlist2.pop_back();
    //Printing list 2.
    showlist(gqlist2);
    
    //Reversing list 1.
    cout << "\ngqlist1.reverse() : ";
    gqlist1.reverse();
    showlist(gqlist1);
    
    //Sorting list 2.
    cout << "\ngqlist2.sort(): ";
    gqlist2.sort();
    showlist(gqlist2);
    
    //Exit the Program - Cleanup.
    return 0;
}

//Print the elements in a list.
void showlist(list<int> l){
    //Declaring an iterator.
    list<int>::iterator it;
    //Outputting each element.
    for (it = l.begin(); it != l.end(); ++it){
        //Displaying the values.
        cout << '\t' << *it;
    }
    cout << '\n';
}