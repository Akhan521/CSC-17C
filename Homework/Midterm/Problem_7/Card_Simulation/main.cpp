/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: October 18, 2022, 10:15 PM
 * Purpose: Problem 7 - Card simulation.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <cstdlib>   //Cstd Library.
#include <ctime>     //Time Library.
#include <iomanip>   //Formatting.
#include <map>       //Maps.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
//Fills an array.
int *fillAry(int,int);
//Prints our array.
void prntAry(int *,int,int);
//Returns the # of modes and the max frequency.
pair<int,int> mode(const int *,int);

//Execution begins here:
int main(int argc, char*argv[]) {
    //Initialize random number seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //Display our purpose.
    cout<<"This program demonstrates a card simulation. We are given 4 cards to\n";
    cout<<"choose, with 13 possible face values each. We would like to find the\n";
    cout<<"probability of choosing 1 pair, 2 pairs, 3 of a kind, and 4 of a kind.\n";
    cout<<"We simulate the probabilities in this program.\n";
    
    //Declare variables.
    int nTries=100000; //The number of tries we'd like to have.
    int numCards=4;    //The number of cards we're given. (Size of our array.)
    int fceVals=13;    //13 possible face values.
    int onePair=0;     //The number of times we got 1 pair.
    int twoPair=0;     //The number of times we got 2 pairs.
    int threeKind=0;   //The number of times we got 3 of a kind.
    int fourKind=0;    //The number of times we got 4 of a kind.
    
    //For each of our tries:
    for(int i=1;i<=nTries;i++){
        //We choose 4 random cards and return them.
        int *chosen=fillAry(numCards,fceVals);
        //We return the # of modes and max frequency. These 2 pieces of data
        //will be used to determine whether we have any 1 pairs, 2 pairs, etc.
        pair<int,int> data=mode(chosen,numCards);
        //If we have 1 mode w/ a max frequency of 2, we have 1 pair:
        if(data.first==1&&data.second==2) onePair++;
        //If we have 2 modes w/ a max frequency of 2, we have 2 pairs.
        else if(data.first==2&&data.second==2) twoPair++;
        //If we have 1 mode w/ a max frequency of 3, we have 3 of a kind.
        else if(data.first==1&&data.second==3) threeKind++;
        //If we have 1 mode w/ a max frequency of 4, we have 4 of a kind.
        else if(data.first==1&&data.second==numCards) fourKind++;
        //Cleaning up:
        delete []chosen;  //Our initial array.
    }
    
    //Print the simulated probabilities:
    cout<<endl<<fixed<<setprecision(3);
    cout<<"Probability of 1 pair      = "<<100.0f*onePair/nTries<<"%"<<endl;
    cout<<"Probability of 2 pairs     = "<<100.0f*twoPair/nTries<<"%"<<endl;
    cout<<"Probability of 3 of a kind = "<<100.0f*threeKind/nTries<<"%"<<endl;
    cout<<"Probability of 4 of a kind = "<<100.0f*fourKind/nTries<<"%"<<endl;
    
    //Exit stage right.
    return 0;
}

//Returns the number of modes and the max frequency.
pair<int,int> mode(const int *array,int size){
    //Max frequency:
    int maxFreq=0;
    //Our map to hold frequencies:
    map<int,int> freq;
    //Filling our map with frequencies:
    for(int i=0;i<size;i++){
        //Incrementing the frequency of the current element.
        freq[array[i]]++;
        //Storing the max frequency:
        maxFreq=max(maxFreq,freq[array[i]]);
    }
    //Finding the number of modes:
    int nModes=0; //To store the number of modes we have.
    //Checking the frequency of every element in our map:
    for(pair<int,int> elem:freq){
        //If the frequency of the current element == Max frequency, we have a mode.
        if(elem.second==maxFreq) nModes++;
    }
    //Returning the number of modes and the max frequency.
    return make_pair(nModes,maxFreq);
}

//Prints our array.
void prntAry(int *array,int n,int perLine){
    //Output the array.
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Fills our array.
int *fillAry(int n, int modNum){
    //Allocate memory.
    int *array=new int[n];
    //Fill the array with 2 digit numbers.
    for(int i=0;i<n;i++){
        *(array+i)=rand()%modNum;
    }
    //Return our array.
    return array;
}

