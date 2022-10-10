/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: October 6, 2022, 11:55 AM
 * Purpose: Queue tutorial 2 - More methods.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <queue>     //Queues.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
void printQ(queue<int>); //Print the queue.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Declaring our queue.
    queue<int> q1;
    
    //Inserting elements.
    q1.push(1);
    q1.push(2);
    q1.push(3);
    
    //Printing our queue.
    cout << "The first queue is : ";
    printQ(q1);
    
    //Declaring another queue.
    queue<int> q2;
    
    //Inserting elements.
    q2.push(4);
    q2.push(5);
    q2.push(6);
    
    //Printing the 2nd queue.
    cout << "The second queue is : ";
    printQ(q2);
    
    //Swapping the 2 queues.
    q1.swap(q2);
    
    //After swapping...
    cout << "After swapping, the 1st queue is : ";
    printQ(q1);
    cout << "After swapping, the 2nd queue is : ";
    printQ(q2);
    
    cout<<"Is our 1st queue empty? "<<endl;
    //Returns false since q1 is not empty.
    cout<<(q1.empty()!=0?"True":"False");
    
    //Exit the Program - Cleanup.
    return 0;
}

//Print the queue:
void printQ(queue<int> data)
{
    //Storing a copy of our inputted queue in another variable.
    queue<int> temp = data;
    
    //Printing our queue and emptying it.
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << '\n';
}