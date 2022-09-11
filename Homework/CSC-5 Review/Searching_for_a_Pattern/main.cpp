/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: 8-30-2022 @ 9:20 PM
 * Purpose: Searching for multiple occurrences of a pattern.
 *          Searching a sentence for a pattern.
 */

//System Libraries Here.
#include <iostream> //cin, cout, and getline().
#include <cstring>  //strlen().
using namespace std;

//User Libraries Here.

//Global Constants Only, No Global Variables.
//PI, e, Gravity, or conversions.

//Function Prototypes Begin Here.
int  srch1(const char [],const char [],int);      //Search for 1 occurrence of a pattern.
void srchAll(const char [],const char [],int []); //Search for all occurrences of a pattern.
void print(const char []);                        //Print the character arrays we created.
void print(const int []);                         //Print the array of indices where the pattern found.

//Program Execution Begins Here.
int main(int argc, char** argv) {
    //Declare all Variables Here.
    const int LINE=81;               //Size of sentence or pattern to find.
    char sntnce[LINE],pattern[LINE]; //Char arrays (80 + null terminator).
    int match[LINE];                 //Index array for where pattern was found.
    
    //Input a sentence and a pattern to match.
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern:
    //Input the sentence and pattern, Output the matching positions.
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the outputs.
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit.
    return 0;
}
//Search 1 function. Searches for 1 occurrence of the pattern. We input the
//sentence, pattern, and the index we'll be starting our search from.
//We return the index where the pattern started.
int srch1(const char a[],const char b[],int start){
    int lenSnt = strlen(a); //Length of the sentence.
    int lenPat = strlen(b); //Length of the pattern.
    int i=start,  //Index variable for our sentence.
        j=0;      //Index variable for our pattern.
    //Make sure we are within the sentence.
    while(i<lenSnt){   
        //We compare the 2 letter-by-letter. If they match, we move on to the next characters in both.
        if(a[i]==b[j]){
            i++; 
            j++;
        }
        //If the letters don't match, we move to the next character in our sentence.
        //We want to start the search all over again from the next letter.
        else if(a[i]!=b[j]){
            i++;
            j=0;
        }
        //We know that the pattern was found if j reaches the length of the pattern.
        if(j==lenPat){
            //Return the starting index of the pattern.
            //This would be the index we ended off at - lenPat (i-j).
            return i-j;
        } 
    }
    //If no match was found...
    return -1;
}
//Search all function. Searches for all occurrences of a pattern by repetitively
//calling the search 1 function as many times as needed. It fills the integer
//array with the indices of where the pattern was found.
void srchAll(const char a[],const char b[],int c[]){
    int start=0; //Where to start our search from. (Passed into srch1()).
    int cnt=0;   //Index variable for our integer array.
    bool found;  //To hold whether we've found an index.
    //Finding all occurrences of a pattern:
    do{
        //Initialize found to false.
        found=false;
        //Search for 1 occurrence of the pattern.
        int idx = srch1(a,b,start);
        //If we've found a valid index, we add it to our integer array.
        if(idx!=-1){
            //Adding the index to our index array.
            c[cnt]=idx;
            //Incrementing our index variable.
            cnt++;
            //Updating our start position for the next search.
            //We want to set start to the index just after the pattern we found.
            //This is because we don't want to repeat the search for the same occurrence.
            //This would be the index we found + the length of the pattern.
            start = idx + strlen(b); 
            //Setting found to true.
            found=true;
        }
        //If there are no occurrences, we simply set the first value to -1.
        else c[cnt]=-1;
    //We continue looping as long as we've found an occurrence. This is to check
    //whether more occurrences of the pattern exist within the sentence.
    }while(found);
}
//Print function for our char arrays.
void print(const char a[]){
    int len = strlen(a);
    for(int i=0;i<len;i++){
        cout<<a[i];
    }
    cout<<endl;
}
//Print function for our index array.
void print(const int a[]){
    int i=0; //Index variable.
    //If no occurrences exist, output None.
    if(a[i]==-1)
        cout<<"None\n";
    //For however many occurrences we have...
    while(a[i]!=-1){
        //Output the index where the pattern was found.
        cout<<a[i]<<endl;
        //Increment our index variable.
        i++;
    }
}