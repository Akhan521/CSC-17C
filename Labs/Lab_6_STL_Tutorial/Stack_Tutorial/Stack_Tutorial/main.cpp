/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: October 6, 2022, 11:30 AM
 * Purpose: Stack tutorial.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <stack>     //Stacks.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    
    //Declaring our stack. It is implemented w/ a deque by default.
    stack<int> stack;
    
    //Pushing values onto our stack.
    stack.push(21);
    stack.push(22);
    stack.push(24);
    stack.push(25);
    
    //Popping the first 2 elements in our stack.
    stack.pop(); //25 is popped.
    stack.pop(); //24 is popped.
    
    //Emptying the rest of our stack.
    cout<<"Emptying our stack..."<<endl;
    while(!stack.empty()) {
        //Output each element before popping it.
        cout << stack.top() <<" ";
        //Popping the element.
        stack.pop();
    }
    
    //Exit the Program - Cleanup.
    return 0;
}