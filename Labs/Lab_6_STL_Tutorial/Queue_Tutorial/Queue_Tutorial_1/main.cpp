/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: October 6, 2022, 11:40 AM
 * Purpose: Queue tutorial 1.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <queue>     //Queues.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
void showQ(queue<int>); //Print the queue.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Declaring our queue.
    queue<int> gquiz;
    
    //Inserting elements.
    gquiz.push(10);
    gquiz.push(20);
    gquiz.push(30);
    
    //Printing our queue.
    cout << "The queue gquiz is : ";
    showQ(gquiz);
    
    //Outputting some properties.
    cout << "\ngquiz.size()  : " << gquiz.size();
    cout << "\ngquiz.front() : " << gquiz.front();
    cout << "\ngquiz.back()  : " << gquiz.back();
    
    //Popping the first element.
    cout<<endl;
    cout << "\ngquiz.pop() : "<<gquiz.front();
    gquiz.pop();
    
    //Printing our queue.
    cout<<endl;
    cout << "\nThe queue gquiz is : ";
    showQ(gquiz);
    
    //Exit the Program - Cleanup.
    return 0;
}

//Print the queue:
void showQ(queue<int> data)
{
    //Storing a copy of our inputted queue in another variable.
    queue<int> g = data;
    
    //Printing our queue and emptying it.
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}