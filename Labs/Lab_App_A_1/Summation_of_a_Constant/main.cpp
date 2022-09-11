/* 
 * File:   main.cpp
 * Author: Aamir Khan
 * Created on August 25, 2022, 9:50 AM
 * Purpose: Summation of a Constant
 * 
 * (Sum from i=m to n of c.)
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int n,m,c;       //Our constants.
    int sltn1,sltn2; //Our 2 solutions.
    //Initialize Variables
    n=m=c=sltn1=sltn2=0;
    cout<<"Summation of a Constant"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"Enter the constant to be summed: ";
    cin>>c;
    cout<<"Enter the lower bound of summation: ";
    cin>>m;
    cout<<"Enter the upper bound of summation: ";
    cin>>n;
    //Map Inputs to Outputs -> Process
    //Solution 1:
    for(int i=m;i<=n;i++){ //For-loop solution.
        sltn1+=c;
    }
    //Solution 2: c * (n - m + 1).
    sltn2=c*(n-m+1);       //Closed-form solution.
    //Display Inputs/Outputs
    cout<<endl;
    cout<<"For-loop solution   : "<<sltn1<<endl;
    cout<<"Closed-form solution: "<<sltn2<<endl;
    //Exit the Program - Cleanup
    return 0;
}