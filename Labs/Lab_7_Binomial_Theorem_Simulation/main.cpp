/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: Oct. 10, 2022, 3:50 PM
 * Purpose: Flipping coins simulation + calculations
 *                using the Binomial Theorem.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <iomanip>   //Formatting.
#include <cstdlib>   //rand() and srand().
#include <ctime>     //Time Library.
#include <cmath>     //Math Library.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
int bCoeff(int,int); //Returns a binomial coefficient.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables.
    int nTries=10000; //How many tries we'd like to have.
    float x=0.5f;     //Probability of flipping a coin and getting heads.
    float y=0.5f;     //Probability of flipping a coin and getting tails.
    
    //Initialize Variables.
    int cnt3H1T=0; //The number of times we had 3 heads and 1 tail.
    
    //Simulation of flipping 4 times using a fair coin:
    for(int tries=1;tries<=nTries;tries++){
        int nHeads=0; //Number of heads.
        int nTails=0; //Number of tails.
        //Flipping a coin 4 times...
        for(int flip=1;flip<=4;flip++){
            char coin=rand()%2+1; // 1 or 2 (Heads or Tails).
            if(coin==1) nHeads++;
            else nTails++;
        }
        //If we have 3 heads and 1 tail, we increment our count.
        if(nHeads==3&&nTails==1)
            cnt3H1T++;
    }
    //Probability using our simulation w/ a fair coin:
    cout<<fixed<<setprecision(2);
    cout<<"Number of times we flip 4 coins: "<<nTries<<endl<<endl;
    cout<<"Flipping 4 times w/ a fair coin and getting 3 heads and 1 tail:\n";
    cout<<"Percent Simulation = "<<100.0f*cnt3H1T/nTries<<"%"<<endl;
    //Calculation using the Binomial Theorem = nCi * x^i * y^n-i.
    //Probability of flipping 4 times and getting 3 heads (n=4 & i=3):
    float prob3Heads=bCoeff(4,3)*pow(x,3)*pow(y,4-3);
    //Probability of flipping 4 times and getting 1 tail (n=4 & i=1):
    float prob1Tail=bCoeff(4,1)*pow(x,1)*pow(y,4-1);
    //Probability of flipping 4 times and getting 3 heads and 1 tail:
    cout<<"Calculation        = "<<100.0f*prob3Heads+prob1Tail<<"%\n"<<endl;
    
    //We now want to use a biased coin, where heads comes up 60% of the time:
    x=0.6f;    //Probability of flipping a coin and getting heads.
    y=0.4f;    //Probability of flipping a coin and getting tails.
    cnt3H1T=0; //The number of times we had 3 heads and 1 tail.
    
    //Simulation of flipping 4 times using a biased coin:
    for(int tries=1;tries<=nTries;tries++){
        int nHeads=0; //Number of heads.
        int nTails=0; //Number of tails.
        //Flipping a coin 4 times...
        for(int flip=1;flip<=4;flip++){
            char coin=rand()%100+1; //1-100.
            //There's a 60% chance that it will come up heads, so
            //it will come up heads 60/100 times.
            if(coin<=60) nHeads++;
            //The other 40%, it will come up tails.
            else nTails++;
        }
        //If we have 3 heads and 1 tail, we increment our count.
        if(nHeads==3&&nTails==1)
            cnt3H1T++;
    }
    //Probability using our simulation w/ a biased coin:
    cout<<fixed<<setprecision(2);
    cout<<"Flipping 4 times w/ a biased coin and getting 3 heads and 1 tail:\n";
    cout<<"Percent Simulation = "<<100.0f*cnt3H1T/nTries<<"%"<<endl;
    //Calculation using the Binomial Theorem = nCi * x^i * y^n-i.
    //Probability of flipping 4 times and getting 3 heads (n=4 & i=3):
    prob3Heads=bCoeff(4,3)*pow(x,3)*pow(y,4-3);
    //Probability of flipping 4 times and getting 1 tail (n=4 & i=1):
    prob1Tail=bCoeff(4,1)*pow(x,1)*pow(y,4-1);
    //Probability of flipping 4 times and getting 3 heads and 1 tail:
    cout<<"Calculation        = "<<100.0f*prob3Heads+prob1Tail<<"%"<<endl;
    
    //Exit the Program - Cleanup.
    return 0;
}

int bCoeff(int n,int i){
    //Base conditions:
    if(i==0) return 1;
    if(n==i) return 1;
    //Recursion:
    return bCoeff(n-1,i-1)+bCoeff(n-1,i);
}