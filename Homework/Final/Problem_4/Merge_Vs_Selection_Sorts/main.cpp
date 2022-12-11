/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: Dec. 11, 2022, 11:50 AM
 * Purpose: Problem 4 - Merge Vs. Our Selection Sort
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <vector>    //Vectors.
#include <cstdlib>   //CSTD Library.
#include <ctime>     //Time Library.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
//Create and fill a vector w/ random short integers.
vector<int> fill(int);
//Outputs our data elements.
void print(vector<int>,int);
//Selection sort routine.
void selSort(vector<int> &,int);
//Merge sort routine.
void mrgSort(vector<int> &); 
//Merge routine used in our Merge sort.
void merge(vector<int> &,vector<int>,vector<int>);

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //Our vector size.
    const int SIZE=100000;
    int perLine=10;
    
    //Creating + filling our vector.
    vector<int> v=fill(SIZE);
    
    //Outputting our unsorted vector.
    print(v, perLine);

    //Merge sorting our vector.
    mrgSort(v);

    //Outputting our sorted vector.
    print(v,perLine);
    
    //Exit the Program - Cleanup.
    return 0;
}
//Creates and fills a vector w/ random short integers.
vector<int> fill(int n){
    //Upper range of a short integer.
    short s=32767; 
    //Creating our vector.
    vector<int> vect(n);
    //Filling our vector...
    for(int i=0;i<n;i++){
        //Filling it w/ values from [-32,768, 32,767].
        vect[i]=rand()%(s+(s+1))-(s+1);
    }
    //Returning our vector.
    return vect;
}
//To print our data elements.
void print(vector<int> v,int perLine){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
        if(i%perLine==perLine-1)
            cout<<endl;
    }
    cout<<endl;
}
//Our selection sort function. We only sort the first "p" elements.
void selSort(vector<int> &array,int p){
    //The "p" chosen must be between [0, N].
    if(p>=0&&p<=array.size()){
        //Our outer loop.
        for(int i=0;i<p;i++){
            //The index of the smallest element.
            int minIndx=i;
            //Our inner loop.
            for(int j=i+1;j<array.size();j++){
                //Finding the smallest element.
                if(array[j]<array[minIndx]) minIndx=j;
            }
            //Performing our swap.
            swap(array[i],array[minIndx]);
        }
    }
    //Otherwise, we output an error message.
    else cout<<"ERROR: Invalid value chosen for p.\n";
}
//Our merge sort function.
void mrgSort(vector<int> &array){
    //Base condition: If we have only 1 element, we simply return.
    if(array.size()==1) return;
    //We divide our arrays in half.
    int mid=array.size()/2;
    //Our left half w/ half of our elements.
    vector<int> left(mid);
    //Our right half w/ the remaining elements.
    vector<int> right(array.size()-mid);
    //Filling the left half.
    for(int i=0;i<mid;i++) left[i]=array[i];
    //Filling the right half.
    for(int i=mid;i<array.size();i++) right[i-mid]=array[i];
    //Recursively sorting our left sub-array.
    mrgSort(left);
    //Recursively sorting our right sub-array.
    mrgSort(right);
    //Merging our halves together in sorted order.
    merge(array,left,right);
}
//To merge 2 arrays into 1 larger array in sorted order.
void merge(vector<int> &array,vector<int> left,vector<int> right){
    //Our pointers for both sub-arrays.
    int l=0,r=0;
    //Placing all of our elements into our final array.
    for(int i=0;i<left.size()+right.size();i++){
        //If we only have elements in our right half left...
        if(l==left.size()) array[i]=right[r++];
        //If we only have elements in our left half left...
        else if(r==right.size()) array[i]=left[l++];
        //If the value from the left half is smaller, we store it first.
        else if(left[l]<=right[r]) array[i]=left[l++];
        //Otherwise, we store the value from the right half first.
        else array[i]=right[r++];
    }
}