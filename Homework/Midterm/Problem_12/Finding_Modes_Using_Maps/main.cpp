/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: October 18, 2022, 3:15 PM
 * Purpose: Problem 12 - Modes with maps.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <cstdlib>   //Cstd Library.
#include <ctime>     //Time Library.
#include <map>       //Maps.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
int *fillAry(int,int);        //Fills an array.
void prntAry(int *,int,int);  //Prints our array.
void prntMod(int *);          //Prints our mode array.
int *mode(const int *,int);   //Creates our mode array.

//Execution begins here
int main(int argc, char*argv[]) {
    //Display our purpose.
    cout<<"This program finds the mode/modes of a data set. It demonstrates\n";
    cout<<"the use of a map to find our modal information. By using a map,\n";
    cout<<"my code was reduced and simplified a great deal.\n";
    
    //Declare variables.
    int arySize=15; //The array size.
    int modNum=10;  //The mod used to fill our array.
    
    //Fill our array.
    int *ary=fillAry(arySize,modNum);
    
    //Print the initial array.
    cout<<"\nOur array:";
    prntAry(ary,arySize,10);
    
    //Create the mode array.
    int *modeAry=mode(ary,arySize);
    
    //Print the modal information of the array.
    cout<<"\nModal information:";
    prntMod(modeAry);
    
    //Delete allocated memory.
    delete []ary;     //Our initial array.
    delete []modeAry; //Our mode array.
    
    //Exit stage right.
    return 0;
}

//Creates our mode array.
int *mode(const int *array,int size){
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
    //Filling our mode array:
    int *modes=new int[nModes+2]; //Sizing it.
    modes[0]=nModes;              //Storing the number of modes.
    modes[1]=maxFreq;             //Storing the max frequency.
    int idx=2;                    //Index variable for our array.
    //Checking the frequency of every element in our map:
    for(pair<int,int> elem:freq){   
        //If the frequency of the current element == Max frequency, we have a mode.
        if(elem.second==maxFreq) 
            modes[idx++]=elem.first; //We store it in our mode array.
    }
    return modes; //Returning our mode array.
}

//Prints the modal information of our array.
void prntMod(int *ary){
    cout<<endl;
    cout<<"The number of modes = "<<
            ary[0]<<endl;
    cout<<"The max frequency = "<<
            ary[1]<<endl;
    if(ary[0]==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    cout<<"The mode set = {";
    for(int i=2;i<ary[0]+1;i++){
        cout<<ary[i]<<",";
    }
    cout<<ary[ary[0]+1]<<"}"<<endl;
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
        *(array+i)=i%modNum;
    }
    //Return our array.
    return array;
}

