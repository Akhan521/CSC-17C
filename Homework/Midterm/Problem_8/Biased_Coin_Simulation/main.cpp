/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: October 17, 2022,8:00 PM
 * Purpose: Problem 8 - Biased coin simulation.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <vector>    //Vectors.
#include <ctime>     //Time Library.
#include <cstdlib>   //Cstd Library.
#include <cmath>     //Math Library.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
int binCoeff(int,int); //Returns a binomial coefficient.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //Displaying our purpose.
    cout<<"This program runs a simulation with a biased coin to determine the\n";
    cout<<"probability of flipping 5 heads in a row. There is a 40% probability\n";
    cout<<"that a flipped coin will come up heads. We display our results from\n";
    cout<<"our simulation and use a binomial calculation to verify our result.\n";
    cout<<endl;
    
    //Declare Variables.
    const int SIZE=100; //The size of our vector.
    int nTries=10000;   //The number of tries we'd like to have.
    float prob=0.4f;    //The probability of flipping a heads (40%).
    
    //Our bit vector:
    vector<bool> v(SIZE);
    
    //Filling 40% of our bit vector. This represents that we have a 40%
    //chance at flipping a heads. (Biased coin.)
    for(int i=0;i<40;i++){
        v[i]=1; //Setting it as a 1.
    }
    
    //Our simulation with a biased coin:
    int cnt5H=0; //The number of times we flipped 5 heads in a row.
    //Flipping 5 coins for as many tries as we have.
    for(int nTry=1;nTry<=nTries;nTry++){
        int heads=0; //The number of heads we flipped.
        for(int flip=1;flip<=5;flip++){
            //Returning a random element from our bit vector.
            //If we land on a 1, this means we flipped a heads.
            if(v[rand()%SIZE])
                heads++;
        }
        //If we flipped 5 heads...
        if(heads==5)
            //We increment our count.
            cnt5H++;
    }
    
    //Displaying our results.
    //Simulation calculation.
    cout<<"Simulation calculation = "
        <<100.0f*cnt5H/nTries<<"%"<<endl;
    //Binomial calculation: nCr * x^n * y^n-r.
    // n = r = 5 because we flip 5 coins and want to know the 
    // probability of flipping 5 heads in a row.
    cout<<"Binomial calculation   = "
        <<100.0f*binCoeff(5,5)*pow(prob,5)*pow(1-prob,5-5)<<"%";
    cout<<endl;
    
    //Exit the Program - Cleanup.
    return 0;
}

//Returns a binomial coefficient: nCr.
int binCoeff(int r,int c){
    //Base conditions:
    if(c==0) return 1; //The start of the row in Pascal's triangle.
    if(r==c) return 1; //The end of the row in Pascal's triangle.
    //Recursion:
    //The sum of the 2 elements above in Pascal's triangle:
    return binCoeff(r-1,c-1)+binCoeff(r-1,c); 
}