/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: October 17, 2022, 12:15 PM
 * Purpose: Problem 12 - Modes with sets.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <cstdlib>   //Cstd Library.
#include <ctime>     //Time Library.
#include <set>       //Sets.
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
    cout<<"the use of sets to find our modal information. By using sets, my\n";
    cout<<"my code was slightly reduced. This code can still be improved quite\n";
    cout<<"a bit with the use of maps instead of sets.\n";
    
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
    int maxFreq=0;   //Max frequency.
    int freq=0;      //To hold the current frequency.
    int nModes=0;    //The number of modes we have.
    set<int> values; //Our set of values.
    //Filling our set with the distinct values in our data set.
    for(int i=0;i<size;i++) values.insert(array[i]);
    //We find the frequency of every element in our set:
    for(int elem:values){ //Going through each element in our set.
        freq=0; //Initialize its frequency with 0 to begin with.
        //We check how many times the element appears in our data set.
        for(int i=0;i<size;i++)
            if(array[i]==elem) freq++; //We increment the frequency.
        if(freq>maxFreq) maxFreq=freq; //Storing the max frequency.
    }
    //Finding the number of modes in our data set:
    for(int elem:values){ //Going through each element in our set.
        freq=0; //Initialize its frequency with 0 to begin with.
        //We check how many times the element appears in our data set.
        for(int i=0;i<size;i++)
            if(array[i]==elem) freq++; //We increment the frequency.
        //If the frequency == Max frequency, we've found a mode.
        if(freq==maxFreq) nModes++;
    }
    //Creating our mode array.
    int *modes=new int[nModes+2]; //Sizing it.
    modes[0]=nModes;              //Storing the number of modes.
    modes[1]=maxFreq;             //Storing the max frequency.
    int idx=2;                    //Index variable for our array.
    //Filling our mode array.
    for(int elem:values){ //Going through each element in our set.     
        freq=0; //Initialize its frequency with 0 to begin with.
        //We check how many times the element appears in our data set.
        for(int i=0;i<size;i++)
            if(array[i]==elem) freq++; //We increment the frequency.
        //If the frequency == Max frequency, we've found a mode, so we store it.
        if(freq==maxFreq) modes[idx++]=elem;
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
