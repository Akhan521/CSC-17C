/* 
 * File:     main.cpp
 * Author:   Aamir Khan
 * Created:  8-30-2022 @ 6:40 PM
 * Purpose:  Even and Odd Vectors into 2D array.
 * We input an array of integers and separate the values
 * into either an even or odd vector based on whether the
 * values are either even or odd. Then, we put it into a
 * 2D array. 1st col = even vector. 2nd col = odd vector.
 */

//System Libraries Here.
#include <iostream> //cin and cout.
#include <vector>   //Vectors.
#include <iomanip>  //setw() and right.
using namespace std;

//User Libraries Here.

//Global Constants Only, No Global Variables.
//Allowed like PI, e, Gravity, conversions, array dimensions necessary.
const int COLMAX=2; //Only 2 columns needed, even and odd.

//Function Prototypes Here.
void read(vector<int> &, vector<int> &);            //Reads 2 vectors.
void copy(vector<int>, vector<int>,int [][COLMAX]); //Copies into 2D array.
void prntVec(vector<int>, vector<int>,int);         //Prints our vectors.
void prntAry(const int [][COLMAX],int,int,int);     //Prints our 2D array.

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here.
    const int ROW=80;           //No more than 80 rows.
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd.
    vector<int> even(0),odd(0); //Declare even and odd vectors.
    
    //Input data and place values in either the even or odd vector.
    read(even,odd);
    
    //Now output the contents of the vectors.
    //          setw(10)
    prntVec(even,odd,10); //Print even and odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array.
    copy(even,odd,array);
    
    //Now output the contents of the array.
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10); //Same format as prntVec.
    
    //Exit.
    return 0;
}
//Read function. Reads 2 vectors.
void read(vector<int> &even, vector<int> &odd){
    int num;  //Number of elements being passed.
    cout<<"Input the number of integers to input.\n";
    cin>>num;
    cout<<"Input each number.\n";
    int input;
    for(int i=0;i<num;i++){
        cin>>input;
        if(input%2) //If input%2==1, we have an odd value.
            odd.push_back(input);
        else        //Else, we have an even value.
            even.push_back(input);
    }
}
//Print function for our vectors.
void prntVec(vector<int> even, vector<int> odd,int spcing){
    //Print the heading.
    cout<<setw(spcing)<<"Vector"<<setw(spcing)<<"Even"<<setw(spcing)<<"Odd"<<endl;
    //Determine how many rows there will be displayed.
    for(int i=0;i<even.size()+odd.size();i++){
        //Printing only an even value and filling the row with spaces...
        //This is for when we have an even and no odd for the given row.
        if(i<even.size()&&i>=odd.size())
            cout<<setw(spcing+spcing)<<even[i]<<setw(spcing)<<"";
        //If we have an even and we also have an odd value to add...
        else if(i<even.size())
            cout<<setw(spcing+spcing)<<even[i]<<setw(spcing);
        //If we only have an odd to add, we just move to the right place.
        else 
            cout<<setw(spcing+spcing+spcing);
        //If we have an odd to add...
        if(i<odd.size())
            cout<<odd[i];
        //Outputting a newline for every row.
        if(i<even.size()||i<odd.size())
            cout<<endl;
        
    }
}
//Copy function. Copies the even vector into column 1 of our 
//2D array and the odd vector into column 2 of our 2D array.
void copy(vector<int> even, vector<int> odd,int arr[][COLMAX]){
    //Copy the evens in the first column.
    for(int i=0;i<even.size();i++){
        arr[i][0]=even[i];
    }
    //Copy the odds in the second column.
    for(int i=0;i<odd.size();i++){
        arr[i][1]=odd[i]; 
    }
}
//Print function for our 2D array. Same format as the printVec function.
void prntAry(const int arr[][COLMAX],int sze1,int sze2,int spcing){
    //Print the heading.
    cout<<setw(spcing)<<"Array"<<setw(spcing)<<"Even"<<setw(spcing)<<"Odd"<<endl;
    //Outputting our values.
    for(int i=0;i<sze1+sze2;i++){
        //Printing only an even value and filling the row with spaces...
        //This is for when we have an even and no odd for the given row.
        if(i<sze1&&i>=sze2)
            cout<<setw(spcing+spcing)<<arr[i][0]<<setw(spcing)<<"";
        //If we have an even and we also have an odd value to add...
        else if(i<sze1)
            cout<<setw(spcing+spcing)<<arr[i][0]<<setw(spcing);
        //If we only have an odd to add, we just move to the right place.
        else 
            cout<<setw(spcing+spcing+spcing);
        //If we have an odd to add...
        if(i<sze2)
            cout<<arr[i][1];
        //Outputting a newline for every row.
        if(i<sze1||i<sze2)
            cout<<endl;
    }
}