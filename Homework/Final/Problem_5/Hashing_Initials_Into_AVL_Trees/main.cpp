/* File:    main.cpp
 * Author:  Aamir Khan
 * Created: Dec. 10, 2022, 3:15 PM
 * Purpose: Hashing Initials Into AVL Trees.
 *            We're reworking Problem 1 to
 *               incorporate AVL Trees.
 */

//System Libraries:
#include <vector> //Vector Library.
#include <map>    //Maps.

//User Libraries:
#include "Tree.h" //Our Tree Class.

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
string genIntls();   //Generates a random 3-letter initial. For ex. MEL.
int hashFnc(string); //Returns a hash-value for the given initial.
//Searches our table for an initial to locate an individual.
bool search(vector<Tree *>,string);

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //Size of our array. (Number of trees.)
    const int SIZE=512;
    
    //To store frequencies.
    map<int,int> freq;
    
    //Our vector of trees that serves as our hash table. (512 Trees.)
    vector<Tree *> table(SIZE);
    
    //Filling our vector w/ tree objects.
    for(int i=0;i<table.size();i++){
        table[i]=new Tree;
    }
    
    //Generating 512 random initials and inserting them into our trees:
    for(int i=0;i<SIZE;i++){
        //Generating a random 3-letter initial.
        string rndIntl=genIntls();
        //Generating a hash value from our random initial.
        int hashVal=hashFnc(rndIntl);
        //Hashing our random initial into our vector of trees.
        table[hashVal%SIZE]->insert(rndIntl);
    }
    
    //To store the max depth/size.
    int maxDepth=0; 
    //Outputting the depth or size of each tree:
    for(int i=0;i<SIZE;i++){
        //Storing the frequency.
        freq[table[i]->size()]++;
        cout<<"Tree "<<i+1<<" has a size of "<<table[i]->size()<<"."<<endl;
        //Storing the max depth.
        if(table[i]->size()>maxDepth) maxDepth=table[i]->size();
    }
    
    //Outputting statistics.
    cout<<"\nFor a depth greater than 0, the number of collisions is equal to\n";
    cout<<"depth - 1. For example, if we had a depth of 1, that means we had\n";
    cout<<"no collisions as only a single element got inserted into the tree.\n";
    cout<<endl;
    cout<<"Max Depth/Size = "<<maxDepth<<endl;
    cout<<"Max Collisions = "<<maxDepth-1<<endl;
    cout<<endl;
    //Outputting our frequencies.
    for(pair<int,int> p:freq){
        //We output the number of trees that had a certain size.
        cout<<p.second<<" trees had "<<p.first<<" element(s).\n";
    }
    
    //Deallocating the memory for our tree objects.
    for(int i=0;i<table.size();i++){
        delete table[i];
    }
    
    //Exit Main.
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
//Searches our table for an initial to locate an individual.
bool search(vector<Tree *> table,string intl){
    int size=table.size();
    //Generating the hash value for the given initial.
    int hashVal=hashFnc(intl);
    //Checking the hashed tree for our initial.
    //If found, we return true. Otherwise, we return false.
    return table[hashVal%size]->search(intl);
}