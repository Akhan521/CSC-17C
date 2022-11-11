/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: November 10, 2022, 9:30 AM
 * Purpose: Bloom Filter.
 */

//System Libraries:
#include <iostream>  //I/O Library
#include <string>    //String Library.
#include <vector>    //Vector Library.
#include <cmath>     //Math Library.
//User Libraries:
#include "GeneralHashFunctions.h"
using namespace std;

//Execution Begins Here:
int main(int argc, char* argv[]){
   //Declare + Initialize our variables:
    int n=15,    //Size of our Bit Vector.
        m=0,     //# of keys used for our hashes (# of elements in our list).
        k=2;     //# of hashes utilized.
    //Whether we'd like to store more elements or not.
    char choice;
    //Our "bit vector" or array initialized with 0's.
    vector<char> bitVctr(n,'0'); 
    //Our list of elements/strings.
    vector<string> list;
    
    //Map Inputs to Outputs -> Process
    cout<<"\tBloom Filter:\n";
    do{
        string input; //To hold our string input.
        cout<<"\nEnter a string to hash:\n";
        cin>>input;
        
        //Storing it in our list.
        list.push_back(input);
        m++; //We've added a key or item to our list.
        cout<<endl;
        
        //Displaying the hashed indices.
        cout<<"FNV Hash Value:  "<<FNVHash(input)%n<<endl;
        cout<<"ELF Hash Value:  "<<ELFHash(input)%n<<endl;  
        
        //Setting our bits given our hash values:
        //For the FNV hash:
        bitVctr[FNVHash(input)%n]='1';
        //For the ELF hash:
        bitVctr[ELFHash(input)%n]='1';

        //Ask whether we'd like to store another string.
        cout<<"\nWould you like to add another string (Y/N)?\n";
        cin>>choice;      
    }while(choice=='y'||choice=='Y');
    
    //Testing elements for membership:
    do{
        system("clear"); //Clearing our screen.
        
        //Display the elements in our set:
        cout<<endl;
        cout<<"\tElements in our Set:\n";
        for(string item:list){
            cout<<item<<endl;
        }

        //Output which bits have already been set:
        cout<<"\nThe following bits have been set:\n";
        for(int i=0;i<bitVctr.size();i++){
            if(bitVctr[i]=='1'){
                cout<<i<<" ";
            }
        }
        cout<<endl;
        
        string input; //To hold our string input.
        cout<<"\nEnter a string to see if it's in our set:\n";
        cin>>input;
        
        //Output our hashed indices for the inputted string.
        cout<<endl;
        cout<<"FNV Hash Value:  "<<FNVHash(input)%n<<endl;
        cout<<"ELF Hash Value:  "<<ELFHash(input)%n<<endl;
         
        //If the bits have been set at both hashed indices, it's likely
        //that the element is present in our set or list of elements.
        if(bitVctr[FNVHash(input)%n]=='1'&&bitVctr[ELFHash(input)%n]=='1'){
            cout<<"\nPresent? MAYBE!\n";
        }else{
            cout<<"\nPresent? N0.\n";
        }
        
        //Determining the probability of a false-positive:
        int numBitsSet=0; //The number of bits that were set (# of unique hashes).
        float prob=0.0f;  //The probability of a false positive.
        //P = (# of bits set/size of bit vector)^# of hashes.
        //Finding out how many bits were set:
        for(int i=0;i<bitVctr.size();i++){
            if(bitVctr[i]=='1') numBitsSet++;
        }
        
        //Performing our calculations.
        prob=pow((static_cast<float>(numBitsSet)/n),k);
        prob*=100; //To have it as a %.
        cout<<"\nProbability of a FP = "<<prob<<"%\n";
        
        //Ask whether we'd like to test another string.
        cout<<"\nWould you like to test another string (Y/N)?\n";
        cin>>choice;
    }while(choice=='y'||choice=='Y');
    
    //Exit the Program - Cleanup
   return 0;
}
