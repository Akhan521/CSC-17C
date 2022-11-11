/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: November 10, 2022, 11:30 AM
 * Purpose: Linear, Binary, and Hash Searches.
 */

//System Libraries:
#include <ctime>     //Time Library.
#include <vector>    //Vector Library.
using namespace std;

//User Libraries:
#include "LinkedList.h"           //Our linked list class.
#include "GeneralHashFunctions.h" //Hash functions.

//Function Prototypes:
//Fills and returns a vector of random strings.
vector<string> fill(int,int);
//Creates a random string of a specified length.
string rndString(int);
//Sorts a vector.
vector<string> sort(vector<string>);
//Linear search function.
bool linSrch(vector<string>,string);
//Binary search function.
bool binSrch(vector<string>,string);
//Hash-based search function.
bool hashSrch(vector<LinkedList<string>> &,string);
//Builds a hash table from a vector.
vector<LinkedList<string>> buildTable(vector<string>);

//Execution Begins Here:
int main(int argc, char* argv[]){
    //Set the random number seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //The size of our array.
    int n=10;
    //The length of each string in our array.
    int length=5;
    
    //Our vector/array that will be searched.
    vector<string> v=fill(n,length);
    
    //A vector of strings we'll be searching for.
    vector<string> toSrch(n);
    
    //Filling half of our toSrch vector w/ strings in our vector.
    for(int i=0;i<n/2;i++) toSrch[i]=v[rand()%n];
    //Filling the other half with strings NOT in our vector.
    for(int i=n/2;i<n;i++) toSrch[i]=rndString(length);
    //Note: I'm trying to make this a 50-50 mix, where half
    //of the strings we're searching for are present and the
    //other half contains strings that are NOT present.
    
    //We construct a hash table from our vector. This hash table will
    //be used to perform a hash-based search for an element.
    vector<LinkedList<string>> hashTable=buildTable(v);
    
    //Displaying the elements in our array.
    cout<<"The elements in our array are:"<<endl;
    for(string elem:v){
        cout<<elem<<endl;
    }
    cout<<endl;
    
    cout<<"The elements we're searching for:"<<endl;
    int f=0;  //The # of elements that were found.
    int nf=0; //The # of elements not found.
    //Searching for random strings with our hash-search function:
    for(int i=0;i<toSrch.size();i++){
        //To store whether the element was found or not.
        bool found=hashSrch(hashTable,toSrch[i]);
        //If we found it, we display that it was found.
        if(found){
            f++; //We found an element.
            cout<<toSrch[i]<<" was found."<<endl;
        }
        //Otherwise, we display that it wasn't found.
        else{
            nf++; //We didn't find an element.
            cout<<toSrch[i]<<" wasn't found."<<endl;
        }
    }
    
    //Output our percentages:
    cout<<endl;
    cout<<"% Found     = "<<100.0f*f/n<<"%"<<endl;
    cout<<"% Not Found = "<<100.0f*nf/n<<"%"<<endl;
    
    //Exit the Program - Cleanup.
    return 0;
}

string rndString(int n){
    //A random string we'll construct.
    string rnd="";
    //We add on as many random characters as we want.
    for(int i=0;i<n;i++){
        //We're adding a random character between A-Z.
        rnd+=rand()%('Z'-'A'+1)+'A'; //Characters A-Z.
    }
    //We return our random string.
    return rnd;
}

vector<string> fill(int n,int length){
    //Our vector.
    vector<string> v(n);
    //We fill our vector with N strings.
    for(int i=0;i<n;i++){
        //We create a random string of a specified length.
        string rnd=rndString(length);
        //We insert our random string into our vector.
        v[i]=rnd;
    }
    //We return our vector.
    return v;
}

vector<string> sort(vector<string> v){
    //To hold a sorted copy of our vector.
    vector<string> sorted(v);
    //Sorting our vector.
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            if(sorted[i]>sorted[j]){
                string temp=sorted[i];
                sorted[i]=sorted[j];
                sorted[j]=temp;
            }
        }
    }
    //Returning a sorted copy of our vector.
    return sorted;
}

bool linSrch(vector<string> v,string item){
    //Iterating through our entire array.
    for(int i=0;i<v.size();i++){
        //If we've found it, we return true.
        if(v[i]==item) return true;
    }
    //Not found.
    return false;
}

bool binSrch(vector<string> v,string item){
    //Our left and right boundaries.
    int l=0,r=v.size()-1;
    //Iterating as long as we have valid bounds...
    while(l<=r){
        //Determining the midpoint.
        int mid=(l+r)/2;
        //If we've found it, we return true.
        if(v[mid]==item) return true;
        else if(v[mid]>item) r=mid-1;
        else l=mid+1;
    }
    //Not found.
    return false;
}

bool hashSrch(vector<LinkedList<string>> &table,string item){
    //The size of our hash table and also our array.
    int n=table.size();
    //The index that's returned when we hash our string.
    int indx=FNVHash(item)%n;
    //If the linked list at our hashed index is empty,
    //the string does not exist in our array. 
    if(table[indx].isEmpty()) return false;
    //If our linked list is not empty, we look through our linked
    //list to see if the string is present. If it is, that indicates
    //that the string exists within our array.
    return table[indx].find(item);
    //Note: The find() method returns true if the item is present in our
    //linked list. Otherwise, it returns false.
}

vector<LinkedList<string>> buildTable(vector<string> v){
    //Our hash table. (Uses linked lists to implement chaining.)
    //This allows us to handle collisions. The size of our table
    //is the same size as our array.
    vector<LinkedList<string>> hashTable(v.size(),LinkedList<string>());
    //We want to hash every element in our vector into our table:
    for(string elem:v){
        //The index that's returned when we hash our element.
        int indx=FNVHash(elem)%hashTable.size();
        //We insert our element into our table at the hashed index.
        hashTable[indx].push_back(elem);
    }
    //We return our constructed hash table.
    return hashTable;
}