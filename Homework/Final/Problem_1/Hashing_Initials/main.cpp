/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: Dec. 8, 2022, 9:30 AM
 * Purpose: Problem 1 - Hashing + Analysis.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <cstdlib>   //Rand() + Srand().
#include <ctime>     //Time Library.
#include <list>      //Linked lists.
#include <map>       //Maps.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
string genIntls();   //Generates a random 3-letter initial. For ex. MEL.
int hashFnc(string); //Hashes an initial and returns a hash-value.
//Searches our list for a specific initial to locate a person.
bool search(list<string>[],int,string);

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare + Initialize Variables.
    const int SIZE=512;
    //An array of linked lists.
    list<string> list[SIZE];
    //To store frequencies.
    map<int,int> freq;
    
    //Map Inputs to Outputs -> Process.
    for(int i=1;i<=SIZE;i++){
        //Generating a random 3-letter initial.
        string rndIntl=genIntls();
        //Generating a hash value from our random initial.
        int hashVal=hashFnc(rndIntl);
        //Hashing our initial into our array of linked lists.
        list[hashVal%SIZE].push_back(rndIntl);
    }
    
    //Display Inputs/Outputs.
    int maxDepth=0; //To store the max depth of our array.
    //Outputting the depth or size of each list:
    for(int i=0;i<SIZE;i++){
        //Storing the frequency.
        freq[list[i].size()]++;
        cout<<"List "<<i+1<<" has a depth of "<<list[i].size()<<"."<<endl;
        //Storing the max depth.
        if(list[i].size()>maxDepth) maxDepth=list[i].size();
    }
    //Outputting statistics.
    cout<<"\nFor a depth greater than 0, the number of collisions is equal\n";
    cout<<"to depth - 1. For example, if we had a depth of 1, that means we\n";
    cout<<"had no collisions as only a single element got hashed into the list.\n";
    cout<<endl;
    cout<<"Max Depth      = "<<maxDepth<<endl;
    cout<<"Max Collisions = "<<maxDepth-1<<endl;
    cout<<endl;
    //Outputting our frequencies.
    for(pair<int,int> p:freq){
        //We output the number of lists w/ a certain number of elements.
        cout<<p.second<<" lists had "<<p.first<<" element(s).\n";
    }
    
    //Exit the Program - Cleanup.
    return 0;
}
//Generates a random 3-letter initial.
string genIntls(){
    string initial="";
    for(int i=0;i<3;i++){
        //Adding a random letter between A-Z.
        initial+=rand()%('Z'-'A'+1)+'A';
    }
    //Returning our 3-letter initial.
    return initial;
}
//Hashes an initial using the telephone keypad as our guide.
//For Ex: MEL would hash to 635. We hash each letter to its number.
int hashFnc(string intl){
    //To store our hash value. A multiplier to manage ones, tens, etc.
    int hashVal=0,mult=1;
    for(int i=intl.length()-1;i>=0;i--){
        //If we have A-C, that will correspond to a 2.
        if(intl[i]=='A'||intl[i]=='B'||intl[i]=='C')
            hashVal+=2*mult;
        //If we have D-F, that will correspond to a 3.
        else if(intl[i]=='D'||intl[i]=='E'||intl[i]=='F')
            hashVal+=3*mult;
        //If we have G-I, that will correspond to a 4.
        else if(intl[i]=='G'||intl[i]=='H'||intl[i]=='I')
            hashVal+=4*mult;
        //If we have J-L, that will correspond to a 5.
        else if(intl[i]=='J'||intl[i]=='K'||intl[i]=='L')
            hashVal+=5*mult;
        //If we have M-O, that will correspond to a 6.
        else if(intl[i]=='M'||intl[i]=='N'||intl[i]=='O')
            hashVal+=6*mult;
        //If we have P-S, that will correspond to a 7.
        else if(intl[i]=='P'||intl[i]=='Q'||intl[i]=='R'||intl[i]=='S')
            hashVal+=7*mult;
        //If we have T-V, that will correspond to a 8.
        else if(intl[i]=='T'||intl[i]=='U'||intl[i]=='V')
            hashVal+=8*mult;
        //If we have W-Z, that will correspond to a 9.
        else hashVal+=9*mult;
        //Updating our multiplier.
        mult*=10;
    }
    //Returning our hash value.
    return hashVal;
}
//Searches our list to locate a person by their initials.
bool search(list<string> list[],int size,string intl){
    //Generating the hash value for the given initial.
    int hashVal=hashFnc(intl);
    //Checking the hashed list for our initial.
    for(string s:list[hashVal%size]){
        //If we've found it, we return true.
        if(s==intl) return true;
    }
    //Otherwise, we return false.
    return false;
}