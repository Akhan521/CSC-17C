/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: Dec. 9, 2022, 5:30 PM
 * Purpose: Problem 3 - Customer Handling Simulation w/ Queues.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <queue>     //Queues.
#include <vector>    //Vectors.
#include <ctime>     //Time Library.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    
    //Declare + Initialize Variables.
    int numClrks=3;      //The number of clerks we begin with.
    int custmrs=0;       //To keep count of what customer we're on.
    int waited=0;        //The number of customers that had to wait.
    int maxInLne=0;      //To hold the max customers in line at one time.
    int arrvlTime=15;    //Customers arrive every 15 seconds.
    float waitTime=0.0f; //To hold the average wait time.
    int hours=12*60*60;  //12 "hours" to run our program for. (In seconds.)
    queue<int> line;     //Our line of customers.
    
    //Our clerks:
    vector<int> clerks(numClrks);
    clerks[0]=60;  //Clerk 1 services 1 customer per minute.
    clerks[1]=120; //Clerk 2 services 1 customer per 2 minutes.
    clerks[2]=80;  //Clerk 3 services 1 customer per 4/3 minutes.
    int size=0;    //To hold our initial size and keep track of 
                   //when we need to add more clerks to the line.
    
    //Map Inputs to Outputs -> Process.
    for(int time=1;time<=hours;time++){
        //To keep track of the wait time.
        int begin=0;
        //Every 15 seconds, a customer enters the line.
        if(time%arrvlTime==0){
            line.push(++custmrs);
            //Storing the maximum customers in line at the same time.
            if(line.size()>maxInLne) maxInLne=line.size();
            //We begin our timer if there are more than 3 customers in line.
            //There are 3 clerks, so we can service 3 customers at a time.
            //If we have more, then the rest have to wait.
            if(line.size()>numClrks){
                begin=time;
                //Storing the number of customers that have to wait.
                waited+=(line.size()-numClrks);
            }
        }
        //Every 5 customers, we add a new clerk.
        if(line.size()==size+5){
            //We update our size.
            size+=5;
            //We add a new clerk w/ the same rate as the first clerk.
            clerks.push_back(clerks[0]);
        }
        //If we no longer need our extra clerk...
        else if(line.size()==size-5){
            //We update our size.
            size-=5;
            //We remove the extra clerk we added in.
            clerks.pop_back();
        }
        //Checking if each of our clerks has finished with a customer.
        for(int c=0;c<clerks.size();c++){
            //If a clerk has finished with a customer...
            if(time%clerks[c]==0){
                //If there were more than 3 customers, we now end our timer.
                //This is the time the rest of the customers had to wait.
                //We'll add it to our wait time to calculate the avg. wait time.
                if(line.size()>numClrks) waitTime+=time-begin;
                //The customer is removed from the front of the line.
                line.pop(); 
            }
        }
    }
    
    //We calculate the average wait time for the customers that had to wait.
    waitTime/=static_cast<float>(waited);
    
    //Outputting our results.
    cout<<"Average Wait Time       = "<<waitTime<<" seconds."<<endl;
    cout<<"Max Customers in Line   = "<<maxInLne<<endl;
    cout<<"Customers Still in Line = "<<line.size()<<endl;
    
    //Exit the Program - Cleanup.
    return 0;
}