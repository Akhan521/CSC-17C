/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: October 17, 2022, 6:20 PM
 * Purpose: Problem 9 - Recursive power functions.
 */

//System Libraries:
#include <iostream>  //I/O Library.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
int powRec(int,int);    //A recursive O(N) power function.
int powRecEff(int,int); //An efficient and recursive O(lg(N)) power function.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    
    //Declare Variables.
    int x, //The base.
        n; //The power.
    
    //Display our purpose.
    cout<<"This program implements 2 recursive power functions."<<endl;
    cout<<"Enter the base being raised to a power. Then, enter the power"<<endl;
    cout<<"the base is being raised to. The results will be displayed.\n"<<endl;
    
    //Initialize Variables.
    cout<<"Enter the base: \n";
    cin>>x;
    cout<<"Enter the power: \n";
    cin>>n;
    
    //Map Inputs to Outputs -> Process.
    
    //Display Inputs/Outputs.
    cout<<endl;
    cout<<"O(N) power function     : "<<x<<"^"<<n<<" = "<<powRec(x,n)<<endl;
    cout<<endl;
    cout<<"O(lg(N)) power function : "<<x<<"^"<<n<<" = "<<powRecEff(x,n)<<endl;
    
    //Exit the Program - Cleanup.
    return 0;
}

//A recursive O(N) power function:
int powRec(int x,int n){
    //Base condition:
    if(n<=0) return 1;
    //Recursion:
    return x * powRec(x,n-1);
}

//A recursive O(lg(N)) power function that uses binary exponentiation: 
int powRecEff(int x,int n){
    //Base condition:
    if(n<=0) return 1; //If we have 0 as our power...
    if(n==1) return x; //If we have 1 as our power...
    //Recursion:
    //Case 1: The power is even.
    if(n%2==0)
        //We square the base and half the power.
        return powRecEff(x*x,n/2);
    //Case 2: The power is odd.
    else
        //We separate a term and subtract the power of the other term by 1.
        return x * powRecEff(x,n-1); 
}

/* Binary Exponentiation:
 * 
 * Case 1:
 * If your power is even, you square the base and half the power. For example,
 * if you had 2^10, you would end up with 4^5. 
 * 
 * Case 2: 
 * If your power is odd, you separate 1 term and subtract the power of the
 * other term by 1. For example, if we had 4^5, you would end up with 4 * 4^4. 
 * From here, we could proceed to simply 4^4, since its power is even.
 * 
 * EXAMPLE: 2^10 = 4^5 = 4 * 4^4 = 4 * 16^2 = 4 * 256^1 = 1024.
 */